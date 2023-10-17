#include "fio.h"
#include "PR/os_flash.h"
#include "gcc/string.h"

typedef struct SaveInfo {
    /* 0x08 */ s32 slot;
    /* 0x04 */ s32 count;
} SaveInfo; // size = 0x8

#define GLOBALS_PAGE_1 6
#define GLOBALS_PAGE_2 7

SHIFT_BSS SaveData FetchSaveBuffer;
SHIFT_BSS SaveInfo LogicalSaveInfo[4];  // 4 save slots presented to the player
SHIFT_BSS SaveInfo PhysicalSaveInfo[6]; // 6 saves as represented on the EEPROM
SHIFT_BSS s32 NextAvailablePhysicalSave;
SHIFT_BSS SaveGlobals gSaveGlobals;
SHIFT_BSS SaveData gCurrentSaveFile;

char MagicSaveString[] = "Mario Story 006";

void fio_deserialize_state(void);
void fio_serialize_state(void);
b32 fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes);
b32 fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes);
void fio_erase_flash(s32 pageNum);

s32 get_spirits_rescued(void) {
    s32 storyProgress = evt_get_variable(NULL, GB_StoryProgress);
    s32 ret = 7;

    if (storyProgress < evt_get_variable(NULL, STORY_CH1_STAR_SPIRIT_RESCUED)) {
        ret = 0;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH2_STAR_SPIRIT_RESCUED)) {
        ret = 1;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH3_STAR_SPIRIT_RESCUED)) {
        ret = 2;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH4_STAR_SPIRIT_RESCUED)) {
        ret = 3;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH5_OPENED_ESCAPE_ROUTE)) {
        ret = 4;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH6_STAR_SPIRIT_RESCUED)) {
        ret = 5;
    } else if (storyProgress < evt_get_variable(NULL, STORY_CH7_STAR_SPIRIT_RESCUED)) {
        ret = 6;
    }

    return ret;
}

s32 fio_calc_globals_checksum(void) {
    u32 sum = 0;
    s32* it = (s32*)&gSaveGlobals;
    u32 i;

    for (i = 0; i < sizeof(gSaveGlobals) / sizeof(*it); i++, it++) {
        sum += *it;
    }
    return sum;
}

b32 fio_validate_globals_checksums(void) {
    SaveGlobals* header = &gSaveGlobals;

    if (strcmp(header->magicString, MagicSaveString)) {
        return FALSE;
    }
    if (header->crc1 != ~header->crc2) {
        return FALSE;
    }
    return fio_calc_globals_checksum() == header->crc1;
}

b32 fio_load_globals(void) {
    fio_read_flash(GLOBALS_PAGE_1, &gSaveGlobals, sizeof(gSaveGlobals));
    if (fio_validate_globals_checksums()) {
        return TRUE;
    }

    fio_read_flash(GLOBALS_PAGE_2, &gSaveGlobals, sizeof(gSaveGlobals));
    if (fio_validate_globals_checksums()) {
        return TRUE;
    }

    bzero(&gSaveGlobals, sizeof(gSaveGlobals));
    return FALSE;
}

b32 fio_save_globals(void) {
    s32 checksum;

    strcpy(gSaveGlobals.magicString, MagicSaveString);
    gSaveGlobals.crc1 = 0;
    gSaveGlobals.crc2 = ~gSaveGlobals.crc1;
    checksum = fio_calc_globals_checksum();
    gSaveGlobals.crc1 = checksum;
    gSaveGlobals.crc2 = ~checksum;
    fio_erase_flash(GLOBALS_PAGE_1);
    fio_write_flash(GLOBALS_PAGE_1, (s8*)&gSaveGlobals, sizeof(gSaveGlobals));
    fio_erase_flash(GLOBALS_PAGE_2);
    fio_write_flash(GLOBALS_PAGE_2, (s8*)&gSaveGlobals, sizeof(gSaveGlobals));
    return TRUE;
}

s32 fio_calc_file_checksum(SaveData* saveData) {
    u32 sum = 0;
    s32* it = (s32*)saveData;
    u32 i;

    for (i = 0; i < sizeof(*saveData) / sizeof(*it); i++, it++) {
        sum += *it;
    }
    return sum;
}

b32 fio_validate_file_checksum(SaveData* saveData) {
    if (!strcmp(saveData->magicString, MagicSaveString) && saveData->crc1 == ~saveData->crc2) {
        return fio_calc_file_checksum(saveData) == saveData->crc1;
    }
    return FALSE;
}

b32 fio_fetch_saved_file_info(void) {
    SaveData* fetchBuf = &FetchSaveBuffer; // temps required to match
    SaveData* validBuf = fetchBuf;
    s32 i, j, minSaveCount;

    for (i = 0; i < ARRAY_COUNT(LogicalSaveInfo); i++) {
        LogicalSaveInfo[i].slot = -1;
        LogicalSaveInfo[i].count = -1;
    }

    for (i = 0; i < ARRAY_COUNT(PhysicalSaveInfo); i++) {
        fio_read_flash(i, fetchBuf, sizeof(SaveData));
        if (fio_validate_file_checksum(fetchBuf)) {
            PhysicalSaveInfo[i].slot = validBuf->saveSlot;
            PhysicalSaveInfo[i].count = validBuf->saveCount;
            // logical saves only track the most recent physical save for each slot
            if (LogicalSaveInfo[validBuf->saveSlot].count < validBuf->saveCount) {
                LogicalSaveInfo[validBuf->saveSlot].slot = i;
                LogicalSaveInfo[validBuf->saveSlot].count = validBuf->saveCount;
            }
        }
    }

    minSaveCount = 0x7FFFFFFF;
    for (j = 0; j < ARRAY_COUNT(PhysicalSaveInfo); j++) {
        // find a logical save for each physical save
        for (i = 0; i < ARRAY_COUNT(LogicalSaveInfo); i++) {
            if (j == LogicalSaveInfo[i].slot) {
                break;
            }
        }
        // condition holds only for physical saves not mapped to logical ones
        if (i == ARRAY_COUNT(LogicalSaveInfo)) {
            if (PhysicalSaveInfo[j].count < minSaveCount) {
                // choose the least-recent unmapped physical save slot
                minSaveCount = PhysicalSaveInfo[j].count;
                NextAvailablePhysicalSave = j;
            }
        }
    }
    return TRUE;
}

b32 fio_load_game(s32 saveSlot) {
    gGameStatusPtr->saveSlot = saveSlot;

    fio_fetch_saved_file_info();
    fio_read_flash(LogicalSaveInfo[saveSlot].slot, &gCurrentSaveFile, sizeof(SaveData));

    if (strcmp(gCurrentSaveFile.magicString, MagicSaveString) == 0) {
        if (gGameStatusPtr->saveCount < gCurrentSaveFile.saveCount) {
            gGameStatusPtr->saveCount = gCurrentSaveFile.saveCount;
        }
        fio_deserialize_state();
        return TRUE;
    }
    return FALSE;
}

void fio_save_game(s32 saveSlot) {
    fio_fetch_saved_file_info();

    gGameStatusPtr->saveSlot = saveSlot;

    fio_serialize_state();

    strcpy(gCurrentSaveFile.magicString, MagicSaveString);

    gCurrentSaveFile.saveSlot = saveSlot;
    gGameStatusPtr->saveCount++;
    gCurrentSaveFile.saveCount = gGameStatusPtr->saveCount;

    gCurrentSaveFile.crc1 = 0;
    gCurrentSaveFile.crc2 = ~gCurrentSaveFile.crc1;
    gCurrentSaveFile.crc1 = fio_calc_file_checksum(&gCurrentSaveFile);
    gCurrentSaveFile.crc2 = ~gCurrentSaveFile.crc1;

    fio_erase_flash(NextAvailablePhysicalSave);
    fio_write_flash(NextAvailablePhysicalSave, (s8*)&gCurrentSaveFile, sizeof(SaveData));
}

void fio_erase_game(s32 saveSlot) {
    s32 i;

    fio_fetch_saved_file_info();

    for (i = 0; i < ARRAY_COUNT(PhysicalSaveInfo); i++) {
        if (PhysicalSaveInfo[i].slot == saveSlot) {
            fio_erase_flash(i);
        }
    }
}

void fio_deserialize_state(void) {
    SaveData* saveData = &gCurrentSaveFile;
    s32 i, j;

    gPlayerData = saveData->player;

    gGameStatusPtr->areaID = saveData->areaID;
    gGameStatusPtr->mapID = saveData->mapID;
    gGameStatusPtr->entryID = saveData->entryID;
    gGameStatusPtr->savedPos.x = saveData->savePos.x;
    gGameStatusPtr->savedPos.y = saveData->savePos.y;
    gGameStatusPtr->savedPos.z = saveData->savePos.z;

    for (i = 0; i < ARRAY_COUNT(gCurrentEncounter.defeatFlags[0]); i++) {
        for (j = 0; j < ARRAY_COUNT(gCurrentEncounter.defeatFlags); j++) {
            gCurrentEncounter.defeatFlags[j][i] = saveData->enemyDefeatFlags[j][i];
        }
    }

    gGameStatusPtr->debugEnemyContact = DEBUG_CONTACT_NONE;
    gGameStatusPtr->debugUnused1 = FALSE;
    gGameStatusPtr->debugUnused2 = FALSE;
    gGameStatusPtr->musicEnabled = TRUE;

    gSaveSlotMetadata[gGameStatusPtr->saveSlot] = saveData->metadata;
}

void func_8002B608(void) {
    gGameStatusPtr->entryID = 10;
    fio_serialize_state();
}

void fio_serialize_state(void) {
    SaveData* saveData = &gCurrentSaveFile;
    s32 i, j;

    saveData->player = gPlayerData;

    saveData->areaID = gGameStatusPtr->areaID;
    saveData->mapID = gGameStatusPtr->mapID;
    saveData->entryID = gGameStatusPtr->entryID;
    saveData->savePos.x = gGameStatusPtr->savedPos.x;
    saveData->savePos.y = gGameStatusPtr->savedPos.y;
    saveData->savePos.z = gGameStatusPtr->savedPos.z;

    for (i = 0; i < ARRAY_COUNT(gCurrentEncounter.defeatFlags[0]); i++) {
        for (j = 0; j < ARRAY_COUNT(gCurrentEncounter.defeatFlags); j++) {
            saveData->enemyDefeatFlags[j][i] = gCurrentEncounter.defeatFlags[j][i];
        }
    }

    saveData->debugEnemyContact = gGameStatusPtr->debugEnemyContact;
    saveData->debugUnused1 = gGameStatusPtr->debugUnused1;
    saveData->debugUnused2 = gGameStatusPtr->debugUnused2;
    saveData->musicEnabled = gGameStatusPtr->musicEnabled;

    gSaveSlotMetadata[gGameStatusPtr->saveSlot].level = gPlayerData.level;
    gSaveSlotMetadata[gGameStatusPtr->saveSlot].spiritsRescued = get_spirits_rescued();
    gSaveSlotMetadata[gGameStatusPtr->saveSlot].timePlayed = gPlayerData.frameCounter;

    saveData->metadata = gSaveSlotMetadata[gGameStatusPtr->saveSlot];
}

void fio_init_flash(void) {
    osFlashInit();
}

b32 fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes) {
    OSIoMesg mb;
    OSMesgQueue mesgQueue;
    OSMesg mesg;
    s8* buf = (s8*)readBuffer;
    s32 amt;
    u16 i;

    osInvalDCache(buf, numBytes);
    osCreateMesgQueue(&mesgQueue, &mesg, 1);

    i = 0;
    while (numBytes != 0) {
        if (numBytes > sizeof(SaveGlobals)) {
            amt = sizeof(SaveGlobals);
        } else {
            amt = numBytes;
        }

        osFlashReadArray(&mb, 0, pageNum * sizeof(SaveGlobals) + i, buf, 1, &mesgQueue);
        osRecvMesg(&mesgQueue, NULL, 1);
        i++;
        numBytes -= amt;
        buf += amt;
    }
    return TRUE;
}

b32 fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes) {
    OSIoMesg mb;
    OSMesgQueue mesgQueue;
    OSMesg mesg;
    s32 amt;
    u16 i;

    osWritebackDCache(readBuffer, numBytes);
    osCreateMesgQueue(&mesgQueue, &mesg, 1);

    i = 0;
    while (numBytes != 0) {
        if (numBytes > sizeof(SaveGlobals)) {
            amt = sizeof(SaveGlobals);
        } else {
            amt = numBytes;
        }

        osFlashWriteBuffer(&mb, 0, readBuffer, &mesgQueue);
        osFlashWriteArray((pageNum * sizeof(SaveGlobals)) + i);
        osRecvMesg(&mesgQueue, NULL, 1);
        i++;
        numBytes -= amt;
        readBuffer += amt;
    }
    return TRUE;
}

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * sizeof(SaveGlobals));
}

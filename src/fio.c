#include "fio.h"
#include "PR/os_flash.h"
#include "gcc/string.h"

typedef struct SaveInfo {
    /* 0x08 */ s32 slot;
    /* 0x04 */ s32 count;
} SaveInfo; // size = 0x8

#define GLOBALS_PAGE_1 6
#define GLOBALS_PAGE_2 7

BSS SaveData FetchSaveBuffer;
#if VERSION_PAL
BSS SaveData SaveCheckBuffer;
#endif
BSS SaveInfo LogicalSaveInfo[4];  // 4 save slots presented to the player
BSS SaveInfo PhysicalSaveInfo[6]; // 6 saves as represented on the EEPROM
BSS s32 NextAvailablePhysicalSave;

SaveGlobals gSaveGlobals;
SaveData gCurrentSaveFile;

char MagicSaveString[] = "Mario Story 006";

void fio_deserialize_state(void);
void fio_serialize_state(void);
bool fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes);
bool fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes);
s32 fio_erase_flash(s32 pageNum);

#if VERSION_PAL
bool save_check_integrity(void) {
    u32 i;
    s32 *it = (s32*)&gCurrentSaveFile;
    s32 *it2 = (s32*)&FetchSaveBuffer;

    for (i = 0; i < sizeof(gCurrentSaveFile) / sizeof(*it); i++, it++, it2++) {
        if (*it != *it2) {
            return true;
        }
    }

    return false;
}

bool check_fetch_save_integrity(void) {
    u32 i;
    s32 *it = (s32*)&FetchSaveBuffer;
    s32 *it2 = (s32*)&SaveCheckBuffer;

    for (i = 0; i < sizeof(FetchSaveBuffer) / sizeof(*it); i++, it++, it2++) {
        if (*it != *it2) {
            return true;
        }
    }

    return false;
}
#endif

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

bool fio_validate_globals_checksums(void) {
    SaveGlobals* header = &gSaveGlobals;

    if (strcmp(header->magicString, MagicSaveString)) {
        return false;
    }
    if (header->crc1 != ~header->crc2) {
        return false;
    }
    return fio_calc_globals_checksum() == header->crc1;
}

bool fio_load_globals(void) {
    fio_read_flash(GLOBALS_PAGE_1, &gSaveGlobals, sizeof(gSaveGlobals));
    if (fio_validate_globals_checksums()) {
        return true;
    }

    fio_read_flash(GLOBALS_PAGE_2, &gSaveGlobals, sizeof(gSaveGlobals));
    if (fio_validate_globals_checksums()) {
        return true;
    }

    bzero(&gSaveGlobals, sizeof(gSaveGlobals));
    return false;
}

bool fio_save_globals(void) {
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
    return true;
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

bool fio_validate_file_checksum(SaveData* saveData) {
    if (!strcmp(saveData->magicString, MagicSaveString) && saveData->crc1 == ~saveData->crc2) {
        return fio_calc_file_checksum(saveData) == saveData->crc1;
    }
    return false;
}

bool fio_fetch_saved_file_info(void) {
    SaveData* fetchBuf = &FetchSaveBuffer; // temps required to match
#if VERSION_PAL
    SaveData* checkBuf = &SaveCheckBuffer;
#endif
    SaveData* validBuf = fetchBuf;
    s32 i, j, minSaveCount;

    for (i = 0; i < ARRAY_COUNT(LogicalSaveInfo); i++) {
        LogicalSaveInfo[i].slot = -1;
        LogicalSaveInfo[i].count = -1;
    }

    for (i = 0; i < ARRAY_COUNT(PhysicalSaveInfo); i++) {
#if VERSION_PAL
        for (j = 0; j < 4; j++) {
            fio_read_flash(i, fetchBuf, sizeof(SaveData));
            fio_read_flash(i, checkBuf, sizeof(SaveData));
            if (!check_fetch_save_integrity()) {
                break;
            }
        }
        if (fio_validate_file_checksum(fetchBuf) && j != 4) {
            PhysicalSaveInfo[i].slot = validBuf->saveSlot;
            PhysicalSaveInfo[i].count = validBuf->saveCount;
            // logical saves only track the most recent physical save for each slot
            if (LogicalSaveInfo[validBuf->saveSlot].count < validBuf->saveCount) {
                LogicalSaveInfo[validBuf->saveSlot].slot = i;
                LogicalSaveInfo[validBuf->saveSlot].count = validBuf->saveCount;
            }
        } else {
            PhysicalSaveInfo[i].count = 0;
            PhysicalSaveInfo[i].slot = 99;
        }
#else
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
#endif
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
    return true;
}

bool fio_load_game(s32 saveSlot) {
#if VERSION_PAL
    int i;
    SaveData *saveData = &gCurrentSaveFile;
    SaveData *temp = saveData;
#endif

    gGameStatusPtr->saveSlot = saveSlot;

#if VERSION_PAL
    for (i = 0; i < 4; i++){
        fio_fetch_saved_file_info();
        if (LogicalSaveInfo[saveSlot].slot < 0) {
            continue;
        }
        fio_read_flash(LogicalSaveInfo[saveSlot].slot, saveData, sizeof(SaveData));
        if (fio_validate_file_checksum(saveData)) {
            break;
        }
    }

    if (i != 4) {
        if (gGameStatusPtr->saveCount < temp->saveCount) {
            gGameStatusPtr->saveCount = temp->saveCount;
        }
        fio_deserialize_state();
        return true;
    }
#else
    fio_fetch_saved_file_info();
    fio_read_flash(LogicalSaveInfo[saveSlot].slot, &gCurrentSaveFile, sizeof(SaveData));

    if (strcmp(gCurrentSaveFile.magicString, MagicSaveString) == 0) {
        if (gGameStatusPtr->saveCount < gCurrentSaveFile.saveCount) {
            gGameStatusPtr->saveCount = gCurrentSaveFile.saveCount;
        }
        fio_deserialize_state();
        return true;
    }
#endif
    return false;
}

void fio_save_game(s32 saveSlot) {
    SaveData* saveData = &gCurrentSaveFile;
#if VERSION_PAL
    int i;
#endif

    fio_fetch_saved_file_info();

    gGameStatusPtr->saveSlot = saveSlot;

    fio_serialize_state();

    strcpy(saveData->magicString, MagicSaveString);

    saveData->saveSlot = saveSlot;
    gGameStatusPtr->saveCount++;
    saveData->saveCount = gGameStatusPtr->saveCount;

    saveData->crc1 = 0;
    saveData->crc2 = ~saveData->crc1;
    saveData->crc1 = fio_calc_file_checksum(saveData);
    saveData->crc2 = ~saveData->crc1;

#if VERSION_PAL
    for (i = 0; i < 4; i++) {
        fio_erase_flash(NextAvailablePhysicalSave);
        fio_write_flash(NextAvailablePhysicalSave, (s8*)saveData, sizeof(SaveData));
        fio_read_flash(NextAvailablePhysicalSave, (s8*)&FetchSaveBuffer, sizeof(SaveData));

        if (!save_check_integrity()) {
            break;
        }
    }
#else
    fio_erase_flash(NextAvailablePhysicalSave);
    fio_write_flash(NextAvailablePhysicalSave, (s8*)saveData, sizeof(SaveData));
#endif
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

#if VERSION_PAL
bool func_PAL_8002B574(void) {
    int i, j;
    SaveData *saveData = &gCurrentSaveFile;
    SaveData *temp = saveData;

    fio_fetch_saved_file_info();

    for (i = 0; i < ARRAY_COUNT(LogicalSaveInfo); i++) {
        s32 new_var = false;  // TODO this match doesn't satisfy me :(
        if (LogicalSaveInfo[i].slot >= 0) {
            for (j = 0; j < 4; j++) {
                fio_read_flash(LogicalSaveInfo[i].slot, temp, sizeof(SaveData));
                if (fio_validate_file_checksum(temp)) {
                    break;
                }
            }
            if (j != 4) {
                goto SLOT_HAS_DATA;
            }
        }
        gSaveSlotHasData[i] = new_var;
        continue;

SLOT_HAS_DATA:
        do {
            gSaveSlotMetadata[i] = gCurrentSaveFile.metadata;
            gSaveSlotHasData[i] = true;
            if (gGameStatusPtr->saveCount < saveData->saveCount) {
                gGameStatusPtr->saveCount = saveData->saveCount;
            }
        } while(0);
    }

    return true;
}
#endif

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
    gGameStatusPtr->debugUnused1 = false;
    gGameStatusPtr->debugUnused2 = false;
    gGameStatusPtr->musicEnabled = true;

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

bool fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes) {
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
    return true;
}

bool fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes) {
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
    return true;
}

s32 fio_erase_flash(s32 pageNum) {
#if VERSION_PAL
    int i;
    s32 success;

    for (i = 0; i < 4; i++) {
        success = osFlashSectorErase(pageNum * sizeof(SaveGlobals));

        if (!success) {
            break;
        }
    }

    return success;
#else
    osFlashSectorErase(pageNum * sizeof(SaveGlobals));
#endif
}

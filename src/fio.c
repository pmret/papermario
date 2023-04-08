#include "fio.h"
#include "PR/os_flash.h"
#include "gcc/string.h"

extern SaveData D_8009A6B0;
extern s32 logicalSaveInfo[4][2];
extern s32 physicalSaveInfo[6][2];
extern s32 nextAvailableSavePage;

char magicSaveString[] = "Mario Story 006";

void fio_deserialize_state(void);
void fio_serialize_state(void);
s32 fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes);
s32 fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes);
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

s32 fio_calc_header_checksum(void) {
    u32 sum = 0;
    s32* it = (s32*)&D_800D95E8;
    u32 i;

    for (i = 0; i < sizeof(D_800D95E8) / sizeof(*it); i++, it++) {
        sum += *it;
    }
    return sum;
}

s32 fio_validate_header_checksums(void) {
    SaveDataHeader* header = &D_800D95E8;

    if (strcmp(header->magicString, magicSaveString)) {
        return FALSE;
    }
    if (header->crc1 != ~header->crc2) {
        return FALSE;
    }
    return fio_calc_header_checksum() == header->crc1;
}

s32 fio_has_valid_backup(void) {
    fio_read_flash(6, &D_800D95E8, sizeof(D_800D95E8));

    if (!fio_validate_header_checksums()) {
        fio_read_flash(7, &D_800D95E8, sizeof(D_800D95E8));

        if (!fio_validate_header_checksums()) {
            bzero(&D_800D95E8, sizeof(D_800D95E8));
            return FALSE;
        }
    }
    return TRUE;
}

s32 fio_flush_backups(void) {
    s32 checksum;

    strcpy(D_800D95E8.magicString, magicSaveString);
    D_800D95E8.crc1 = 0;
    D_800D95E8.crc2 = -1;
    checksum = fio_calc_header_checksum();
    D_800D95E8.crc1 = checksum;
    D_800D95E8.crc2 = ~checksum;
    fio_erase_flash(6);
    fio_write_flash(6, (s8*)&D_800D95E8, sizeof(D_800D95E8));
    fio_erase_flash(7);
    fio_write_flash(7, (s8*)&D_800D95E8, sizeof(D_800D95E8));
    return 1;
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

s32 fio_validate_file_checksum(SaveData* saveData) {
    if (!strcmp(saveData->magicString, magicSaveString) && saveData->crc1 == ~saveData->crc2) {
        return fio_calc_file_checksum(saveData) == saveData->crc1;
    }
    return FALSE;
}

s32 fio_fetch_saved_file_info(void) {
    SaveData* buffer = &D_8009A6B0; // temps required to match
    SaveData* buffer2 = buffer;
    s32 i, j, savePage;

    for (i = 0; i < ARRAY_COUNT(logicalSaveInfo); i++) {
        logicalSaveInfo[i][0] = -1;
        logicalSaveInfo[i][1] = -1;
    }

    for (i = 0; i < ARRAY_COUNT(physicalSaveInfo); i++) {
        fio_read_flash(i, buffer, sizeof(SaveData));
        if (fio_validate_file_checksum(buffer)) {
            physicalSaveInfo[i][0] = buffer2->saveSlot;
            physicalSaveInfo[i][1] = buffer2->saveCount;
            if (logicalSaveInfo[buffer2->saveSlot][1] < buffer2->saveCount) {
                logicalSaveInfo[buffer2->saveSlot][0] = i;
                logicalSaveInfo[buffer2->saveSlot][1] = buffer2->saveCount;
            }
        }
    }

    savePage = 0x7FFFFFFF;
    for (j = 0; j < ARRAY_COUNT(physicalSaveInfo); j++) {
        for (i = 0; i < ARRAY_COUNT(logicalSaveInfo); i++) {
            if (j == logicalSaveInfo[i][0]) {
                break;
            }
        }

        if (i == ARRAY_COUNT(logicalSaveInfo)) {
            if (physicalSaveInfo[j][1] < savePage) {
                savePage = physicalSaveInfo[j][1];
                nextAvailableSavePage = j;
            }
        }
    }
    return TRUE;
}

s32 fio_load_game(s32 saveSlot) {
    gGameStatusPtr->saveSlot = saveSlot;

    fio_fetch_saved_file_info();
    fio_read_flash(logicalSaveInfo[saveSlot][0], &gCurrentSaveFile, sizeof(SaveData));

    if (strcmp(gCurrentSaveFile.magicString, magicSaveString) == 0) {
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

    strcpy(gCurrentSaveFile.magicString, magicSaveString);

    gCurrentSaveFile.saveSlot = saveSlot;
    gGameStatusPtr->saveCount++;
    gCurrentSaveFile.saveCount = gGameStatusPtr->saveCount;

    gCurrentSaveFile.crc1 = 0;
    gCurrentSaveFile.crc2 = -1;
    gCurrentSaveFile.crc1 = fio_calc_file_checksum(&gCurrentSaveFile);
    gCurrentSaveFile.crc2 = ~gCurrentSaveFile.crc1;

    fio_erase_flash(nextAvailableSavePage);
    fio_write_flash(nextAvailableSavePage, (s8*)&gCurrentSaveFile, sizeof(SaveData));
}

void fio_erase_game(s32 saveSlot) {
    s32 i;

    fio_fetch_saved_file_info();

    for (i = 0; i < 6; i++) {
        if (physicalSaveInfo[i][0] == saveSlot) {
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
    gGameStatusPtr->unk_76 = 0;
    gGameStatusPtr->unk_77 = 0;
    gGameStatusPtr->musicEnabled = TRUE;

    gSaveSlotMetadata[gGameStatusPtr->saveSlot] = saveData->unk_12EC;
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
    saveData->unk_12E1 = gGameStatusPtr->unk_76;
    saveData->unk_12E2 = gGameStatusPtr->unk_77;
    saveData->musicEnabled = gGameStatusPtr->musicEnabled;

    gSaveSlotMetadata[gGameStatusPtr->saveSlot].level = gPlayerData.level;
    gSaveSlotMetadata[gGameStatusPtr->saveSlot].spiritsRescued = get_spirits_rescued();
    gSaveSlotMetadata[gGameStatusPtr->saveSlot].timePlayed = gPlayerData.frameCounter;

    saveData->unk_12EC = gSaveSlotMetadata[gGameStatusPtr->saveSlot];
}

void fio_init_flash(void) {
    osFlashInit();
}

s32 fio_read_flash(s32 pageNum, void* readBuffer, u32 numBytes) {
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
        if (numBytes > sizeof(SaveDataHeader)) {
            amt = sizeof(SaveDataHeader);
        } else {
            amt = numBytes;
        }

        osFlashReadArray(&mb, 0, pageNum * sizeof(SaveDataHeader) + i, buf, 1, &mesgQueue);
        osRecvMesg(&mesgQueue, NULL, 1);
        i++;
        numBytes -= amt;
        buf += amt;
    }
    return TRUE;
}

s32 fio_write_flash(s32 pageNum, s8* readBuffer, u32 numBytes) {
    OSIoMesg mb;
    OSMesgQueue mesgQueue;
    OSMesg mesg;
    s32 amt;
    u16 i;

    osWritebackDCache(readBuffer, numBytes);
    osCreateMesgQueue(&mesgQueue, &mesg, 1);

    i = 0;
    while (numBytes != 0) {
        if (numBytes > sizeof(SaveDataHeader)) {
            amt = sizeof(SaveDataHeader);
        } else {
            amt = numBytes;
        }

        osFlashWriteBuffer(&mb, 0, readBuffer, &mesgQueue);
        osFlashWriteArray((pageNum * sizeof(SaveDataHeader)) + i);
        osRecvMesg(&mesgQueue, NULL, 1);
        i++;
        numBytes -= amt;
        readBuffer += amt;
    }
    return TRUE;
}

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * sizeof(SaveDataHeader));
}

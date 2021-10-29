#include "fio.h"

char magicSaveString[] = "Mario Story 006";

void fio_serialize_state(void);
void fio_erase_flash(s32 pageNum);
void fio_write_flash(s32 pageNum, s32* readBuffer, s32 numBytes);

s32 get_spirits_rescued(void) {
    s32 storyProgress = evt_get_variable(NULL, EVT_STORY_PROGRESS);
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
    s32* it = D_800D95E8;
    u32 i;

    for (i = 0; i < 0x20; i++, it++) {
        sum += *it;
    }
    return sum;
}

#ifdef NON_MATCHING
s32 fio_validate_header_checksums(void) {
    SaveData* saveData = D_800D95E8;

    if (!strcmp(saveData->magicString, magicSaveString) && saveData->crc1 == ~saveData->crc2) {
        return fio_calc_header_checksum() == saveData->crc1;
    }
    return FALSE;
}
#else
INCLUDE_ASM(s32, "fio", fio_validate_header_checksums);
#endif

s32 fio_has_valid_backup(void) {
    fio_read_flash(6, &D_800D95E8, 0x80);

    if (fio_validate_header_checksums() == FALSE) {
        fio_read_flash(7, &D_800D95E8, 0x80);

        if (fio_validate_header_checksums() == FALSE) {
            bzero(&D_800D95E8, 0x80);
            return FALSE;
        }
    }
    return TRUE;
}

s32 fio_flush_backups(void) {
    s32 checksum;

    strcpy(D_800D95E8, &magicSaveString);
    D_800D95E8[12] = 0;
    D_800D95E8[13] = -1;
    checksum = fio_calc_header_checksum();
    D_800D95E8[12] = checksum;
    D_800D95E8[13] = ~checksum;
    fio_erase_flash(6);
    fio_write_flash(6, D_800D95E8, 128);
    fio_erase_flash(7);
    fio_write_flash(7, D_800D95E8, 128);
    return 1;
}

s32 fio_calc_file_checksum(SaveData* saveData) {
    u32 sum = 0;
    s32* it = saveData;
    u32 i;

    for (i = 0; i < 0x4E0; i++, it++) {
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
    s32* buffer = D_8009A6B0;
    void* bufferPtr = (void*)buffer;
    s32 i, j, savePage;

    for (i = 0; i < ARRAY_COUNT(logicalSaveInfo); i++) {
        logicalSaveInfo[i][0] = -1;
        logicalSaveInfo[i][1] = -1;
    }

    for (i = 0; i < ARRAY_COUNT(physicalSaveInfo); i++) {
        fio_read_flash(i, bufferPtr, sizeof(SaveData));
        if (fio_validate_file_checksum(bufferPtr) != 0) {
            physicalSaveInfo[i][0] = buffer[14];
            physicalSaveInfo[i][1] = buffer[15];
            if (logicalSaveInfo[buffer[14]][1] < buffer[15]) {
                logicalSaveInfo[buffer[14]][0] = i;
                logicalSaveInfo[buffer[14]][1] = buffer[15];
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

    return 1;
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
    fio_write_flash(nextAvailableSavePage, &gCurrentSaveFile, sizeof(SaveData));
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

INCLUDE_ASM(s32, "fio", fio_deserialize_state);

void func_8002B608(void) {
    gGameStatusPtr->entryID = 10;
    fio_serialize_state();
}

INCLUDE_ASM(void, "fio", fio_serialize_state);

void fio_init_flash(void) {
    osFlashInit();
}

INCLUDE_ASM(s32, "fio", fio_read_flash, s32 pageNum, s32* readBuffer, s32 numBytes);

INCLUDE_ASM(s32, "fio", fio_write_flash);

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * 128);
}

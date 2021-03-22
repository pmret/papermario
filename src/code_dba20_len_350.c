#include "common.h"

void clear_saved_variables(void) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(saveFile->globalFlags); i++) {
        saveFile->globalFlags[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(saveFile->globalBytes); i++) {
        saveFile->globalBytes[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(saveFile->areaFlags); i++) {
        saveFile->areaFlags[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(saveFile->areaBytes); i++) {
        saveFile->areaBytes[i] = 0;
    }
}

void clear_area_flags(void) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 i;

    if (gGameStatusPtr->changedArea) {
        for (i = 0; i < ARRAY_COUNT(saveFile->areaFlags); i++) {
            saveFile->areaFlags[i] = 0;
        }

        for (i = 0; i < ARRAY_COUNT(saveFile->areaBytes); i++) {
            saveFile->areaBytes[i] = 0;
        }
    }
}

s32 clear_global_flag(s32 index) {
    s32 wordIdx;
    s32 bitIdx;
    SaveData* saveFile;
    s32 flag;

    if (index <= -120000000) {
        index += 130000000;
    }

    wordIdx = index / 32;
    bitIdx = index % 32;

    saveFile = &gCurrentSaveFile;
    flag = saveFile->globalFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }

    saveFile->globalFlags[wordIdx] &= ~(1 << bitIdx);
    return flag;
}

s32 set_global_flag(s32 index) {
    s32 wordIdx;
    s32 bitIdx;
    SaveData* saveFile;
    s32 flag;

    if (index <= -120000000) {
        index += 130000000;
    }

    wordIdx = index / 32;
    bitIdx = index % 32;

    saveFile = &gCurrentSaveFile;
    flag = saveFile->globalFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }

    saveFile->globalFlags[wordIdx] |= (1 << bitIdx);
    return flag;
}

s32 get_global_flag(s32 index) {
    s32 wordIdx;
    s32 bitIdx;
    s32 flag;
    s32 phi_return;

    if (index <= -120000000) {
        index += 130000000;
    }

    wordIdx = index / 32;
    bitIdx = index % 32;
    flag = gCurrentSaveFile.globalFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }
    return flag;
}

s8 set_global_byte(s32 index, s8 value) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 ret = saveFile->globalBytes[index];

    saveFile->globalBytes[index] = value;
    return ret;
}

s32 get_global_byte(s32 index) {
    return gCurrentSaveFile.globalBytes[index];
}

s32 clear_area_flag(s32 index) {
    s32 wordIdx = index / 32;
    s32 bitIdx = index % 32;
    SaveData* saveFile = &gCurrentSaveFile;
    s32 flag = saveFile->areaFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }

    saveFile->areaFlags[wordIdx] &= ~(1 << bitIdx);
    return flag;
}

s32 set_area_flag(s32 index) {
    s32 wordIdx = index / 32;
    s32 bitIdx = index % 32;
    SaveData* saveFile = &gCurrentSaveFile;
    s32 flag = saveFile->areaFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }

    saveFile->areaFlags[wordIdx] |= 1 << bitIdx;
    return flag;
}

s32 get_area_flag(s32 index) {
    s32 wordIdx = index / 32;
    s32 bitIdx = index % 32;
    s32 flag = gCurrentSaveFile.areaFlags[wordIdx] & (1 << bitIdx);

    if (flag != 0) {
        flag = 1;
    }

    return flag;
}

s8 set_area_byte(s32 index, s8 value) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 ret = saveFile->areaBytes[index];

    saveFile->areaBytes[index] = value;
    return ret;
}

s32 get_area_byte(s32 index) {
    return gCurrentSaveFile.areaBytes[index];
}

#include "common.h"

#ifdef NON_MATCHING
void clear_saved_variables(void) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 i;

    for (i = ARRAY_COUNT(saveFile->globalFlags) - 1; i >= 0; i--) {
        saveFile->globalFlags[i] = 0;
    }

    for (i = ARRAY_COUNT(saveFile->globalBytes) - 1; i >= 0; i--) {
        saveFile->globalBytes[i] = 0;
    }

    for (i = ARRAY_COUNT(saveFile->areaFlags) - 1; i >= 0; i--) {
        saveFile->areaFlags[i] = 0;
    }

    for (i = ARRAY_COUNT(saveFile->areaBytes) - 1; i >= 0; i--) {
        saveFile->areaBytes[i] = 0;
    }
}
#else
INCLUDE_ASM("code_dba20_len_350", clear_saved_variables);
#endif

#ifdef NON_MATCHING
void clear_area_flags(void) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 i;

    if (GAME_STATUS->changedArea) {
        for (i = ARRAY_COUNT(saveFile->areaFlags) - 1; i >= 0; i--) {
            saveFile->areaFlags[i] = 0;
        }
   
        for (i = ARRAY_COUNT(saveFile->areaBytes) - 1; i >= 0; i--) {
            saveFile->areaBytes[i] = 0;
        }
    }
}
#else
INCLUDE_ASM("code_dba20_len_350", clear_area_flags);
#endif

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

    if (flag) {
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

    if (flag) {
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

s8 get_global_byte(s32 index) {
    return gCurrentSaveFile.globalBytes[index];
}

s32 clear_area_flag(s32 index) {
    s32 wordIdx = index / 32;
    s32 bitIdx = index % 32;
    SaveData *saveFile = &gCurrentSaveFile;
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
    SaveData *saveFile = &gCurrentSaveFile;
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

s8 get_area_byte(s32 index) {
    return gCurrentSaveFile.areaBytes[index];
}

#include "common.h"

INCLUDE_ASM("code_dba20_len_350", clear_saved_variables);

INCLUDE_ASM("code_dba20_len_350", clear_area_flags);

INCLUDE_ASM("code_dba20_len_350", clear_global_flag);


#ifdef NON_MATCHING
s32 set_global_flag(s32 index) {
    //SaveData* saveFile = &gCurrentSaveFile;
    s32 flag;

    if (index <= -120000000) {
        index += 130000000;
    }

    flag = gCurrentSaveFile->globalFlags[index / 32] & (1 << (index % 32));

    if (flag) {
        flag = 1;
    }

    gCurrentSaveFile->globalFlags[index / 32] |= (1 << (index % 32));
    return flag;
}
#else
INCLUDE_ASM("code_dba20_len_350", set_global_flag);
#endif

#ifdef NON_MATCHING
s32 get_global_flag(s32 index) {
    s32 bitIdx;
    s32 wordIdx;
    s32 bit;
    s32 phi_return;

    if (index <= -120000000) {
        index += 130000000;
    }
    wordIdx = index / 32;
    bitIdx = index % 32;
    bit = gCurrentSaveFile->globalFlags[wordIdx] & (1 << bitIdx);

    if (bit != 0) {
        bit = 1;
    }
    return bit;
    //return (bit != 0) ? 1 : bit; // ??? surely this is `bit != 0`
}
#else
s32 INCLUDE_ASM("code_dba20_len_350", get_global_flag, s32 index);
#endif

s8 set_global_byte(s32 index, s8 value) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 ret = saveFile->globalBytes[index];

    saveFile->globalBytes[index] = value;
    return ret;
}

s8 get_global_byte(s32 index) {
    return gCurrentSaveFile.globalBytes[index];
}

INCLUDE_ASM("code_dba20_len_350", clear_area_flag);

#ifdef NON_MATCHING
s32 set_area_flag(s32 index) {
    SaveData* saveFile = &gCurrentSaveFile;
    s32 flag;
    s32 flagIdx;
    s32 flagShift;

    flagIdx = index / 32;
    flagShift = index % 32;

    flag = saveFile->areaFlags[flagIdx] & (1 << flagShift);

    if (flag != 0) {
        flag = 1;
    }

    saveFile->areaFlags[flagIdx] |= (1 << flagShift);

    return flag;
}
#else
INCLUDE_ASM("code_dba20_len_350", set_area_flag);
#endif

s32 get_area_flag(s32 index) {
    s32 flag;
    s32 flagIdx;
    s32 flagShift;

    flagIdx = index / 32;
    flagShift = index % 32;

    flag = gCurrentSaveFile.areaFlags[flagIdx] & (1 << flagShift);

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

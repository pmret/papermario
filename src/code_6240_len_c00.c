#include "common.h"

void fio_serialize_state(void);

s32 get_spirits_rescued(void) {
    s32 storyProgress = get_variable(NULL, SI_SAVE_VAR(0));
    s32 ret = 7;

    if (storyProgress < get_variable(NULL, -0x4D)) {
        ret = 0;
    } else if (storyProgress < get_variable(NULL, -0x37)) {
        ret = 1;
    } else if (storyProgress < get_variable(NULL, -0xF)) {
        ret = 2;
    } else if (storyProgress < get_variable(NULL, 5)) {
        ret = 3;
    } else if (storyProgress < get_variable(NULL, 0x25)) {
        ret = 4;
    } else if (storyProgress < get_variable(NULL, 0x39)) {
        ret = 5;
    } else if (storyProgress < get_variable(NULL, 0x57)) {
        ret = 6;
    }

    return ret;
}

INCLUDE_ASM(s32, "code_6240_len_c00", fio_calc_header_checksum);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_validate_header_checksums);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_has_valid_backup);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_flush_backups);

#ifdef NON_MATCHING
s32 fio_calc_file_checksum(s32* saveData) {
    u32 sum = 0;
    u32 i = 0;

    for (i = 0; i < 0x4E0; i++) {
        sum += saveData[i];
    }
    return sum;
}
#else
INCLUDE_ASM(s32, "code_6240_len_c00", fio_calc_file_checksum);
#endif

INCLUDE_ASM(s32, "code_6240_len_c00", fio_validate_file_checksum);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_fetch_saved_file_info);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_load_game);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_save_game);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_erase_game);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_deserialize_state);

void func_8002B608(void) {
    gGameStatusPtr->entryID = 10;
    fio_serialize_state();
}

INCLUDE_ASM(void, "code_6240_len_c00", fio_serialize_state);

void fio_init_flash(void) {
    osFlashInit();
}

INCLUDE_ASM(s32, "code_6240_len_c00", fio_read_flash);

INCLUDE_ASM(s32, "code_6240_len_c00", fio_write_flash);

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * 128);
}

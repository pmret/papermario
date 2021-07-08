#include "common.h"

void fio_serialize_state(void);

s32 get_spirits_rescued(void) {
    s32 storyProgress = get_variable(NULL, STORY_PROGRESS);
    s32 ret = 7;

    if (storyProgress < get_variable(NULL, STORY_CH1_STAR_SPIRIT_RESCUED)) {
        ret = 0;
    } else if (storyProgress < get_variable(NULL, STORY_CH2_STAR_SPIRIT_RESCUED)) {
        ret = 1;
    } else if (storyProgress < get_variable(NULL, STORY_CH3_STAR_SPIRIT_RESCUED)) {
        ret = 2;
    } else if (storyProgress < get_variable(NULL, STORY_CH4_STAR_SPIRIT_RESCUED)) {
        ret = 3;
    } else if (storyProgress < get_variable(NULL, STORY_CH5_OPENED_ESCAPE_ROUTE)) {
        ret = 4;
    } else if (storyProgress < get_variable(NULL, STORY_CH6_STAR_SPIRIT_RESCUED)) {
        ret = 5;
    } else if (storyProgress < get_variable(NULL, STORY_CH7_STAR_SPIRIT_RESCUED)) {
        ret = 6;
    }

    return ret;
}

extern s32 D_800D95E8[];

INCLUDE_ASM(s32, "fio", fio_calc_header_checksum);

INCLUDE_ASM(s32, "fio", fio_validate_header_checksums);

INCLUDE_ASM(s32, "fio", fio_has_valid_backup);

INCLUDE_ASM(s32, "fio", fio_flush_backups);

#ifdef NON_MATCHING
s32 fio_calc_file_checksum(s32* saveData) {
    u32 sum;
    u32 i;

    sum = 0;
    i = 0;

    for (i = 0; i < 0x4E0; i++) {
        sum += saveData[i];
    }
    return sum;
}
#else
INCLUDE_ASM(s32, "fio", fio_calc_file_checksum);
#endif

INCLUDE_ASM(s32, "fio", fio_validate_file_checksum);

INCLUDE_ASM(s32, "fio", fio_fetch_saved_file_info);

INCLUDE_ASM(s32, "fio", fio_load_game);

INCLUDE_ASM(s32, "fio", fio_save_game);

INCLUDE_ASM(s32, "fio", fio_erase_game);

INCLUDE_ASM(s32, "fio", fio_deserialize_state);

void func_8002B608(void) {
    gGameStatusPtr->entryID = 10;
    fio_serialize_state();
}

INCLUDE_ASM(void, "fio", fio_serialize_state);

void fio_init_flash(void) {
    osFlashInit();
}

INCLUDE_ASM(s32, "fio", fio_read_flash);

INCLUDE_ASM(s32, "fio", fio_write_flash);

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * 128);
}

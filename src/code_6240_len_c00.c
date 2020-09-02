#include "common.h"

INCLUDE_ASM("code_6240_len_c00", get_spirits_rescued);

INCLUDE_ASM("code_6240_len_c00", fio_calc_header_checksum);

INCLUDE_ASM("code_6240_len_c00", fio_validate_header_checksums);

INCLUDE_ASM("code_6240_len_c00", fio_has_valid_backup);

INCLUDE_ASM("code_6240_len_c00", fio_flush_backups);

INCLUDE_ASM("code_6240_len_c00", fio_calc_file_checksum);

INCLUDE_ASM("code_6240_len_c00", fio_validate_file_checksum);

INCLUDE_ASM("code_6240_len_c00", fio_fetch_saved_file_info);

INCLUDE_ASM("code_6240_len_c00", fio_load_game);

INCLUDE_ASM("code_6240_len_c00", fio_save_game);

INCLUDE_ASM("code_6240_len_c00", fio_erase_game);

INCLUDE_ASM("code_6240_len_c00", fio_deserialize_state);

INCLUDE_ASM("code_6240_len_c00", fio_serialize_state);

void fio_init_flash(void) {
    osFlashInit();
}

INCLUDE_ASM("code_6240_len_c00", fio_read_flash);

INCLUDE_ASM("code_6240_len_c00", fio_write_flash);

void fio_erase_flash(s32 pageNum) {
    osFlashSectorErase(pageNum * 128);
}

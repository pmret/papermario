#ifndef _FIO_H_
#define _FIO_H_

#include "common.h"

extern char magicSaveString[];
extern s32 logicalSaveInfo[4][2];
extern s32 physicalSaveInfo[6][2];
extern s32 nextAvailableSavePage;
extern s32 D_800D95E8[];
extern s32 D_8009A6B0[];

void fio_serialize_state(void);
void fio_erase_flash(s32 pageNum);
void fio_write_flash(s32 pageNum, s32* readBuffer, s32 numBytes);

s32 get_spirits_rescued(void);
s32 fio_calc_header_checksum(void);
s32 fio_validate_header_checksums(void);
s32 fio_has_valid_backup(void);
s32 fio_flush_backups(void);
s32 fio_calc_file_checksum(SaveData* saveData);
s32 fio_validate_file_checksum(SaveData* saveData);
s32 fio_fetch_saved_file_info(void);
s32 fio_load_game(s32 saveSlot);
void fio_save_game(s32 saveSlot);
void fio_erase_game(s32 saveSlot);
void func_8002B608(void);
//fio_deserialize_state;
//fio_init_flash;
//fio_serialize_state;
//fio_read_flash;
//fio_write_flash;

#endif

#ifndef _FIO_H_
#define _FIO_H_

#include "common.h"

s32 fio_has_valid_backup(void);
s32 fio_flush_backups(void);
s32 fio_load_game(s32 saveSlot);
void fio_save_game(s32 saveSlot);
void fio_erase_game(s32 saveSlot);

extern SaveMetadata gSaveSlotMetadata[4];
extern u8 gSaveSlotHasData[4];
extern SaveDataHeader D_800D95E8;

#endif

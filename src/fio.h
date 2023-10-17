#ifndef _FIO_H_
#define _FIO_H_

#include "common.h"

b32 fio_load_globals(void);
b32 fio_save_globals(void);
b32 fio_load_game(s32 saveSlot);
void fio_save_game(s32 saveSlot);
void fio_erase_game(s32 saveSlot);

extern SaveMetadata gSaveSlotMetadata[4];
extern u8 gSaveSlotHasData[4];
extern SaveGlobals gSaveGlobals;

#endif

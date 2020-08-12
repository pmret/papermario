#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "types.h"

extern ui_status gUIStatus;
extern player_data gPlayerData;
extern player_status gPlayerStatus;
extern game_status* gGameStatusPtr[1];
extern item_table_entry gItemTable[364];
extern s16* D_80151328;
extern s16 D_8010CD10;
extern s16 D_8010CD12;

extern u16 gMapTransitionAlpha;
extern u16 D_800A0942;
extern s16 D_800A0944;

extern s16 D_80151308;

extern s16 D_8010F304[]; // Key Items
extern s16 D_8010F444[]; // Items

extern s16 gCurrentDoorSoundsSet;



extern UNK_TYPE D_800E92D8;
extern UNK_TYPE D_80147474;
extern UNK_TYPE D_80147574;
extern UNK_TYPE D_80109270;
extern UNK_TYPE D_80108558;
extern u16 D_800A0940;
extern u16 D_800A0942;
extern s16 D_800A0944;

#endif

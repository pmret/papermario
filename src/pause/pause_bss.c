#include "types.h"

#ifndef M2CTX
#define BSS __attribute__ ((section (".bss")))
#else
#define BSS static
#endif

BSS s32 gPauseHeldButtons;
BSS s32 gPausePressedButtons;
BSS s32 gPauseCurrentDescMsg;
BSS s32 gPauseCurrentDescIconScript;
BSS s32 gPauseCursorIconID;
BSS s8 gPauseMenuCurrentTab;
BSS char D_802700D[7];
BSS s32 gPauseTutorialFrameCounter;
BSS s32 D_802700E4;
BSS s32 D_802700E8;
BSS s32 D_802700EC;
BSS s32 D_802700F0[4];
BSS s32 D_80270100;
BSS s32 D_80270104;
BSS s32 gPauseShownDescMsg;
BSS s32 gPauseDescTextMaxPos;
BSS s32 gPauseDescTextPos;
BSS s32 gPauseDescTextOffset;
BSS s32 gPauseShownDescIconScript;
BSS s32 gPauseTutorialSprites[3];
BSS s32 D_80270128[2];
BSS s32 D_80270130[4];
BSS s32 D_80270140;
BSS s32 D_80270144;
BSS s32 D_80270148;
BSS s32 D_8027014C;
BSS s32 D_80270150[4];
BSS s32 D_80270160[4];
BSS s32 D_80270170[4];
BSS s32 D_80270180[4];
BSS s32 D_80270190[4];
BSS s32 D_802701A0[4];
BSS s32 D_802701B0[4];
BSS s32 D_802701C0[4];
BSS s32 D_802701D0[4];
BSS s32 D_802701E0[4];
BSS s32 D_802701F0[4];
BSS s32 D_80270200[64];
BSS s32 D_80270300[64];
BSS s32 D_80270400[64];
BSS s32 D_80270500[58];
BSS s32 gItemIcons[20];
BSS s32 D_80270638[50];
BSS s32 D_80270700[1];
BSS s32 D_80270704[11];
BSS s8  D_80270730[512];
BSS s8  D_80270930[15752];
BSS s8  D_802746B8[512];
BSS s8  D_802748B8[15752];

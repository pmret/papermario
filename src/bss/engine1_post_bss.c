#define NO_EXTERN_VARIABLES
#include "common.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

BSS PartnerStatus gPartnerStatus;
BSS s32 gSpinHistoryPosY[6];
BSS s32 gSpinHistoryPosX[6];
BSS s32 gSpinHistoryPosZ[6];
BSS StatusBar gStatusBar;
BSS PlayerStatus gPlayerStatus;
BSS PlayerSpinState gPlayerSpinState;
BSS s32 D_8010F284[3];
BSS PlayerData gPlayerData;
BSS s16 gSpinHistoryPosAngle[5];

#endif

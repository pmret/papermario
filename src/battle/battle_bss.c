#define NO_EXTERN_VARIABLES
#include "common.h"
#include "battle/battle.h"

//
// battle.c bss symbols
//

BSS s32 D_800DC060;
BSS StageListRow* gCurrentStagePtr;
BSS s32 gBattleState;
BSS s32 D_800DC06C;
BSS BattleStatus gBattleStatus;
BSS s32 gLastDrawBattleState;
BSS s32 D_800DC4D4;
BSS s32 gDefeatedBattleSubstate;
BSS s32 gBattleSubState;
BSS s32 D_800DC4E0;
BSS s32 gDefeatedBattleState;
BSS s32 gCurrentBattleID;
BSS s32 gCurrentStageID;
BSS s32 D_800DC4F0;
BSS Battle* gOverrideBattlePtr;
BSS s32 D_800DC4F8;
BSS Battle* gCurrentBattlePtr;

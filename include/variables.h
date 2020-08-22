#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "types.h"

extern UiStatus gUIStatus;
extern PlayerData gPlayerData;
extern ActionState gPlayerActionState;
extern PlayerAnim gPlayerAnimation;
extern PlayerStatus gPlayerStatus;
extern GameStatus* gGameStatusPtr[1];
extern StaticItem gItemTable[364];
extern s16 gMainGameState; /* 0 = battle, 1 = pause, 2 = world */
extern UNK_FUN_PTR(gCurrentUpdateFunction);

extern ScriptInstance* gWorldScriptList[128];
extern ScriptInstance* gBattleScriptList[128];
extern ScriptInstance** gCurrentScriptListPtr[128];

extern s32 gScriptIdList[128];
extern s32 gScriptIndexList[128];

extern Model* gWorldModelList[256];
extern Model* gBattleModelList[256];
extern Model** gCurrentModelListPtr[256];

extern u32* gWorldModelSpecialDls[32];
extern u32* gBattleModelSpecialDls[32];
extern u32** gCurrentModelSpecialDlsPtr[32];

extern Entity* gWorldEntityList[30];
extern Entity* gBattleEntityList[30];
extern Entity** gCurrentEntityListPtr[30];

extern UNK_TYPE* gWorldDynamicEntityList[16];
extern UNK_TYPE* gBattleDynamicEntityList[16];
extern UNK_TYPE** gCurrentDynamicEntityListPtr[16];

extern Shadow* gWorldShadowList[60];
extern Shadow* gBattleShadowList[60];
extern Shadow** gCurrentShadowListPtr[60];

extern Camera gCameras[4];

extern f32 gGlobalTimeSpace;

extern Npc* gPlayerNpc;

extern s8 D_800A0900;
extern s16* D_80151328;
extern s16 D_8010CD10;
extern s16 D_8010CD12;
extern s32 D_801595A0;
extern char gCloudyFlowerFieldsBg[]; // "fla_bg"
extern char gSunnyFlowerFieldsBg[];  // "flb_bg"
extern BackgroundHeader gBackgroundImage;
extern s8 D_8014F12F;

extern PrintContext* gCurrentPrintContext;
extern PrintContext* D_802DB268;

// Triggers
extern s16 gTriggerCount;
extern Trigger* gTriggerList1[64];
extern Trigger* gTriggerList2[64];
extern Trigger** gCurrentTriggerListPtr[64];

extern u16 gMapTransitionAlpha;
extern u16 D_800A0942;
extern s16 D_800A0944;

extern s16 D_80151308;

extern s32 D_8009A650[1];

extern s16 gCurrentDoorSoundsSet;

extern UNK_TYPE D_800E92D8;
extern UNK_TYPE D_80147474;
extern UNK_TYPE D_80147574;
extern UNK_TYPE D_80109270;
extern UNK_TYPE D_80108558;

#endif

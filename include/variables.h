#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "types.h"
#include "macros.h"
#include "enums.h"

extern UiStatus gUIStatus;
extern PlayerData gPlayerData;
extern ActionState gPlayerActionState;
extern PlayerAnim gPlayerAnimation;
extern PlayerStatus gPlayerStatus;
extern PlayerStatus* gPlayerStatusPtr;
extern CollisionStatus gCollisionStatus;
extern GameStatus* gGameStatusPtr[1];
extern s32 gRandSeed;
extern StaticItem gItemTable[364];
extern s16 gMainGameState; /* 0 = battle, 1 = pause, 2 = world */
extern UNK_FUN_PTR(gCurrentUpdateFunction);

extern BattleStatus gBattleStatus;

extern ScriptList gWorldScriptList;
extern ScriptList gBattleScriptList;
extern ScriptList* gCurrentScriptListPtr;

extern s32 gNumScripts;
extern s32 D_802DAC98;

extern s32 gScriptListCount;

extern s32 gScriptIdList[MAX_SCRIPTS];
extern s32 gScriptIndexList[MAX_SCRIPTS];

extern Model* gWorldModelList[256];
extern Model* gBattleModelList[256];
extern Model** gCurrentModelListPtr[256];

extern u32* gWorldModelSpecialDls[32];
extern u32* gBattleModelSpecialDls[32];
extern u32** gCurrentModelSpecialDlsPtr[32];

extern Entity* gWorldEntityList[30];
extern Entity* gBattleEntityList[30];
extern Entity** gCurrentEntityListPtr[30];
extern s32 gLastCreatedEntityIndex;

extern UNK_TYPE* gWorldDynamicEntityList[16];
extern UNK_TYPE* gBattleDynamicEntityList[16];
extern UNK_TYPE*** gCurrentDynamicEntityListPtr;

extern Npc* gWorldNpcList[64];
extern Npc* gBattleNpcList[64];
extern Npc** gCurrentNpcListPtr[64];

extern Shadow* gWorldShadowList[60];
extern Shadow* gBattleShadowList[60];
extern Shadow** gCurrentShadowListPtr[60];

extern Camera gCameras[4];
extern s32 gCurrentCameraID;

extern Npc* gPlayerNpcPtr;

extern s8 D_800A0900;
extern EncounterStatus gCurrentEncounter;
extern s16 D_80151308;
extern s32 D_80151310;
extern s16* D_80151328;
extern s16 D_8010CD10;
extern s16 D_8010CD12;
extern s32 D_8010CD20;
extern s32 D_8010EF08;
extern s32 D_8010F094; // player shadow index?
extern s32 D_801595A0;
extern s16 D_80159AE2;
extern s16 D_80159AE4;
extern BackgroundHeader gBackgroundImage;

extern PrintContext* gCurrentPrintContext;
extern s32 D_802DB264;
extern PrintContext* D_802DB268;

// Triggers
extern s16 gTriggerCount;
extern Trigger* gTriggerList1[64];
extern Trigger* gTriggerList2[64];
extern Trigger** gCurrentTriggerListPtr[64];

// Map transition data. Should probably be a struct
extern u16 gMapTransitionAlpha;
extern s16 D_800A0942;
extern s16 D_800A0944;
extern s16 D_800A0954;
extern s16 D_800A0956;
extern s16 D_800A0958;
extern s16 D_800A095A;
extern u8 D_800A095B;
extern s16 D_800A095C;
extern u8 D_800A095D;
extern s16 D_800A095E;
extern u8 D_800A095F;
extern s32 D_800A0960;
extern s32 D_800A0964;

// Pause
//extern s32 gPauseMenuStrings[348];

extern s32 gGameState;
extern s32 D_8009A650[1];
extern u16 D_8009A6A0;
extern u16 D_8009A6A2;
extern u16 D_8009A6A4;
extern u16 D_8009A6A6;

extern s16 gCurrentDoorSoundsSet;

extern s32 D_800D9620;
extern UNK_TYPE D_800E92D8;
extern UNK_TYPE D_80147474;
extern UNK_TYPE D_80147574;
extern UNK_TYPE D_80109270;
extern UNK_TYPE D_80108558;
extern UNK_TYPE D_8010F250; // play_sound state struct?
extern s8 D_8010EBB0[];

// Effects
extern EffectTableEntry gEffectTable[135];

//nusys
extern OSPiHandle* carthandle;

extern SaveData gCurrentSaveFile;

extern s32 D_802D9CA4;
extern u32* gMapFlags;
extern u32* gMapVars;

extern f32 D_80286540;

extern u32 gWorldMapVars[MAX_MAPVARS];
extern u32 gBattleMapVars[MAX_MAPVARS];

extern u32 gWorldMapFlags[MAX_MAPFLAGS];
extern u32 gBattleMapFlags[MAX_MAPFLAGS];

extern s32 D_8009A5D8;

extern u8 D_800779B0;
extern u8 D_800A0963;

extern s32 mapScriptLibStart;
extern s32 mapScriptLibEnd;
extern s32 mapScriptLibVram;

// Scripts
extern Bytecode* SCRIPT_NpcDefeat;

#endif

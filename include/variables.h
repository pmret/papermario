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
extern GameStatus gGameStatus;
extern GameStatus* gGameStatusPtr;
extern s32 gRandSeed;
extern StaticItem gItemTable[364];
extern UNK_FUN_PTR(gCurrentUpdateFunction);

extern s32 gBattleState;
extern BattleStatus gBattleStatus;
extern s32 gBattleDmaDest;

extern ScriptList gWorldScriptList;
extern ScriptList gBattleScriptList;
extern ScriptList* gCurrentScriptListPtr;

extern s32 gNumScripts;
extern s32 D_802DAC98;

extern s32 gScriptListCount;

extern s32 gScriptIdList[MAX_SCRIPTS];
extern s32 gScriptIndexList[MAX_SCRIPTS];

extern s32 gMoveScriptTable[][4];

extern ModelList gWorldModelList;
extern ModelList gBattleModelList;
extern ModelList* gCurrentModelListPtr;

// TODO: potentially a display list, figure this out
extern u32* gWorldModelSpecialDls[32];
extern u32* gBattleModelSpecialDls[32];
extern u32** gCurrentModelSpecialDlsPtr[32];

extern EntityList gWorldEntityList;
extern EntityList gBattleEntityList;
extern EntityList* gCurrentEntityListPtr;
extern s32 gLastCreatedEntityIndex;

extern DynamicEntityList gWorldDynamicEntityList;
extern DynamicEntityList gBattleDynamicEntityList;
extern DynamicEntityList* gCurrentDynamicEntityListPtr;

extern NpcList gWorldNpcList;
extern NpcList gBattleNpcList;
extern NpcList* gCurrentNpcListPtr;

extern ShadowList gWorldShadowList;
extern ShadowList gBattleShadowList;
extern ShadowList* gCurrentShadowListPtr;

extern Camera gCameras[4];
extern s32 gCurrentCameraID;

extern CollisionData gCollisionData;

extern s8 D_800A0900;
extern f32 D_800F7B60[];
extern s16 D_800F7B80;
extern EncounterStatus gCurrentEncounter;
extern s8* D_801512F0;
extern s16 D_80151308;
extern s32 D_80151310;
extern s16* D_80151328;

extern s32 D_8010C92C;
extern s16 D_8010CD00;
extern s16 D_8010CD10;
extern s16 D_8010CD12;
extern s32 D_8010CD20;
extern s32 D_801595A0;
extern BackgroundHeader gBackgroundImage;

extern PrintContext* gCurrentPrintContext;
extern s32 D_802DB264;
extern PrintContext* D_802DB268;

extern s32 D_802EB390;
extern s32 D_802EB394;
extern PrintContext* D_802EB398;
extern PrintContext* D_802EB39C;
extern s32 D_802E99DC;

extern Entity* D_802EB3A0;
extern s32 D_8015C7D0[3]; // not size 3

extern f32 D_800F7B70[4];

extern UNK_TYPE D_0A0031E0;
extern UNK_TYPE D_0A001508;
extern UNK_TYPE D_0A0031B0;
extern UNK_TYPE D_0A0014D8;
extern UNK_TYPE D_0A002F78;
extern UNK_TYPE D_0A001218;
extern UNK_TYPE D_0A003F70;
extern UNK_TYPE D_0A002318;

// Animation related
extern AnimatedMeshList* gCurrentAnimMeshListPtr;

extern PartnerAnimations gPartnerAnimations[12];

extern AnimatedModelList gBattleMeshAnimationList;
extern AnimatedModelList gWorldMeshAnimationList;
extern AnimatedModelList* gCurrentMeshAnimationListPtr;

// Triggers
extern s16 gTriggerCount;
extern TriggerList gTriggerList1;
extern TriggerList gTriggerList2;
extern TriggerList* gCurrentTriggerListPtr;

// Map transition data. Should probably be a struct
extern u16 gMapTransitionAlpha;
extern s8 D_800A0930;
extern s8 D_800A0931;
extern s16 D_800A0932[1];
extern s16 D_800A0942;
extern s16 D_800A0944;
extern s16 D_800A0946;
extern s16 D_800A0948;
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
extern s8 D_800A0B94;
extern s16 D_800A0BB8;


extern UIPanel gUIPanels[64];

extern s32 D_802A3838;

// Pause
extern s32 gPauseMenuHeldButtons;
extern s32 gPauseMenuPressedButtons;
extern s32 gPauseMenuCurrentDescString;
extern s32* gPauseMenuCurrentDescIconScript;
extern s8 gPauseMenuCurrentTab;
extern s32 gPauseMenuCommonIconIDs[8];
extern s32 gPauseMenuTabIconIDs[6];
extern s32 gPauseMenuStrings[348];
extern s32 gPauseMenuIconScripts[8];
extern MenuTab* gPauseMenuTabs[7];
extern s32 gPauseMenuCursorPosX;
extern s32 gPauseMenuCursorPosY;
extern s32 gPauseMenuCursorOpacity;
extern s32 gPauseMenuTargetPosX;
extern s32 gPauseMenuTargetPosY;
extern s32 gPauseMenuCursorTargetOpacity;
extern u8 gPauseMenuTextScrollInterpEasingLUT[16];
extern u8 gPauseMenuPageScrollInterpEasingLUT[16];

// Badges
extern s32 gBadgeMenuCurrentScrollPos;
extern s32 gBadgeMenuTargetScrollPos;
extern ItemID gBadgeMenuItemIDs[128];
extern s32 gBadgeMenuCurrentPage;
extern PauseItemPage gBadgeMenuPages[20];
extern s32 gBadgeMenuSelectedIndex;
extern s32 gBadgeMenuSelectedItemID;
extern s16 gBadgeMenuNumItems;
extern s32 D_80270388;
extern s32 D_80270394;
extern s32 gBadgeMenuLevel;
extern s32 gBadgeMenuCurrentTab;
extern s32 gBadgeMenuBShowNotEnoughBP;
extern s32 D_802703A4;
extern s32 D_802703A8;

// Items
extern s16 gItemMenuItemIDs[100];
extern s32 gItemMenuCurrentPage;
extern PauseItemPage gItemMenuPages[20];
extern s32 gItemMenuSelectedIndex;
extern s32 gItemMenuSelectedItemID;
extern s16 gItemMenuNumItems;
extern s32 D_802705D0;
extern s32 gItemMenuCurrentScrollPos;
extern s32 gItemMenuTargetScrollPos;
extern u32 D_802705DC;
extern s32 gItemMenuLevel;
extern s32 gItemMenuCurrentTab;
extern MenuIcon* gItemIcons[20];
extern s32 gItemMenuScrollUpIcon;

// Stats
extern s32 gStatsMenuIconIDs[12];


extern s32 gGameState;
extern s16 D_8009A604;
extern s32 D_8009A64C;
extern s32* D_8009A658;
extern s32 gOverrideFlags;
extern u16 D_8009A6A0;
extern u16 D_8009A6A2;
extern u16 D_8009A6A4;
extern u16 D_8009A6A6;

extern s32* D_800A0914;
extern s32* D_800A0918;
extern s32* D_800A091C;
extern s8 D_800A0920;
extern s32 D_800A0924;
extern s8 D_800A0921;
extern s16 D_800A0922;
extern s32 D_800B0CF0;
extern s32 D_800D91E0;
extern s32 D_800D9230;
extern s32* D_80210000;
extern u8 D_802D9D70; // player alpha1 copy?
extern u8 D_802D9D71; // player alpha2 copy?

extern DisplayContext D_80164000[];

extern f32 gCurtainScale;
extern f32 gCurtainScaleGoal;
extern f32 gCurtainFade;
extern f32 gCurtainFadeGoal;
extern UNK_FUN_PTR(gCurtainDrawCallback);

extern s16 gCurrentDoorSoundsSet;

extern s32 D_800D9620;
extern UNK_TYPE D_800E92D8;
extern UNK_TYPE D_80147574;
extern UNK_TYPE D_80109270;
extern UNK_TYPE D_80108558;
extern s32 D_80108248;
extern s32 D_80108518;
extern s32 D_80108270;
extern s32 D_80108538;
extern s32 D_80080FC4;
extern s32 D_801086AC;
extern s32 D_801083D8;
extern s32 D_80108068;
extern s32 D_80104BEC;
extern Temp8010EBB0 D_8010EBB0; // something with partners
extern Temp8010F250 D_8010F250; // sfx_play_sound state struct?

// Effects
extern EffectTableEntry gEffectTable[135];

//nusys
extern OSPiHandle* carthandle;

extern SaveData gCurrentSaveFile;

extern u32* gMapFlags;
extern u32* gMapVars;

extern f32 D_80286540;

extern u32 gWorldMapVars[MAX_MAPVARS];
extern u32 gBattleMapVars[MAX_MAPVARS];

extern u32 gWorldMapFlags[MAX_MAPFLAGS];
extern u32 gBattleMapFlags[MAX_MAPFLAGS];

extern s32 D_8009A5D0;
extern s32 timeFreezeMode;
extern s32 D_8009A678;

extern u8 D_800779B0;
extern u32 D_80078174;
extern s32 timeFreezeMode;
extern u8 D_800A0963;

extern s32 D_8009A5D0;
extern s32 D_8009A678;

extern UNK_TYPE D_802EB3B0;
extern UNK_TYPE D_00000094;
extern UNK_TYPE D_00000094_2; // two symbols resolve to the same addr. Required for matching
extern UNK_TYPE D_802EA0A0;
extern StaticEntityData D_802EA07C;
extern UNK_TYPE D_802EA310;
extern UNK_TYPE D_802EA618;
extern UNK_TYPE D_802EA63C;
extern UNK_TYPE D_802EA660;
extern s16 D_8015C7D2;

extern UNK_TYPE D_0A000328;
extern UNK_TYPE D_0A000380;
extern UNK_TYPE D_0A000750;
extern UNK_TYPE D_0A000800;
extern UNK_TYPE D_0A000808;

// Scripts
extern Script* SCRIPT_NpcDefeat;
extern Script ShakeCam1;
extern Script ShakeCamX;

extern s16 gMusicUnkVolume;
extern s16 gMusicUnkVolume2;
extern s16 gMusicCurrentVolume;
extern s16 gMusicTargetVolume;
extern MusicSettings gMusicSettings[4];
extern MusicSettings D_8014F6F0;

// OS
extern OSThread D_800A4270; // idle thread, id 1
extern OSThread D_800A4420; // id 3
extern s32 D_800B8590;
extern OSThread* __osActiveQueue;
extern OSThread* __osRunningThread;
extern OSThread* __osRunQueue;
extern OSDevMgr __osPiDevMgr;

// gfx
extern DisplayContext* gDisplayContext;
extern Gfx* gMasterGfxPos;
extern u16 gMatrixListPos;
extern s32 gCurrentDisplayContextIndex;

extern UNK_TYPE D_0A004350;
extern UNK_TYPE D_0A0026F0;
extern UNK_TYPE D_802EAE7C;

extern s32 D_80291FA8[];
extern s32 D_80291FD0[];
extern s32 D_80291FF8[];
extern s32 D_80291FF8[];
extern s32 D_80292020[];
extern s32 D_80292048[];
extern s32 D_80292070[];
extern s32 D_80292098[];
extern s32 D_80292098[];
extern s32 D_802920C0[];
extern s32 D_802920E8[];
extern s32 D_802920E8[];
extern s32 D_80292110[];

extern UNK_PTR D_800F7BE8;
extern UNK_PTR D_800F7BBC;

extern s32 D_802C05CC;

extern s16 gCurrentCamID;

// Heap?
extern s32 D_803DA800;

// Dead code
extern PlayerStatus* D_800FFC90; // gPlayerStatusPtr

#endif

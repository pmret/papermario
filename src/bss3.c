#include "types.h"

// This file exists to enforce the order of BSS symbols, since they were reordered in the original rom.

#ifndef M2CTX
#define BSS __attribute__ ((section (".bss")))
#else
#define BSS static
#endif

BSS s32 D_801512B0;
BSS s32 gHudElementsNumber;
BSS s32 gCurrentCustomModelGfxBuildersPtr;
BSS s32 D_801512BC;
BSS s32 D_801512C0;
BSS s32 gEntityHeapBase;
BSS s32 gHudElementCacheTableRaster;
BSS s32 gCurrentModels;
BSS s32 gHudElementCacheTablePalette;
BSS s32 gAnimCount;
BSS s16 gMsgBGScrollAmtX;
BSS s16 D_801512DA;
BSS s32 D_801512DC;
BSS s32 gCurrentTransformGroups;
BSS s32 gMsgGlobalWaveCounter;
BSS s32 gCurrentCustomModelGfxPtr;
BSS s32 gLastCreatedEntityIndex;
BSS s32 D_801512F0;
BSS s32 gMsgVarImages;
BSS s32 ItemEntitiesCreated;
BSS s32 gCurrentModelTreeRoot;
BSS s32 D_80151300;
BSS s32 D_80151304;
BSS u32 D_80151308;
BSS s16 gMsgBGScrollAmtY;
BSS s16 D_8015130E;
BSS s32 gEntityHideMode;
BSS s32 gHudElementCacheBuffer;
BSS s32 gEntityModelCount;
BSS s32 D_8015131C;
BSS char D_80151320[0x4];
BSS s32 D_80151324;
BSS s32 D_80151328;
BSS s32 D_8015132C;
BSS s32 D_80151330;
BSS s32 gTriggerCount;
BSS s32 D_80151338;
BSS s32 gHudElementCacheSize;
BSS u32 gCurrentDoorSoundsSet;
BSS s32 D_80151344;
BSS char D_80151348[0x38];
BSS s8 gWorldEntityList[0x78];
BSS s8 gBattleEntityList[0x78];
BSS s32 gCurrentEntityListPtr;
BSS char D_80151474[0x4];
BSS s8 gWorldShadowList[0xF0];
BSS s8 gBattleShadowList[0xF0];
BSS s32 gCurrentShadowListPtr;
BSS s32 wEntityBlueprintSize;
BSS s32 bEntityBlueprintSize;
BSS char D_80151664[0x4];
BSS s8 wEntityBlueprint[0x74];
BSS s32 D_801516DC;
BSS char D_8015DCE0[0x8];
BSS s8 bEntityBlueprint[0x14];
BSS s32 D_801516FC;
BSS s8 gMainGameState[0x40];
BSS s8 gCurrentTileDescriptor[0x30];
BSS s8 wModelList[0x400];
BSS s8 bModelList[0x400];
BSS s8 wTransformGroups[0x10];
BSS s8 bTransformGroups[0x10];
BSS s8 wModelSpecialDls[0x80];
BSS s8 bModelSpecialDls[0x80];
BSS s8 wCustomModelGfxBuilders[0x80];
BSS s8 bCustomModelGfxBuilders[0x80];
BSS s8 wModelLocalVtxBuffers[0x40];
BSS s8 bModelLocalVtxBuffers[0x40];
BSS s32 gCurrentModelLocalVtxBuffers;
BSS s32 D_80152214;
BSS s32 D_80152218;
BSS char D_8015221C[0x4];
BSS s8 D_80152220[0x800];
BSS s8 D_80152A20[0x800];
BSS s8 wBgRenderType;
BSS s8 bBgRenderType;
BSS s8 D_80153222;
BSS s8 D_80153223;
BSS s16 mdl_treeIterPos;
BSS s16 D_80153226;
BSS s8 wFogSettings[0x20];
BSS s8 bFogSettings[0x1C];
BSS s32 gCurrentFogSettings;
BSS s8 texPannerMainU[0x40];
BSS s8 texPannerMainV[0x40];
BSS s8 texPannerAuxU[0x40];
BSS s8 texPannerAuxV[0x40];
BSS s32 mdl_nextTextureAddress;
BSS s16 mdl_currentTransformGroupChildIndex;
BSS s16 D_8015336E;
BSS s32 D_80153370;
BSS s16 D_80153374;
BSS s16 D_80153376;
BSS s8 D_80153378[0x8];
BSS s8 D_80153380[0x20];
BSS s8 mdl_renderTaskLists[0xC];
BSS s32 mdl_renderTaskMode;
BSS s8 mdl_renderTaskCount[0x10];
BSS s8 D_801533C0[0x300];
BSS s8 D_801536C0[0x300];
BSS s8 D_801539C0[0x40];
BSS s8 D_80153A00[0x40];
BSS s32 gCurrentAnimMeshListPtr;
BSS s32 gAnimModelFogEnabled;
BSS s32 gAnimModelFogR;
BSS s32 gAnimModelFogG;
BSS s32 gAnimModelFogB;
BSS s32 gAnimModelFogA;
BSS s32 gAnimModelFogStart;
BSS s32 gAnimModelFogEnd;
BSS s32 gAnimVtxSegment;
BSS char D_80153A64[0x4];
BSS s8 gAnimRotMtx[0x40];
BSS s8 gAnimScaleMtx[0x40];
BSS s8 gAnimTranslateMtx[0x40];
BSS s8 gAnimRotScaleMtx[0x40];
BSS s8 gAnimTreeRoot[0x8];
BSS s8 gWorldEntityModelList[0x400];
BSS s8 gBattleEntityModelList[0x400];
BSS s32 gCurrentEntityModelList;
BSS s32 D_80154374;
BSS s32 entity_fog_enabled;
BSS s8 entity_fog_red;
BSS char D_8015437D;
BSS char D_8015437E;
BSS s8 D_8015437F;
BSS s8 entity_fog_green;
BSS char D_80154381;
BSS char D_80154382;
BSS s8 D_80154383;
BSS s8 entity_fog_blue;
BSS char D_80154385;
BSS char D_80154386;
BSS s8 D_80154387;
BSS s8 entity_fog_alpha;
BSS char D_80154389;
BSS char D_8015438A;
BSS s8 D_8015438B;
BSS s32 entity_fog_dist_min;
BSS s32 entity_fog_dist_max;
BSS char D_80154394[0xC];
BSS s8 gWorldDynamicEntityList[0x40];
BSS s8 gBattleDynamicEntityList[0x40];
BSS s32 gCurrentDynamicEntityListPtr;
BSS char D_80154424[0xC];
BSS s8 gMessageBuffers[0x800];
BSS s8 gMessagePrinters[0x1008];
BSS s8 gMessageMsgVars[0x60];
BSS s8 D_80155C98[0x8];
BSS s8 gMessageWindowProjMatrix[0x80];
BSS s32 D_80155D20;
BSS char D_8015DD24[0x50];
BSS s32 msg_drawState;
BSS char D_8015DD78[0x8];
BSS s32 D_80155D80;
BSS s32 ItemEntityAlternatingSpawn;
BSS s32 ItemEntityRenderGroup;
BSS s16 D_80155D8C;
BSS s16 D_80155D8E;
BSS s8 D_80155D90[0x10];
BSS s8 WorldItemEntities[0x400];
BSS s8 BattleItemEntities[0x400];
BSS s32 gCurrentItemEntities;
BSS s16 isPickingUpItem;
BSS s16 D_801565A6;
BSS s32 D_801565A8;
BSS char D_801565AC[0x4];
BSS s8 D_801565B0[0x330];
BSS s32 D_801568E0;
BSS s32 D_801568E4;
BSS s32 D_801568E8;
BSS s32 D_801568EC;
BSS s32 D_801568F0;
BSS s32 D_801568F4;
BSS s32 D_801568F8;
BSS char D_801568FC[0x4];
BSS s32 screen_overlay_frontType;
BSS s32 screen_overlay_frontZoom;
BSS s32 screen_overlay_backType;
BSS s32 screen_overlay_backZoom;
BSS s8 D_80156910[0x10];
BSS s8 D_80156920[0x28];
BSS s8 D_80156948[0x8];
BSS s32 fold_vtxBuf;
BSS s32 D_80156954;
BSS s8 D_80156958[0x8];
BSS s8 D_80156960[0x8];
BSS s8 D_80156968[0x8];
BSS s8 D_80156970[0x10];
BSS s8 fold_groupDescriptors[0x5A0];
BSS s8 fold_gfxDataCache[0x40];
BSS s8 gHudElementsWorld[0x500];
BSS s8 gHudElementsBattle[0x500];
BSS s32 gHudElements;
BSS s32 gHudElementCacheBufferWorld;
BSS s32 gHudElementCacheSizeWorld;
BSS char D_8015796C[0x4];
BSS s8 gHudElementCacheTableRasterWorld[0x600];
BSS s8 gHudElementCacheTablePaletteWorld[0x600];
BSS s32 gHudElementCacheBufferBattle;
BSS s32 gHudElementCacheSizeBattle;
BSS char D_80158578[0x8];
BSS s8 gHudElementCacheTableRasterBattle[0x600];
BSS s8 gHudElementCacheTablePaletteBattle[0x600];
BSS s8 D_80159180[0x10];
BSS s8 wTriggerList[0x100];
BSS s8 bTriggerList[0x100];
BSS s32 gCurrentTriggerListPtr;
BSS char D_80159394[0xC];
BSS s8 D_801593A0[0x1FE];
BSS s16 D_8015959E;
BSS s8 D_801595A0[0x20];
BSS s8 D_801595C0[0xB0];
BSS s8 D_80159670[0xB0];
BSS s8 D_80159720[0xB0];
BSS s8 D_801597D0[0xB0];
BSS s8 D_80159880[0x20];
BSS s8 D_801598A0[0x118];
BSS s8 D_801599B8[0x118];
BSS s32 D_80159AD0;
BSS s32 D_80159AD4;
BSS char D_80159AD8[0x8];
BSS s16 gMusicDefaultVolume;
BSS s16 gMusicTargetVolume;
BSS s16 gMusicMaxVolume;
BSS s16 gMusicCurrentVolume;
BSS char D_80159AE8[0x8];
BSS s8 gMusicSettings[0x60];
BSS s8 D_80159B50[0x200];
BSS s32 gWindows;
BSS s8 D_80159D54[0xC];
BSS s8 D_80159D60[0x110];
BSS s8 D_80159E70[0xC];
BSS char D_80159E7C;
BSS char D_80159E7D;
BSS char D_80159E7E;
BSS char D_80159E7F;
BSS s8 D_80159E80[0x190];
BSS s8 D_8015A010[0x60];
BSS s8 D_8015A070[0xC];
BSS s8 D_8015A07C[0x164];
BSS char D_8015A1E0;
BSS char D_8015A1E1;
BSS char D_8015A1E2;
BSS char D_8015A1E3;
BSS s8 D_8015A1E4[0xD8];
BSS s16 D_8015A2BC;
BSS s16 D_8015A2BE;
BSS char D_8015A2C0[0x10];
BSS s8 D_8015A2D0[0xA0];
BSS s8 D_8015A370[0x1E0];
BSS s8 gCollisionStatus[0x28];
BSS s16 D_8015A578;
BSS s16 D_8015A57A;
BSS char D_8015A57C[0x14];
BSS s8 mdl_textureHandles[0x2200];
BSS s8 D_8015C790[0x30];
BSS s8 AmbientSoundData[0x10];
BSS s32 CreateEntityVarArgBuffer[4];
BSS s32 D_8015C7E0;

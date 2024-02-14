#define NO_EXTERN_VARIABLES
#include "common.h"
#include "model.h"
#include "hud_element.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

BSS SpriteShadingProfile* gAuxSpriteShadingProfile;
BSS s32 gHudElementsNumber;
BSS ModelCustomGfxBuilderList* gCurrentCustomModelGfxBuildersPtr;
BSS s32 D_801512BC;
BSS s32 entity_numEntities;
BSS s32 gEntityHeapBase;
BSS HudCacheEntry* gHudElementCacheTableRaster;
BSS ModelList* gCurrentModels;
BSS HudCacheEntry* gHudElementCacheTablePalette;
BSS s32 gAnimCount;
BSS s32 gMsgBGScrollAmtX;
BSS s32 D_801512DC;
BSS ModelTransformGroupList* gCurrentTransformGroups;
BSS u16 gMsgGlobalWaveCounter;
BSS ModelCustomGfxList* gCurrentCustomModelGfxPtr;
BSS s32 gLastCreatedEntityIndex;
BSS u8* gBackgroundTintModePtr;
BSS MessageImageData* gMsgVarImages[1];
BSS s32 ItemEntitiesCreated;
BSS ModelNode** gCurrentModelTreeRoot;
BSS s32 gEntityHeapBottom;
BSS s32 D_80151304;
BSS u16 gCurrentRoomDoorSounds;
BSS s32 gMsgBGScrollAmtY;
BSS s32 gEntityHideMode;
BSS u8* gHudElementCacheBuffer;
BSS s32 gEntityModelCount;
BSS u8* D_8015131C;
BSS s32 D_80151320;
BSS s32 entity_numShadows;
BSS SpriteShadingProfile* gSpriteShadingProfile;
BSS s32 isAreaSpecificEntityDataLoaded;
BSS s32 entity_updateCounter;
BSS s16 gTriggerCount;
BSS Gfx* D_80151338;
BSS s32* gHudElementCacheSize;
BSS u16 gCurrentDoorSounds;
BSS s32 D_80151344;
#if VERSION_JP
BSS s32 D_80151348[4];
#elif VERSION_PAL || VERSION_IQUE
BSS s32 D_80151348[8];
#else
BSS s32 D_80151348[12];
#endif

#endif

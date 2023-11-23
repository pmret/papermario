.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

#ifndef SHIFT

.section .bss

dlabel gAuxSpriteShadingProfile
.space 4

dlabel gHudElementsNumber
.space 4

dlabel gCurrentCustomModelGfxBuildersPtr
.space 4

dlabel D_801512BC
.space 4

dlabel entity_numEntities
.space 4

dlabel gEntityHeapBase
.space 4

dlabel gHudElementCacheTableRaster
.space 4

dlabel gCurrentModels
.space 4

dlabel gHudElementCacheTablePalette
.space 4

dlabel gAnimCount
.space 4

dlabel gMsgBGScrollAmtX
.space 4

dlabel D_801512DC
.space 4

dlabel gCurrentTransformGroups
.space 4

dlabel gMsgGlobalWaveCounter
.space 4

dlabel gCurrentCustomModelGfxPtr
.space 4

dlabel gLastCreatedEntityIndex
.space 4

dlabel gBackgroundTintModePtr
.space 4

dlabel gMsgVarImages
.space 4

dlabel ItemEntitiesCreated
.space 4

dlabel gCurrentModelTreeRoot
.space 4

dlabel gEntityHeapBottom
.space 4

dlabel D_80151304
.space 4

dlabel gCurrentRoomDoorSounds
.space 4

dlabel gMsgBGScrollAmtY
.space 2

dlabel D_8015130E
.space 2

dlabel gEntityHideMode
.space 4

dlabel gHudElementCacheBuffer
.space 4

dlabel gEntityModelCount
.space 4

dlabel D_8015131C
.space 4

dlabel D_80151320
.space 4

dlabel entity_numShadows
.space 4

dlabel gSpriteShadingProfile
.space 4

dlabel isAreaSpecificEntityDataLoaded
.space 4

dlabel entity_updateCounter
.space 4

dlabel gTriggerCount
.space 4

dlabel D_80151338
.space 4

dlabel gHudElementCacheSize
.space 4

dlabel gCurrentDoorSounds
.space 4

dlabel D_80151344
.space 4

dlabel D_80151348
.space 0x00000038

dlabel gWorldEntityList
.space 0x00000078

dlabel gBattleEntityList
.space 0x00000078

dlabel gCurrentEntityListPtr
.space 4

dlabel D_80151474
.space 4

dlabel gWorldShadowList
.space 0x000000f0

dlabel gBattleShadowList
.space 0x000000f0

dlabel gCurrentShadowListPtr
.space 4

dlabel wEntityDataLoadedSize
.space 4

dlabel bEntityDataLoadedSize
.space 4

dlabel D_80151664
.space 4

dlabel wEntityBlueprint
.space 0x00000078

.space 8

dlabel bEntityBlueprint
.space 0x00000014

dlabel D_801516FC
.space 4

dlabel gMainGameMode
.space 0x00000040

dlabel gCurrentTextureHeader
.space 0x00000030

dlabel wModelList
.space 0x00000400

dlabel bModelList
.space 0x00000400

dlabel wTransformGroups
.space 0x00000010

dlabel bTransformGroups
.space 0x00000010

dlabel wCustomModelGfx
.space 0x00000080

dlabel bCustomModelGfx
.space 0x00000080

dlabel wCustomModelGfxBuilders
.space 0x00000080

dlabel bCustomModelGfxBuilders
.space 0x00000080

dlabel wModelLocalVtxBuffers
.space 0x00000040

dlabel bModelLocalVtxBuffers
.space 0x00000040

dlabel gCurrentModelLocalVtxBuffers
.space 4

dlabel wModelTreeRoot
.space 4

dlabel bModelTreeRoot
.space 4

dlabel D_8015221C
.space 4

dlabel wModelTreeNodeInfo
.space 0x00000800

dlabel bModelTreeNodeInfo
.space 0x00000800

dlabel wBackgroundTintMode
.space 1

dlabel bBackgroundTintMode
.space 1

dlabel D_80153222
.space 1

dlabel D_80153223
.space 1

dlabel TreeIterPos
.space 4

dlabel wFogSettings
.space 0x00000020

dlabel bFogSettings
.space 0x0000001c

dlabel gFogSettings
.space 4

dlabel texPannerMainU
.space 0x00000040

dlabel texPannerMainV
.space 0x00000040

dlabel texPannerAuxU
.space 0x00000040

dlabel texPannerAuxV
.space 0x00000040

dlabel TextureHeapPos
.space 4

dlabel mtg_IterIdx
.space 2

dlabel mtg_SearchModelID
.space 2

dlabel mtg_FoundModelNode
.space 4

dlabel mtg_MinChild
.space 2

dlabel mtg_MaxChild
.space 2

dlabel D_80153378
.space 8

dlabel DepthCopyBuffer
.space 0x00000020

dlabel RenderTaskLists
.space 0x0000000c

dlabel RenderTaskListIdx
.space 4

dlabel RenderTaskCount
.space 0x00000010

dlabel D_801533C0
.space 0x00000300

dlabel D_801536C0
.space 0x00000300

dlabel D_801539C0
.space 0x00000040

dlabel D_80153A00
.space 0x00000040

dlabel gCurrentAnimMeshListPtr
.space 4

dlabel gAnimModelFogEnabled
.space 4

dlabel gAnimModelFogR
.space 4

dlabel gAnimModelFogG
.space 4

dlabel gAnimModelFogB
.space 4

dlabel gAnimModelFogA
.space 4

dlabel gAnimModelFogStart
.space 4

dlabel gAnimModelFogEnd
.space 4

dlabel gAnimVtxSegment
.space 4

dlabel D_80153A64
.space 4

dlabel gAnimRotMtx
.space 0x00000040

dlabel gAnimScaleMtx
.space 0x00000040

dlabel gAnimTranslateMtx
.space 0x00000040

dlabel gAnimRotScaleMtx
.space 0x00000040

dlabel gAnimTreeRoot
.space 8

dlabel gWorldEntityModelList
.space 0x00000400

dlabel gBattleEntityModelList
.space 0x00000400

dlabel gCurrentEntityModelList
.space 4

dlabel D_80154374
.space 4

dlabel entity_fog_enabled
.space 4

dlabel entity_fog_red
.space 4

dlabel entity_fog_green
.space 4

dlabel entity_fog_blue
.space 4

dlabel entity_fog_alpha
.space 4

dlabel entity_fog_dist_min
.space 4

dlabel entity_fog_dist_max
.space 4

dlabel D_80154394
.space 0x0000000c

dlabel gWorldWorkerList
.space 0x00000040

dlabel gBattleWorkerList
.space 0x00000040

dlabel gCurrentWorkerListPtr
.space 4

dlabel D_80154424
.space 0x0000000c

dlabel gMessageBuffers
.space 0x00000800

dlabel gMessagePrinters
.space 0x00001008

dlabel gMessageMsgVars
.space 0x00000060

dlabel D_80155C98
.space 8

dlabel gMessageWindowProjMatrix
.space 0x00000080

dlabel D_80155D20
.space 4

dlabel D_8015DD24
.space 0x00000050

dlabel msg_drawState
.space 4

dlabel D_8015DD78
.space 8

dlabel UnusedItemPhysicsScriptID
.space 4

dlabel ItemEntityAlternatingSpawn
.space 4

dlabel ItemEntityRenderGroup
.space 4

dlabel CoinSparkleCenterX
.space 2

dlabel CoinSparkleCenterY
.space 2

dlabel CoinSparkleCenterZ
.space 2

dlabel pad_ItemEntity
.space 0x000000E

dlabel WorldItemEntities
.space 0x00000400

dlabel BattleItemEntities
.space 0x00000400

dlabel gCurrentItemEntities
.space 4

dlabel isPickingUpItem
.space 2

dlabel ItemSpawnWithinPlayerPickupDelay
.space 2

dlabel D_801565A8
.space 4

dlabel D_801565AC
.space 4

dlabel ItemPickupMenu
.space 0x00000330

dlabel ItemPickupIconID
.space 4

dlabel ItemPickupStateDelay
.space 4

dlabel ThrowAwayMenuIdx
.space 4

dlabel ThrowAwayItemID
.space 4

dlabel ItemPickupGotOutline
.space 4

dlabel GotItemTutorialPrinter
.space 4

dlabel GotItemTutorialClosed
.space 4

dlabel D_801568FC
.space 4

dlabel screen_overlay_frontType
.space 4

dlabel screen_overlay_frontZoom
.space 4

dlabel screen_overlay_backType
.space 4

dlabel screen_overlay_backZoom
.space 4

dlabel D_80156910
.space 0x00000010

dlabel ImgFXCurrentTexture
.space 0x00000028

dlabel ImgFXVtxBuffers
.space 8

dlabel imgfx_vtxBuf
.space 4

dlabel ImgFXInstances
.space 4

dlabel D_80156958
.space 8

dlabel D_80156960
.space 8

dlabel D_80156968
.space 8

dlabel D_80156970
.space 0x00000010

dlabel ImgFXAnimHeaders
.space 0x000005a0

dlabel ImgFXDataCache
.space 0x00000040

dlabel gHudElementsWorld
.space 0x00000500

dlabel gHudElementsBattle
.space 0x00000500

dlabel gHudElements
.space 4

dlabel gHudElementCacheBufferWorld
.space 4

dlabel gHudElementCacheSizeWorld
.space 4

dlabel D_8015796C
.space 4

dlabel gHudElementCacheTableRasterWorld
.space 0x00000600

dlabel gHudElementCacheTablePaletteWorld
.space 0x00000600

dlabel gHudElementCacheBufferBattle
.space 4

dlabel gHudElementCacheSizeBattle
.space 4

dlabel D_80158578
.space 8

dlabel gHudElementCacheTableRasterBattle
.space 0x00000600

dlabel gHudElementCacheTablePaletteBattle
.space 0x00000600

dlabel D_80159180
.space 0x00000010

dlabel wTriggerList
.space 0x00000100

dlabel bTriggerList
.space 0x00000100

dlabel gCurrentTriggerListPtr
.space 4

dlabel D_80159394
.space 0x0000000c

dlabel gBackgroundPalette
.space 0x00000200

dlabel gBackroundLastScrollValue
.space 0x00000020

dlabel wSpriteShadingProfile
.space 0x000000b0

dlabel bSpriteShadingProfile
.space 0x000000b0

dlabel wSpriteShadingProfileAux
.space 0x000000b0

dlabel bSpriteShadingProfileAux
.space 0x000000b0

dlabel SpriteShadingPalette
.space 0x00000020

dlabel wEnvSounds
.space 0x00000118

dlabel bEnvSounds
.space 0x00000118

dlabel gCurrentEnvSounds
.space 4

dlabel SfxReverbMode
.space 4

dlabel D_80159AD8
.space 8

dlabel MusicDefaultVolume
.space 2

dlabel MusicTargetVolume
.space 2

dlabel MusicMaxVolume
.space 2

dlabel MusicCurrentVolume
.space 2

dlabel D_80159AE8
.space 8

dlabel gMusicSettings
.space 0x00000060

dlabel D_80159B50
.space 0x00000200

dlabel gWindows
.space 0x00000800

dlabel gCollisionStatus
.space 0x00000028

dlabel gCurrentHiddenPanels
.space 0x10

.space 8

dlabel TextureHandles
.space 0x00002200

dlabel ScreenOverlays
.space 0x00000030

dlabel AmbientSoundData
.space 0x00000010

dlabel CreateEntityVarArgBuffer
.space 0x00000010

dlabel D_8015C7E0
.space 0x20

dlabel D_8015C800
.space 0x7800

dlabel D_80164000
.space 0x32C60

#endif

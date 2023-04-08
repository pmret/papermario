.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

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
.space 2

dlabel D_801512DA
.space 2

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

dlabel gBackgroundFogModePtr
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

dlabel entity_area_specific_data_is_loaded
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
.space 0x00000074

dlabel D_801516DC
.space 4

dlabel D_8015DCE0
.space 8

dlabel bEntityBlueprint
.space 0x00000014

dlabel D_801516FC
.space 4

dlabel gMainGameState
.space 0x00000040

dlabel gCurrentTileDescriptor
.space 0x00000030

dlabel wModelList
.space 0x00000400

dlabel bModelList
.space 0x00000400

dlabel wTransformGroups
.space 0x00000010

dlabel bTransformGroups
.space 0x00000010

dlabel wModelSpecialDls
.space 0x00000080

dlabel bModelSpecialDls
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

dlabel D_80152214
.space 4

dlabel D_80152218
.space 4

dlabel D_8015221C
.space 4

dlabel D_80152220
.space 0x00000800

dlabel D_80152A20
.space 0x00000800

dlabel wBackgroundFogMode
.space 1

dlabel bBackgroundFogMode
.space 1

dlabel D_80153222
.space 1

dlabel D_80153223
.space 1

dlabel mdl_treeIterPos
.space 2

dlabel D_80153226
.space 2

dlabel wFogSettings
.space 0x00000020

dlabel bFogSettings
.space 0x0000001c

dlabel gCurrentFogSettings
.space 4

dlabel texPannerMainU
.space 0x00000040

dlabel texPannerMainV
.space 0x00000040

dlabel texPannerAuxU
.space 0x00000040

dlabel texPannerAuxV
.space 0x00000040

dlabel mdl_nextTextureAddress
.space 4

dlabel mdl_currentTransformGroupChildIndex
.space 2

dlabel D_8015336E
.space 2

dlabel D_80153370
.space 4

dlabel D_80153374
.space 2

dlabel D_80153376
.space 2

dlabel D_80153378
.space 8

dlabel depthCopyBuffer
.space 0x00000020

dlabel mdl_renderTaskLists
.space 0x0000000c

dlabel mdl_renderTaskQueueIdx
.space 4

dlabel mdl_renderTaskCount
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
.space 1

dlabel D_8015437D
.space 1

dlabel D_8015437E
.space 1

dlabel D_8015437F
.space 1

dlabel entity_fog_green
.space 1

dlabel D_80154381
.space 1

dlabel D_80154382
.space 1

dlabel D_80154383
.space 1

dlabel entity_fog_blue
.space 1

dlabel D_80154385
.space 1

dlabel D_80154386
.space 1

dlabel D_80154387
.space 1

dlabel entity_fog_alpha
.space 1

dlabel D_80154389
.space 1

dlabel D_8015438A
.space 1

dlabel D_8015438B
.space 1

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

dlabel D_80155D80
.space 4

dlabel ItemEntityAlternatingSpawn
.space 4

dlabel ItemEntityRenderGroup
.space 4

dlabel D_80155D8C
.space 2

dlabel D_80155D8E
.space 2

dlabel D_80155D90
.space 0x00000010

dlabel WorldItemEntities
.space 0x00000400

dlabel BattleItemEntities
.space 0x00000400

dlabel gCurrentItemEntities
.space 4

dlabel isPickingUpItem
.space 2

dlabel D_801565A6
.space 2

dlabel D_801565A8
.space 4

dlabel D_801565AC
.space 4

dlabel D_801565B0
.space 0x00000330

dlabel D_801568E0
.space 4

dlabel D_801568E4
.space 4

dlabel D_801568E8
.space 4

dlabel D_801568EC
.space 4

dlabel D_801568F0
.space 4

dlabel D_801568F4
.space 4

dlabel D_801568F8
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

dlabel D_80156920
.space 0x00000028

dlabel D_80156948
.space 8

dlabel fold_vtxBuf
.space 4

dlabel D_80156954
.space 4

dlabel D_80156958
.space 8

dlabel D_80156960
.space 8

dlabel D_80156968
.space 8

dlabel D_80156970
.space 0x00000010

dlabel FoldAnimHeaders
.space 0x000005a0

dlabel fold_gfxDataCache
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
.space 0x000001fe

dlabel D_8015959E
.space 2

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

dlabel D_80159880
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
.space 2

dlabel D_8015A57A
.space 2

dlabel D_8015A57C
.space 0x00000014

dlabel mdl_textureHandles
.space 0x00002200

dlabel D_8015C790
.space 0x00000030

dlabel AmbientSoundData
.space 0x00000010

dlabel CreateEntityVarArgBuffer
.space 0x00000010

dlabel D_8015C7E0
.space 0x7820

dlabel D_80164000
.space 0x32C60

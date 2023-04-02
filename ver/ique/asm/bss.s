.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .bss

dlabel nuScPreNMIFlag
.space 4

dlabel D_8009A5B4
.space 4

dlabel D_8009A5B8
.space 4

dlabel D_8009A5BC
.space 4

dlabel __osFlashVersion
.space 4

dlabel gSoundGlobals
.space 4

dlabel D_8009A5C4
.space 4

dlabel __osBaseCounter
.space 4

dlabel gBGMPlayerC
.space 4

dlabel gEncounterSubState
.space 4

dlabel __osBbRCountWraps
.space 4

dlabel CurrentSefCmdHandler
.space 4

dlabel timeFreezeMode
.space 4

dlabel __osBbLastRCount
.space 4

dlabel nuGfxZBuffer
.space 4

dlabel nuContDataLockKey
.space 4

dlabel __osViIntrCount
.space 4

dlabel BeginSoundUpdateCallback
.space 4

dlabel D_8009A5EC
.space 4

dlabel nuGfxCfbCounter
.space 4

dlabel mdl_currentModelTreeNodeInfo
.space 4

dlabel nuGfxDisplay
.space 4

dlabel gBGMPlayerB
.space 4

dlabel gEncounterState
.space 4

dlabel gNpcCount
.space 2

dlabel __osMaxControllers
.space 2

dlabel __osFlashMsgBuf
.space 4

dlabel __osCurrentTime
.space 8

dlabel nuGfxUcode
.space 4

dlabel nuContNum
.space 4

dlabel __osBbLastVCount
.space 4

dlabel nuGfxTaskSpool
.space 4

dlabel __osContLastCmd
.space 4

dlabel __osEepromTimerMsg
.space 4

dlabel D_8009A624
.space 4

dlabel gAuAmbienceManager
.space 4

dlabel __osTimerCounter
.space 4

dlabel nuIdleFunc
.space 4

dlabel gCurrentCamID
.space 4

dlabel nuPiCartHandle
.space 4

dlabel __osBbVCountWraps
.space 4

dlabel D_8009A63C
.space 4

dlabel gSoundManager
.space 4

dlabel D_8009A644
.space 8

dlabel nuGfxCfb_ptr
.space 4

dlabel gOverrideFlags
.space 4

dlabel D_8009A654
.space 4

dlabel nuGfxCfb
.space 4

dlabel D_8009A65C
.space 4

dlabel __osFinalrom
.space 4

dlabel gBGMPlayerA
.space 4

dlabel gFirstStrikeMessagePos
.space 4

dlabel gMainGfxPos
.space 4

dlabel D_8009A670
.space 4

dlabel gDisplayContext
.space 4

dlabel D_8009A678
.space 4

dlabel D_8009A67C
.space 4

.space 8

dlabel D_8009A680
.space 4

dlabel D_8009A684
.space 0x0000000c

dlabel D_8009A690
.space 4

dlabel D_8009A694
.space 0x0000000c

dlabel D_8009A6A0
.space 2

dlabel D_8009A6A2
.space 2

dlabel D_8009A6A4
.space 2

dlabel D_8009A6A6
.space 2

dlabel D_8009A6A8
.space 8

dlabel D_8009A6B0
.space 0x00001380

dlabel logicalSaveInfo
.space 0x00000020

dlabel physicalSaveInfo
.space 0x00000030

dlabel nextAvailableSavePage
.space 4

dlabel D_8009BA84
.space 0x0000000c

dlabel gCurtainScale
.space 4

dlabel gCurtainScaleGoal
.space 4

dlabel gCurtainFade
.space 4

dlabel gCurtainFadeGoal
.space 4

dlabel gCurtainDrawCallback
.space 4

dlabel D_8009BAA4
.space 4

dlabel D_8009BAA8
.space 0x00000080

dlabel D_8009BA28
.space 8

dlabel gCrashScreen
.space 0x000009e0

dlabel nuGfxTask_ptr
.space 4

dlabel taskDoneMsg
.space 2

dlabel swapBufMsg
.space 2

dlabel GfxTaskMgrThread
.space 0x000001b0

.align 4
dlabel GfxTaskMgrStack
.space 0x00002000

dlabel D_8009E6D0
.space 0x00000020

dlabel gCurrentCamConfiguration
.space 0x0000001c

dlabel D_800A08DC
.space 4

dlabel D_800A08E0
.space 4

dlabel D_800A08E4
.space 4

dlabel D_800A08E8
.space 4

dlabel D_800A08EC
.space 4

dlabel gameMode
.space 4

dlabel D_800A08F4
.space 0x0000000c

dlabel D_800A0900
.space 4

dlabel D_800A0904
.space 4

dlabel D_800A0908
.space 4

dlabel D_800A090C
.space 4

dlabel gLogosImages
.space 4

dlabel gLogosImage3
.space 4

dlabel gLogosImage1
.space 4

dlabel gLogosImage2
.space 4

dlabel D_800A0920
.space 1

dlabel D_800A0921
.space 1

dlabel D_800A0922
.space 2

dlabel SavedReverbMode
.space 4

dlabel D_800A0928
.space 8

dlabel D_800A0930
.space 1

dlabel D_800A0931
.space 1

dlabel D_800A0932
.space 2

dlabel D_800A0934
.space 0x0000000c

dlabel gMapTransitionAlpha
.space 2

dlabel gMapTransitionFadeRate
.space 2

dlabel gMapTransitionState
.space 2

dlabel gMapTransitionStateTime
.space 2

dlabel D_800A0948
.space 4

dlabel D_800A094C
.space 4

dlabel D_800A0950
.space 4

dlabel D_800A0954
.space 2

dlabel D_800A0956
.space 2

dlabel D_800A0958
.space 2

dlabel D_800A095A
.space 1

dlabel D_800A095B
.space 1

dlabel D_800A095C
.space 1

dlabel D_800A095D
.space 1

dlabel D_800A095E
.space 1

dlabel D_800A095F
.space 1

dlabel D_800A0960
.space 0x00000003

dlabel D_800A0963
.space 1

dlabel D_800A0964
.space 4

dlabel D_800A0968
.space 8

dlabel D_800A0970
.space 4

dlabel TitleScreen_ImgList
.space 4

dlabel TitleScreen_ImgList_Logo
.space 4

dlabel TitleScreen_ImgList_Copyright
.space 4

dlabel TitleScreen_ImgList_PressStart
.space 4

dlabel D_800A0984
.space 4

dlabel D_800A0988
.space 4

dlabel D_800A098C
.space 4

dlabel gWorldNpcList
.space 0x00000100

dlabel gBattleNpcList
.space 0x00000100

dlabel gCurrentNpcListPtr
.space 4

dlabel gNpcPlayerCollisionsEnabled
.space 4

dlabel D_800A0B98
.space 8

dlabel D_800A0BA0
.space 4

dlabel D_800A0BA4
.space 4

dlabel WorldMerleeOrbEffect
.space 4

dlabel WorldMerleeWaveEffect
.space 4

dlabel D_800A0BB0
.space 4

dlabel D_800A0BB4
.space 4

dlabel D_800A0BB8
.space 4

dlabel D_800A0BBC
.space 4

dlabel D_800A0BC0
.space 0x00000380

dlabel D_800A0F40
.space 4

dlabel D_800A0F44
.space 4

dlabel D_800A0F48
.space 8

dlabel AuInitialGlobalVolume
.space 4

dlabel D_800A0F54
.space 4

dlabel nuAuMgrThread
.space 0x000001b0

# TODO: figure out what this extra space is used for
.space 0x00000408

dlabel AuStack
.space 0x00002000

dlabel AlCmdListBuffers
.space 0x0000000c

dlabel D_800A351C
.space 4

dlabel nuAuTasks
.space 0x00000108

dlabel D_800A3628
.space 0x0000000c

dlabel AlFrameSize
.space 4

dlabel AlMinFrameSize
.space 4

dlabel D_800A363C
.space 4

dlabel nuAuDmaMesgQ
.space 4

dlabel D_800A3644
.space 0x00000014

dlabel nuAuDmaMesgBuf
.space 0x000000c8

dlabel nuAuDmaIOMesgBuf
.space 0x000004b0

dlabel nuAuDmaState
.space 4

dlabel D_800A3BD4
.space 4

dlabel D_800A3BD8
.space 8

dlabel nuAuDmaBufList
.space 0x000003e8

dlabel D_800A3FC8
.space 8

dlabel CurrentSeqCmdHandler
.space 4

dlabel D_800A3FD4
.space 0x0000000c

dlabel AuDelayBufferMain
.space 4

dlabel AuDelayBufferAux
.space 4

dlabel AuDelayCounter
.space 4

dlabel AuDelayedVoiceGroup
.space 2

dlabel AuDelayedChannel
.space 2

dlabel AuDelayCount
.space 4

dlabel D_800A3FF4
.space 0x0000000c

dlabel gEffectGraphicsData
.space 0x000001b4

dlabel D_800A41B4
.space 0x0000000c

dlabel D_800A41C0
.space 4

dlabel D_800A41C4
.space 0x0000001c

dlabel gMapConfig
.space 4

dlabel D_800A41E4
.space 4

dlabel gMapSettings
.space 4

dlabel D_800A41EC
.space 0x00000044

dlabel gCollisionRayStartX
.space 4

dlabel gCollisionRayStartY
.space 4

dlabel gCollisionRayStartZ
.space 4

dlabel gCollisionRayDirX
.space 4

dlabel gCollisionRayDirY
.space 4

dlabel gCollisionRayDirZ
.space 4

dlabel gCollisionPointX
.space 4

dlabel gCollisionPointY
.space 4

dlabel gCollisionPointZ
.space 4

dlabel gCollisionRayLength
.space 4

dlabel gCollisionNormalX
.space 4

dlabel gCollisionNormalY
.space 4

dlabel gCollisionNormalZ
.space 4

dlabel gCollisionDataBackup
.space 4

dlabel gCollisionDataZoneBackup
.space 4

dlabel D_800A426C
.space 4

dlabel IdleThread
.space 0x000001b0

dlabel MainThread
.space 0x000001b0

dlabel IdleStack
.space 0x00002000

dlabel nuScStack
.space 0x00002000

dlabel nuScAudioStack
.space 0x00002000

dlabel nuScGraphicsStack
.space 0x00002000

dlabel D_800AC5D0
.space 4

dlabel D_800AC5D4
.space 0x00000014

dlabel D_800AC5E8
.space 0x000000c8

dlabel nuGfxMesgBuf
.space 0x00000020

dlabel GfxStack
.space 0x00002000

dlabel nuSiMesgBuf
.space 0x00000020

dlabel siMgrThread
.space 0x1b0

dlabel siMgrStack
.space 0x2000

dlabel nuContWaitMesgBuf
.space 4

dlabel nuContDataMutexBuf
.space 4

.align 4
dlabel tmp_task
.space 0x00000040

dlabel siAccessBuf
.space 4

dlabel D_800AC6D8
.space 8

.space 4

dlabel retrace
.space 4

.space 4

dlabel viThread
.space 0x1B0

dlabel viThreadStack
.space 0x1000

dlabel viEventQueue
.space 0x18

dlabel viEventBuf
.space 4 * 5

dlabel viRetraceMsg
.space 0x00000018

dlabel viCounterMsg
.space 0x00000018

.align 4

dlabel piThread
.space 0x1B0

dlabel piThreadStack
.space 0x1000

dlabel piEventQueue
.space 0x18

dlabel piEventBuf
.space 4

dlabel D_800AF8AC
.space 4

dlabel piAccessBuf
.space 4

.space 0x24

dlabel wMapTexName
.space 4

dlabel D_800B0CF4
.space 0x00000014

dlabel D_800B0D08
dlabel __osThreadSave
.space 0x1b0

dlabel nuContWaitMesgQ
.space 0x18

.align 4
dlabel __osContPifRam
.space 0x40

dlabel gCurrentEncounter
.space 0x00000bf4

dlabel __Dom2SpeedParam
.space 0x74

dlabel nuContStatus
.space 0x4 * 4

dlabel D_800B1B90
.space 0x000001b0

dlabel nuContRmbCtl
.space 0xA * 4

.space 2

    .align 4
dlabel nuContData
.space 6 * 4

    .align 4
dlabel gCameras
.space 0x00001560

dlabel D_800B32E0
.space 0x800

dlabel D_800B3AE0
.space 0x800

dlabel gCollisionData
.space 0x10

dlabel nuGfxMesgQ
.space 0x18

dlabel __CartRomHandle
.space 0x74

dlabel __osPiAccessQueue
.space 0x18

    .align 3
dlabel gEffectInstances
.space 4*96

dlabel __Dom1SpeedParam
.space 0x74

    .align 4
dlabel nuBootStack
.space 0x00002000

dlabel nuMainStack
.space 0x00002000

dlabel nuYieldBuf
.space 0x00000c10

dlabel auSynDriver
.space 0x00000030

dlabel D_800B91D0
.space 0x00020000

dlabel __osFlashHandler
.space 0x00000074

.align 3
dlabel gZoneCollisionData
.space 0x00000010

dlabel wMapHitName
.space 0x00000014

dlabel nuSiMgrMesgQ
.space 0x00000018

    .align 3
dlabel __osBaseTimer
.space 0x20

dlabel wMapShapeName
.space 0x00000018

dlabel nuAuHeap
.space 0x00000010

dlabel __osFlashMessageQ
.space 0x18

# TODO: figure out where this space comes from
.space 0x20

dlabel nuGfxTask
.space 0x58*10

dlabel D_800D95E8
.space 0x80

dlabel wMapBgName
.space 0x00000014

dlabel __osPfsInodeCache
.space 0x00000100

dlabel __osEventStateTab
.space 0x00000100

    .align 4

dlabel __osPfsPifRam
.space 0x0000003c

.space 4

dlabel D_800DA040
.space 0x00000400

dlabel nusched
.space 0x67e

    .align 3

dlabel __osEepromTimerQ
.space 0x00000018

dlabel nuContPfs
.space 0x68 * 4

dlabel nuSiMesgQ
.space 0x00000018

dlabel D_800DAC90
.space 0x00000018

dlabel __osSiAccessQueue
.space 0x00000018

dlabel __osBbFlashBuffer
.space 0x80

dlabel gCurrentSaveFile
.space 0x00001380

dlabel nuContDataMutexQ
.space 0x00000020

dlabel D_800DC060
.space 4

dlabel gCurrentStagePtr
.space 4

dlabel gBattleState
.space 4

dlabel D_800DC06C
.space 4

dlabel gBattleStatus
.space 0x00000460

dlabel gLastDrawBattleState
.space 4

dlabel D_800DC4D4
.space 4

dlabel gDefeatedBattleSubstate
.space 4

dlabel gBattleSubState
.space 4

dlabel D_800DC4E0
.space 4

dlabel gDefeatedBattleState
.space 4

dlabel gCurrentBattleID
.space 4

dlabel gCurrentStageID
.space 4

dlabel D_800DC4F0
.space 4

dlabel gOverrideBattlePtr
.space 4

dlabel D_800DC4F8
.space 4

dlabel gCurrentBattlePtr
.space 4

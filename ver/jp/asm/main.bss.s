.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .bss

dlabel nuScPreNMIFlag
.space 8

dlabel D_8009A5B8
.space 8

dlabel gSoundGlobals
.space 8

dlabel __osBaseCounter
.space 4

dlabel gBGMPlayerC
.space 4

dlabel gEncounterSubState
.space 4

dlabel CurrentSefCmdHandler
.space 4

dlabel timeFreezeMode
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
.space 8

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

dlabel __osCurrentTime
.space 8

dlabel nuGfxUcode
.space 4

dlabel nuContNum
.space 4

dlabel nuGfxTaskSpool
.space 4

dlabel __osContLastCmd
.space 4

dlabel __osEepromTimerMsg
.space 8

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

dlabel D_8009A63C
.space 4

dlabel gSoundManager
.space 12

dlabel nuGfxCfb_ptr
.space 4

dlabel gOverrideFlags
.space 4

dlabel HasPreBattleSongPushed
.space 4

dlabel nuGfxCfb
.space 8

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
.space 8

dlabel ResetFrameBufferArray
.space 0x00000010

dlabel SoftResetDelay
.space 0x00000010

dlabel D_8009A6A0
.space 2

dlabel D_8009A6A2
.space 2

dlabel D_8009A6A4
.space 2

dlabel D_8009A6A6
.space 10

dlabel FetchSaveBuffer
.space 0x00001380

dlabel LogicalSaveInfo
.space 0x00000020

dlabel PhysicalSaveInfo
.space 0x00000030

dlabel NextAvailablePhysicalSave
.space 0x00000010

dlabel gCurtainScale
.space 4

dlabel gCurtainScaleGoal
.space 4

dlabel gCurtainFade
.space 4

dlabel gCurtainFadeGoal
.space 4

dlabel gCurtainDrawCallback
.space 8

dlabel D_8009BAA8
.space 0x00000088

dlabel gCrashScreen
.space 0x000009E0

dlabel nuGfxTask_ptr
.space 4

dlabel taskDoneMsg
.space 2

dlabel swapBufMsg
.space 2

dlabel GfxTaskMgrThread
.space 0x000001B8

dlabel GfxTaskMgrStack
.space 0x00002000

dlabel D_8009E6D0
.space 0x00000020

dlabel gCurrentCamConfiguration
.space 0x0000001C

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

dlabel CurGameMode
.space 0x00000010

dlabel D_800A0900
.space 4

dlabel D_800A0904
.space 4

dlabel D_800A0908
.space 8

dlabel gLogosImages
.space 4

dlabel gLogosImage3
.space 4

dlabel gLogosImage1
.space 4

dlabel gLogosImage2
.space 4

dlabel StepPauseDelay
.space 1

dlabel StepPauseState
.space 1

dlabel StepPauseAlpha
.space 2

dlabel SavedReverbMode
.space 12

dlabel D_800A0930
.space 1

dlabel D_800A0931
.space 1

dlabel D_800A0932
.space 14

dlabel gMapTransitionAlpha
.space 2

dlabel gMapTransitionFadeRate
.space 2

dlabel gMapTransitionState
.space 2

dlabel gMapTransitionStateTime
.space 2

dlabel gLoadedFromFileSelect
.space 8

dlabel IntroEnableDrawFrameDelay
.space 4

dlabel IntroOverlayAlpha
.space 2

dlabel IntroFrontFadeAlpha
.space 2

dlabel IntroOverlayDelta
.space 2

dlabel IntroFadeColorR
.space 2

dlabel IntroFadeColorG
.space 2

dlabel IntroFadeColorB
.space 2

dlabel IntroOverlayType
.space 4

dlabel D_800A0964
.space 12

dlabel TitleScreen_AppearDelay
.space 4

dlabel TitleScreen_ImgList
.space 4

dlabel TitleScreen_ImgList_Logo
.space 4

dlabel TitleScreen_ImgList_Copyright
.space 4

dlabel TitleScreen_ImgList_PressStart
.space 4

dlabel TitleScreen_ImgList_CopyrightPalette
.space 4

dlabel TitleScreen_TimeLeft
.space 8

dlabel gWorldNpcList
.space 0x00000100

dlabel gBattleNpcList
.space 0x00000100

dlabel gCurrentNpcListPtr
.space 4

dlabel gNpcPlayerCollisionsEnabled
.space 12

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
.space 8

dlabel D_800A0BC0
.space 0x00000380

dlabel D_800A0F40
.space 4

dlabel D_800A0F44
.space 12

dlabel AuInitialGlobalVolume
.space 8

dlabel nuAuMgrThread
.space 0x000005B8

dlabel AuStack
.space 0x00002000

dlabel AlCmdListBuffers
.space 0x00000010

dlabel nuAuTasks
.space 0x00000108

dlabel D_800A3628
.space 12

dlabel AlFrameSize
.space 4

dlabel AlMinFrameSize
.space 8

dlabel nuAuDmaMesgQ
.space 0x00000018

dlabel nuAuDmaMesgBuf
.space 0x000000C8

dlabel nuAuDmaIOMesgBuf
.space 0x000004B0

dlabel nuAuDmaState
.space 0x00000010

dlabel nuAuDmaBufList
.space 0x000003F0

dlabel CurrentSeqCmdHandler
.space 0x00000010

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
.space 0x00000010

dlabel gEffectGraphicsData
.space 0x000001E0

dlabel gMapConfig
.space 8

dlabel gMapSettings
.space 0x00000048

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
.space 8

dlabel IdleThread
.space 0x000001B0

dlabel MainThread
.space 0x000001B0

dlabel IdleStack
.space 0x00002000

dlabel nuScStack
.space 0x00002000

dlabel nuScAudioStack
.space 0x00002000

dlabel nuScGraphicsStack
.space 0x00002000

dlabel D_800AC5D0
.space 0x00000018

dlabel D_800AC5E8
.space 0x000000C8

dlabel nuGfxMesgBuf
.space 0x00000020

dlabel GfxStack
.space 0x00002000

dlabel nuSiMesgBuf
.space 0x00000020

dlabel siMgrThread
.space 0x000001B0

dlabel siMgrStack
.space 0x00002000

dlabel nuContWaitMesgBuf
.space 4

dlabel nuContDataMutexBuf
.space 12

dlabel piThread
.space 0x000001B0

dlabel piThreadStack
.space 0x00001000

dlabel piEventQueue
.space 0x00000018

dlabel piEventBuf
.space 8

dlabel piAccessBuf
.space 0x00000010

dlabel tmp_task
.space 0x00000040

dlabel siAccessBuf
.space 0x00000010

dlabel retrace
.space 8

dlabel viThread
.space 0x000001B8

dlabel viThreadStack
.space 0x00001000

dlabel viEventQueue
.space 0x00000018

dlabel viEventBuf
.space 0x00000018

dlabel viRetraceMsg
.space 0x00000018

dlabel viCounterMsg
.space 0x00000018

dlabel __MotorDataBuf
.space 0x00000100

dlabel __osFlashID
.space 0x00000010

dlabel __osFlashMsg
.space 0x00000018

dlabel __osFlashMessageQ
.space 0x00000018

dlabel __osFlashHandler
.space 0x00000074

dlabel __osFlashMsgBuf
.space 4

dlabel __osFlashVersion
.space 8

dlabel wMapTexName
.space 0x00000018

dlabel __osThreadSave
.space 0x000001B0

dlabel nuContWaitMesgQ
.space 0x00000018

dlabel __osContPifRam
.space 0x00000040

dlabel gCurrentEncounter
.space 0x00000BF8

dlabel __Dom2SpeedParam
.space 0x00000074

dlabel nuContStatus
.space 0x00000014

dlabel D_800B1B90
.space 0x000001B0

dlabel nuContRmbCtl
.space 0x00000028

dlabel nuContData
.space 0x00000018

dlabel gCameras
.space 0x00002560

dlabel gCollisionData
.space 0x00000010

dlabel nuGfxMesgQ
.space 0x00000018

dlabel __CartRomHandle
.space 0x00000078

dlabel __osPiAccessQueue
.space 0x00000018

dlabel gEffectInstances
.space 0x00000180

dlabel __Dom1SpeedParam
.space 0x00000078

dlabel nuBootStack
.space 0x00002000

dlabel nuMainStack
.space 0x00002000

dlabel nuYieldBuf
.space 0x00000C10

dlabel auSynDriver
.space 0x00000030

dlabel D_800B91D0
.space 0x00020000

dlabel gZoneCollisionData
.space 0x00000010

dlabel wMapHitName
.space 0x00000014

dlabel nuSiMgrMesgQ
.space 0x0000001C

dlabel __osBaseTimer
.space 0x00000020

dlabel wMapShapeName
.space 0x00000018

dlabel nuAuHeap
.space 0x00000030

dlabel nuGfxTask
.space 0x00000370

dlabel gSaveGlobals
.space 0x00000080

dlabel wMapBgName
.space 0x00000018

dlabel __osPfsInodeCache
.space 0x00000100

dlabel rspbootUcodeBuffer
.space 0x00000800

dlabel __osEventStateTab
.space 0x00000080

dlabel __osPfsPifRam
.space 0x00000040

dlabel D_800DA040
.space 0x00000400

dlabel nusched
.space 0x00000680

dlabel __osEepromTimerQ
.space 0x00000018

dlabel nuContPfs
.space 0x000001A0

dlabel nuSiMesgQ
.space 0x00000018

dlabel D_800DAC90
.space 0x00000018

dlabel __osSiAccessQueue
.space 0x00000018

dlabel gCurrentSaveFile
.space 0x00001380

dlabel nuContDataMutexQ
.space 0x00000020

dlabel D_800DC060
.space 4

dlabel gCurrentStagePtr
.space 4

dlabel gBattleState
.space 8

dlabel gBattleStatus
.space 0x00000460

dlabel gLastDrawBattleState
.space 4

dlabel D_800DC4D4
.space 8

dlabel gBattleSubState
.space 4

dlabel D_800DC4E0
.space 8

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

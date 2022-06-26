#include "types.h"

// This file exists to enforce the order of BSS symbols, since they were reordered in the original rom.

#ifndef M2CTX
#define BSS __attribute__ ((section (".bss")))
#else
#define BSS static
#endif

BSS u8 nuScPreNMIFlag;
BSS char D_8009A5B4[0x4];
BSS s32 D_8009A5B8;
BSS char D_8009A5BC[0x4];
BSS s32 gSoundGlobals;
BSS char D_8009A5C4[0x4];
BSS s32 __osBaseCounter;
BSS s32 gBGMPlayerC;
BSS s32 D_8009A5D0;
BSS s32 CurrentSEFCmdHandler;
BSS s32 timeFreezeMode;
BSS s32 nuGfxZBuffer;
BSS u32 nuContDataLockKey;
BSS s32 __osViIntrCount;
BSS s32 D_8009A5E8;
BSS float D_8009A5EC;
BSS u32 nuGfxCfbCounter;
BSS s32 mdl_currentModelTreeNodeInfo;
BSS u32 nuGfxDisplay;
BSS s32 gBGMPlayerB;
BSS s32 gGameState;
BSS s16 gNpcCount;
BSS s16 __osMaxControllers;
BSS s32 __osCurrentTime;
BSS s32 D_8009A60C;
BSS s32 nuGfxUcode;
BSS u32 nuContNum;
BSS u32 nuGfxTaskSpool;
BSS u8 __osContLastCmd;
BSS s32 D_8009A620;
BSS char D_8009A624[0x4];
BSS s32 D_8009A628;
BSS s32 __osTimerCounter;
BSS s32 D_8009A630;
BSS s16 gCurrentCamID;
BSS s32 nuPiCartHandle;
BSS s32 D_8009A63C;
BSS s32 gSoundManager;
BSS char D_8009A644[0x8];
BSS s32 nuGfxCfb_ptr;
BSS s32 gOverrideFlags;
BSS s8 D_8009A654;
BSS s32* nuGfxCfb;
BSS char D_8009A65C[0x4];
BSS s32 D_8009A660;
BSS s32 gBGMPlayerA;
BSS s16 D_8009A668;
BSS s32 gMasterGfxPos;
BSS s32 D_8009A670;
BSS s32 gDisplayContext;
BSS s32 D_8009A678;
BSS char D_8009A67C[0x4];
BSS s32 D_8009A680;
BSS char D_8009A684[0xC];
BSS s16 D_8009A690;
BSS char D_8009A694[0xC];
BSS u16 D_8009A6A0;
BSS u16 D_8009A6A2;
BSS u16 D_8009A6A4;
BSS u16 D_8009A6A6;
BSS char D_8009A6A8[0x8];
BSS s8 D_8009A6B0[0x1380];
BSS s32 logicalSaveInfo[4][2];
BSS s32 physicalSaveInfo[6][2];
BSS s32 nextAvailableSavePage;
BSS char D_8009BA84[0xC];
BSS float gCurtainScale;
BSS float gCurtainScaleGoal;
BSS float gCurtainFade;
BSS float gCurtainFadeGoal;
BSS UNK_FUN_PTR(gCurtainDrawCallback);
BSS char D_8009BAA4[0x4];
BSS s8 D_8009BAA8[0x40 * 2];
BSS char D_8009BA28[0x8];
BSS s8 gCrashScreen[0x9E0];
BSS s32 nuGfxTask_ptr;
BSS s16 taskDoneMsg;
BSS s16 swapBufMsg;
BSS s8 GfxTaskMgrThread[0x21B0];
BSS char D_8009E6C8[0x8];
BSS s32 D_8009E6D0[8];
BSS s32 nuSiMesgBuf[8];
BSS s8 siMgrThread[0x21B0];
BSS s8 blendedCamSettings[0x1C];
BSS float D_800A08DC;
BSS float D_800A08E0;
BSS s32 D_800A08E4;
BSS s32 D_800A08E8;
BSS s32 D_800A08EC;
BSS s16 gameMode;
BSS char D_800A08F4[0xC];
BSS s8 D_800A0900;
BSS s32 D_800A0904;
BSS s32 D_800A0908;
BSS char D_800A090C[0x4];
BSS s32 gLogosImages;
BSS s32 gLogosImage3;
BSS s32 gLogosImage1;
BSS s32 gLogosImage2;
BSS s8 D_800A0920;
BSS s8 D_800A0921;
BSS s16 D_800A0922;
BSS s32 D_800A0924;
BSS char D_800A0928[0x8];
BSS s8 D_800A0930;
BSS s8 D_800A0931;
BSS s16 D_800A0932;
BSS char D_800A0934[0xC];
BSS s16 gMapTransitionAlpha;
BSS s16 D_800A0942;
BSS s16 D_800A0944;
BSS s16 D_800A0946;
BSS s16 D_800A0948;
BSS char D_800A094C[0x4];
BSS s32 D_800A0950;
BSS s16 D_800A0954;
BSS s16 D_800A0956;
BSS s16 D_800A0958;
BSS s8 D_800A095A;
BSS u8 D_800A095B;
BSS s8 D_800A095C;
BSS u8 D_800A095D;
BSS s8 D_800A095E;
BSS u8 D_800A095F;
BSS s8 D_800A0960[3];
BSS u8 D_800A0963;
BSS s32 D_800A0964;
BSS char D_800A0968[0x8];
BSS s32 D_800A0970;
BSS s32 D_800A0974;
BSS s32 D_800A0978;
BSS s32 D_800A097C;
BSS s32 D_800A0980;
BSS char D_800A0984[0x4];
BSS s32 D_800A0988;
BSS char D_800A098C[0x4];
BSS s8 gWorldNpcList[0x100];
BSS s8 gBattleNpcList[0x100];
BSS s32 gCurrentNpcListPtr;
BSS s8 D_800A0B94;
BSS char D_800A0B98[0x8];
BSS s32 D_800A0BA0;
BSS float D_800A0BA4;
BSS s32 D_800A0BA8;
BSS s32 D_800A0BAC;
BSS s32 D_800A0BB0;
BSS s32 D_800A0BB4;
BSS s16 D_800A0BB8;
BSS char D_800A0BBC[0x4];
BSS s8 D_800A0BC0[32 * 0x1C];
BSS s32 D_800A0F40;
BSS s32 D_800A0F44;
BSS char D_800A0F48[0x8];
BSS u16 D_800A0F50;
BSS char D_800A0F54[0x4];
BSS s8 nuAuMgrThread[0x25B8];
BSS s32 AlCmdListBuffers[3];
BSS char D_800A351C[4];
BSS s32 D_800A3520;
BSS char D_800A3524[0x104];
BSS s8 D_800A3628[0xC];
BSS s32 AlFrameSize;
BSS s32 AlMinFrameSize;
BSS char D_800A363C[0x4];
BSS s32 nuAuDmaMesgQ;
BSS char D_800A3644[0x14];
BSS s8 nuAuDmaMesgBuf[0xC8];
BSS s8 nuAuDmaIOMesgBuf[0x4B0];
BSS s32 nuAuDmaState;
BSS s32 D_800A3BD4;
BSS char D_800A3BD8[0x8];
BSS s8 nuAuDmaBufList[50 * 0x14];
BSS s8 D_800A3FC8[8];
BSS s32 D_800A3FD0;
BSS char D_800A3FD4[0xC];
BSS s32 D_800A3FE0;
BSS s32 D_800A3FE4;
BSS s32 D_800A3FE8;
BSS s8 D_800A3FEC;
BSS s16 D_800A3FEE;
BSS s32 D_800A3FF0;
BSS char D_800A3FF4[0xC];
BSS s8 gEffectGraphicsData[15 * 0x1D];
BSS char D_800A41B4[0xC];
BSS s32 D_800A41C0;
BSS char D_800A41C4[0x1C];
BSS s32 gMap;
BSS char D_800A41E4[0x4];
BSS s32 gMapConfig;
BSS char D_800A41EC[0x44];
BSS float gCollisionRayStartX;
BSS float gCollisionRayStartY;
BSS float gCollisionRayStartZ;
BSS float gCollisionRayDirX;
BSS float gCollisionRayDirY;
BSS float gCollisionRayDirZ;
BSS float gCollisionPointX;
BSS float gCollisionPointY;
BSS float gCollisionPointZ;
BSS float gCollisionRayLength;
BSS s32 gCollisionNormalX;
BSS s32 gCollisionNormalY;
BSS s32 gCollisionNormalZ;
BSS s32 gCollisionDataBackup;
BSS s32 gCollisionDataZoneBackup;
BSS char D_800A426C[0x4];
BSS s8 D_800A4270[0x1B0];
BSS s8 D_800A4420[0x21B0];
BSS s8 nuScStack[0x2000];
BSS s8 nuScAudioStack[0x2000];
BSS s8 nuScGraphicsStack[0x2000];
BSS s32 D_800AC5D0;
BSS char D_800AC5D4[0x14];
BSS s8 D_800AC5E8[0xC8];
BSS s8 nuGfxMesgBuf[0x2020];
BSS s32 nuContWaitMesgBuf;
BSS s32 nuContDataMutexBuf;
BSS char D_800AC6D8[0x8];
BSS s8 piMgrThread[0x11B0];
BSS s32 __osPiMesgQueue;
BSS char D_800AF890[0x14];
BSS s32 piMgrMesgBuff;
BSS char D_800AF8AC[0x4];
BSS s32 piAccessBuf;
BSS char D_800AF8B4[0xC];
BSS char tmp_task[0x40];
BSS s32 siAccessBuf;
BSS char D_800AF904[0xC];
BSS s32 D_800AF910;
BSS char D_800AF914[0x4];
BSS s32 D_800AF918;
BSS char D_800AF91C[0x11B4];
BSS s32 D_800B0AD0;
BSS char D_800B0AD4[0x14];
BSS s32 D_800B0AE8;
BSS char D_800B0AEC[0x14];
BSS s16 D_800B0B00;
BSS s16 D_800B0B02;
BSS s32 D_800B0B04;
BSS char D_800B0B08[0x10];
BSS s16 D_800B0B18;
BSS s16 D_800B0B1A;
BSS s32 D_800B0B1C;
BSS char D_800B0B20[0x10];
BSS s32 D_800B0B30;
BSS char D_800B0B34[0x38];
BSS s32 D_800B0B6C;
BSS char D_800B0B70[0xC0];
BSS s32 __osFlashID;
BSS char D_800B0C34[0xC];
BSS s32 __osFlashMsg;
BSS char D_800B0C44[0x14];
BSS s32 __osFlashMessageQ;
BSS char D_800B0C5C[0x14];
BSS s32 __osFlashHandler;
BSS char D_800B0C74[0x70];
BSS s32 __osFlashMsgBuf;
BSS s32 __osFlashVersion;
BSS char D_800B0CEC[0x4];
BSS s32 wMapTexName;
BSS char D_800B0CF4[0x14];
BSS s32 D_800B0D08;
BSS char D_800B0D0C[0x1AC];
BSS s32 nuContWaitMesgQ;
BSS char D_800B0EBC[0x14];
BSS s32 __osContPifRam;
BSS char D_800B0ED4[0x34];
BSS s32 D_800B0F08;
BSS s32 D_800B0F0C;
BSS s8 gCurrentEncounter[0xBF8];
BSS s32 LeoDiskHandle;
BSS s8 D_800B1B0C;
BSS s8 D_800B1B0D;
BSS s8 D_800B1B0E;
BSS s8 D_800B1B0F;
BSS s32 D_800B1B10;
BSS char D_800B1B14[0x68];
BSS s32 nuContStatus[5];
BSS s8 D_800B1B90[0x1B0];
BSS s8 nuContRmbCtl[0x28];
BSS s8 nuContData[0x18];
BSS s8 gCameras[4 * 0x958];
BSS s32 gCollisionData;
BSS char D_800B42E4[0xC];
BSS s32 nuGfxMesgQ;
BSS char D_800B42F4[0x14];
BSS s32 D_800B4308;
BSS s8 D_800B430C;
BSS s8 D_800B430D;
BSS s8 D_800B430E;
BSS s8 D_800B430F;
BSS s8 D_800B4310;
BSS s8 D_800B4311;
BSS s32 D_800B4314;
BSS s32 D_800B4318;
BSS char D_800B431C[0x64];
BSS s32 __osPiAccessQueue;
BSS char D_800B4384[0x14];
BSS s32 gEffectInstances[96];
BSS s32 CartRomHandle;
BSS s8 D_800B451C;
BSS s8 D_800B451D;
BSS s8 D_800B451E;
BSS s8 D_800B451F;
BSS s8 D_800B4520[0x2070];
BSS s8 D_800B6590[0x2000];
BSS u8 nuYieldBuf[0xC10];
BSS s8 D_800B91A0[0x30];
BSS s8 D_800B91D0[0x20000];
BSS s8 gZoneCollisionData[0x10];
BSS s8 wMapHitName[0x18];
BSS s8 nuSiMgrMesgQ[0x38];
BSS s8 wMapShapeName[0x18];
BSS s8 nuAuHeap[0x30];
BSS s8 nuGfxTask[10 * 0x58];
BSS s8 D_800D95E8[0x38];
BSS s8 D_800D9620[0x48];
BSS s8 D_800D9668[0x18];
BSS s8 __osPfsInodeCache[0x100];
BSS s8 rspbootUcodeBuffer[0x100];
BSS s8 D_800D9880[0x700];
BSS s8 __osEventStateTab[0x80];
BSS s8 __osPfsPifRam[0x3C];
BSS s32 D_800DA03C;
BSS s8 D_800DA040[0x400];
BSS s32 nusched;
BSS s8 D_800DA444[0x38];
BSS s8 D_800DA47C[0x38];
BSS s8 D_800DA4B4[0xA8];
BSS s8 D_800DA55C[0x54C];
BSS s8 D_800DAAA8[0x10];
BSS s32 AlNumFields;
BSS s8 D_800DAABC;
BSS s8 D_800DAABD;
BSS s8 D_800DAAC0[0x18];
BSS s8 nuContPfs[0x1A0];
BSS s8 nuSiMesgQ[0x18];
BSS s8 D_800DAC90[0x18];
BSS s8 __osSiAccessQueue[0x18];
BSS s8 gCurrentSaveFile[0x1380];
BSS s8 nuContDataMutexQ[0x20];
BSS s32 D_800DC060;
BSS s32 D_800DC064;
BSS s32 gBattleState;
BSS char D_800DC06C[0x4];
BSS s8 gBattleStatus[0x460];
BSS s32 D_800DC4D0;
BSS s32 D_800DC4D4;
BSS s32 D_800DC4D8;
BSS s32 gBattleState2;
BSS s32 D_800DC4E0;
BSS s32 D_800DC4E4;
BSS s16 D_800DC4E8;
BSS u8 gCurrentBattleSection;
BSS u8 D_800DC4EB;
BSS s32 D_800DC4EC;
BSS s32 D_800DC4F0;
BSS s32 D_800DC4F4;
BSS s32 D_800DC4F8;
BSS s32 D_800DC4FC;

#define NO_EXTERN_VARIABLES
#include "common.h"
#include "PR/osint.h"
#include "PR/controller.h"
#include "nu/nusys.h"
#include "npc.h"
#include "effects.h"
#include "audio.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

//
// main segment COMMON/.scommon symbols
//

#if VERSION_IQUE || VERSION_PAL
BSS OSIoMesg __osFlashMsg OSALIGNED(8);
#endif
BSS char wMapTexName[0x18];
BSS OSThread __osThreadSave;
BSS OSMesgQueue nuContWaitMesgQ;
BSS OSPifRam __osContPifRam BBALIGNED(16);
BSS EncounterStatus gCurrentEncounter;
BSS OSPiHandle __Dom2SpeedParam OSALIGNED(8);
BSS OSContStatus nuContStatus[NU_CONT_MAXCONTROLLERS];
BSS OSThread D_800B1B90;
BSS NUContRmbCtl nuContRmbCtl[NU_CONT_MAXCONTROLLERS];
#if VERSION_IQUE || VERSION_PAL
BSS u32 __osFlashID[4] OSALIGNED(8);
#endif
BSS OSContPad nuContData[NU_CONT_MAXCONTROLLERS];
BSS Camera gCameras[4] ALIGNED(16);
BSS unsigned char D_800B32E0[0x800] ALIGNED(16);
BSS unsigned char D_800B3AE0[0x800] ALIGNED(16);
BSS CollisionData gCollisionData;
BSS OSMesgQueue	nuGfxMesgQ;
BSS OSPiHandle __CartRomHandle OSALIGNED(8);
BSS OSMesgQueue __osPiAccessQueue OSALIGNED(8);
BSS EffectInstance* gEffectInstances[96] ALIGNED(8);
BSS OSPiHandle __Dom1SpeedParam OSALIGNED(8);
#if !VERSION_PAL
BSS u8 nuBootStack[0x2000] ALIGNED(8);
#endif
BSS u64 nuMainStack[NU_SC_STACK_SIZE / sizeof(u64)];
BSS u8 nuYieldBuf[NU_GFX_YIELD_BUF_SIZE];
BSS AuSynDriver auSynDriver;
BSS s32 D_800B91D0[NU_GFX_RDP_OUTPUTBUFF_SIZE / sizeof(u32)] ALIGNED(16);
#if VERSION_IQUE || VERSION_PAL
BSS OSPiHandle __osFlashHandler OSALIGNED(8);
#endif
BSS CollisionData gZoneCollisionData ALIGNED(8);
#if VERSION_JP || VERSION_IQUE
BSS char wMapHitName[0x14];
#else
BSS char wMapHitName[0x18];
#endif
BSS OSMesgQueue	nuSiMgrMesgQ;
BSS OSTimer __osBaseTimer;
BSS char wMapShapeName[0x18];
BSS ALHeap nuAuHeap;
#if VERSION_IQUE || VERSION_PAL
BSS OSMesgQueue __osFlashMessageQ OSALIGNED(8);
#endif
BSS OSTimer __osEepromTimer;
BSS NUScTask nuGfxTask[NU_GFX_TASK_NUM];
BSS SaveGlobals gSaveGlobals;
BSS char wMapBgName[0x14];
BSS __OSInode __osPfsInodeCache OSALIGNED(8);
#if !VERSION_IQUE
BSS u8 rspbootUcodeBuffer[0x100] ALIGNED(16);
BSS char D_800D9880[0x700];
#endif
BSS __OSEventState __osEventStateTab[OS_NUM_EVENTS];
BSS OSPifRam __osPfsPifRam BBALIGNED(16);
BSS u64 D_800DA040[0x400 / sizeof(u64)];
BSS NUSched nusched;
BSS OSMesgQueue __osEepromTimerQ OSALIGNED(8);
BSS OSPfs nuContPfs[NU_CONT_MAXCONTROLLERS];
BSS OSMesgQueue nuSiMesgQ;
BSS OSMesgQueue D_800DAC90;
BSS OSMesgQueue __osSiAccessQueue OSALIGNED(8);
#ifdef BBPLAYER
BSS u8 __osBbFlashBuffer[0x80];
#endif
BSS SaveData gCurrentSaveFile;
BSS OSMesgQueue nuContDataMutexQ;

#endif

#define NO_EXTERN_VARIABLES
#include "common.h"
#include "audio.h"
#include "model.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

//
// Main segment COMMON/.scommon symbols
//

BSS u8 nuScPreNMIFlag;
BSS s32 D_8009A5B4;
BSS s32 D_8009A5B8;
BSS s32 D_8009A5BC;
#if VERSION_IQUE
BSS s32 __osFlashVersion;
#endif
BSS AuGlobals* gSoundGlobals;
BSS s32 D_8009A5C4;
BSS u32 __osBaseCounter;
BSS BGMPlayer* gBGMPlayerC;
BSS s32 gEncounterSubState;
#ifdef BBPLAYER
BSS u32 __osBbRCountWraps;
#endif
BSS void *CurrentSefCmdHandler;
BSS s32 timeFreezeMode;
#ifdef BBPLAYER
BSS u32 __osBbLastRCount;
#endif
BSS u16* nuGfxZBuffer;
BSS u32 nuContDataLockKey;
BSS u32 __osViIntrCount;
BSS AuCallback BeginSoundUpdateCallback;
BSS f32 D_8009A5EC;
BSS u32 nuGfxCfbCounter;
BSS ModelTreeInfoList* gCurrentModelTreeNodeInfo;
BSS u32 nuGfxDisplay;
BSS BGMPlayer* gBGMPlayerB;
BSS s32 gEncounterState;
BSS s16 gNpcCount;
BSS u8 __osMaxControllers;
#if VERSION_IQUE
BSS OSMesg __osFlashMsgBuf;
#endif
BSS OSTime __osCurrentTime;
BSS NUUcode* nuGfxUcode;
BSS u32 nuContNum;
#ifdef BBPLAYER
BSS u32 __osBbLastVCount;
#endif
BSS volatile u32 nuGfxTaskSpool;
BSS u8 __osContLastCmd;
BSS OSMesg __osEepromTimerMsg;
BSS s32 D_8009A624;
BSS AmbienceManager* gAuAmbienceManager;
BSS u32 __osTimerCounter;
BSS void (*nuIdleFunc)(void);
BSS s16 gCurrentCamID;
BSS OSPiHandle* nuPiCartHandle;
#ifdef BBPLAYER
BSS u32 __osBbVCountWraps;
#endif
BSS s8 D_8009A63C;
BSS SoundManager* gSoundManager;
BSS s32 D_8009A644;
BSS s32 D_8009A648;
BSS u16* nuGfxCfb_ptr;
BSS s32 gOverrideFlags;
BSS s8 HasPreBattleSongPushed;
BSS u16** nuGfxCfb;
BSS s32 D_8009A65C;
BSS u32 __osFinalrom;
BSS BGMPlayer* gBGMPlayerA;
BSS s16 gFirstStrikeMessagePos;
BSS Gfx* gMainGfxPos;
BSS s8 D_8009A670;
BSS DisplayContext* gDisplayContext;
BSS s32 D_8009A678;
BSS s32 D_8009A67C;
#if VERSION_IQUE
BSS s32 D_80099258[2];
#endif
BSS u16* ResetFrameBufferArray;

#endif

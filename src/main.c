#include "common.h"
#include "nu/nusys.h"

//
// Start of libultra BSS
//

#include "PR/controller.h"
#include "PR/osint.h"
SHIFT_BSS OSPifRam __osEepPifRam;
SHIFT_BSS __OSEventState __osEventStateTab[OS_NUM_EVENTS];
SHIFT_BSS OSPifRam __MotorDataBuf[MAXCONTROLLERS];
SHIFT_BSS u16 retrace;
SHIFT_BSS OSThread viThread;
SHIFT_BSS unsigned char viThreadStack[OS_VIM_STACKSIZE] ALIGNED(16);
SHIFT_BSS char piThreadStack[OS_PIM_STACKSIZE] ALIGNED(16);
SHIFT_BSS OSMesgQueue viEventQueue;
SHIFT_BSS OSMesg viEventBuf[5] ALIGNED(8);
SHIFT_BSS OSIoMesg viRetraceMsg ALIGNED(8);
SHIFT_BSS OSIoMesg viCounterMsg ALIGNED(8);
SHIFT_BSS OSTask tmp_task;
SHIFT_BSS OSMesg piAccessBuf[1] ALIGNED(16);
SHIFT_BSS OSMesgQueue __osPiAccessQueue;
SHIFT_BSS OSThread piThread;
SHIFT_BSS OSMesgQueue piEventQueue;
SHIFT_BSS OSMesg piEventBuf[1];
SHIFT_BSS OSContStatus nuContStatus[5]; // ??? enough space for 5, but it makes no sense
SHIFT_BSS OSMesgQueue nuSiMesgQ;
SHIFT_BSS u32 nuContDataLockKey;
SHIFT_BSS OSMesg nuContWaitMesgBuf;
SHIFT_BSS OSMesg nuContDataMutexBuf;
SHIFT_BSS OSMesgQueue nuContDataMutexQ ALIGNED(16);
SHIFT_BSS OSMesgQueue nuContWaitMesgQ;
SHIFT_BSS OSContPad nuContData[4];
SHIFT_BSS u32 nuContNum;
SHIFT_BSS volatile u32 nuGfxTaskSpool;
SHIFT_BSS OSMesgQueue nuGfxMesgQ;
SHIFT_BSS char GfxStack[NU_GFX_STACK_SIZE] ALIGNED(16);
SHIFT_BSS OSThread D_800B1B90;
SHIFT_BSS OSMesg nuGfxMesgBuf[NU_GFX_MESGS];
SHIFT_BSS OSPiHandle* nuPiCartHandle;
SHIFT_BSS NUContRmbCtl nuContRmbCtl[4];
SHIFT_BSS OSPfs nuContPfs[4];
SHIFT_BSS NUUcode* nuGfxUcode;
SHIFT_BSS OSMesgQueue D_800AC5D0;
SHIFT_BSS OSMesg D_800AC5E8[NU_PI_MESG_NUM];
SHIFT_BSS u32 nuGfxDisplay;
SHIFT_BSS u32 nuGfxCfbCounter;
SHIFT_BSS NUSched nusched;
SHIFT_BSS u8 nuScPreNMIFlag;
SHIFT_BSS u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];
SHIFT_BSS u64 nuScAudioStack[NU_SC_STACK_SIZE / sizeof(u64)];
SHIFT_BSS u64 nuScGraphicsStack[NU_SC_STACK_SIZE / sizeof(u64)];
SHIFT_BSS NUIdleFunc nuIdleFunc;
SHIFT_BSS OSMesgQueue nuSiMgrMesgQ;
SHIFT_BSS OSMesg nuSiMesgBuf[8];
SHIFT_BSS OSThread siMgrThread;
SHIFT_BSS u64 siMgrStack[NU_SI_STACK_SIZE/sizeof(u64)];
SHIFT_BSS OSMesg D_8009E6D0[NU_GFX_TASKMGR_MESGS];
SHIFT_BSS OSMesgQueue D_800DAC90;
SHIFT_BSS NUScTask* nuGfxTask_ptr;
SHIFT_BSS s16 taskDoneMsg;
SHIFT_BSS s16 swapBufMsg;
SHIFT_BSS OSThread GfxTaskMgrThread;
SHIFT_BSS NUScTask nuGfxTask[NU_GFX_TASK_NUM];
SHIFT_BSS u64 D_800DA040[0x400 / sizeof(u64)];
SHIFT_BSS s32 D_800B91D0[NU_GFX_RDP_OUTPUTBUFF_SIZE / sizeof(u32)];
SHIFT_BSS u64 GfxTaskMgrStack[NU_GFX_TASKMGR_STACK_SIZE / sizeof(u64)];
SHIFT_BSS u8 nuYieldBuf[0xC10] ALIGNED(16);
SHIFT_BSS OSMesg siAccessBuf[1] ALIGNED(8);
SHIFT_BSS OSMesgQueue __osSiAccessQueue;
SHIFT_BSS OSThread __osThreadSave;

// boot.s
SHIFT_BSS u8 nuBootStack[0x2000] ALIGNED(8);

//osFlash.c (IDO)
SHIFT_BSS u32 __osFlashID[4];
SHIFT_BSS OSIoMesg __osFlashMsg;
SHIFT_BSS OSMesgQueue __osFlashMessageQ;
SHIFT_BSS OSPiHandle __osFlashHandler;
SHIFT_BSS OSMesg __osFlashMsgBuf;
SHIFT_BSS s32 __osFlashVersion;

//
// End of libultra BSS
//

// used in effects/gfx/flame.c
SHIFT_BSS unsigned char D_800B32E0[0x800] ALIGNED(16);
SHIFT_BSS unsigned char D_800B3AE0[0x800] ALIGNED(16);

s16 D_80074010 = 8; // might be an array, could be size 1-8

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void appendGfx_reset_tile_pattern(void);

void gfx_draw_frame(void);
void gfx_init_state(void);

void create_audio_system(void);
void load_engine_data(void);

enum {
    RESET_STATE_NONE    = 0,
    RESET_STATE_INIT    = 1,
    RESET_STATE_FADE    = 2,
};

// TODO try uniting these two split files
extern s32 ResetGameState;
extern u16* ResetSavedFrameImg;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern IMG_BIN ResetTilesImg[];

#ifdef SHIFT
#define shim_create_audio_system_obfuscated create_audio_system
#define shim_load_engine_data_obfuscated load_engine_data
#endif

SHIFT_BSS u16* ResetFrameBufferArray;
SHIFT_BSS u16* nuGfxZBuffer;

void boot_main(void* data) {
#if VERSION_JP
    if (osTvType == OS_TV_NTSC) {
        nuGfxDisplayOff();
        osViSetMode(&osViModeNtscLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
        nuGfxDisplayOff();
    } else {
        PANIC();
    }
#else // not VERSION_JP
    if (osTvType == OS_TV_NTSC) {
        osViSetMode(&osViModeNtscLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else if (osTvType == OS_TV_MPAL) {
        osViSetMode(&osViModeMpalLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else {
        PANIC();
    }

    nuGfxDisplayOff();
    crash_screen_init();
#endif

#if !VERSION_IQUE
    is_debug_init();
#endif
    nuGfxInit();
    gGameStatusPtr->contBitPattern = nuContInit();

#if VERSION_IQUE
    create_audio_system();
    load_engine_data();
#else
    load_obfuscation_shims();
    shim_create_audio_system_obfuscated();
    shim_load_engine_data_obfuscated();
#endif

    nuGfxFuncSet((NUGfxFunc) gfxRetrace_Callback);
    nuGfxPreNMIFuncSet(gfxPreNMI_Callback);
    gRandSeed += osGetCount();
    nuGfxDisplayOn();

    while (TRUE) {}
}

void gfxRetrace_Callback(s32 gfxTaskNum) {
    if (ResetGameState != RESET_STATE_NONE) {
        if (ResetGameState == RESET_STATE_INIT) {
            nuGfxTaskAllEndWait();
            if (gfxTaskNum == 0) {
                u16* fb = (u16*) osViGetCurrentFramebuffer();
                u16** bufferSet = &ResetFrameBufferArray;

                bufferSet[2] = fb;
                bufferSet[1] = fb;
                bufferSet[0] = fb;
                ResetSavedFrameImg = fb;
                nuGfxSetCfb(&ResetFrameBufferArray, 3);
                osViSwapBuffer(ResetFrameBufferArray);
                ResetGameState = RESET_STATE_FADE;
            }
        }
        if (ResetGameState == RESET_STATE_FADE) {
            appendGfx_reset_tile_pattern();
        }
    } else {
        D_80073E0A ^= 1;
        if (D_80073E0A == 0) {
            step_game_loop();
            D_80073E08 = 1;

            if (gfxTaskNum < 3) {
                D_80073E08 = 0;
                gfx_task_background();
                gfx_draw_frame();
            }
        }
    }
}

// on reset, draw a series of animated triangular black tiles emanating from the center of the screen
void appendGfx_reset_tile_pattern(void) {
    s16 t;
    s16 i;
    s16 j;
    u16* frozenFrame;

    gMatrixListPos = 0;
    gDisplayContext = &D_80164000[gCurrentDisplayContextIndex];
    gMainGfxPos = gDisplayContext->mainGfx;
    frozenFrame = ResetSavedFrameImg;
    gfx_init_state();

    gDPSetDepthImage(gMainGfxPos++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(frozenFrame));
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_RESET_TILES, PM_CC_RESET_TILES);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, 127);
    gDPLoadTextureTile_4b(gMainGfxPos++, ResetTilesImg, G_IM_FMT_I, 128, 8, 0, 0, 127, 7, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 15; j++) {
            s32 s4 = i + 14;
            t = (33 - (s4 - j)) / 2 + 15 - D_80074010;
            if (t >= 16) {
                continue;
            }
            if (t < 0) {
                continue;
            }
            gSPTextureRectangle(gMainGfxPos++, ((i * 8) + 160) * 4,
                                                 ((j * 8)) * 4,
                                                 ((i * 8) + 168) * 4,
                                                 ((j * 8) + 8) * 4,
                                                 G_TX_RENDERTILE,
                                                 (t * 8) * 32, 0, 0x0400, 0x0400);
            gSPTextureRectangle(gMainGfxPos++, ((i * 8) + 160) * 4,
                                                 (232 - (j * 8)) * 4,
                                                 ((i * 8) + 168) * 4,
                                                 (240 - (j * 8)) * 4,
                                                 G_TX_RENDERTILE,
                                                 (t * 8) * 32, 7 * 32, 0x0400, -0x0400);
            gSPTextureRectangle(gMainGfxPos++, (152 - (i * 8)) * 4,
                                                 ((j * 8)) * 4,
                                                 (160 - (i * 8)) * 4,
                                                 ((j * 8) + 8) * 4,
                                                 G_TX_RENDERTILE,
                                                 (t * 8 + 7) * 32, 0, -0x0400, 0x0400);
            gSPTextureRectangle(gMainGfxPos++, (152 - (i * 8)) * 4,
                                                 (232 - (j * 8)) * 4,
                                                 (160 - (i * 8)) * 4,
                                                 (240 - (j * 8)) * 4,
                                                 G_TX_RENDERTILE,
                                                 (t * 8 + 7) * 32, 7 * 32, -0x0400, -0x0400);
        }
    }

    D_80074010++;
    gDPFullSync(gMainGfxPos++);
    gSPEndDisplayList(gMainGfxPos++);
    nuGfxTaskStart(gDisplayContext->mainGfx, (u32)(gMainGfxPos - gDisplayContext->mainGfx) * 8, NU_GFX_UCODE_F3DEX, NU_SC_TASK_LODABLE);
    gCurrentDisplayContextIndex ^= 1;
}

#if VERSION_IQUE
NOP_FIX
#endif

void gfxPreNMI_Callback(void) {
    ResetGameState = RESET_STATE_INIT;
    nuContRmbForceStop();
}

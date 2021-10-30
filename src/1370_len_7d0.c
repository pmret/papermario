#include "common.h"
#include "nu/nusys.h"

s16 D_80074010 = 8; // might be an array, could be size 1-8

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void gfx_task_main(void);

// TODO: name these symbols the same, this is just a shift
#ifdef VERSION_US
extern s32 D_80073E00;
#else
extern s32 D_80073DE0;
#endif
extern u16* D_80073E04;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern s32 D_80073E10;
extern u16* D_8009A680;
extern OSViMode _osViModeNtscLan1;
extern OSViMode _osViModeMPalLan1;

void boot_main(void) {
#ifdef VERSION_JP
    if (osTvType == OS_TV_NTSC) {
        nuGfxDisplayOff();
        osViSetMode(&_osViModeNtscLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
        nuGfxDisplayOff();
    } else {
        PANIC();
    }
#else // VERSION_JP
    if (osTvType == OS_TV_NTSC) {
        osViSetMode(&_osViModeNtscLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else if (osTvType == OS_TV_MPAL) {
        osViSetMode(&_osViModeMPalLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else {
        PANIC();
    }

    nuGfxDisplayOff();
    crash_screen_init();
#endif

    is_debug_init();
    nuGfxInit();
    gGameStatusPtr->contBitPattern = nuContInit();
#ifdef VERSION_US
    func_8002D160();
    func_802B2000();
    func_802B203C();
#else
    func_8002CA00();
    func_802B2000();
    func_802B203C();
#endif
    nuGfxFuncSet((NUGfxFunc) gfxRetrace_Callback);
    nuGfxPreNMIFuncSet(gfxPreNMI_Callback);
    gRandSeed += osGetCount();
    nuGfxDisplayOn();

    while (TRUE) {}
}

#ifdef VERSION_US
void gfxRetrace_Callback(s32 arg0) {
    if (D_80073E00 != 0) {
        if (D_80073E00 == 1) {
            nuGfxTaskAllEndWait();
            if (arg0 == 0) {
                u16* fb = (u16*) osViGetCurrentFramebuffer();
                u16** temp_8009A680 = &D_8009A680;

                temp_8009A680[2] = fb;
                temp_8009A680[1] = fb;
                temp_8009A680[0] = fb;
                D_80073E04 = fb;
                nuGfxSetCfb(&D_8009A680, 3);
                osViSwapBuffer(D_8009A680);
                D_80073E00 = 2;
            }
        }
        if (D_80073E00 == 2) {
            gfx_task_main();
        }
    } else {
        D_80073E0A ^= 1;
        if (D_80073E0A == 0) {
            step_game_loop();
            D_80073E08 = 1;

            if (arg0 < 3) {
                D_80073E08 = 0;
                gfx_task_background();
                gfx_draw_frame();
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "1370", gfxRetrace_Callback);
#endif

//gfx stuff
#ifdef NON_MATCHING
void gfx_task_main(void) {
    u16 t;
    s32 temp_a0_3;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_a3_2;
    s32 temp_s0_3;
    s32 temp_s1_2;
    s32 temp_s3;
    s32 temp_t7;
    s16 i;
    s16 j;
    s32* temp;

    gMatrixListPos = 0;
    gDisplayContext = &D_80164000[gCurrentDisplayContextIndex];
    gMasterGfxPos = gDisplayContext->mainGfx;
    temp = D_80073E04;
    gfx_init_state();

    gDPSetDepthImage(gMasterGfxPos++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(temp));
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, 0, 0, 0, TEXEL0, 0, 0, 0, 0, 0, 0, 0, TEXEL0);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gMasterGfxPos++, 0, 0, 0, 127);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 64, &D_80073E10);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 254, 28);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_4b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 508, 28);

    for (i = 0; i < 20; i++) {
        temp_s3 = ((i * 8) + 168) * 4;
        temp_s1_2 = ((i * 8) + 160) * 4;
        temp_s0_3 = (160 - (i * 8)) * 4;
        temp_t7 = (152 - (i * 8)) * 4;

        for (j = 0; j < 15; j++) {
            t = (33 - ((i + 14) - j)) / 2 - (D_80074010 - 15);
            if (t < 16 && t >= 0) {
                temp_a0_3 = ((j * 8) + 8) * 4;
                temp_a3_2 = ((j * 8) - 8) * 4;
                temp_a1_3 = (SCREEN_HEIGHT - (j * 8)) * 4;
                temp_a2 = (232 - (j * 8)) * 4;

                gSPTextureRectangle(gMasterGfxPos++, temp_s3, temp_a0_3, temp_s1_2, temp_a3_2, 4, -0x2000, t, 0x0400, 0x0400);
                gSPTextureRectangle(gMasterGfxPos++, temp_s3, temp_a1_3, temp_s1_2, temp_a2, 4, -0x2000, t, 0x0400, -0x0400);
                gSPTextureRectangle(gMasterGfxPos++, temp_s0_3, temp_a0_3, temp_t7, temp_a3_2, 4, -0x2000, t, -0x0400, 0x0400);
                gSPTextureRectangle(gMasterGfxPos++, temp_s0_3, temp_a1_3, temp_t7, temp_a2, 4, -0x2000, t, -0x0400, -0x0400);
            }
        }
    }

    D_80074010++;
    gDPFullSync(gMasterGfxPos++);
    gSPEndDisplayList(gMasterGfxPos++);
    nuGfxTaskStart(gDisplayContext->mainGfx, (u32)(gMasterGfxPos - gDisplayContext->mainGfx) * 8, 0, 0x40000);
    gCurrentDisplayContextIndex ^= 1;
}
#else
    #ifdef VERSION_US
INCLUDE_ASM(void, "1370_len_7d0", gfx_task_main);
    #else
INCLUDE_ASM(s32, "1370", func_80026148);
    #endif
#endif

void gfxPreNMI_Callback(void) {
#ifdef VERSION_US
    D_80073E00 = 1;
#else
    D_80073DE0 = 1;
#endif
    nuContRmbForceStop();
}

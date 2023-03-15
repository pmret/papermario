#include "common.h"
#include "nu/nusys.h"

s16 D_80074010 = 8; // might be an array, could be size 1-8

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void gfx_task_main(void);

void gfx_draw_frame(void);
void gfx_init_state(void);

void create_audio_system(void);
void load_engine_data(void);

extern s32 D_80073E00;
extern u16* D_80073E04;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern s32 D_80073E10[];
extern u16* D_8009A680;

#ifdef SHIFT
#define shim_create_audio_system_obfuscated create_audio_system
#define shim_load_engine_data_obfuscated load_engine_data
#endif

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

void gfx_task_main(void) {
    s16 t;
    s16 i;
    s16 j;
    u16* temp;

    gMatrixListPos = 0;
    gDisplayContext = &D_80164000[gCurrentDisplayContextIndex];
    gMainGfxPos = gDisplayContext->mainGfx;
    temp = D_80073E04;
    gfx_init_state();

    gDPSetDepthImage(gMainGfxPos++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(temp));
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, 0, 0, 0, 0, TEXEL0, 0, 0, 0, 0, 0, 0, 0, TEXEL0);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, 127);
    gDPLoadTextureTile_4b(gMainGfxPos++, D_80073E10, G_IM_FMT_I, 128, 8, 0, 0, 127, 7, 0, G_TX_NOMIRROR | G_TX_WRAP,
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
    D_80073E00 = 1;
    nuContRmbForceStop();
}

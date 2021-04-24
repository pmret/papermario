#include "common.h"
#include "nu/nusys.h"

s16 D_80074010 = 8; // might be an array, could be size 1-8

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void gfx_task_main(void);

extern s32* D_80073E00;
extern s32 D_80073E04;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern s32 D_80073E10;
extern s32* D_8009A680;
extern OSViMode _osViModeNtscLan1;
extern OSViMode _osViModeMPalLan1;

void boot_main(void) {
    OSViMode* viMode;

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
    crash_create_monitor();
    func_80025C60();
    nuGfxInitEX2();
    gGameStatusPtr->contBitPattern = nuContInit();
    func_8002D160();
    func_802B2000();
    func_802B203C();
    nuGfxFuncSet(gfxRetrace_Callback);
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
                void* fb = osViGetCurrentFramebuffer();
                s32* temp_8009A680 = &D_8009A680; // TODO probably the wrong type

                temp_8009A680[2] = fb;
                temp_8009A680[1] = fb;
                temp_8009A680[0] = fb;
                D_80073E04 = fb;
                nuGfxSetCfb(temp_8009A680, 3);
                osViSwapBuffer(*temp_8009A680);
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

INCLUDE_ASM(void, "1370_len_7d0", gfx_task_main);
// void gfx_task_main(void) {
//     s16 temp_t5;
//     s32 temp_a0_3;
//     s32 temp_a0_4;
//     s32 temp_a1_3;
//     s32 temp_a2;
//     s32 temp_a3;
//     s32 temp_a3_2;
//     s32 temp_s0_3;
//     s32 temp_s1_2;
//     s32 temp_s3;
//     s32 temp_t1;
//     s32 temp_t7;
//     s32 temp_v1_4;
//     u32 temp_t0;
//     u32 temp_v0_2;
//     s16 i;

//     gMatrixListPos = 0;
//     gDisplayContext = &D_80164000[gCurrentDisplayContextIndex];
//     gMasterGfxPos = D_80164000[gCurrentDisplayContextIndex].mainGfx;
//     gfx_init_state(gCurrentDisplayContextIndex, &D_80164000);

//     gDPSetDepthImage(gMasterGfxPos++, nuGfxZBuffer + 0x80000000);
//     gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80073E04));
//     gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
//     gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
//     gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
//     gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
//     gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
//     gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
//     gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
//     gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, 0, 0, 0, TEXEL0, 0, 0, 0, 0, 0, 0, 0, COMBINED);
//     gDPSetAlphaCompare(gMasterGfxPos++, G_AC_THRESHOLD);
//     gDPSetBlendColor(gMasterGfxPos++, 0x00, 0x00, 0x00, 0x7F);
//     gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 64, &D_80073E10);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
//                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync(gMasterGfxPos++);
//     gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x00FE, 0x001C);
//     gDPPipeSync(gMasterGfxPos++);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_4b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
//                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x01FC, 0x001C);

//     i = 0;
// loop_1:
//     temp_v1_4 = i * 8;
//     temp_s3 = (((temp_v1_4 + 0xA8) * 4) & 0xFFF) << 0xC;
//     temp_s1_2 = (((temp_v1_4 + 0xA0) * 4) & 0xFFF) << 0xC;
//     temp_s0_3 = (((0xA0 - temp_v1_4) * 4) & 0xFFF) << 0xC;
//     temp_t7 = (((0x98 - temp_v1_4) * 4) & 0xFFF) << 0xC;

// loop_2:
//     temp_a3 = i >> 0x10;
//     temp_v0_2 = 0x21 - ((i + 0xE) - temp_a3);
//     temp_t5 = ((s32) (temp_v0_2 + (temp_v0_2 >> 0x1F)) >> 1) - (D_80074010 - 0xF);

//     if (temp_t5 < 0x10) {
//         if (temp_t5 >= 0) {
//             temp_t1 = temp_a3 * 8;
//             temp_a0_3 = (((temp_t1 + 8) * 4) & 0xFFF) | 0xE4000000;
//             temp_a3_2 = (temp_a3 << 5) & 0xFFF;
//             temp_t0 = temp_t5 << 0x18;

//             temp_a1_2->words.w0 = temp_s3 | temp_a0_3;
//             temp_a1_2->words.w1 = temp_s1_2 | temp_a3_2;
//             temp_v1_6->words.w0 = 0xE1000000;
//             temp_v1_6->words.w1 = temp_t0;


//             temp_a1_3 = (((0xF0 - temp_t1) * 4) & 0xFFF) | 0xE4000000;
//             temp_a2 = ((0xE8 - temp_t1) * 4) & 0xFFF;

//             temp_v1_6->unk10 = (s32) (temp_s3 | temp_a1_3);
//             temp_v1_6->unk14 = (s32) (temp_s1_2 | temp_a2);
//             temp_v1_6->unk18 = 0xE1000000U;
//             temp_v1_6->unk1C = (s32) (temp_t0 | 0xE0);


//             temp_a0_4 = ((temp_t5 << 8) | 0xE0) << 0x10;

//             temp_v1_6->unk28 = (s32) (temp_s0_3 | temp_a0_3);
//             temp_v1_6->unk2C = (s32) (temp_t7 | temp_a3_2);
//             temp_v1_6->unk30 = 0xE1000000U;
//             temp_v1_6->unk34 = temp_a0_4;


//             temp_v1_6->unk40 = (s32) (temp_s0_3 | temp_a1_3);
//             temp_v1_6->unk44 = (s32) (temp_t7 | temp_a2);
//             temp_v1_6->unk48 = 0xE1000000U;
//             temp_v1_6->unk4C = (s32) (temp_a0_4 | 0xE0);


//             gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0, 0, G_TX_RENDERTILE, 0, 0, 0x400, 00400);
//             gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0, 0, G_TX_RENDERTILE, 0, 0, 0x400, -0x400);
//             gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0, 0, G_TX_RENDERTILE, 0, 0, -0x400, 0x400);
//             gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0, 0, G_TX_RENDERTILE, 0, 0, -0x400, -0x400);
//         }
//     }

//     i++;
//     if (i < 15) {
//         goto loop_2;
//     }
//     if (i < 20) {
//         goto loop_1;
//     }

//     D_80074010++;

//     gDPFullSync(gMasterGfxPos++);
//     gSPEndDisplayList(gMasterGfxPos++);

//     nuGfxTaskStart(gDisplayContext->mainGfx, ((gMasterGfxPos - gDisplayContext->mainGfx) >> 3) * 8, 0, 0x40000);
//     gCurrentDisplayContextIndex = gCurrentDisplayContextIndex ^ 1;
// }

void gfxPreNMI_Callback(void) {
    D_80073E00 = 1;
    nuContRmbForceStop();
}

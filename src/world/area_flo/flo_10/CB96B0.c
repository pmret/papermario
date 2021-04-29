#include "flo_10.h"

extern u16* nuGfxZBuffer;

// in no way close at all, may as well start over
// good luck have fun
#ifdef NON_MATCHING
void N(func_802404B0_CB96B0)(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 phi_a3;
    s32 temp_s2_2;
    s32 temp_v0_2;
    s32 temp_a2_3;
    s32 phi_s3;
    s32 phi_s4;
    s32 phi_s5;
    s32 phi_s6;
    s32 phi_s7;
    s32 phi_a2;

    s32 subroutine_arg4;
    s32 subroutine_arg5;
    s32 subroutine_arg6;

    N(D_80244070_CBD270) += 5;
    if ((arg0 < arg2) && (arg1 < arg3)) {
        if (arg0 < 0) {
            phi_s6 = 0;
        } else {
            phi_s6 = arg0;
        }

        if (arg1 < 0) {
            arg1 = 0;
        }

        phi_s4 = arg2;
        if (arg2 < 0) {
            phi_s4 = 0;
        }

        phi_a3 = arg3;
        if (arg3 < 0) {
            phi_a3 = 0;
        }

        if (phi_s6 >= 0x140) {
            phi_s6 = 0x13F;
        }
        if (arg1 >= 0xF0) {
            arg1 = 0xEF;
        }
        if (phi_s4 >= 0x140) {
            phi_s4 = 0x13F;
        }
        if (phi_a3 >= 0xF0) {
            phi_a3 = 0xEF;
        }

        if ((phi_s6 != phi_s4) && (arg1 != phi_a3)) {
            if (phi_s6 < 0) {
                phi_s6 += 3;
            }
            phi_s6 = (phi_s6 >> 2) * 4;

            if (phi_s4 < 0) {
                phi_s4 += 3;
            }
            subroutine_arg5 = phi_s4 / 6;
            subroutine_arg4 = phi_s4 / 6;
            subroutine_arg6 = D_8009A64C;

            for (i = 0; i < subroutine_arg4; i++) {
                phi_s5 = arg1 - ((i + 1) * 6);
                phi_s7 = arg1 + ((i + 1) * 6);

                if (phi_s5 >= 0) {
                    phi_a2 = phi_s5 * 2;
                    if (phi_a2 >= 0x100) {
                        phi_a2 = 0xFF;
                    }

                    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, phi_a2);
                    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(subroutine_arg6));

                    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, (phi_s4 - phi_s6) / 6, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 9, G_TX_NOLOD);
                    gDPLoadSync(gMasterGfxPos++);

                    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, phi_s6 * 4, phi_s5 * 4, (phi_s4 - 1) * 4, (phi_s5 - 1) * 4);

                    gDPPipeSync(gMasterGfxPos++);
                    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, phi_s4 - phi_s6, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 9, G_TX_NOLOD);

                    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, phi_s6 * 4, phi_s5 * 4, (phi_s4 - 1) * 4, (phi_s5 - 1) * 4);

                    gSPTextureRectangle(gMasterGfxPos++,
                            (phi_s4 - 1) * 4, (phi_s5 - 1) * 4, phi_s6 * 4, phi_s5 * 4,
                            G_TX_RENDERTILE,
                            phi_s6, phi_s5,
                            0x0400, (sin_deg(N(D_80244070_CBD270) + (i * 30)) * 500.0f) - 0x1F4);
                }
            }

            if (subroutine_arg5 != 0) {
                temp_s2_2 = arg1 - (i * 6);
                temp_v0_2 = temp_s2_2 - 6;
                temp_a2_3 = temp_v0_2 * 2;
                if (temp_v0_2 >= 0) {
                    phi_a2 = temp_a2_3;
                    if (temp_a2_3 >= 0x100) {
                        phi_a2 = 0xFF;
                    }

                    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, phi_a2);
                    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(subroutine_arg6));
                    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, (phi_s4 - phi_s6) / 6, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 9, G_TX_NOLOD);
                    gDPLoadSync(gMasterGfxPos++);

                    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, phi_s6 * 4, (temp_s2_2 - subroutine_arg5) * 4, (phi_s4 - 1) * 4, (temp_s2_2 - 1) * 4);
                    gDPPipeSync(gMasterGfxPos++);
                    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, (phi_s4 - phi_s6) / 6, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 9, G_TX_NOLOD);
                    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, (phi_s4 - 1) * 4, (temp_s2_2 - subroutine_arg5) * 4, phi_s6 * 4, (temp_s2_2 - subroutine_arg5) * 4);
                    gSPTextureRectangle(gMasterGfxPos++, phi_s6 * 4, arg1 + (i * 6), phi_s4 * 4, ((arg1 + (i * 6)) + subroutine_arg5) * 4, G_TX_RENDERTILE, phi_s6, temp_s2_2, 0x0400, -0x0400);
                }
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_10/CB96B0", flo_10_func_802404B0_CB96B0, s32 arg0, s32 arg1, s32 arg2, s32 arg3);
#endif

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x14];
    /* 0x1C */ s32 unk_1C;
} N(UnkStruct2);

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ N(UnkStruct2)* unk_0C;
} N(UnkStruct);

void N(func_80240A98_CB9C98)(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(0x30));
    // modelNode propertylist? Causes too many derefences and conflicts with the modelNode load below
    N(UnkStruct2)* unk1 = ((N(UnkStruct)*)model->modelNode)->unk_0C;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f20;
    f32 temp_f22;
    s32 test;

    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    sp3C = unk1->unk_04;
    sp38 = unk1->unk_1C;

    transform_point(camera->perspectiveMatrix,
                    model->center[0] - sp3C, model->center[1], model->center[2] - sp38, 1.0f,
                    &sp28, &sp2C, &sp30, &sp34);

    sp28 = sp28 * (1.0f / sp34);
    sp2C = sp2C * -(1.0f / sp34);
    sp30 = sp30 * (1.0f / sp34);
    sp34 = (1.0f / sp34);

    if (sp34 < 0.0f) {
        sp28 = 0.0f;
        sp2C = 1.0f;
    }
    temp_f20 = sp28;
    temp_f22 = sp2C;

    transform_point(camera->perspectiveMatrix,
                    model->center[0] - sp3C, model->center[1], model->center[2] + sp38, 1.0f,
                    &sp28, &sp2C, &sp30, &sp34);

    sp28 = sp28 * (1.0f / sp34);
    sp2C = sp2C * -(1.0f / sp34);
    sp30 = sp30 * (1.0f / sp34);
    sp34 = 1.0f / sp34;

    temp_f24 = temp_f20;
    temp_f26 = temp_f22;
    if (sp34 < 0.0f) {
        sp28 = 0.0f;
        sp2C = 1.0f;
    }

    if (sp28 < temp_f20) {
        temp_f24 = sp28;
    }

    if (sp2C < temp_f22) {
        temp_f26 = sp2C;
    }

    if (temp_f20 < sp28) {
        temp_f20 = sp28;
    }

    if (temp_f22 < sp2C) {
        temp_f22 = sp2C;
    }

    transform_point(camera->perspectiveMatrix,
                    model->center[0] + sp3C, model->center[1], model->center[2] + sp38, 1.0f,
                    &sp28, &sp2C, &sp30, &sp34);

    sp28 = sp28 * (1.0f / sp34);
    sp2C = sp2C * -(1.0f / sp34);
    sp30 = sp30 * (1.0f / sp34);
    sp34 = (1.0f / sp34);

    if (sp34 < 0.0f) {
        sp28 = 1.0f;
        sp2C = 1.0f;
    }

    if (sp28 < temp_f24) {
        temp_f24 = sp28;
    }

    if (sp2C < temp_f26) {
        temp_f26 = sp2C;
    }

    if (temp_f20 < sp28) {
        temp_f20 = sp28;
    }

    if (temp_f22 < sp2C) {
        temp_f22 = sp2C;
    }

    transform_point(camera->perspectiveMatrix,
                    model->center[0] + sp3C, model->center[1], model->center[2] - sp38, 1.0f,
                    &sp28, &sp2C, &sp30, &sp34);

    sp28 = sp28 * (1.0f / sp34);
    sp2C = sp2C * -(1.0f / sp34);
    sp30 = sp30 * (1.0f / sp34);
    sp34 = (1.0f / sp34);

    if (sp34 < 0.0f) {
        sp28 = 1.0f;
        sp2C = 1.0f;
    }

    if (sp28 < temp_f24) {
        temp_f24 = sp28;
    }

    if (sp2C < temp_f26) {
        temp_f26 = sp2C;
    }

    if (temp_f20 < sp28) {
        temp_f20 = sp28;
    }

    if (temp_f22 < sp2C) {
        temp_f22 = sp2C;
    }

    if ((temp_f24 != temp_f20) || (temp_f26 != temp_f22)) {
        temp_f24 = ((temp_f24 * camera->viewportW) + camera->viewportW) * 0.5f;
        temp_f26 = ((temp_f26 * camera->viewportH) + camera->viewportH) * 0.5f;
        temp_f20 = ((temp_f20 * camera->viewportW) + camera->viewportW) * 0.5f;
        temp_f22 = ((temp_f22 * camera->viewportH) + camera->viewportH) * 0.5f;

        temp_f24 += camera->viewportStartX;
        temp_f26 += camera->viewportStartY;
        temp_f20 += camera->viewportStartX;
        temp_f22 += camera->viewportStartY;

        gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
        gDPSetRenderMode(gMasterGfxPos++, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(nuGfxZBuffer));
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 248, 240, 240, 0);
        gDPPipeSync(gMasterGfxPos++);

        gSPDisplayList(gMasterGfxPos++, model->modelNode[1]->type);
        gDPPipeSync(gMasterGfxPos++);

        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_8009A64C));
        gDPSetDepthSource(gMasterGfxPos++, G_ZS_PRIM);
        gDPSetPrimDepth(gMasterGfxPos++, 32734, 0);
        gDPSetRenderMode(gMasterGfxPos++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
        gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
        gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
        gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        gDPPipeSync(gMasterGfxPos++);

        N(func_802404B0_CB96B0)(temp_f24, temp_f26, temp_f20, temp_f22);

        gDPPipeSync(gMasterGfxPos++);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
        gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
    }
}

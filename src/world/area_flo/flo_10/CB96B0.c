#include "flo_10.h"
#include "nu/nusys.h"
#include "model.h"

void N(func_802404B0_CB96B0)(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
INCLUDE_ASM(void, "world/area_flo/flo_10/CB96B0", flo_10_func_802404B0_CB96B0);

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
                    model->center.x - sp3C, model->center.y, model->center.z - sp38, 1.0f,
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
                    model->center.x - sp3C, model->center.y, model->center.z + sp38, 1.0f,
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
                    model->center.x + sp3C, model->center.y, model->center.z + sp38, 1.0f,
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
                    model->center.x + sp3C, model->center.y, model->center.z - sp38, 1.0f,
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
        gDPSetRenderMode(gMasterGfxPos++, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                         Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxZBuffer));
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 248, 240, 240, 0);
        gDPPipeSync(gMasterGfxPos++);

        gSPDisplayList(gMasterGfxPos++, model->modelNode->displayData->displayList);
        gDPPipeSync(gMasterGfxPos++);

        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
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

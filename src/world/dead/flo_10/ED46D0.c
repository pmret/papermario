#include "flo_10.h"

#include "nu/nusys.h"
#include "model.h"

// rodata
extern char D_80244BB8_ED8DD8[];
extern char D_80244BEC_ED8E0C[];

void N(UnkModelFunc000)(s32, s32, s32, s32);
INCLUDE_ASM(s32, "ED46D0", ED46D0_UnkModelFunc000);

s32 func_80066FE0(u16*);

// Similar to the flo_10 counterpart but contains debug code
void N(UnkModelFunc001)(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(0x30));
    ModelBoundingBox* bb = (ModelBoundingBox*) model->modelNode->propertyList;
    f32 bbHalfX = bb->halfSizeX;
    f32 bbHalfZ = bb->halfSizeZ;
    f32 outX, outY, outZ, outS;
    Gfx* new_var;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f20;
    f32 temp_f22;

    transform_point(camera->perspectiveMatrix,
                    model->center.x - bbHalfX, model->center.y, model->center.z - bbHalfZ, 1.0f,
                    &outX, &outY, &outZ, &outS);

    outX *= 1.0f / outS;
    outY *= -(1.0f / outS);
    outZ *= 1.0f / outS;
    outS = 1.0f / outS;

    if (outS < 0.0f) {
        outX = 0.0f;
        outY = 1.0f;
    }
    temp_f20 = outX;
    temp_f22 = outY;

    transform_point(camera->perspectiveMatrix,
                    model->center.x - bbHalfX, model->center.y, model->center.z + bbHalfZ, 1.0f,
                    &outX, &outY, &outZ, &outS);

    outX *= 1.0f / outS;
    outY *= -(1.0f / outS);
    outZ *= 1.0f / outS;
    outS = 1.0f / outS;

    temp_f24 = temp_f20;
    temp_f26 = temp_f22;
    if (outS < 0.0f) {
        outX = 0.0f;
        outY = 1.0f;
    }

    if (temp_f24 > outX) {
        temp_f24 = outX;
    }

    if (temp_f26 > outY) {
        temp_f26 = outY;
    }

    if (temp_f20 < outX) {
        temp_f20 = outX;
    }

    if (temp_f22 < outY) {
        temp_f22 = outY;
    }

    transform_point(camera->perspectiveMatrix,
                    model->center.x + bbHalfX, model->center.y, model->center.z + bbHalfZ, 1.0f,
                    &outX, &outY, &outZ, &outS);

    outX *= 1.0f / outS;
    outY *= -(1.0f / outS);
    outZ *= 1.0f / outS;
    outS = 1.0f / outS;

    if (outS < 0.0f) {
        outX = 1.0f;
        outY = 1.0f;
    }

    if (temp_f24 > outX) {
        temp_f24 = outX;
    }

    if (temp_f26 > outY) {
        temp_f26 = outY;
    }

    if (temp_f20 < outX) {
        temp_f20 = outX;
    }

    if (temp_f22 < outY) {
        temp_f22 = outY;
    }

    transform_point(camera->perspectiveMatrix,
                    model->center.x + bbHalfX, model->center.y, model->center.z - bbHalfZ, 1.0f,
                    &outX, &outY, &outZ, &outS);

    outX *= 1.0f / outS;
    outY *= -(1.0f / outS);
    outZ *= 1.0f / outS;
    outS = 1.0f / outS;

    if (outS < 0.0f) {
        outX = 1.0f;
        outY = 1.0f;
    }

    if (temp_f24 > outX) {
        temp_f24 = outX;
    }

    if (temp_f26 > outY) {
        temp_f26 = outY;
    }

    if (temp_f20 < outX) {
        temp_f20 = outX;
    }

    if (temp_f22 < outY) {
        temp_f22 = outY;
    }

    if (temp_f24 != temp_f20 || temp_f26 != temp_f22) {
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

        new_var = gMasterGfxPos++;
        if ((func_80066FE0(nuGfxZBuffer) % 8) != 0) {
            osSyncPrintf(D_80244BB8_ED8DD8, D_80244BEC_ED8E0C, 175, func_80066FE0(nuGfxZBuffer));
        }
        gDPSetColorImage(new_var, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxZBuffer));

        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 248, 240, 240, 0);
        gDPPipeSync(gMasterGfxPos++);

        gSPDisplayList(gMasterGfxPos++, model->modelNode->displayData->displayList);
        gDPPipeSync(gMasterGfxPos++);

        new_var = gMasterGfxPos++;
        if ((func_80066FE0(nuGfxCfb_ptr) % 8) != 0) {
            osSyncPrintf(D_80244BB8_ED8DD8, D_80244BEC_ED8E0C, 186, func_80066FE0(nuGfxCfb_ptr));
        }
        gDPSetColorImage(new_var, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));

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

        N(UnkModelFunc000)(temp_f24, temp_f26, temp_f20, temp_f22);

        gDPPipeSync(gMasterGfxPos++);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
        gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
    }
}

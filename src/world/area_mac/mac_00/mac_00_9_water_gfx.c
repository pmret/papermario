#include "mac_00.h"
#include "model.h"

MAP_RODATA_PAD(1,unk);

void N(gfx_build_water)(void) {
    Model* model;

    gDPSetDepthSource(gMainGfxPos++, G_ZS_PRIM);
    gDPSetPrimDepth(gMainGfxPos++, 0x7FF0, 0);
    gDPSetRenderMode(gMainGfxPos++, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS,
            Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
    gDPSetCombineMode(gMainGfxPos++, PM_CC_PRIM_NO_ALPHA, PM_CC_PRIM_NO_ALPHA);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 128, 0);
    gDPPipeSync(gMainGfxPos++);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_water));

    gSPDisplayList(gMainGfxPos++, model->modelNode->displayData->displayList);
    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
    gDPSetDepthSource(gMainGfxPos++, G_ZS_PIXEL);
    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    mdl_draw_hidden_panel_surface(&gMainGfxPos, MODEL_water);
}

EvtScript N(EVS_SetupWaterCustomGfx) = {
    Wait(1)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(gfx_build_water)), NULL)
    Call(SetModelCustomGfx, MODEL_water, CUSTOM_GFX_0, -1)
    Return
    End
};

#include "mac_00.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

#include "model.h"

void func_802423F0_7ED100(void) {
    Model* model;

    gDPSetDepthSource(gMasterGfxPos++, G_ZS_PRIM);
    gDPSetPrimDepth(gMasterGfxPos++, 32752, 0);
    gDPSetRenderMode(gMasterGfxPos++, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                     Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 128, 0);
    gDPPipeSync(gMasterGfxPos++);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(0xD6));

    gSPDisplayList(gMasterGfxPos++, model->modelNode->displayData->displayList);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    mdl_draw_hidden_panel_surface(&gMasterGfxPos, 0xD6);
}

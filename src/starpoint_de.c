#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 starpoint_lights1_de = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("de/starpoint/starpoint.png", D_PAL_802ABC98_81B048);
#include "de/starpoint/load_starpoint.gfx.inc.c"
#include "de/starpoint/starpoint.vtx.inc.c"

Gfx D_PAL_802ACD50_81C100[] = {
    gsSPSetLights1(starpoint_lights1_de),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACC98_81C048),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ACD10_81C0C0[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDB0_81C160[] = {
    gsSPSetLights1(starpoint_lights1_de),
    gsSPDisplayList(D_PAL_802ACD50_81C100),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDD8_81C188[] = {
    gsSPSetLights1(starpoint_lights1_de),
    gsSPDisplayList(D_PAL_802ACDB0_81C160),
    gsSPEndDisplayList(),
};

Lights1 starpoint_lights2_de = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("de/starpoint/starpoints.png", D_PAL_802ACE18_81C1C8);
#include "de/starpoint/load_starpoints.gfx.inc.c"
#include "de/starpoint/starpoints.vtx.inc.c"

Gfx D_PAL_802ADED0_81D280[] = {
    gsSPSetLights1(starpoint_lights2_de),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADE18_81D1C8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ADE90_81D240[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF30_81D2E0[] = {
    gsSPSetLights1(starpoint_lights2_de),
    gsSPDisplayList(D_PAL_802ADED0_81D280),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF58_81D308[] = {
    gsSPSetLights1(starpoint_lights2_de),
    gsSPDisplayList(D_PAL_802ADF30_81D2E0),
    gsSPEndDisplayList(),
};


EntityModelScript EMS_starpoint_starpoint_de = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ACDD8_81C188, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_starpoints_de = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ADF58_81D308, RENDER_MODE_CLOUD_NO_ZCMP);

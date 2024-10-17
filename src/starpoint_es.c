#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 starpoint_lights1_es = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("es/starpoint/starpoint.png", D_PAL_802ABC98_81F6C8);
#include "es/starpoint/load_starpoint.gfx.inc.c"
#include "es/starpoint/starpoint.vtx.inc.c"

Gfx D_PAL_802ACD50_820780[] = {
    gsSPSetLights1(starpoint_lights1_es),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACC98_8206C8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ACD10_820740[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDB0_8207E0[] = {
    gsSPSetLights1(starpoint_lights1_es),
    gsSPDisplayList(D_PAL_802ACD50_820780),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDD8_820808[] = {
    gsSPSetLights1(starpoint_lights1_es),
    gsSPDisplayList(D_PAL_802ACDB0_8207E0),
    gsSPEndDisplayList(),
};

Lights1 starpoint_lights2_es = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("es/starpoint/starpoints.png", D_PAL_802ACE18_820848);
#include "es/starpoint/load_starpoints.gfx.inc.c"
#include "es/starpoint/starpoints.vtx.inc.c"

Gfx D_PAL_802ADED0_821900[] = {
    gsSPSetLights1(starpoint_lights2_es),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADE18_821848),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ADE90_8218C0[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF30_821960[] = {
    gsSPSetLights1(starpoint_lights2_es),
    gsSPDisplayList(D_PAL_802ADED0_821900),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF58_821988[] = {
    gsSPSetLights1(starpoint_lights2_es),
    gsSPDisplayList(D_PAL_802ADF30_821960),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_starpoint_starpoint_es = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ACDD8_820808, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_starpoints_es = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ADF58_821988, RENDER_MODE_CLOUD_NO_ZCMP);

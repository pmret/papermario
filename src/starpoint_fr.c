#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 starpoint_lights1_fr = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("fr/starpoint/starpoint.png", D_PAL_802ABC98_81D388);
#include "fr/starpoint/load_starpoint.gfx.inc.c"
#include "fr/starpoint/starpoint.vtx.inc.c"

Gfx D_PAL_802ACD50_81E440[] = {
    gsSPSetLights1(starpoint_lights1_fr),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACC98_81E388),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ACD10_81E400[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDB0_81E4A0[] = {
    gsSPSetLights1(starpoint_lights1_fr),
    gsSPDisplayList(D_PAL_802ACD50_81E440),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDD8_81E4C8[] = {
    gsSPSetLights1(starpoint_lights1_fr),
    gsSPDisplayList(D_PAL_802ACDB0_81E4A0),
    gsSPEndDisplayList(),
};

Lights1 starpoint_lights2_fr = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("fr/starpoint/starpoints.png", D_PAL_802ACE18_81E508);
#include "fr/starpoint/load_starpoints.gfx.inc.c"
#include "fr/starpoint/starpoints.vtx.inc.c"

Gfx D_PAL_802ADED0_81F5C0[] = {
    gsSPSetLights1(starpoint_lights2_fr),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADE18_81F508),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802ADE90_81F580[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF30_81F620[] = {
    gsSPSetLights1(starpoint_lights2_fr),
    gsSPDisplayList(D_PAL_802ADED0_81F5C0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF58_81F648[] = {
    gsSPSetLights1(starpoint_lights2_fr),
    gsSPDisplayList(D_PAL_802ADF30_81F620),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_starpoint_starpoint_fr = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ACDD8_81E4C8, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_starpoints_fr = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ADF58_81F648, RENDER_MODE_CLOUD_NO_ZCMP);

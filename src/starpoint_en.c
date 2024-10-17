#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 starpoint_lights1 = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

INCLUDE_IMG("starpoint/starpoint.png", D_802A1018_7A89B8);
#include "starpoint/load_starpoint.gfx.inc.c"
#include "starpoint/starpoint.vtx.inc.c"
Gfx D_802A20D0_7A9A70[] = {
    gsSPSetLights1(starpoint_lights1),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A2018_7A99B8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_802A2090_7A9A30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
Gfx D_802A2130_7A9AD0[] = {
    gsSPSetLights1(starpoint_lights1),
    gsSPDisplayList(D_802A20D0_7A9A70),
    gsSPEndDisplayList(),
};
Gfx D_802A2158_7A9AF8[] = {
    gsSPSetLights1(starpoint_lights1),
    gsSPDisplayList(D_802A2130_7A9AD0),
    gsSPEndDisplayList(),
};

Lights1 starpoint_lights2 = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);
#include "starpoint/starpoints.vtx.inc.c"
INCLUDE_IMG("starpoint/starpoints.png", D_802A21D8_7A9B78);
#include "starpoint/load_starpoints.gfx.inc.c"

Gfx D_802A3250_7AABF0[] = {
    gsSPSetLights1(starpoint_lights2),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A31D8_7AAB78),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_802A2198_7A9B38, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
Gfx D_802A32B0_7AAC50[] = {
    gsSPSetLights1(starpoint_lights2),
    gsSPDisplayList(D_802A3250_7AABF0),
    gsSPEndDisplayList(),
};
Gfx D_802A32D8_7AAC78[] = {
    gsSPSetLights1(starpoint_lights2),
    gsSPDisplayList(D_802A32B0_7AAC50),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_starpoint_starpoint = STANDARD_ENTITY_MODEL_SCRIPT(D_802A2158_7A9AF8, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_starpoints = STANDARD_ENTITY_MODEL_SCRIPT(D_802A32D8_7AAC78, RENDER_MODE_CLOUD_NO_ZCMP);

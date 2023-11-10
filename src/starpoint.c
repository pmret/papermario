#include "common.h"
#include "entity.h"

Lights1 starpoint_lights1 = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);
#include "starpoint/starpoint.png.inc.c"
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
#include "starpoint/starpoints.png.inc.c"
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

#include "starpoint/digit_0.vtx.inc.c"
#include "starpoint/digit_0.png.inc.c"
#include "starpoint/load_digit_0.gfx.inc.c"
#include "starpoint/__render_digit_0.gfx.inc.c"
#include "starpoint/_render_digit_0.gfx.inc.c"
#include "starpoint/render_digit_0.gfx.inc.c"

#include "starpoint/digit_1.vtx.inc.c"
#include "starpoint/digit_1.png.inc.c"
#include "starpoint/load_digit_1.gfx.inc.c"
#include "starpoint/__render_digit_1.gfx.inc.c"
#include "starpoint/_render_digit_1.gfx.inc.c"
#include "starpoint/render_digit_1.gfx.inc.c"

#include "starpoint/digit_2.vtx.inc.c"
#include "starpoint/digit_2.png.inc.c"
#include "starpoint/load_digit_2.gfx.inc.c"
#include "starpoint/__render_digit_2.gfx.inc.c"
#include "starpoint/_render_digit_2.gfx.inc.c"
#include "starpoint/render_digit_2.gfx.inc.c"

#include "starpoint/digit_3.vtx.inc.c"
#include "starpoint/digit_3.png.inc.c"
#include "starpoint/load_digit_3.gfx.inc.c"
#include "starpoint/__render_digit_3.gfx.inc.c"
#include "starpoint/_render_digit_3.gfx.inc.c"
#include "starpoint/render_digit_3.gfx.inc.c"

#include "starpoint/digit_4.vtx.inc.c"
#include "starpoint/digit_4.png.inc.c"
#include "starpoint/load_digit_4.gfx.inc.c"
#include "starpoint/__render_digit_4.gfx.inc.c"
#include "starpoint/_render_digit_4.gfx.inc.c"
#include "starpoint/render_digit_4.gfx.inc.c"

#include "starpoint/digit_5.vtx.inc.c"
#include "starpoint/digit_5.png.inc.c"
#include "starpoint/load_digit_5.gfx.inc.c"
#include "starpoint/__render_digit_5.gfx.inc.c"
#include "starpoint/_render_digit_5.gfx.inc.c"
#include "starpoint/render_digit_5.gfx.inc.c"

#include "starpoint/digit_6.vtx.inc.c"
#include "starpoint/digit_6.png.inc.c"
#include "starpoint/load_digit_6.gfx.inc.c"
#include "starpoint/__render_digit_6.gfx.inc.c"
#include "starpoint/_render_digit_6.gfx.inc.c"
#include "starpoint/render_digit_6.gfx.inc.c"

#include "starpoint/digit_7.vtx.inc.c"
#include "starpoint/digit_7.png.inc.c"
#include "starpoint/load_digit_7.gfx.inc.c"
#include "starpoint/__render_digit_7.gfx.inc.c"
#include "starpoint/_render_digit_7.gfx.inc.c"
#include "starpoint/render_digit_7.gfx.inc.c"

#include "starpoint/digit_8.vtx.inc.c"
#include "starpoint/digit_8.png.inc.c"
#include "starpoint/load_digit_8.gfx.inc.c"
#include "starpoint/__render_digit_8.gfx.inc.c"
#include "starpoint/_render_digit_8.gfx.inc.c"
#include "starpoint/render_digit_8.gfx.inc.c"

#include "starpoint/digit_9.vtx.inc.c"
#include "starpoint/digit_9.png.inc.c"
#include "starpoint/load_digit_9.gfx.inc.c"
#include "starpoint/__render_digit_9.gfx.inc.c"
#include "starpoint/_render_digit_9.gfx.inc.c"
#include "starpoint/render_digit_9.gfx.inc.c"

EntityModelScript EMS_starpoint_starpoint = STANDARD_ENTITY_MODEL_SCRIPT(D_802A2158_7A9AF8, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_starpoints = STANDARD_ENTITY_MODEL_SCRIPT(D_802A32D8_7AAC78, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_0 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A4410_7ABDB0, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_1 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A5530_7ACED0, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_2 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A6650_7ADFF0, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_3 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A7770_7AF110, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_4 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A8890_7B0230, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_5 = STANDARD_ENTITY_MODEL_SCRIPT(D_802A99B0_7B1350, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_6 = STANDARD_ENTITY_MODEL_SCRIPT(D_802AAAD0_7B2470, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_7 = STANDARD_ENTITY_MODEL_SCRIPT(D_802ABBF0_7B3590, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_8 = STANDARD_ENTITY_MODEL_SCRIPT(D_802ACD10_7B46B0, RENDER_MODE_CLOUD_NO_ZCMP);
EntityModelScript EMS_starpoint_digit_9 = STANDARD_ENTITY_MODEL_SCRIPT(D_802ADE30_7B57D0, RENDER_MODE_CLOUD_NO_ZCMP);

Gfx D_802ADF90_7B5930[] = {
    gsSPEndDisplayList(),
};
EntityModelScript EMS_starpoint_dummy = STANDARD_ENTITY_MODEL_SCRIPT(D_802ADF90_7B5930, RENDER_MODE_CLOUD_NO_ZCMP);

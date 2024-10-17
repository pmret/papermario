#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 level_up_letters_en_de_lights = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

#include "level_up/draw_second_E.vtx.inc.c"
#include "level_up/draw_V.vtx.inc.c"
#include "level_up/draw_E.vtx.inc.c"
#include "level_up/draw_second_L.vtx.inc.c"
#include "level_up/draw_L.vtx.inc.c"
#include "level_up/draw_P.vtx.inc.c"
#include "level_up/draw_U.vtx.inc.c"
#include "level_up/draw_exclamation_mark.vtx.inc.c"

INCLUDE_IMG("level_up/big_V.png", D_PAL_802A6838_7F8418);
#include "level_up/big_V.gfx.inc.c"
INCLUDE_IMG("level_up/big_P.png", D_PAL_802A78B0_7F9490);
#include "level_up/big_P.gfx.inc.c"
INCLUDE_IMG("level_up/big_exclamation_mark.png", D_PAL_802A8928_7FA508);
#include "level_up/big_exclamation_mark.gfx.inc.c"
INCLUDE_IMG("level_up/big_U.png", D_PAL_802A99A0_7FB580);
#include "level_up/big_U.gfx.inc.c"
INCLUDE_IMG("level_up/big_L.png", D_PAL_802AAA18_7FC5F8);
#include "level_up/big_L.gfx.inc.c"
INCLUDE_IMG("level_up/big_E.png", D_PAL_802ABA90_7FD670);
#include "level_up/big_E.gfx.inc.c"

Gfx D_PAL_802ACB08_7FE6E8[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A9928_7FB508),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A67B8_7F8398[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACB70_7FE750[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AA9A0_7FC580),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6738_7F8318[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACBD8_7FE7B8[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A88B0_7FA490),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A66B8_7F8298[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACC40_7FE820[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ABA18_7FD5F8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6638_7F8218[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACCA8_7FE888[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ABA18_7FD5F8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A65B8_7F8198[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACD10_7FE8F0[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACA90_7FE670),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6538_7F8118[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACD78_7FE958[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A7838_7F9418),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A64B8_7F8098[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACDE0_7FE9C0[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACA90_7FE670),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6438_7F8018[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACE48_7FEA28[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsSPDisplayList(D_PAL_802ACDE0_7FE9C0),
    gsSPDisplayList(D_PAL_802ACD78_7FE958),
    gsSPDisplayList(D_PAL_802ACD10_7FE8F0),
    gsSPDisplayList(D_PAL_802ACCA8_7FE888),
    gsSPDisplayList(D_PAL_802ACC40_7FE820),
    gsSPDisplayList(D_PAL_802ACBD8_7FE7B8),
    gsSPDisplayList(D_PAL_802ACB70_7FE750),
    gsSPDisplayList(D_PAL_802ACB08_7FE6E8),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ACEA8_7FEA88[] = {
    gsSPSetLights1(level_up_letters_en_de_lights),
    gsSPDisplayList(D_PAL_802ACE48_7FEA28),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_level_up_en_de = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ACEA8_7FEA88, RENDER_MODE_CLOUD_NO_ZCMP);

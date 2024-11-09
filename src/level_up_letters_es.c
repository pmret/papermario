#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 level_up_letters_es_lights = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

#include "es/level_up/draw_UB.vtx.inc.c"
#include "es/level_up/draw_ES.vtx.inc.c"
#include "es/level_up/draw_UN.vtx.inc.c"
#include "es/level_up/draw_inverted_excl_mark_S.vtx.inc.c"
#include "es/level_up/draw_NI.vtx.inc.c"
#include "es/level_up/draw_L_exclamation_mark.vtx.inc.c"
#include "es/level_up/draw_VE.vtx.inc.c"

INCLUDE_IMG("es/level_up/big_inverted_excl_mark_S.png", D_PAL_802A67B8_8069A8);
#include "es/level_up/big_inverted_excl_mark_S.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_UB.png", D_PAL_802A7830_807A20);
#include "es/level_up/big_UB.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_ES.png", D_PAL_802A88A8_808A98);
#include "es/level_up/big_ES.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_UN.png", D_PAL_802A9920_809B10);
#include "es/level_up/big_UN.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_NI.png", D_PAL_802AA998_80AB88);
#include "es/level_up/big_NI.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_VE.png", D_PAL_802ABA10_80BC00);
#include "es/level_up/big_VE.gfx.inc.c"
INCLUDE_IMG("es/level_up/big_L_exclamation_mark.png", D_PAL_802ACA88_80CC78);
#include "es/level_up/big_L_exclamation_mark.gfx.inc.c"

Gfx D_PAL_802ADB00_80DCF0[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ACA10_80CC00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6738_806928[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADB68_80DD58[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADA88_80DC78),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A66B8_8068A8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADBD0_80DDC0[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AB998_80BB88),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6638_806828[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADC38_80DE28[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A77B8_8079A8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A65B8_8067A8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADCA0_80DE90[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AA920_80AB10),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6538_806728[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADD08_80DEF8[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A98A8_809A98),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A64B8_8066A8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADD70_80DF60[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802A8830_808A20),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6438_806628[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADDD8_80DFC8[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsSPDisplayList(D_PAL_802ADD70_80DF60),
    gsSPDisplayList(D_PAL_802ADD08_80DEF8),
    gsSPDisplayList(D_PAL_802ADCA0_80DE90),
    gsSPDisplayList(D_PAL_802ADC38_80DE28),
    gsSPDisplayList(D_PAL_802ADBD0_80DDC0),
    gsSPDisplayList(D_PAL_802ADB68_80DD58),
    gsSPDisplayList(D_PAL_802ADB00_80DCF0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADE30_80E020[] = {
    gsSPSetLights1(level_up_letters_es_lights),
    gsSPDisplayList(D_PAL_802ADDD8_80DFC8),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_level_up_es = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ADE30_80E020, RENDER_MODE_CLOUD_NO_ZCMP);

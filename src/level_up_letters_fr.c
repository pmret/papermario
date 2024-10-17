#include "common.h"
#include "entity.h"
#include "include_asset.h"

Lights1 level_up_letters_fr_lights = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

#include "fr/level_up/draw_NI.vtx.inc.c"
#include "fr/level_up/draw_VE.vtx.inc.c"
#include "fr/level_up/draw_AU.vtx.inc.c"
#include "fr/level_up/draw_SU.vtx.inc.c"
#include "fr/level_up/draw_PE.vtx.inc.c"
#include "fr/level_up/draw_RI.vtx.inc.c"
#include "fr/level_up/draw_EU.vtx.inc.c"
#include "fr/level_up/draw_R_exclamation_mark.vtx.inc.c"
INCLUDE_IMG("fr/level_up/big_NI.png", D_PAL_802A6838_7FEEE8);
INCLUDE_IMG("fr/level_up/big_VE.png", D_PAL_802A75B8_7FFC68);
INCLUDE_IMG("fr/level_up/big_AU.png", D_PAL_802A82B8_800968);
INCLUDE_IMG("fr/level_up/big_SU.png", D_PAL_802A9078_801728);
INCLUDE_IMG("fr/level_up/big_RI.png", D_PAL_802A9E38_8024E8);
INCLUDE_IMG("fr/level_up/big_EU.png", D_PAL_802AABF8_8032A8);
INCLUDE_IMG("fr/level_up/big_R_exclamation_mark.png", D_PAL_802AB9B8_804068);
INCLUDE_IMG("fr/level_up/big_PE.png", D_PAL_802AC7B8_804E68);
#include "fr/level_up/big_NI.gfx.inc.c"
#include "fr/level_up/big_VE.gfx.inc.c"
#include "fr/level_up/big_AU.gfx.inc.c"
#include "fr/level_up/big_SU.gfx.inc.c"
#include "fr/level_up/big_PE.gfx.inc.c"
#include "fr/level_up/big_RI.gfx.inc.c"
#include "fr/level_up/big_EU.gfx.inc.c"
#include "fr/level_up/big_R_exclamation_mark.gfx.inc.c"

Gfx D_PAL_802ADB78_806228[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADB00_8061B0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A67B8_7FEE68[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADBE0_806290[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADA88_806138),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6738_7FEDE8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADC48_8062F8[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802ADA10_8060C0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A66B8_7FED68[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADCB0_806360[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AD998_806048),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6638_7FECE8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADD18_8063C8[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AD920_805FD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A65B8_7FEC68[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADD80_806430[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AD8A8_805F58),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6538_7FEBE8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADDE8_806498[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AD830_805EE0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A64B8_7FEB68[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADE50_806500[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_PAL_802AD7B8_805E68),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_PAL_802A6438_7FEAE8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADEB8_806568[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsSPDisplayList(D_PAL_802ADE50_806500),
    gsSPDisplayList(D_PAL_802ADDE8_806498),
    gsSPDisplayList(D_PAL_802ADD80_806430),
    gsSPDisplayList(D_PAL_802ADD18_8063C8),
    gsSPDisplayList(D_PAL_802ADCB0_806360),
    gsSPDisplayList(D_PAL_802ADC48_8062F8),
    gsSPDisplayList(D_PAL_802ADBE0_806290),
    gsSPDisplayList(D_PAL_802ADB78_806228),
    gsSPEndDisplayList(),
};

Gfx D_PAL_802ADF18_8065C8[] = {
    gsSPSetLights1(level_up_letters_fr_lights),
    gsSPDisplayList(D_PAL_802ADEB8_806568),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_level_up_fr = STANDARD_ENTITY_MODEL_SCRIPT(D_PAL_802ADF18_8065C8, RENDER_MODE_CLOUD_NO_ZCMP);

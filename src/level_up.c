#include "common.h"
#include "hud_element.h"
#include "entity.h"

Lights1 level_up_lights = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

#include "level_up/draw_second_E.vtx.inc.c"
#include "level_up/draw_V.vtx.inc.c"
#include "level_up/draw_E.vtx.inc.c"
#include "level_up/draw_second_L.vtx.inc.c"
#include "level_up/draw_L.vtx.inc.c"
#include "level_up/draw_P.vtx.inc.c"
#include "level_up/draw_U.vtx.inc.c"
#include "level_up/draw_exclamation_mark.vtx.inc.c"

#include "level_up/big_V.png.inc.c"
#include "level_up/big_V.gfx.inc.c"
#include "level_up/big_P.png.inc.c"
#include "level_up/big_P.gfx.inc.c"
#include "level_up/big_exclamation_mark.png.inc.c"
#include "level_up/big_exclamation_mark.gfx.inc.c"
#include "level_up/big_U.png.inc.c"
#include "level_up/big_U.gfx.inc.c"
#include "level_up/big_L.png.inc.c"
#include "level_up/big_L.gfx.inc.c"
#include "level_up/big_E.png.inc.c"
#include "level_up/big_E.gfx.inc.c"

Gfx D_802A76E8_7A5628[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A4508_7A2448),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
#if VERSION_IQUE
    gsSPVertex(&D_802A1218_79F158[0], 8, 0),
#else
    gsSPVertex(&D_802A1398_79F2D8[0], 8, 0),
#endif
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A7750_7A5690[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A5580_7A34C0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1318_79F258[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A77B8_7A56F8[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A3490_7A13D0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1298_79F1D8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A7820_7A5760[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A65F8_7A4538),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1218_79F158[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A7888_7A57C8[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A65F8_7A4538),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
#if VERSION_IQUE
    gsSPVertex(&D_802A1098_79EFD8[0], 8, 0),
#else
    gsSPVertex(&D_802A1198_79F0D8[0], 8, 0),
#endif
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A78F0_7A5830[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A7670_7A55B0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1118_79F058[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A7958_7A5898[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A2418_7A0358),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1098_79EFD8[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A79C0_7A5900[] = {
    gsSPSetLights1(level_up_lights),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPDisplayList(D_802A7670_7A55B0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1018_79EF58[0], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_802A7A28_7A5968[] = {
    gsSPSetLights1(level_up_lights),
#if !VERSION_IQUE
    gsSPDisplayList(D_802A79C0_7A5900),
    gsSPDisplayList(D_802A7958_7A5898),
#endif
    gsSPDisplayList(D_802A78F0_7A5830),
    gsSPDisplayList(D_802A7888_7A57C8),
#if !VERSION_IQUE
    gsSPDisplayList(D_802A7820_7A5760),
    gsSPDisplayList(D_802A77B8_7A56F8),
    gsSPDisplayList(D_802A7750_7A5690),
#endif
    gsSPDisplayList(D_802A76E8_7A5628),
    gsSPEndDisplayList(),
};

Gfx D_802A7A88_7A59C8[] = {
    gsSPSetLights1(level_up_lights),
    gsSPDisplayList(D_802A7A28_7A5968),
    gsSPEndDisplayList(),
};

#include "level_up/heart.png.inc.c"
#include "level_up/heart.pal.inc.c"
#include "level_up/flower.png.inc.c"
#include "level_up/flower.pal.inc.c"
#include "level_up/leaves.png.inc.c"
#include "level_up/leaves.pal.inc.c"
#include "level_up/badge.png.inc.c"
#include "level_up/badge.pal.inc.c"
#include "level_up/FP.png.inc.c"
#include "level_up/FP.pal.inc.c"
#include "level_up/BP.png.inc.c"
#include "level_up/BP.pal.inc.c"
#include "level_up/HP.png.inc.c"
#include "level_up/HP.pal.inc.c"

#include "level_up/digit_0.png.inc.c"
#include "level_up/digit_0.pal.inc.c"
#include "level_up/digit_1.png.inc.c"
#include "level_up/digit_1.pal.inc.c"
#include "level_up/digit_2.png.inc.c"
#include "level_up/digit_2.pal.inc.c"
#include "level_up/digit_3.png.inc.c"
#include "level_up/digit_3.pal.inc.c"
#include "level_up/digit_4.png.inc.c"
#include "level_up/digit_4.pal.inc.c"
#include "level_up/digit_5.png.inc.c"
#include "level_up/digit_5.pal.inc.c"
#include "level_up/digit_6.png.inc.c"
#include "level_up/digit_6.pal.inc.c"
#include "level_up/digit_7.png.inc.c"
#include "level_up/digit_7.pal.inc.c"
#include "level_up/digit_8.png.inc.c"
#include "level_up/digit_8.pal.inc.c"
#include "level_up/digit_9.png.inc.c"
#include "level_up/digit_9.pal.inc.c"

#include "level_up/small_digit_0.png.inc.c"
#include "level_up/small_digit_0.pal.inc.c"
#include "level_up/small_digit_1.png.inc.c"
#include "level_up/small_digit_1.pal.inc.c"
#include "level_up/small_digit_2.png.inc.c"
#include "level_up/small_digit_2.pal.inc.c"
#include "level_up/small_digit_3.png.inc.c"
#include "level_up/small_digit_3.pal.inc.c"
#include "level_up/small_digit_4.png.inc.c"
#include "level_up/small_digit_4.pal.inc.c"
#include "level_up/small_digit_5.png.inc.c"
#include "level_up/small_digit_5.pal.inc.c"
#include "level_up/small_digit_6.png.inc.c"
#include "level_up/small_digit_6.pal.inc.c"
#include "level_up/small_digit_7.png.inc.c"
#include "level_up/small_digit_7.pal.inc.c"
#include "level_up/small_digit_8.png.inc.c"
#include "level_up/small_digit_8.pal.inc.c"
#include "level_up/small_digit_9.png.inc.c"
#include "level_up/small_digit_9.pal.inc.c"
#include "level_up/small_arrow.png.inc.c"
#include "level_up/small_arrow.pal.inc.c"

#define level_up_digit_0_red_png level_up_digit_0_png
#include "level_up/digit_0.red.pal.inc.c"
#define level_up_digit_1_red_png level_up_digit_1_png
#include "level_up/digit_1.red.pal.inc.c"
#define level_up_digit_2_red_png level_up_digit_2_png
#include "level_up/digit_2.red.pal.inc.c"
#define level_up_digit_3_red_png level_up_digit_3_png
#include "level_up/digit_3.red.pal.inc.c"
#define level_up_digit_4_red_png level_up_digit_4_png
#include "level_up/digit_4.red.pal.inc.c"
#define level_up_digit_5_red_png level_up_digit_5_png
#include "level_up/digit_5.red.pal.inc.c"
#define level_up_digit_6_red_png level_up_digit_6_png
#include "level_up/digit_6.red.pal.inc.c"
#define level_up_digit_7_red_png level_up_digit_7_png
#include "level_up/digit_7.red.pal.inc.c"
#define level_up_digit_8_red_png level_up_digit_8_png
#include "level_up/digit_8.red.pal.inc.c"
#define level_up_digit_9_red_png level_up_digit_9_png
#include "level_up/digit_9.red.pal.inc.c"

#define level_up_small_digit_0_red_png level_up_small_digit_0_png
#include "level_up/small_digit_0.red.pal.inc.c"
#define level_up_small_digit_1_red_png level_up_small_digit_1_png
#include "level_up/small_digit_1.red.pal.inc.c"
#define level_up_small_digit_2_red_png level_up_small_digit_2_png
#include "level_up/small_digit_2.red.pal.inc.c"
#define level_up_small_digit_3_red_png level_up_small_digit_3_png
#include "level_up/small_digit_3.red.pal.inc.c"
#define level_up_small_digit_4_red_png level_up_small_digit_4_png
#include "level_up/small_digit_4.red.pal.inc.c"
#define level_up_small_digit_5_red_png level_up_small_digit_5_png
#include "level_up/small_digit_5.red.pal.inc.c"
#define level_up_small_digit_6_red_png level_up_small_digit_6_png
#include "level_up/small_digit_6.red.pal.inc.c"
#define level_up_small_digit_7_red_png level_up_small_digit_7_png
#include "level_up/small_digit_7.red.pal.inc.c"
#define level_up_small_digit_8_red_png level_up_small_digit_8_png
#include "level_up/small_digit_8.red.pal.inc.c"
#define level_up_small_digit_9_red_png level_up_small_digit_9_png
#include "level_up/small_digit_9.red.pal.inc.c"
#define level_up_small_arrow_red_png level_up_small_arrow_png
#include "level_up/small_arrow.red.pal.inc.c"

#define level_up_digit_0_blue_png level_up_digit_0_png
#include "level_up/digit_0.blue.pal.inc.c"
#define level_up_digit_1_blue_png level_up_digit_1_png
#include "level_up/digit_1.blue.pal.inc.c"
#define level_up_digit_2_blue_png level_up_digit_2_png
#include "level_up/digit_2.blue.pal.inc.c"
#define level_up_digit_3_blue_png level_up_digit_3_png
#include "level_up/digit_3.blue.pal.inc.c"
#define level_up_digit_4_blue_png level_up_digit_4_png
#include "level_up/digit_4.blue.pal.inc.c"
#define level_up_digit_5_blue_png level_up_digit_5_png
#include "level_up/digit_5.blue.pal.inc.c"
#define level_up_digit_6_blue_png level_up_digit_6_png
#include "level_up/digit_6.blue.pal.inc.c"
#define level_up_digit_7_blue_png level_up_digit_7_png
#include "level_up/digit_7.blue.pal.inc.c"
#define level_up_digit_8_blue_png level_up_digit_8_png
#include "level_up/digit_8.blue.pal.inc.c"
#define level_up_digit_9_blue_png level_up_digit_9_png
#include "level_up/digit_9.blue.pal.inc.c"

#define level_up_small_digit_0_blue_png level_up_small_digit_0_png
#include "level_up/small_digit_0.blue.pal.inc.c"
#define level_up_small_digit_1_blue_png level_up_small_digit_1_png
#include "level_up/small_digit_1.blue.pal.inc.c"
#define level_up_small_digit_2_blue_png level_up_small_digit_2_png
#include "level_up/small_digit_2.blue.pal.inc.c"
#define level_up_small_digit_3_blue_png level_up_small_digit_3_png
#include "level_up/small_digit_3.blue.pal.inc.c"
#define level_up_small_digit_4_blue_png level_up_small_digit_4_png
#include "level_up/small_digit_4.blue.pal.inc.c"
#define level_up_small_digit_5_blue_png level_up_small_digit_5_png
#include "level_up/small_digit_5.blue.pal.inc.c"
#define level_up_small_digit_6_blue_png level_up_small_digit_6_png
#include "level_up/small_digit_6.blue.pal.inc.c"
#define level_up_small_digit_7_blue_png level_up_small_digit_7_png
#include "level_up/small_digit_7.blue.pal.inc.c"
#define level_up_small_digit_8_blue_png level_up_small_digit_8_png
#include "level_up/small_digit_8.blue.pal.inc.c"
#define level_up_small_digit_9_blue_png level_up_small_digit_9_png
#include "level_up/small_digit_9.blue.pal.inc.c"
#define level_up_small_arrow_blue_png level_up_small_arrow_png
#include "level_up/small_arrow.blue.pal.inc.c"

#include "level_up/select_one_to_upgrade.png.inc.c"
#include "level_up/select_one_to_upgrade.pal.inc.c"

EntityModelScript EMS_level_up = STANDARD_ENTITY_MODEL_SCRIPT(D_802A7A88_7A59C8, RENDER_MODE_CLOUD_NO_ZCMP);

HudScript HES_level_up_heart = HES_TEMPLATE_CI_ENUM_SIZE(level_up_heart, 40, 40);
HudScript HES_level_up_heart_copy = HES_TEMPLATE_CI_ENUM_SIZE(level_up_heart, 40, 40);
HudScript HES_level_up_flower = HES_TEMPLATE_CI_ENUM_SIZE(level_up_flower, 40, 40);
HudScript HES_level_up_leaves = HES_TEMPLATE_CI_ENUM_SIZE(level_up_leaves, 40, 40);
HudScript HES_level_up_badge = HES_TEMPLATE_CI_ENUM_SIZE(level_up_badge, 40, 40);

HudScript HES_level_up_FP = HES_TEMPLATE_CI_CUSTOM_SIZE(level_up_FP, 32, 24);
HudScript HES_level_up_green_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_0, 8, 16);
HudScript HES_level_up_green_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_1, 8, 16);
HudScript HES_level_up_green_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_2, 8, 16);
HudScript HES_level_up_green_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_3, 8, 16);
HudScript HES_level_up_green_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_4, 8, 16);
HudScript HES_level_up_green_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_5, 8, 16);
HudScript HES_level_up_green_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_6, 8, 16);
HudScript HES_level_up_green_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_7, 8, 16);
HudScript HES_level_up_green_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_8, 8, 16);
HudScript HES_level_up_green_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_9, 8, 16);
HudScript HES_level_up_small_green_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_0, 8, 8);
HudScript HES_level_up_small_green_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_1, 8, 8);
HudScript HES_level_up_small_green_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_2, 8, 8);
HudScript HES_level_up_small_green_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_3, 8, 8);
HudScript HES_level_up_small_green_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_4, 8, 8);
HudScript HES_level_up_small_green_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_5, 8, 8);
HudScript HES_level_up_small_green_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_6, 8, 8);
HudScript HES_level_up_small_green_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_7, 8, 8);
HudScript HES_level_up_small_green_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_8, 8, 8);
HudScript HES_level_up_small_green_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_9, 8, 8);
HudScript HES_level_up_small_green_arrow = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_arrow, 8, 8);

HudScript HES_level_up_HP = HES_TEMPLATE_CI_CUSTOM_SIZE(level_up_HP, 32, 24);
HudScript HES_level_up_red_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_0_red, 8, 16);
HudScript HES_level_up_red_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_1_red, 8, 16);
HudScript HES_level_up_red_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_2_red, 8, 16);
HudScript HES_level_up_red_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_3_red, 8, 16);
HudScript HES_level_up_red_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_4_red, 8, 16);
HudScript HES_level_up_red_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_5_red, 8, 16);
HudScript HES_level_up_red_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_6_red, 8, 16);
HudScript HES_level_up_red_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_7_red, 8, 16);
HudScript HES_level_up_red_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_8_red, 8, 16);
HudScript HES_level_up_red_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_9_red, 8, 16);
HudScript HES_level_up_small_red_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_0_red, 8, 8);
HudScript HES_level_up_small_red_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_1_red, 8, 8);
HudScript HES_level_up_small_red_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_2_red, 8, 8);
HudScript HES_level_up_small_red_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_3_red, 8, 8);
HudScript HES_level_up_small_red_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_4_red, 8, 8);
HudScript HES_level_up_small_red_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_5_red, 8, 8);
HudScript HES_level_up_small_red_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_6_red, 8, 8);
HudScript HES_level_up_small_red_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_7_red, 8, 8);
HudScript HES_level_up_small_red_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_8_red, 8, 8);
HudScript HES_level_up_small_red_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_9_red, 8, 8);
HudScript HES_level_up_small_red_arrow = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_arrow_red, 8, 8);

HudScript HES_level_up_BP = HES_TEMPLATE_CI_CUSTOM_SIZE(level_up_BP, 32, 24);
HudScript HES_level_up_blue_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_0_blue, 8, 16);
HudScript HES_level_up_blue_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_1_blue, 8, 16);
HudScript HES_level_up_blue_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_2_blue, 8, 16);
HudScript HES_level_up_blue_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_3_blue, 8, 16);
HudScript HES_level_up_blue_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_4_blue, 8, 16);
HudScript HES_level_up_blue_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_5_blue, 8, 16);
HudScript HES_level_up_blue_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_6_blue, 8, 16);
HudScript HES_level_up_blue_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_7_blue, 8, 16);
HudScript HES_level_up_blue_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_8_blue, 8, 16);
HudScript HES_level_up_blue_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_digit_9_blue, 8, 16);
HudScript HES_level_up_small_blue_digit_0 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_0_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_1 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_1_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_2 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_2_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_3 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_3_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_4 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_4_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_5 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_5_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_6 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_6_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_7 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_7_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_8 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_8_blue, 8, 8);
HudScript HES_level_up_small_blue_digit_9 = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_digit_9_blue, 8, 8);
HudScript HES_level_up_small_blue_arrow = HES_TEMPLATE_CI_ENUM_SIZE(level_up_small_arrow_blue, 8, 8);

HudScript HES_level_up_select_one_to_upgrade = HES_TEMPLATE_CI_CUSTOM_SIZE(level_up_select_one_to_upgrade, 208, 16);

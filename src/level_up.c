#include "common.h"
#include "hud_element.h"
#include "entity.h"
#include "include_asset.h"

Lights1 level_up_lights = gdSPDefLights1(0, 0, 0, 0, 0, 0, 0, 0, 0);

#include "level_up/draw_second_E.vtx.inc.c"
#include "level_up/draw_V.vtx.inc.c"
#include "level_up/draw_E.vtx.inc.c"
#include "level_up/draw_second_L.vtx.inc.c"
#include "level_up/draw_L.vtx.inc.c"
#include "level_up/draw_P.vtx.inc.c"
#include "level_up/draw_U.vtx.inc.c"
#include "level_up/draw_exclamation_mark.vtx.inc.c"

INCLUDE_IMG("level_up/big_V.png", D_802A1418_79F358);
#include "level_up/big_V.gfx.inc.c"
INCLUDE_IMG("level_up/big_P.png", D_802A2490_7A03D0);
#include "level_up/big_P.gfx.inc.c"
INCLUDE_IMG("level_up/big_exclamation_mark.png", D_802A3508_7A1448);
#include "level_up/big_exclamation_mark.gfx.inc.c"
INCLUDE_IMG("level_up/big_U.png", D_802A4580_7A24C0);
#include "level_up/big_U.gfx.inc.c"
INCLUDE_IMG("level_up/big_L.png", D_802A55F8_7A3538);
#include "level_up/big_L.gfx.inc.c"
INCLUDE_IMG("level_up/big_E.png", D_802A6670_7A45B0);
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

INCLUDE_IMG("level_up/heart.png", level_up_heart_png);
INCLUDE_PAL("level_up/heart.pal", level_up_heart_pal);
INCLUDE_IMG("level_up/flower.png", level_up_flower_png);
INCLUDE_PAL("level_up/flower.pal", level_up_flower_pal);
INCLUDE_IMG("level_up/leaves.png", level_up_leaves_png);
INCLUDE_PAL("level_up/leaves.pal", level_up_leaves_pal);
INCLUDE_IMG("level_up/badge.png", level_up_badge_png);
INCLUDE_PAL("level_up/badge.pal", level_up_badge_pal);
INCLUDE_IMG("level_up/FP.png", level_up_FP_png);
INCLUDE_PAL("level_up/FP.pal", level_up_FP_pal);
INCLUDE_IMG("level_up/BP.png", level_up_BP_png);
INCLUDE_PAL("level_up/BP.pal", level_up_BP_pal);
INCLUDE_IMG("level_up/HP.png", level_up_HP_png);
INCLUDE_PAL("level_up/HP.pal", level_up_HP_pal);

INCLUDE_IMG("level_up/digit_0.png", level_up_digit_0_png);
INCLUDE_PAL("level_up/digit_0.pal", level_up_digit_0_pal);
INCLUDE_IMG("level_up/digit_1.png", level_up_digit_1_png);
INCLUDE_PAL("level_up/digit_1.pal", level_up_digit_1_pal);
INCLUDE_IMG("level_up/digit_2.png", level_up_digit_2_png);
INCLUDE_PAL("level_up/digit_2.pal", level_up_digit_2_pal);
INCLUDE_IMG("level_up/digit_3.png", level_up_digit_3_png);
INCLUDE_PAL("level_up/digit_3.pal", level_up_digit_3_pal);
INCLUDE_IMG("level_up/digit_4.png", level_up_digit_4_png);
INCLUDE_PAL("level_up/digit_4.pal", level_up_digit_4_pal);
INCLUDE_IMG("level_up/digit_5.png", level_up_digit_5_png);
INCLUDE_PAL("level_up/digit_5.pal", level_up_digit_5_pal);
INCLUDE_IMG("level_up/digit_6.png", level_up_digit_6_png);
INCLUDE_PAL("level_up/digit_6.pal", level_up_digit_6_pal);
INCLUDE_IMG("level_up/digit_7.png", level_up_digit_7_png);
INCLUDE_PAL("level_up/digit_7.pal", level_up_digit_7_pal);
INCLUDE_IMG("level_up/digit_8.png", level_up_digit_8_png);
INCLUDE_PAL("level_up/digit_8.pal", level_up_digit_8_pal);
INCLUDE_IMG("level_up/digit_9.png", level_up_digit_9_png);
INCLUDE_PAL("level_up/digit_9.pal", level_up_digit_9_pal);

INCLUDE_IMG("level_up/small_digit_0.png", level_up_small_digit_0_png);
INCLUDE_PAL("level_up/small_digit_0.pal", level_up_small_digit_0_pal);
INCLUDE_IMG("level_up/small_digit_1.png", level_up_small_digit_1_png);
INCLUDE_PAL("level_up/small_digit_1.pal", level_up_small_digit_1_pal);
INCLUDE_IMG("level_up/small_digit_2.png", level_up_small_digit_2_png);
INCLUDE_PAL("level_up/small_digit_2.pal", level_up_small_digit_2_pal);
INCLUDE_IMG("level_up/small_digit_3.png", level_up_small_digit_3_png);
INCLUDE_PAL("level_up/small_digit_3.pal", level_up_small_digit_3_pal);
INCLUDE_IMG("level_up/small_digit_4.png", level_up_small_digit_4_png);
INCLUDE_PAL("level_up/small_digit_4.pal", level_up_small_digit_4_pal);
INCLUDE_IMG("level_up/small_digit_5.png", level_up_small_digit_5_png);
INCLUDE_PAL("level_up/small_digit_5.pal", level_up_small_digit_5_pal);
INCLUDE_IMG("level_up/small_digit_6.png", level_up_small_digit_6_png);
INCLUDE_PAL("level_up/small_digit_6.pal", level_up_small_digit_6_pal);
INCLUDE_IMG("level_up/small_digit_7.png", level_up_small_digit_7_png);
INCLUDE_PAL("level_up/small_digit_7.pal", level_up_small_digit_7_pal);
INCLUDE_IMG("level_up/small_digit_8.png", level_up_small_digit_8_png);
INCLUDE_PAL("level_up/small_digit_8.pal", level_up_small_digit_8_pal);
INCLUDE_IMG("level_up/small_digit_9.png", level_up_small_digit_9_png);
INCLUDE_PAL("level_up/small_digit_9.pal", level_up_small_digit_9_pal);
INCLUDE_IMG("level_up/small_arrow.png", level_up_small_arrow_png);
INCLUDE_PAL("level_up/small_arrow.pal", level_up_small_arrow_pal);

#define level_up_digit_0_red_png level_up_digit_0_png
INCLUDE_PAL("level_up/digit_0.red.pal", level_up_digit_0_red_pal);
#define level_up_digit_1_red_png level_up_digit_1_png
INCLUDE_PAL("level_up/digit_1.red.pal", level_up_digit_1_red_pal);
#define level_up_digit_2_red_png level_up_digit_2_png
INCLUDE_PAL("level_up/digit_2.red.pal", level_up_digit_2_red_pal);
#define level_up_digit_3_red_png level_up_digit_3_png
INCLUDE_PAL("level_up/digit_3.red.pal", level_up_digit_3_red_pal);
#define level_up_digit_4_red_png level_up_digit_4_png
INCLUDE_PAL("level_up/digit_4.red.pal", level_up_digit_4_red_pal);
#define level_up_digit_5_red_png level_up_digit_5_png
INCLUDE_PAL("level_up/digit_5.red.pal", level_up_digit_5_red_pal);
#define level_up_digit_6_red_png level_up_digit_6_png
INCLUDE_PAL("level_up/digit_6.red.pal", level_up_digit_6_red_pal);
#define level_up_digit_7_red_png level_up_digit_7_png
INCLUDE_PAL("level_up/digit_7.red.pal", level_up_digit_7_red_pal);
#define level_up_digit_8_red_png level_up_digit_8_png
INCLUDE_PAL("level_up/digit_8.red.pal", level_up_digit_8_red_pal);
#define level_up_digit_9_red_png level_up_digit_9_png
INCLUDE_PAL("level_up/digit_9.red.pal", level_up_digit_9_red_pal);

#define level_up_small_digit_0_red_png level_up_small_digit_0_png
INCLUDE_PAL("level_up/small_digit_0.red.pal", level_up_small_digit_0_red_pal);
#define level_up_small_digit_1_red_png level_up_small_digit_1_png
INCLUDE_PAL("level_up/small_digit_1.red.pal", level_up_small_digit_1_red_pal);
#define level_up_small_digit_2_red_png level_up_small_digit_2_png
INCLUDE_PAL("level_up/small_digit_2.red.pal", level_up_small_digit_2_red_pal);
#define level_up_small_digit_3_red_png level_up_small_digit_3_png
INCLUDE_PAL("level_up/small_digit_3.red.pal", level_up_small_digit_3_red_pal);
#define level_up_small_digit_4_red_png level_up_small_digit_4_png
INCLUDE_PAL("level_up/small_digit_4.red.pal", level_up_small_digit_4_red_pal);
#define level_up_small_digit_5_red_png level_up_small_digit_5_png
INCLUDE_PAL("level_up/small_digit_5.red.pal", level_up_small_digit_5_red_pal);
#define level_up_small_digit_6_red_png level_up_small_digit_6_png
INCLUDE_PAL("level_up/small_digit_6.red.pal", level_up_small_digit_6_red_pal);
#define level_up_small_digit_7_red_png level_up_small_digit_7_png
INCLUDE_PAL("level_up/small_digit_7.red.pal", level_up_small_digit_7_red_pal);
#define level_up_small_digit_8_red_png level_up_small_digit_8_png
INCLUDE_PAL("level_up/small_digit_8.red.pal", level_up_small_digit_8_red_pal);
#define level_up_small_digit_9_red_png level_up_small_digit_9_png
INCLUDE_PAL("level_up/small_digit_9.red.pal", level_up_small_digit_9_red_pal);
#define level_up_small_arrow_red_png level_up_small_arrow_png
INCLUDE_PAL("level_up/small_arrow.red.pal", level_up_small_arrow_red_pal);

#define level_up_digit_0_blue_png level_up_digit_0_png
INCLUDE_PAL("level_up/digit_0.blue.pal", level_up_digit_0_blue_pal);
#define level_up_digit_1_blue_png level_up_digit_1_png
INCLUDE_PAL("level_up/digit_1.blue.pal", level_up_digit_1_blue_pal);
#define level_up_digit_2_blue_png level_up_digit_2_png
INCLUDE_PAL("level_up/digit_2.blue.pal", level_up_digit_2_blue_pal);
#define level_up_digit_3_blue_png level_up_digit_3_png
INCLUDE_PAL("level_up/digit_3.blue.pal", level_up_digit_3_blue_pal);
#define level_up_digit_4_blue_png level_up_digit_4_png
INCLUDE_PAL("level_up/digit_4.blue.pal", level_up_digit_4_blue_pal);
#define level_up_digit_5_blue_png level_up_digit_5_png
INCLUDE_PAL("level_up/digit_5.blue.pal", level_up_digit_5_blue_pal);
#define level_up_digit_6_blue_png level_up_digit_6_png
INCLUDE_PAL("level_up/digit_6.blue.pal", level_up_digit_6_blue_pal);
#define level_up_digit_7_blue_png level_up_digit_7_png
INCLUDE_PAL("level_up/digit_7.blue.pal", level_up_digit_7_blue_pal);
#define level_up_digit_8_blue_png level_up_digit_8_png
INCLUDE_PAL("level_up/digit_8.blue.pal", level_up_digit_8_blue_pal);
#define level_up_digit_9_blue_png level_up_digit_9_png
INCLUDE_PAL("level_up/digit_9.blue.pal", level_up_digit_9_blue_pal);

#define level_up_small_digit_0_blue_png level_up_small_digit_0_png
INCLUDE_PAL("level_up/small_digit_0.blue.pal", level_up_small_digit_0_blue_pal);
#define level_up_small_digit_1_blue_png level_up_small_digit_1_png
INCLUDE_PAL("level_up/small_digit_1.blue.pal", level_up_small_digit_1_blue_pal);
#define level_up_small_digit_2_blue_png level_up_small_digit_2_png
INCLUDE_PAL("level_up/small_digit_2.blue.pal", level_up_small_digit_2_blue_pal);
#define level_up_small_digit_3_blue_png level_up_small_digit_3_png
INCLUDE_PAL("level_up/small_digit_3.blue.pal", level_up_small_digit_3_blue_pal);
#define level_up_small_digit_4_blue_png level_up_small_digit_4_png
INCLUDE_PAL("level_up/small_digit_4.blue.pal", level_up_small_digit_4_blue_pal);
#define level_up_small_digit_5_blue_png level_up_small_digit_5_png
INCLUDE_PAL("level_up/small_digit_5.blue.pal", level_up_small_digit_5_blue_pal);
#define level_up_small_digit_6_blue_png level_up_small_digit_6_png
INCLUDE_PAL("level_up/small_digit_6.blue.pal", level_up_small_digit_6_blue_pal);
#define level_up_small_digit_7_blue_png level_up_small_digit_7_png
INCLUDE_PAL("level_up/small_digit_7.blue.pal", level_up_small_digit_7_blue_pal);
#define level_up_small_digit_8_blue_png level_up_small_digit_8_png
INCLUDE_PAL("level_up/small_digit_8.blue.pal", level_up_small_digit_8_blue_pal);
#define level_up_small_digit_9_blue_png level_up_small_digit_9_png
INCLUDE_PAL("level_up/small_digit_9.blue.pal", level_up_small_digit_9_blue_pal);
#define level_up_small_arrow_blue_png level_up_small_arrow_png
INCLUDE_PAL("level_up/small_arrow.blue.pal", level_up_small_arrow_blue_pal);

INCLUDE_IMG("level_up/select_one_to_upgrade.png", level_up_select_one_to_upgrade_png);
INCLUDE_PAL("level_up/select_one_to_upgrade.pal", level_up_select_one_to_upgrade_pal);

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

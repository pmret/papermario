#include "common.h"
#include "entity.h"

extern IMG_BIN ui_battle_menu_spirits_png[];
extern PAL_BIN ui_battle_menu_spirits_pal[];
extern IMG_BIN ui_battle_solid_star_png[];
extern PAL_BIN ui_battle_solid_star_pal[];

#include "ui/battle/cursor_hand.png.inc.c"
#include "ui/battle/cursor_hand.pal.inc.c"

Vtx BtlCursorModelVtx[] = {
    {{{ -22, -6, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, -6, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, 25, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{ -22, 25, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
};

Gfx BtlCursorModelGfx[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_cursor_hand_pal),
    gsDPLoadTextureTile_4b(ui_battle_cursor_hand_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlCursorModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_CursorIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlCursorModelGfx, RENDER_MODE_ALPHATEST);

Vtx BtlBonkModelVtx[] = {
    {{{ -16, -16, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
};

Gfx BtlBonkModelGfx[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_01, PM_CC_02),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_menu_spirits_pal),
    gsDPLoadTextureTile_4b(ui_battle_menu_spirits_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlBonkModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_BonkIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlBonkModelGfx, RENDER_MODE_CLOUD_NO_ZCMP);

Vtx BtlStarModelVtx[] = {
    {{{ -16, -16, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
};

Gfx BtlStarModelGfx[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_solid_star_pal),
    gsDPLoadTextureTile_4b(ui_battle_solid_star_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlStarModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_StarIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlStarModelGfx, RENDER_MODE_ALPHATEST);

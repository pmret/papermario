#include "common.h"
#include "include_asset.h"

INCLUDE_IMG("filemenu/copyarrow.png", D_8024A200);
INCLUDE_IMG("filemenu/corners_yellow.png", D_8024A400);
INCLUDE_IMG("filemenu/corners_gray.png", D_8024B400);

Gfx filemenu_dl_copyarrow[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(G_RM_PASS, G_RM_CLD_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGBA, PM_CC_33),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(D_8024A200, G_IM_FMT_IA, 64, 16, 0, 0, 63, 15, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Vtx D_8024B6B0[] = {
    {{{ -8, -16, 0 }, 0, { 0,    0 }, { 0, 0, 0, 0 }}},
    {{{ -8,  16, 0 }, 0, { 0, 2048 }, { 0, 0, 0, 0 }}},
};

Vtx D_8024B6D0[] = {
    {{{ 56,  16, 0 }, 0, { 4096, 2048 }, { 0, 0, 0, 255 }}},
    {{{ 56, -16, 0 }, 0, { 4096,    0 }, { 0, 0, 0, 255 }}},
};

Gfx D_8024B6F0[] = {
    gsSPVertex(D_8024B6B0, 2, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8024B708[] = {
    gsSPVertex(D_8024B6D0, 2, 2),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

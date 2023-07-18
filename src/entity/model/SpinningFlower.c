#include "common.h"

#include "entity/model/SpinningFlower_1.vtx.inc.c"
#include "entity/model/SpinningFlower_2.vtx.inc.c"
#include "entity/model/SpinningFlower_3.vtx.inc.c"
#include "entity/model/SpinningFlower_4.vtx.inc.c"

#include "entity/model/SpinningFlower_img1.png.inc.c"
Gfx D_0A000280_E9CB80[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000180_E9CA80, G_IM_FMT_IA, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/SpinningFlower_petal.png.inc.c"
Gfx D_0A000AF8_E9D3F8[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A0002F8_E9CBF8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx D_0A000B70_E9D470 = RDP_MATRIX(
    1.000000, 0.000000, 0.000000,  0.000000,
    0.000000, 1.000000, 0.000000, 20.000000,
    0.000000, 0.000000, 1.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  1.000000
);

Gfx D_0A000BB0_E9D4B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(D_0A000280_E9CB80),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000120_E9CA20, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 0, 0, 4, 0, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C00_E9D500[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0000A0_E9C9A0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSP2Triangles(6, 7, 5, 0, 6, 5, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C60_E9D560[] = {
    gsSPDisplayList(D_0A000C00_E9D500),
    gsSPDisplayList(D_0A000BB0_E9D4B0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C78_E9D578[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(D_0A000AF8_E9D3F8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000050_E9C950, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(1, 4, 2, 0, 1, 3, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000CC8_E9D5C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(D_0A000AF8_E9D3F8),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E9C900, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(2, 3, 4, 0, 0, 2, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000D18_E9D618[] = {
    gsSPDisplayList(D_0A000CC8_E9D5C8),
    gsSPDisplayList(D_0A000C78_E9D578),
    gsSPEndDisplayList(),
};

Gfx D_0A000D30_E9D630[] = {
    gsSPDisplayList(D_0A000C60_E9D560),
    gsSPEndDisplayList(),
};

Gfx Entity_SpinningFlower_Render[] = {
    gsSPDisplayList(D_0A000D30_E9D630),
    gsSPEndDisplayList(),
};

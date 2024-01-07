#include "common.h"
#include "include_asset.h"

#include "entity/model/PinkFlower_1.vtx.inc.c"
#include "entity/model/PinkFlower_2.vtx.inc.c"
#include "entity/model/PinkFlower_3.vtx.inc.c"
#include "entity/model/PinkFlower_4.vtx.inc.c"
#include "entity/model/PinkFlower_5.vtx.inc.c"

INCLUDE_IMG("entity/model/PinkFlower_light.png", D_0A0005B0_E9BAB0);
Gfx D_0A0007B0_E9BCB0[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A0005B0_E9BAB0, G_IM_FMT_IA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/PinkFlower_tex.png", D_0A000820_E9BD20);
Gfx D_0A001020_E9C520[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000820_E9BD20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 64, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx D_0A001098_E9C598 = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, -10.000000,
    0.000000, 1.000000, 0.000000,  25.000000,
    0.000000, 0.000000, 1.000000,  13.000000,
    0.000000, 0.000000, 0.000000,   1.000000
);

Gfx Entity_PinkFlower_RenderNode3[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A0004B0_E9B9B0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 0, 0, 5, 6, 1, 0),
    gsSP2Triangles(5, 1, 0, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 7, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(8, 11, 12, 0, 11, 13, 12, 0),
    gsSP2Triangles(10, 14, 13, 0, 10, 13, 11, 0),
    gsSP2Triangles(9, 15, 10, 0, 15, 14, 10, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PinkFlower_RenderNode2[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A0003B0_E9B8B0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(2, 1, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(2, 5, 6, 0, 2, 6, 3, 0),
    gsSP2Triangles(5, 7, 6, 0, 5, 4, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(10, 12, 13, 0, 10, 13, 11, 0),
    gsSP2Triangles(10, 9, 14, 0, 10, 14, 12, 0),
    gsSP2Triangles(12, 15, 13, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PinkFlower_RenderNode1[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000290_E9B790, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
    gsSP2Triangles(11, 10, 13, 0, 11, 13, 12, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PinkFlower_RenderNode5[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(D_0A001020_E9C520),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000040_E9B540, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 5, 0, 6, 5, 7, 0),
    gsSP2Triangles(8, 0, 3, 0, 8, 3, 6, 0),
    gsSP2Triangles(2, 9, 10, 0, 2, 10, 4, 0),
    gsSP2Triangles(1, 11, 9, 0, 1, 9, 2, 0),
    gsSP2Triangles(5, 4, 12, 0, 5, 12, 13, 0),
    gsSP2Triangles(4, 10, 14, 0, 4, 14, 12, 0),
    gsSP2Triangles(7, 5, 13, 0, 7, 13, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(16, 19, 20, 0, 19, 18, 21, 0),
    gsSP2Triangles(19, 21, 11, 0, 20, 19, 11, 0),
    gsSP2Triangles(20, 11, 1, 0, 22, 20, 1, 0),
    gsSP2Triangles(22, 1, 0, 0, 23, 20, 22, 0),
    gsSP2Triangles(11, 21, 24, 0, 11, 24, 9, 0),
    gsSP2Triangles(9, 24, 25, 0, 9, 25, 10, 0),
    gsSP2Triangles(10, 25, 26, 0, 10, 26, 14, 0),
    gsSP2Triangles(27, 22, 0, 0, 27, 0, 8, 0),
    gsSP2Triangles(23, 27, 28, 0, 23, 22, 27, 0),
    gsSP2Triangles(28, 27, 8, 0, 28, 8, 29, 0),
    gsSPVertex(&D_0A000040_E9B540[6], 3, 0),
    gsSPVertex(&D_0A000040_E9B540[15], 1, 3),
    gsSPVertex(&D_0A000040_E9B540[17], 2, 4),
    gsSPVertex(&D_0A000040_E9B540[21], 1, 6),
    gsSPVertex(&D_0A000040_E9B540[24], 3, 7),
    gsSPVertex(&D_0A000040_E9B540[29], 8, 10),
    gsSP2Triangles(10, 2, 0, 0, 10, 0, 11, 0),
    gsSP2Triangles(11, 0, 1, 0, 11, 1, 12, 0),
    gsSP2Triangles(12, 1, 3, 0, 12, 3, 16, 0),
    gsSP2Triangles(6, 13, 14, 0, 6, 14, 7, 0),
    gsSP2Triangles(7, 14, 15, 0, 7, 15, 8, 0),
    gsSP2Triangles(8, 15, 17, 0, 8, 17, 9, 0),
    gsSP2Triangles(5, 4, 13, 0, 5, 13, 6, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0013B8_E9C8B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPDisplayList(D_0A0007B0_E9BCB0),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E9B500, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

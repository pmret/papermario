#include "common.h"
#include "include_asset.h"

#include "entity/model/PowBlock.vtx.inc.c"

INCLUDE_IMG("entity/model/PowBlock_face.png", D_0A000100_E43C20);
INCLUDE_PAL("entity/model/PowBlock_face.pal", D_0A000900_E44420);
Gfx Entity_PowBlock_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A000900_E44420),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000100_E43C20, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_PowBlock_mtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx Entity_PowBlock_RenderTopBottom[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_PowBlock_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000000_E43B20, 4, 0),
    gsSPVertex(&D_0A000000_E43B20[8], 4, 4),
    gsSP2Triangles(3, 4, 7, 0, 3, 7, 0, 0),
    gsSP2Triangles(1, 6, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PowBlock_RenderSides[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_PowBlock_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000000_E43B20, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PowBlock_RenderFaces[] = {
    gsSPDisplayList(Entity_PowBlock_RenderSides),
    gsSPDisplayList(Entity_PowBlock_RenderTopBottom),
    gsSPEndDisplayList(),
};

Gfx Entity_PowBlock_RenderBlock[] = {
    gsSPDisplayList(Entity_PowBlock_RenderFaces),
    gsSPEndDisplayList(),
};

Gfx Entity_PowBlock_Render[] = {
    gsSPDisplayList(Entity_PowBlock_RenderBlock),
    gsSPEndDisplayList(),
};

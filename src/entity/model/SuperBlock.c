#include "common.h"
#include "include_asset.h"

#include "entity/model/SuperBlock.vtx.inc.c"

INCLUDE_IMG("entity/model/SuperBlock_tex.png", D_0A000480_E44C80);
INCLUDE_PAL("entity/model/SuperBlock_tex.pal", D_0A000580_E44D80);
Gfx Entity_SuperBlock_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000580_E44D80),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000480_E44C80, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_SuperBlock_mtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx Entity_SuperBlock_RenderTop[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[24], 1, 0),
    gsSPVertex(&D_0A000000_E44800[28], 1, 1),
    gsSPVertex(&D_0A000000_E44800[35], 1, 2),
    gsSPVertex(&D_0A000000_E44800[39], 1, 3),
    gsSPVertex(&D_0A000000_E44800[43], 1, 4),
    gsSPVertex(&D_0A000000_E44800[47], 2, 5),
    gsSPVertex(&D_0A000000_E44800[52], 1, 7),
    gsSPVertex(&D_0A000000_E44800[56], 16, 8),
    gsSP2Triangles(8, 9, 0, 0, 8, 0, 5, 0),
    gsSP2Triangles(10, 11, 2, 0, 10, 2, 1, 0),
    gsSP2Triangles(6, 3, 12, 0, 6, 12, 13, 0),
    gsSP2Triangles(4, 7, 14, 0, 4, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderRightFrontEdge[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[48], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderLeftFrontEdge[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[40], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderRightBackEdge[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[32], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderLeftBackEdge[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[24], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderBottom[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlock_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E44800[0], 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_RenderBlock[] = {
    gsSPMatrix(&Entity_SuperBlock_mtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_SuperBlock_RenderBottom),
    gsSPDisplayList(Entity_SuperBlock_RenderLeftBackEdge),
    gsSPDisplayList(Entity_SuperBlock_RenderRightBackEdge),
    gsSPDisplayList(Entity_SuperBlock_RenderLeftFrontEdge),
    gsSPDisplayList(Entity_SuperBlock_RenderRightFrontEdge),
    gsSPDisplayList(Entity_SuperBlock_RenderTop),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlock_Render[] = {
    gsSPDisplayList(Entity_SuperBlock_RenderBlock),
    gsSPEndDisplayList(),
};

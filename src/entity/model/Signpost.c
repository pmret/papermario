#include "common.h"
#include "include_asset.h"

#include "entity/model/Signpost_1.vtx.inc.c"
#include "entity/model/Signpost_2.vtx.inc.c"

INCLUDE_IMG("entity/model/Signpost.png", D_0A000580_E59A00);
INCLUDE_PAL("entity/model/Signpost.pal", D_0A000780_E59C00);
Gfx Entity_Signpost_LoadTexture[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000580_E59A00, G_IM_FMT_CI, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000780_E59C00),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Gfx Entity_Signpost_RenderSign[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Entity_Signpost_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000120_E595A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(2, 1, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(4, 1, 0, 0, 4, 0, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 7, 9, 10, 0),
    gsSP2Triangles(10, 9, 11, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 13, 15, 16, 0),
    gsSP2Triangles(15, 14, 17, 0, 15, 17, 18, 0),
    gsSP2Triangles(14, 13, 19, 0, 14, 19, 17, 0),
    gsSP2Triangles(20, 0, 3, 0, 20, 3, 21, 0),
    gsSP2Triangles(22, 23, 20, 0, 22, 20, 21, 0),
    gsSP2Triangles(20, 23, 24, 0, 20, 24, 25, 0),
    gsSP2Triangles(24, 23, 22, 0, 24, 22, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 27, 29, 30, 0),
    gsSPVertex(&D_0A000120_E595A0[7], 2, 0),
    gsSPVertex(&D_0A000120_E595A0[13], 1, 2),
    gsSPVertex(&D_0A000120_E595A0[16], 1, 3),
    gsSPVertex(&D_0A000120_E595A0[19], 1, 4),
    gsSPVertex(&D_0A000120_E595A0[31], 9, 5),
    gsSP2Triangles(1, 0, 5, 0, 1, 5, 9, 0),
    gsSP2Triangles(2, 6, 10, 0, 2, 10, 4, 0),
    gsSP2Triangles(6, 11, 8, 0, 6, 8, 10, 0),
    gsSP2Triangles(6, 2, 3, 0, 6, 3, 12, 0),
    gsSP2Triangles(7, 11, 6, 0, 7, 6, 12, 0),
    gsSP2Triangles(8, 11, 7, 0, 8, 7, 13, 0),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000120_E595A0[40], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000120_E595A0, 1, 0),
    gsSPVertex(&D_0A000120_E595A0[6], 1, 1),
    gsSPVertex(&D_0A000120_E595A0[20], 1, 2),
    gsSPVertex(&D_0A000120_E595A0[25], 1, 3),
    gsSPVertex(&D_0A000120_E595A0[27], 2, 4),
    gsSPVertex(&D_0A000120_E595A0[44], 14, 6),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(6, 4, 7, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 10, 0),
    gsSP2Triangles(6, 10, 11, 0, 6, 11, 12, 0),
    gsSP2Triangles(5, 13, 14, 0, 5, 14, 15, 0),
    gsSP2Triangles(5, 15, 16, 0, 5, 16, 17, 0),
    gsSP2Triangles(5, 17, 18, 0, 5, 18, 19, 0),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000120_E595A0[58], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Signpost_RenderPole[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Entity_Signpost_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E59480, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(7, 10, 11, 0, 7, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 11, 10, 0, 16, 10, 17, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Signpost_RenderMain[] = {
    gsSPDisplayList(Entity_Signpost_RenderPole),
    gsSPDisplayList(Entity_Signpost_RenderSign),
    gsSPEndDisplayList(),
};

Gfx Entity_Signpost_Render[] = {
    gsSPDisplayList(Entity_Signpost_RenderMain),
    gsSPEndDisplayList(),
};

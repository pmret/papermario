#include "common.h"
#include "include_asset.h"

#include "entity/model/Hammer1Block.vtx.inc.c"

INCLUDE_IMG("entity/model/Hammer1Block_face.png", D_0A000280_E317B0);
INCLUDE_PAL("entity/model/Hammer1Block_face.pal", D_0A000380_E318B0);
Gfx Entity_Hammer1Block_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000380_E318B0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000280_E317B0, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Gfx Entity_Hammer1Block_RenderFaces[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Entity_Hammer1Block_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0A000000_E31530, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
    gsSP2Triangles(16, 18, 19, 0, 16, 19, 17, 0),
    gsSP2Triangles(18, 20, 21, 0, 18, 21, 19, 0),
    gsSP2Triangles(22, 23, 4, 0, 22, 4, 5, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(26, 28, 29, 0, 26, 29, 27, 0),
    gsSPVertex(&D_0A000000_E31530[28], 12, 0),
    gsSP2Triangles(0, 2, 6, 0, 0, 6, 1, 0),
    gsSP2Triangles(3, 7, 4, 0, 3, 4, 8, 0),
    gsSP2Triangles(4, 5, 9, 0, 4, 9, 8, 0),
    gsSP2Triangles(5, 10, 11, 0, 5, 11, 9, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Hammer1Block_RenderBlock[] = {
    gsSPDisplayList(Entity_Hammer1Block_RenderFaces),
    gsSPEndDisplayList(),
};

Gfx Entity_Hammer1Block_Render[] = {
    gsSPDisplayList(Entity_Hammer1Block_RenderBlock),
    gsSPEndDisplayList(),
};

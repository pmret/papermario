#include "common.h"
#include "include_asset.h"

#include "entity/model/HitYellowBlock_1.vtx.inc.c"
#include "entity/model/HitYellowBlock_2.vtx.inc.c"

extern unsigned char D_0A000420_E45E10[];
extern unsigned char D_0A000C20_E46610[];

Gfx Entity_HitYellowBlock_RenderBlock2[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPLoadTextureBlock(D_0A000C20_E46610, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0A000160_E45B50, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 7, 6, 0, 20, 6, 21, 0),
    gsDPPipeSync(),
    gsDPSetCombineMode(PM_CC_04, PM_CC_04),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

Gfx Entity_HitYellowBlock_RenderBlock1[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPLoadTextureBlock(D_0A000420_E45E10, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0A000000_E459F0, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 7, 6, 0, 20, 6, 21, 0),
    gsDPPipeSync(),
    gsDPSetCombineMode(PM_CC_04, PM_CC_04),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/HitYellowBlock_face1.png", D_0A000420_E45E10);
INCLUDE_IMG("entity/model/HitYellowBlock_face2.png", D_0A000C20_E46610);

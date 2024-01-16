#include "common.h"
#include "include_asset.h"

#include "entity/model/BombableRock_1.vtx.inc.c"
#include "entity/model/BombableRock_2.vtx.inc.c"
#include "entity/model/BombableRock_3.vtx.inc.c"
#include "entity/model/BombableRock_4.vtx.inc.c"
#include "entity/model/BombableRock_5.vtx.inc.c"

INCLUDE_IMG("entity/model/BombableRock.png", D_0A000840_E9DE90);
INCLUDE_PAL("entity/model/BombableRock.pal", D_0A001040_E9E690);
Gfx D_0A001060_E9E6B0[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000840_E9DE90, G_IM_FMT_CI, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A001040_E9E690),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx Entity_BombableRock_FragmentMatrices[] = {
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000023, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x000006D4, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00090012, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xA924647E, 0xBB9A0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100012, 0xFFF70001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xBB9A647E, 0x56DC0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00012, 0x00090001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x4466647E, 0xA9240000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF70012, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x56DC647E, 0x44660000 }
        }
    },
};

Gfx D_0A001258_E9E8A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001060_E9E6B0),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000720_E9DD70, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 5, 0, 0),
    gsSP2Triangles(2, 4, 6, 0, 2, 6, 5, 0),
    gsSP2Triangles(4, 3, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 5, 0),
    gsSP2Triangles(10, 7, 6, 0, 10, 6, 3, 0),
    gsSP2Triangles(5, 9, 11, 0, 5, 11, 0, 0),
    gsSP2Triangles(7, 11, 9, 0, 7, 9, 8, 0),
    gsSP2Triangles(3, 1, 12, 0, 3, 12, 13, 0),
    gsSP2Triangles(13, 10, 3, 0, 7, 10, 14, 0),
    gsSP2Triangles(7, 14, 11, 0, 15, 16, 17, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 14, 10, 0),
    gsSP2Triangles(14, 12, 1, 0, 0, 14, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0012F8_E9E948[] = {
    gsSPDisplayList(D_0A001258_E9E8A8),
    gsSPEndDisplayList(),
};

Gfx D_0A001308_E9E958[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001060_E9E6B0),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000600_E9DC50, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 5, 0, 0),
    gsSP2Triangles(2, 4, 6, 0, 2, 6, 5, 0),
    gsSP2Triangles(4, 3, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 5, 0),
    gsSP2Triangles(10, 7, 6, 0, 10, 6, 3, 0),
    gsSP2Triangles(5, 9, 11, 0, 5, 11, 0, 0),
    gsSP2Triangles(7, 11, 9, 0, 7, 9, 8, 0),
    gsSP2Triangles(3, 1, 12, 0, 3, 12, 13, 0),
    gsSP2Triangles(13, 10, 3, 0, 7, 10, 14, 0),
    gsSP2Triangles(7, 14, 11, 0, 15, 16, 17, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 14, 10, 0),
    gsSP2Triangles(14, 12, 1, 0, 0, 14, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0013A8_E9E9F8[] = {
    gsSPDisplayList(D_0A001308_E9E958),
    gsSPEndDisplayList(),
};

Gfx D_0A0013B8_E9EA08[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001060_E9E6B0),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A0004A0_E9DAF0, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 5, 0, 0),
    gsSP2Triangles(2, 4, 6, 0, 2, 6, 5, 0),
    gsSP2Triangles(4, 3, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 5, 0),
    gsSP2Triangles(10, 7, 6, 0, 10, 6, 3, 0),
    gsSP2Triangles(5, 9, 11, 0, 5, 11, 0, 0),
    gsSP2Triangles(7, 11, 9, 0, 7, 9, 8, 0),
    gsSP2Triangles(3, 1, 12, 0, 3, 12, 13, 0),
    gsSP2Triangles(13, 10, 3, 0, 7, 10, 14, 0),
    gsSP2Triangles(7, 14, 11, 0, 15, 16, 17, 0),
    gsSP2Triangles(14, 12, 1, 0, 0, 14, 1, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001458_E9EAA8[] = {
    gsSPDisplayList(D_0A0013B8_E9EA08),
    gsSPEndDisplayList(),
};

Gfx D_0A001468_E9EAB8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001060_E9E6B0),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000380_E9D9D0, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 5, 0, 0),
    gsSP2Triangles(2, 4, 6, 0, 2, 6, 5, 0),
    gsSP2Triangles(4, 3, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 5, 0),
    gsSP2Triangles(10, 7, 6, 0, 10, 6, 3, 0),
    gsSP2Triangles(5, 9, 11, 0, 5, 11, 0, 0),
    gsSP2Triangles(7, 11, 9, 0, 7, 9, 8, 0),
    gsSP2Triangles(3, 1, 12, 0, 3, 12, 13, 0),
    gsSP2Triangles(13, 10, 3, 0, 7, 10, 14, 0),
    gsSP2Triangles(7, 14, 11, 0, 15, 16, 17, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 14, 10, 0),
    gsSP2Triangles(14, 12, 1, 0, 0, 14, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001508_E9EB58[] = {
    gsSPDisplayList(D_0A001468_E9EAB8),
    gsSPEndDisplayList(),
};

Gfx D_0A001518_E9EB68[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001060_E9E6B0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E9D650[0], 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 6, 7, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP2Triangles(8, 6, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(8, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 12, 11, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(20, 23, 24, 0, 20, 24, 18, 0),
    gsSP2Triangles(20, 18, 17, 0, 20, 17, 25, 0),
    gsSP2Triangles(20, 25, 26, 0, 20, 26, 27, 0),
    gsSP2Triangles(20, 27, 28, 0, 20, 28, 29, 0),
    gsSPVertex(&D_0A000000_E9D650[26], 2, 0),
    gsSPVertex(&D_0A000000_E9D650[30], 26, 2),
    gsSP2Triangles(2, 1, 0, 0, 3, 9, 10, 0),
    gsSP2Triangles(3, 10, 11, 0, 3, 11, 12, 0),
    gsSP2Triangles(3, 12, 13, 0, 3, 13, 14, 0),
    gsSP2Triangles(3, 14, 4, 0, 4, 15, 3, 0),
    gsSP2Triangles(3, 16, 17, 0, 3, 17, 18, 0),
    gsSP2Triangles(5, 19, 20, 0, 5, 20, 21, 0),
    gsSP2Triangles(5, 21, 22, 0, 5, 22, 23, 0),
    gsSP2Triangles(5, 23, 24, 0, 5, 24, 6, 0),
    gsSP2Triangles(6, 7, 5, 0, 7, 25, 26, 0),
    gsSP1Triangle(8, 26, 27, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001610_E9EC60[] = {
    gsSPDisplayList(D_0A001518_E9EB68),
    gsSPEndDisplayList(),
};

Gfx D_0A001620_E9EC70[] = {
    gsSPDisplayList(D_0A001610_E9EC60),
    gsSPDisplayList(D_0A001508_E9EB58),
    gsSPDisplayList(D_0A001458_E9EAA8),
    gsSPDisplayList(D_0A0013A8_E9E9F8),
    gsSPDisplayList(D_0A0012F8_E9E948),
    gsSPEndDisplayList(),
};

Gfx D_0A001650_E9ECA0[] = {
    gsSPDisplayList(D_0A001620_E9EC70),
    gsSPEndDisplayList(),
};

Gfx* Entity_BombableRock_FragmentsRender[] = {
    D_0A001610_E9EC60,
    D_0A001508_E9EB58,
    D_0A001458_E9EAA8,
    D_0A0013A8_E9E9F8,
    D_0A0012F8_E9E948,
};

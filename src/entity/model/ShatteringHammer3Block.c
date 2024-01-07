#include "common.h"
#include "include_asset.h"

#include "entity/model/ShatteringHammer3Block.vtx.inc.c"

INCLUDE_IMG("entity/model/ShatteringHammer3Block_texture.png", D_0A001050_E398E0);
INCLUDE_PAL("entity/model/ShatteringHammer3Block_texture.pal", D_0A001150_E399E0);
Gfx D_0A001170_E39A00[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A001150_E399E0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A001050_E398E0, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_ShatteringHammer3Block_FragmentsMatrices[] = {
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100029, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABAAAB, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000029, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000AAAB, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00029, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555AAAB, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100029, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABAAAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000029, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000AAAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00029, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555AAAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100029, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABAAAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000029, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000AAAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00029, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555AAAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100019, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB0000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000019, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00000000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00019, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55550000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100019, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB0000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00019, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55550000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100019, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB0000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000019, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00019, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55550000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100008, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB5556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000008, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00005556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00008, 0x00100001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55555556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100008, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB5556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000008, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00005556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00008, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55555556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00100008, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB5556, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000008, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00005556, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF00008, 0xFFF00001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55555556, 0x55550000 }
        }
    },
};

Gfx D_0A001898_E3A128[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[135], 1, 0),
    gsSPVertex(&D_0A000000_E38890[142], 1, 1),
    gsSPVertex(&D_0A000000_E38890[144], 2, 2),
    gsSPVertex(&D_0A000000_E38890[159], 4, 4),
    gsSPVertex(&D_0A000000_E38890[179], 2, 8),
    gsSPVertex(&D_0A000000_E38890[185], 2, 10),
    gsSP2Triangles(8, 0, 1, 0, 8, 1, 9, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001918_E3A1A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[215], 1, 0),
    gsSPVertex(&D_0A000000_E38890[218], 1, 1),
    gsSPVertex(&D_0A000000_E38890[251], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001978_E3A208[] = {
    gsSPDisplayList(D_0A001918_E3A1A8),
    gsSPDisplayList(D_0A001898_E3A128),
    gsSPEndDisplayList(),
};

Gfx D_0A001990_E3A220[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 1, 0),
    gsSPVertex(&D_0A000000_E38890[125], 1, 1),
    gsSPVertex(&D_0A000000_E38890[135], 1, 2),
    gsSPVertex(&D_0A000000_E38890[142], 1, 3),
    gsSPVertex(&D_0A000000_E38890[144], 2, 4),
    gsSPVertex(&D_0A000000_E38890[159], 4, 6),
    gsSPVertex(&D_0A000000_E38890[175], 2, 10),
    gsSPVertex(&D_0A000000_E38890[179], 2, 12),
    gsSPVertex(&D_0A000000_E38890[185], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001A30_E3A2C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[207], 1, 0),
    gsSPVertex(&D_0A000000_E38890[210], 1, 1),
    gsSPVertex(&D_0A000000_E38890[245], 6, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001A88_E3A318[] = {
    gsSPDisplayList(D_0A001A30_E3A2C0),
    gsSPDisplayList(D_0A001990_E3A220),
    gsSPEndDisplayList(),
};

Gfx D_0A001AA0_E3A330[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 1, 0),
    gsSPVertex(&D_0A000000_E38890[125], 1, 1),
    gsSPVertex(&D_0A000000_E38890[135], 1, 2),
    gsSPVertex(&D_0A000000_E38890[142], 1, 3),
    gsSPVertex(&D_0A000000_E38890[159], 4, 4),
    gsSPVertex(&D_0A000000_E38890[175], 2, 8),
    gsSPVertex(&D_0A000000_E38890[179], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001B28_E3A3B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[195], 1, 0),
    gsSPVertex(&D_0A000000_E38890[198], 1, 1),
    gsSPVertex(&D_0A000000_E38890[235], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001B88_E3A418[] = {
    gsSPDisplayList(D_0A001B28_E3A3B8),
    gsSPDisplayList(D_0A001AA0_E3A330),
    gsSPEndDisplayList(),
};

Gfx D_0A001BA0_E3A430[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[126], 4, 0),
    gsSPVertex(&D_0A000000_E38890[134], 2, 4),
    gsSPVertex(&D_0A000000_E38890[137], 1, 6),
    gsSPVertex(&D_0A000000_E38890[142], 5, 7),
    gsSPVertex(&D_0A000000_E38890[159], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 7, 0, 4, 7, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001C20_E3A4B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[215], 4, 0),
    gsSPVertex(&D_0A000000_E38890[231], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001C70_E3A500[] = {
    gsSPDisplayList(D_0A001C20_E3A4B0),
    gsSPDisplayList(D_0A001BA0_E3A430),
    gsSPEndDisplayList(),
};

Gfx D_0A001C88_E3A518[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 8, 0),
    gsSPVertex(&D_0A000000_E38890[134], 2, 8),
    gsSPVertex(&D_0A000000_E38890[137], 1, 10),
    gsSPVertex(&D_0A000000_E38890[142], 5, 11),
    gsSPVertex(&D_0A000000_E38890[159], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001D10_E3A5A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[207], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001D50_E3A5E0[] = {
    gsSPDisplayList(D_0A001D10_E3A5A0),
    gsSPDisplayList(D_0A001C88_E3A518),
    gsSPEndDisplayList(),
};

Gfx D_0A001D68_E3A5F8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 8, 0),
    gsSPVertex(&D_0A000000_E38890[134], 2, 8),
    gsSPVertex(&D_0A000000_E38890[137], 1, 10),
    gsSPVertex(&D_0A000000_E38890[142], 1, 11),
    gsSPVertex(&D_0A000000_E38890[159], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001DE8_E3A678[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[195], 4, 0),
    gsSPVertex(&D_0A000000_E38890[227], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E38_E3A6C8[] = {
    gsSPDisplayList(D_0A001DE8_E3A678),
    gsSPDisplayList(D_0A001D68_E3A5F8),
    gsSPEndDisplayList(),
};

Gfx D_0A001E50_E3A6E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[126], 4, 0),
    gsSPVertex(&D_0A000000_E38890[134], 2, 4),
    gsSPVertex(&D_0A000000_E38890[137], 1, 6),
    gsSPVertex(&D_0A000000_E38890[142], 5, 7),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 7, 0, 4, 7, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001EC0_E3A750[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[215], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001F10_E3A7A0[] = {
    gsSPDisplayList(D_0A001EC0_E3A750),
    gsSPDisplayList(D_0A001E50_E3A6E0),
    gsSPEndDisplayList(),
};

Gfx D_0A001F28_E3A7B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 8, 0),
    gsSPVertex(&D_0A000000_E38890[134], 2, 8),
    gsSPVertex(&D_0A000000_E38890[137], 1, 10),
    gsSPVertex(&D_0A000000_E38890[142], 5, 11),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001FA0_E3A830[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[207], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001FE8_E3A878[] = {
    gsSPDisplayList(D_0A001FA0_E3A830),
    gsSPDisplayList(D_0A001F28_E3A7B8),
    gsSPEndDisplayList(),
};

Gfx D_0A002000_E3A890[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 8, 0),
    gsSPVertex(&D_0A000000_E38890[134], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002060_E3A8F0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[195], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0020B0_E3A940[] = {
    gsSPDisplayList(D_0A002060_E3A8F0),
    gsSPDisplayList(D_0A002000_E3A890),
    gsSPEndDisplayList(),
};

Gfx D_0A0020C8_E3A958[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[130], 1, 0),
    gsSPVertex(&D_0A000000_E38890[133], 1, 1),
    gsSPVertex(&D_0A000000_E38890[135], 1, 2),
    gsSPVertex(&D_0A000000_E38890[142], 1, 3),
    gsSPVertex(&D_0A000000_E38890[144], 2, 4),
    gsSPVertex(&D_0A000000_E38890[159], 4, 6),
    gsSPVertex(&D_0A000000_E38890[177], 4, 10),
    gsSPVertex(&D_0A000000_E38890[185], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002160_E3A9F0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[187], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0021A8_E3AA38[] = {
    gsSPDisplayList(D_0A002160_E3A9F0),
    gsSPDisplayList(D_0A0020C8_E3A958),
    gsSPEndDisplayList(),
};

Gfx D_0A0021C0_E3AA50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 1, 0),
    gsSPVertex(&D_0A000000_E38890[125], 1, 1),
    gsSPVertex(&D_0A000000_E38890[130], 1, 2),
    gsSPVertex(&D_0A000000_E38890[133], 1, 3),
    gsSPVertex(&D_0A000000_E38890[135], 1, 4),
    gsSPVertex(&D_0A000000_E38890[142], 1, 5),
    gsSPVertex(&D_0A000000_E38890[144], 2, 6),
    gsSPVertex(&D_0A000000_E38890[159], 4, 8),
    gsSPVertex(&D_0A000000_E38890[175], 6, 12),
    gsSPVertex(&D_0A000000_E38890[185], 2, 18),
    gsSP2Triangles(0, 12, 13, 0, 0, 13, 1, 0),
    gsSP2Triangles(2, 14, 15, 0, 2, 15, 3, 0),
    gsSP2Triangles(16, 4, 5, 0, 16, 5, 17, 0),
    gsSP2Triangles(18, 6, 7, 0, 18, 7, 19, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002270_E3AB00[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[181], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0022B0_E3AB40[] = {
    gsSPDisplayList(D_0A002270_E3AB00),
    gsSPDisplayList(D_0A0021C0_E3AA50),
    gsSPEndDisplayList(),
};

Gfx D_0A0022C8_E3AB58[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 1, 0),
    gsSPVertex(&D_0A000000_E38890[125], 1, 1),
    gsSPVertex(&D_0A000000_E38890[130], 1, 2),
    gsSPVertex(&D_0A000000_E38890[133], 1, 3),
    gsSPVertex(&D_0A000000_E38890[135], 1, 4),
    gsSPVertex(&D_0A000000_E38890[142], 1, 5),
    gsSPVertex(&D_0A000000_E38890[159], 4, 6),
    gsSPVertex(&D_0A000000_E38890[175], 6, 10),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002360_E3ABF0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[167], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0023A8_E3AC38[] = {
    gsSPDisplayList(D_0A002360_E3ABF0),
    gsSPDisplayList(D_0A0022C8_E3AB58),
    gsSPEndDisplayList(),
};

Gfx D_0A0023C0_E3AC50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[126], 10, 0),
    gsSPVertex(&D_0A000000_E38890[137], 1, 10),
    gsSPVertex(&D_0A000000_E38890[142], 5, 11),
    gsSPVertex(&D_0A000000_E38890[159], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002440_E3ACD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[163], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002480_E3AD10[] = {
    gsSPDisplayList(D_0A002440_E3ACD0),
    gsSPDisplayList(D_0A0023C0_E3AC50),
    gsSPEndDisplayList(),
};

Gfx D_0A002498_E3AD28[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 14, 0),
    gsSPVertex(&D_0A000000_E38890[137], 1, 14),
    gsSPVertex(&D_0A000000_E38890[142], 1, 15),
    gsSPVertex(&D_0A000000_E38890[159], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 15, 0, 12, 15, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002518_E3ADA8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[155], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002558_E3ADE8[] = {
    gsSPDisplayList(D_0A002518_E3ADA8),
    gsSPDisplayList(D_0A002498_E3AD28),
    gsSPEndDisplayList(),
};

Gfx D_0A002570_E3AE00[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[126], 10, 0),
    gsSPVertex(&D_0A000000_E38890[137], 1, 10),
    gsSPVertex(&D_0A000000_E38890[142], 5, 11),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0025E0_E3AE70[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[147], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002628_E3AEB8[] = {
    gsSPDisplayList(D_0A0025E0_E3AE70),
    gsSPDisplayList(D_0A002570_E3AE00),
    gsSPEndDisplayList(),
};

Gfx D_0A002640_E3AED0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 14, 0),
    gsSPVertex(&D_0A000000_E38890[137], 1, 14),
    gsSPVertex(&D_0A000000_E38890[142], 5, 15),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 15, 0, 12, 15, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0026B8_E3AF48[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[138], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0026F8_E3AF88[] = {
    gsSPDisplayList(D_0A0026B8_E3AF48),
    gsSPDisplayList(D_0A002640_E3AED0),
    gsSPEndDisplayList(),
};

Gfx D_0A002710_E3AFA0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[122], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002770_E3B000[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[114], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0027B8_E3B048[] = {
    gsSPDisplayList(D_0A002770_E3B000),
    gsSPDisplayList(D_0A002710_E3AFA0),
    gsSPEndDisplayList(),
};

Gfx D_0A0027D0_E3B060[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 1, 0),
    gsSPVertex(&D_0A000000_E38890[37], 1, 1),
    gsSPVertex(&D_0A000000_E38890[55], 2, 2),
    gsSPVertex(&D_0A000000_E38890[74], 4, 4),
    gsSPVertex(&D_0A000000_E38890[92], 2, 8),
    gsSPVertex(&D_0A000000_E38890[102], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002850_E3B0E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[59], 2, 0),
    gsSPVertex(&D_0A000000_E38890[104], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0028A8_E3B138[] = {
    gsSPDisplayList(D_0A002850_E3B0E0),
    gsSPDisplayList(D_0A0027D0_E3B060),
    gsSPEndDisplayList(),
};

Gfx D_0A0028C0_E3B150[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 1, 0),
    gsSPVertex(&D_0A000000_E38890[37], 1, 1),
    gsSPVertex(&D_0A000000_E38890[42], 1, 2),
    gsSPVertex(&D_0A000000_E38890[45], 1, 3),
    gsSPVertex(&D_0A000000_E38890[55], 2, 4),
    gsSPVertex(&D_0A000000_E38890[74], 4, 6),
    gsSPVertex(&D_0A000000_E38890[92], 4, 10),
    gsSPVertex(&D_0A000000_E38890[102], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002958_E3B1E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[47], 2, 0),
    gsSPVertex(&D_0A000000_E38890[96], 6, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0029A8_E3B238[] = {
    gsSPDisplayList(D_0A002958_E3B1E8),
    gsSPDisplayList(D_0A0028C0_E3B150),
    gsSPEndDisplayList(),
};

Gfx D_0A0029C0_E3B250[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 1, 0),
    gsSPVertex(&D_0A000000_E38890[37], 1, 1),
    gsSPVertex(&D_0A000000_E38890[42], 1, 2),
    gsSPVertex(&D_0A000000_E38890[45], 1, 3),
    gsSPVertex(&D_0A000000_E38890[74], 4, 4),
    gsSPVertex(&D_0A000000_E38890[92], 4, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A40_E3B2D0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[23], 2, 0),
    gsSPVertex(&D_0A000000_E38890[82], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A98_E3B328[] = {
    gsSPDisplayList(D_0A002A40_E3B2D0),
    gsSPDisplayList(D_0A0029C0_E3B250),
    gsSPEndDisplayList(),
};

Gfx D_0A002AB0_E3B340[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 8, 0),
    gsSPVertex(&D_0A000000_E38890[54], 4, 8),
    gsSPVertex(&D_0A000000_E38890[74], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B20_E3B3B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[58], 4, 0),
    gsSPVertex(&D_0A000000_E38890[78], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B70_E3B400[] = {
    gsSPDisplayList(D_0A002B20_E3B3B0),
    gsSPDisplayList(D_0A002AB0_E3B340),
    gsSPEndDisplayList(),
};

Gfx D_0A002B88_E3B418[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 12, 0),
    gsSPVertex(&D_0A000000_E38890[54], 4, 12),
    gsSPVertex(&D_0A000000_E38890[74], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C00_E3B490[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[46], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C40_E3B4D0[] = {
    gsSPDisplayList(D_0A002C00_E3B490),
    gsSPDisplayList(D_0A002B88_E3B418),
    gsSPEndDisplayList(),
};

Gfx D_0A002C58_E3B4E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 12, 0),
    gsSPVertex(&D_0A000000_E38890[74], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002CC0_E3B550[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[22], 4, 0),
    gsSPVertex(&D_0A000000_E38890[70], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D10_E3B5A0[] = {
    gsSPDisplayList(D_0A002CC0_E3B550),
    gsSPDisplayList(D_0A002C58_E3B4E8),
    gsSPEndDisplayList(),
};

Gfx D_0A002D28_E3B5B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 8, 0),
    gsSPVertex(&D_0A000000_E38890[54], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D88_E3B618[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[58], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002DD8_E3B668[] = {
    gsSPDisplayList(D_0A002D88_E3B618),
    gsSPDisplayList(D_0A002D28_E3B5B8),
    gsSPEndDisplayList(),
};

Gfx D_0A002DF0_E3B680[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 12, 0),
    gsSPVertex(&D_0A000000_E38890[54], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002E58_E3B6E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[46], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002EA0_E3B730[] = {
    gsSPDisplayList(D_0A002E58_E3B6E8),
    gsSPDisplayList(D_0A002DF0_E3B680),
    gsSPEndDisplayList(),
};

Gfx D_0A002EB8_E3B748[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[34], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F10_E3B7A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001170_E39A00),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E38890[22], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F60_E3B7F0[] = {
    gsSPDisplayList(D_0A002F10_E3B7A0),
    gsSPDisplayList(D_0A002EB8_E3B748),
    gsSPEndDisplayList(),
};

Gfx* Entity_ShatteringHammer3Block_FragmentsRender[] = {
    D_0A002F60_E3B7F0,
    D_0A002EA0_E3B730,
    D_0A002DD8_E3B668,
    D_0A002D10_E3B5A0,
    D_0A002C40_E3B4D0,
    D_0A002B70_E3B400,
    D_0A002A98_E3B328,
    D_0A0029A8_E3B238,
    D_0A0028A8_E3B138,
    D_0A0027B8_E3B048,
    D_0A0026F8_E3AF88,
    D_0A002628_E3AEB8,
    D_0A002558_E3ADE8,
    D_0A002480_E3AD10,
    D_0A0023A8_E3AC38,
    D_0A0022B0_E3AB40,
    D_0A0021A8_E3AA38,
    D_0A0020B0_E3A940,
    D_0A001FE8_E3A878,
    D_0A001F10_E3A7A0,
    D_0A001E38_E3A6C8,
    D_0A001D50_E3A5E0,
    D_0A001C70_E3A500,
    D_0A001B88_E3A418,
    D_0A001A88_E3A318,
    D_0A001978_E3A208,
};

#include "common.h"

#include "entity/model/ShatteringHammer1Block.vtx.inc.c"

#include "entity/model/ShatteringHammer1Block_texture.png.inc.c"
#include "entity/model/ShatteringHammer1Block_texture.pal.inc.c"
Gfx D_0A001460_E33880[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A001260_E33680),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A001060_E33480, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_ShatteringHammer1Block_FragmentsMatrices[] = {
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

Gfx D_0A001B88_E33FA8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[137], 2, 0),
    gsSPVertex(&D_0A000000_E32420[145], 2, 2),
    gsSPVertex(&D_0A000000_E32420[160], 4, 4),
    gsSPVertex(&D_0A000000_E32420[180], 2, 8),
    gsSPVertex(&D_0A000000_E32420[186], 2, 10),
    gsSP2Triangles(8, 0, 1, 0, 8, 1, 9, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001C00_E34020[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[216], 1, 0),
    gsSPVertex(&D_0A000000_E32420[219], 1, 1),
    gsSPVertex(&D_0A000000_E32420[252], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001C60_E34080[] = {
    gsSPDisplayList(D_0A001C00_E34020),
    gsSPDisplayList(D_0A001B88_E33FA8),
    gsSPEndDisplayList(),
};

Gfx D_0A001C78_E34098[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 1, 0),
    gsSPVertex(&D_0A000000_E32420[127], 1, 1),
    gsSPVertex(&D_0A000000_E32420[137], 2, 2),
    gsSPVertex(&D_0A000000_E32420[145], 2, 4),
    gsSPVertex(&D_0A000000_E32420[160], 4, 6),
    gsSPVertex(&D_0A000000_E32420[176], 2, 10),
    gsSPVertex(&D_0A000000_E32420[180], 2, 12),
    gsSPVertex(&D_0A000000_E32420[186], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001D10_E34130[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[208], 1, 0),
    gsSPVertex(&D_0A000000_E32420[211], 1, 1),
    gsSPVertex(&D_0A000000_E32420[246], 6, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001D68_E34188[] = {
    gsSPDisplayList(D_0A001D10_E34130),
    gsSPDisplayList(D_0A001C78_E34098),
    gsSPEndDisplayList(),
};

Gfx D_0A001D80_E341A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 1, 0),
    gsSPVertex(&D_0A000000_E32420[127], 1, 1),
    gsSPVertex(&D_0A000000_E32420[137], 2, 2),
    gsSPVertex(&D_0A000000_E32420[160], 4, 4),
    gsSPVertex(&D_0A000000_E32420[176], 2, 8),
    gsSPVertex(&D_0A000000_E32420[180], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E00_E34220[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[196], 1, 0),
    gsSPVertex(&D_0A000000_E32420[199], 1, 1),
    gsSPVertex(&D_0A000000_E32420[236], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E60_E34280[] = {
    gsSPDisplayList(D_0A001E00_E34220),
    gsSPDisplayList(D_0A001D80_E341A0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E78_E34298[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[128], 4, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 4),
    gsSPVertex(&D_0A000000_E32420[144], 4, 8),
    gsSPVertex(&D_0A000000_E32420[160], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001EF0_E34310[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[216], 4, 0),
    gsSPVertex(&D_0A000000_E32420[232], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001F40_E34360[] = {
    gsSPDisplayList(D_0A001EF0_E34310),
    gsSPDisplayList(D_0A001E78_E34298),
    gsSPEndDisplayList(),
};

Gfx D_0A001F58_E34378[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 8, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 8),
    gsSPVertex(&D_0A000000_E32420[144], 4, 12),
    gsSPVertex(&D_0A000000_E32420[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001FD8_E343F8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[208], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002018_E34438[] = {
    gsSPDisplayList(D_0A001FD8_E343F8),
    gsSPDisplayList(D_0A001F58_E34378),
    gsSPEndDisplayList(),
};

Gfx D_0A002030_E34450[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 8, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 8),
    gsSPVertex(&D_0A000000_E32420[160], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0020A0_E344C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[196], 4, 0),
    gsSPVertex(&D_0A000000_E32420[228], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0020F0_E34510[] = {
    gsSPDisplayList(D_0A0020A0_E344C0),
    gsSPDisplayList(D_0A002030_E34450),
    gsSPEndDisplayList(),
};

Gfx D_0A002108_E34528[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[128], 4, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 4),
    gsSPVertex(&D_0A000000_E32420[144], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002170_E34590[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[216], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0021C0_E345E0[] = {
    gsSPDisplayList(D_0A002170_E34590),
    gsSPDisplayList(D_0A002108_E34528),
    gsSPEndDisplayList(),
};

Gfx D_0A0021D8_E345F8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 8, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 8),
    gsSPVertex(&D_0A000000_E32420[144], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002248_E34668[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[208], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002290_E346B0[] = {
    gsSPDisplayList(D_0A002248_E34668),
    gsSPDisplayList(D_0A0021D8_E345F8),
    gsSPEndDisplayList(),
};

Gfx D_0A0022A8_E346C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 8, 0),
    gsSPVertex(&D_0A000000_E32420[136], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002308_E34728[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[196], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002358_E34778[] = {
    gsSPDisplayList(D_0A002308_E34728),
    gsSPDisplayList(D_0A0022A8_E346C8),
    gsSPEndDisplayList(),
};

Gfx D_0A002370_E34790[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[132], 1, 0),
    gsSPVertex(&D_0A000000_E32420[135], 1, 1),
    gsSPVertex(&D_0A000000_E32420[137], 2, 2),
    gsSPVertex(&D_0A000000_E32420[145], 2, 4),
    gsSPVertex(&D_0A000000_E32420[160], 4, 6),
    gsSPVertex(&D_0A000000_E32420[178], 4, 10),
    gsSPVertex(&D_0A000000_E32420[186], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002400_E34820[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[188], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002448_E34868[] = {
    gsSPDisplayList(D_0A002400_E34820),
    gsSPDisplayList(D_0A002370_E34790),
    gsSPEndDisplayList(),
};

Gfx D_0A002460_E34880[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 1, 0),
    gsSPVertex(&D_0A000000_E32420[127], 1, 1),
    gsSPVertex(&D_0A000000_E32420[132], 1, 2),
    gsSPVertex(&D_0A000000_E32420[135], 1, 3),
    gsSPVertex(&D_0A000000_E32420[137], 2, 4),
    gsSPVertex(&D_0A000000_E32420[145], 2, 6),
    gsSPVertex(&D_0A000000_E32420[160], 4, 8),
    gsSPVertex(&D_0A000000_E32420[176], 6, 12),
    gsSPVertex(&D_0A000000_E32420[186], 2, 18),
    gsSP2Triangles(0, 12, 13, 0, 0, 13, 1, 0),
    gsSP2Triangles(2, 14, 15, 0, 2, 15, 3, 0),
    gsSP2Triangles(16, 4, 5, 0, 16, 5, 17, 0),
    gsSP2Triangles(18, 6, 7, 0, 18, 7, 19, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002508_E34928[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[182], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002548_E34968[] = {
    gsSPDisplayList(D_0A002508_E34928),
    gsSPDisplayList(D_0A002460_E34880),
    gsSPEndDisplayList(),
};

Gfx D_0A002560_E34980[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 1, 0),
    gsSPVertex(&D_0A000000_E32420[127], 1, 1),
    gsSPVertex(&D_0A000000_E32420[132], 1, 2),
    gsSPVertex(&D_0A000000_E32420[135], 1, 3),
    gsSPVertex(&D_0A000000_E32420[137], 2, 4),
    gsSPVertex(&D_0A000000_E32420[160], 4, 6),
    gsSPVertex(&D_0A000000_E32420[176], 6, 10),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0025F0_E34A10[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[168], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002638_E34A58[] = {
    gsSPDisplayList(D_0A0025F0_E34A10),
    gsSPDisplayList(D_0A002560_E34980),
    gsSPEndDisplayList(),
};

Gfx D_0A002650_E34A70[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[128], 12, 0),
    gsSPVertex(&D_0A000000_E32420[144], 4, 12),
    gsSPVertex(&D_0A000000_E32420[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0026C8_E34AE8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[164], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002708_E34B28[] = {
    gsSPDisplayList(D_0A0026C8_E34AE8),
    gsSPDisplayList(D_0A002650_E34A70),
    gsSPEndDisplayList(),
};

Gfx D_0A002720_E34B40[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 16, 0),
    gsSPVertex(&D_0A000000_E32420[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002790_E34BB0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[156], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0027D0_E34BF0[] = {
    gsSPDisplayList(D_0A002790_E34BB0),
    gsSPDisplayList(D_0A002720_E34B40),
    gsSPEndDisplayList(),
};

Gfx D_0A0027E8_E34C08[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[128], 12, 0),
    gsSPVertex(&D_0A000000_E32420[144], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002850_E34C70[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[148], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002898_E34CB8[] = {
    gsSPDisplayList(D_0A002850_E34C70),
    gsSPDisplayList(D_0A0027E8_E34C08),
    gsSPEndDisplayList(),
};

Gfx D_0A0028B0_E34CD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 16, 0),
    gsSPVertex(&D_0A000000_E32420[144], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002920_E34D40[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[140], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002960_E34D80[] = {
    gsSPDisplayList(D_0A002920_E34D40),
    gsSPDisplayList(D_0A0028B0_E34CD0),
    gsSPEndDisplayList(),
};

Gfx D_0A002978_E34D98[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[124], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0029D8_E34DF8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[116], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A20_E34E40[] = {
    gsSPDisplayList(D_0A0029D8_E34DF8),
    gsSPDisplayList(D_0A002978_E34D98),
    gsSPEndDisplayList(),
};

Gfx D_0A002A38_E34E58[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 1, 0),
    gsSPVertex(&D_0A000000_E32420[39], 1, 1),
    gsSPVertex(&D_0A000000_E32420[57], 2, 2),
    gsSPVertex(&D_0A000000_E32420[76], 4, 4),
    gsSPVertex(&D_0A000000_E32420[94], 2, 8),
    gsSPVertex(&D_0A000000_E32420[104], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002AB8_E34ED8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[61], 2, 0),
    gsSPVertex(&D_0A000000_E32420[106], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B10_E34F30[] = {
    gsSPDisplayList(D_0A002AB8_E34ED8),
    gsSPDisplayList(D_0A002A38_E34E58),
    gsSPEndDisplayList(),
};

Gfx D_0A002B28_E34F48[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 1, 0),
    gsSPVertex(&D_0A000000_E32420[39], 1, 1),
    gsSPVertex(&D_0A000000_E32420[44], 1, 2),
    gsSPVertex(&D_0A000000_E32420[47], 1, 3),
    gsSPVertex(&D_0A000000_E32420[57], 2, 4),
    gsSPVertex(&D_0A000000_E32420[76], 4, 6),
    gsSPVertex(&D_0A000000_E32420[94], 4, 10),
    gsSPVertex(&D_0A000000_E32420[104], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002BC0_E34FE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[49], 2, 0),
    gsSPVertex(&D_0A000000_E32420[98], 6, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C10_E35030[] = {
    gsSPDisplayList(D_0A002BC0_E34FE0),
    gsSPDisplayList(D_0A002B28_E34F48),
    gsSPEndDisplayList(),
};

Gfx D_0A002C28_E35048[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 1, 0),
    gsSPVertex(&D_0A000000_E32420[39], 1, 1),
    gsSPVertex(&D_0A000000_E32420[44], 1, 2),
    gsSPVertex(&D_0A000000_E32420[47], 1, 3),
    gsSPVertex(&D_0A000000_E32420[76], 4, 4),
    gsSPVertex(&D_0A000000_E32420[94], 4, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002CA8_E350C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[25], 2, 0),
    gsSPVertex(&D_0A000000_E32420[84], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D00_E35120[] = {
    gsSPDisplayList(D_0A002CA8_E350C8),
    gsSPDisplayList(D_0A002C28_E35048),
    gsSPEndDisplayList(),
};

Gfx D_0A002D18_E35138[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 8, 0),
    gsSPVertex(&D_0A000000_E32420[56], 4, 8),
    gsSPVertex(&D_0A000000_E32420[76], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D88_E351A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[60], 4, 0),
    gsSPVertex(&D_0A000000_E32420[80], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002DD8_E351F8[] = {
    gsSPDisplayList(D_0A002D88_E351A8),
    gsSPDisplayList(D_0A002D18_E35138),
    gsSPEndDisplayList(),
};

Gfx D_0A002DF0_E35210[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 12, 0),
    gsSPVertex(&D_0A000000_E32420[56], 4, 12),
    gsSPVertex(&D_0A000000_E32420[76], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002E68_E35288[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[48], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002EA8_E352C8[] = {
    gsSPDisplayList(D_0A002E68_E35288),
    gsSPDisplayList(D_0A002DF0_E35210),
    gsSPEndDisplayList(),
};

Gfx D_0A002EC0_E352E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 12, 0),
    gsSPVertex(&D_0A000000_E32420[76], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F28_E35348[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[24], 4, 0),
    gsSPVertex(&D_0A000000_E32420[72], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F78_E35398[] = {
    gsSPDisplayList(D_0A002F28_E35348),
    gsSPDisplayList(D_0A002EC0_E352E0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F90_E353B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 8, 0),
    gsSPVertex(&D_0A000000_E32420[56], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002FF0_E35410[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[60], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003040_E35460[] = {
    gsSPDisplayList(D_0A002FF0_E35410),
    gsSPDisplayList(D_0A002F90_E353B0),
    gsSPEndDisplayList(),
};

Gfx D_0A003058_E35478[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 12, 0),
    gsSPVertex(&D_0A000000_E32420[56], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0030C0_E354E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[48], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003108_E35528[] = {
    gsSPDisplayList(D_0A0030C0_E354E0),
    gsSPDisplayList(D_0A003058_E35478),
    gsSPEndDisplayList(),
};

Gfx D_0A003120_E35540[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[36], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003178_E35598[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E33880),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E32420[24], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0031C8_E355E8[] = {
    gsSPDisplayList(D_0A003178_E35598),
    gsSPDisplayList(D_0A003120_E35540),
    gsSPEndDisplayList(),
};

Gfx* Entity_ShatteringHammer1Block_FragmentsRender[] = {
    D_0A0031C8_E355E8,
    D_0A003108_E35528,
    D_0A003040_E35460,
    D_0A002F78_E35398,
    D_0A002EA8_E352C8,
    D_0A002DD8_E351F8,
    D_0A002D00_E35120,
    D_0A002C10_E35030,
    D_0A002B10_E34F30,
    D_0A002A20_E34E40,
    D_0A002960_E34D80,
    D_0A002898_E34CB8,
    D_0A0027D0_E34BF0,
    D_0A002708_E34B28,
    D_0A002638_E34A58,
    D_0A002548_E34968,
    D_0A002448_E34868,
    D_0A002358_E34778,
    D_0A002290_E346B0,
    D_0A0021C0_E345E0,
    D_0A0020F0_E34510,
    D_0A002018_E34438,
    D_0A001F40_E34360,
    D_0A001E60_E34280,
    D_0A001D68_E34188,
    D_0A001C60_E34080,
};

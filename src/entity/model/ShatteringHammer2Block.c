#include "common.h"

#include "entity/model/ShatteringHammer2Block.vtx.inc.c"

#include "entity/model/ShatteringHammer2Block_texture.png.inc.c"
Gfx D_0A001460_E36AD0[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A001060_E366D0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_ShatteringHammer2Block_FragmentsMatrices[] = {
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

Gfx D_0A001B58_E371C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[137], 2, 0),
    gsSPVertex(&D_0A000000_E35670[145], 2, 2),
    gsSPVertex(&D_0A000000_E35670[160], 4, 4),
    gsSPVertex(&D_0A000000_E35670[180], 2, 8),
    gsSPVertex(&D_0A000000_E35670[186], 2, 10),
    gsSP2Triangles(8, 0, 1, 0, 8, 1, 9, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001BD0_E37240[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[216], 1, 0),
    gsSPVertex(&D_0A000000_E35670[219], 1, 1),
    gsSPVertex(&D_0A000000_E35670[252], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001C30_E372A0[] = {
    gsSPDisplayList(D_0A001BD0_E37240),
    gsSPDisplayList(D_0A001B58_E371C8),
    gsSPEndDisplayList(),
};

Gfx D_0A001C48_E372B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 1, 0),
    gsSPVertex(&D_0A000000_E35670[127], 1, 1),
    gsSPVertex(&D_0A000000_E35670[137], 2, 2),
    gsSPVertex(&D_0A000000_E35670[145], 2, 4),
    gsSPVertex(&D_0A000000_E35670[160], 4, 6),
    gsSPVertex(&D_0A000000_E35670[176], 2, 10),
    gsSPVertex(&D_0A000000_E35670[180], 2, 12),
    gsSPVertex(&D_0A000000_E35670[186], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001CE0_E37350[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[208], 1, 0),
    gsSPVertex(&D_0A000000_E35670[211], 1, 1),
    gsSPVertex(&D_0A000000_E35670[246], 6, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001D38_E373A8[] = {
    gsSPDisplayList(D_0A001CE0_E37350),
    gsSPDisplayList(D_0A001C48_E372B8),
    gsSPEndDisplayList(),
};

Gfx D_0A001D50_E373C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 1, 0),
    gsSPVertex(&D_0A000000_E35670[127], 1, 1),
    gsSPVertex(&D_0A000000_E35670[137], 2, 2),
    gsSPVertex(&D_0A000000_E35670[160], 4, 4),
    gsSPVertex(&D_0A000000_E35670[176], 2, 8),
    gsSPVertex(&D_0A000000_E35670[180], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001DD0_E37440[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[196], 1, 0),
    gsSPVertex(&D_0A000000_E35670[199], 1, 1),
    gsSPVertex(&D_0A000000_E35670[236], 10, 2),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E30_E374A0[] = {
    gsSPDisplayList(D_0A001DD0_E37440),
    gsSPDisplayList(D_0A001D50_E373C0),
    gsSPEndDisplayList(),
};

Gfx D_0A001E48_E374B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[128], 4, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 4),
    gsSPVertex(&D_0A000000_E35670[144], 4, 8),
    gsSPVertex(&D_0A000000_E35670[160], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001EC0_E37530[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[216], 4, 0),
    gsSPVertex(&D_0A000000_E35670[232], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001F10_E37580[] = {
    gsSPDisplayList(D_0A001EC0_E37530),
    gsSPDisplayList(D_0A001E48_E374B8),
    gsSPEndDisplayList(),
};

Gfx D_0A001F28_E37598[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 8, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 8),
    gsSPVertex(&D_0A000000_E35670[144], 4, 12),
    gsSPVertex(&D_0A000000_E35670[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001FA8_E37618[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[208], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001FE8_E37658[] = {
    gsSPDisplayList(D_0A001FA8_E37618),
    gsSPDisplayList(D_0A001F28_E37598),
    gsSPEndDisplayList(),
};

Gfx D_0A002000_E37670[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 8, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 8),
    gsSPVertex(&D_0A000000_E35670[160], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002070_E376E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[196], 4, 0),
    gsSPVertex(&D_0A000000_E35670[228], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0020C0_E37730[] = {
    gsSPDisplayList(D_0A002070_E376E0),
    gsSPDisplayList(D_0A002000_E37670),
    gsSPEndDisplayList(),
};

Gfx D_0A0020D8_E37748[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[128], 4, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 4),
    gsSPVertex(&D_0A000000_E35670[144], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002140_E377B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[216], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002190_E37800[] = {
    gsSPDisplayList(D_0A002140_E377B0),
    gsSPDisplayList(D_0A0020D8_E37748),
    gsSPEndDisplayList(),
};

Gfx D_0A0021A8_E37818[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 8, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 8),
    gsSPVertex(&D_0A000000_E35670[144], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002218_E37888[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[208], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002260_E378D0[] = {
    gsSPDisplayList(D_0A002218_E37888),
    gsSPDisplayList(D_0A0021A8_E37818),
    gsSPEndDisplayList(),
};

Gfx D_0A002278_E378E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 8, 0),
    gsSPVertex(&D_0A000000_E35670[136], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0022D8_E37948[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[196], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002328_E37998[] = {
    gsSPDisplayList(D_0A0022D8_E37948),
    gsSPDisplayList(D_0A002278_E378E8),
    gsSPEndDisplayList(),
};

Gfx D_0A002340_E379B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[132], 1, 0),
    gsSPVertex(&D_0A000000_E35670[135], 1, 1),
    gsSPVertex(&D_0A000000_E35670[137], 2, 2),
    gsSPVertex(&D_0A000000_E35670[145], 2, 4),
    gsSPVertex(&D_0A000000_E35670[160], 4, 6),
    gsSPVertex(&D_0A000000_E35670[178], 4, 10),
    gsSPVertex(&D_0A000000_E35670[186], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 2, 3, 0, 12, 3, 13, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0023D0_E37A40[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[188], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002418_E37A88[] = {
    gsSPDisplayList(D_0A0023D0_E37A40),
    gsSPDisplayList(D_0A002340_E379B0),
    gsSPEndDisplayList(),
};

Gfx D_0A002430_E37AA0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 1, 0),
    gsSPVertex(&D_0A000000_E35670[127], 1, 1),
    gsSPVertex(&D_0A000000_E35670[132], 1, 2),
    gsSPVertex(&D_0A000000_E35670[135], 1, 3),
    gsSPVertex(&D_0A000000_E35670[137], 2, 4),
    gsSPVertex(&D_0A000000_E35670[145], 2, 6),
    gsSPVertex(&D_0A000000_E35670[160], 4, 8),
    gsSPVertex(&D_0A000000_E35670[176], 6, 12),
    gsSPVertex(&D_0A000000_E35670[186], 2, 18),
    gsSP2Triangles(0, 12, 13, 0, 0, 13, 1, 0),
    gsSP2Triangles(2, 14, 15, 0, 2, 15, 3, 0),
    gsSP2Triangles(16, 4, 5, 0, 16, 5, 17, 0),
    gsSP2Triangles(18, 6, 7, 0, 18, 7, 19, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0024D8_E37B48[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[182], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002518_E37B88[] = {
    gsSPDisplayList(D_0A0024D8_E37B48),
    gsSPDisplayList(D_0A002430_E37AA0),
    gsSPEndDisplayList(),
};

Gfx D_0A002530_E37BA0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 1, 0),
    gsSPVertex(&D_0A000000_E35670[127], 1, 1),
    gsSPVertex(&D_0A000000_E35670[132], 1, 2),
    gsSPVertex(&D_0A000000_E35670[135], 1, 3),
    gsSPVertex(&D_0A000000_E35670[137], 2, 4),
    gsSPVertex(&D_0A000000_E35670[160], 4, 6),
    gsSPVertex(&D_0A000000_E35670[176], 6, 10),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0025C0_E37C30[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[168], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002608_E37C78[] = {
    gsSPDisplayList(D_0A0025C0_E37C30),
    gsSPDisplayList(D_0A002530_E37BA0),
    gsSPEndDisplayList(),
};

Gfx D_0A002620_E37C90[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[128], 12, 0),
    gsSPVertex(&D_0A000000_E35670[144], 4, 12),
    gsSPVertex(&D_0A000000_E35670[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002698_E37D08[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[164], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0026D8_E37D48[] = {
    gsSPDisplayList(D_0A002698_E37D08),
    gsSPDisplayList(D_0A002620_E37C90),
    gsSPEndDisplayList(),
};

Gfx D_0A0026F0_E37D60[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 16, 0),
    gsSPVertex(&D_0A000000_E35670[160], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002760_E37DD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[156], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0027A0_E37E10[] = {
    gsSPDisplayList(D_0A002760_E37DD0),
    gsSPDisplayList(D_0A0026F0_E37D60),
    gsSPEndDisplayList(),
};

Gfx D_0A0027B8_E37E28[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[128], 12, 0),
    gsSPVertex(&D_0A000000_E35670[144], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002820_E37E90[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[148], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002868_E37ED8[] = {
    gsSPDisplayList(D_0A002820_E37E90),
    gsSPDisplayList(D_0A0027B8_E37E28),
    gsSPEndDisplayList(),
};

Gfx D_0A002880_E37EF0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 16, 0),
    gsSPVertex(&D_0A000000_E35670[144], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0028F0_E37F60[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[140], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002930_E37FA0[] = {
    gsSPDisplayList(D_0A0028F0_E37F60),
    gsSPDisplayList(D_0A002880_E37EF0),
    gsSPEndDisplayList(),
};

Gfx D_0A002948_E37FB8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[124], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0029A8_E38018[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[116], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0029F0_E38060[] = {
    gsSPDisplayList(D_0A0029A8_E38018),
    gsSPDisplayList(D_0A002948_E37FB8),
    gsSPEndDisplayList(),
};

Gfx D_0A002A08_E38078[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 1, 0),
    gsSPVertex(&D_0A000000_E35670[39], 1, 1),
    gsSPVertex(&D_0A000000_E35670[57], 2, 2),
    gsSPVertex(&D_0A000000_E35670[76], 4, 4),
    gsSPVertex(&D_0A000000_E35670[94], 2, 8),
    gsSPVertex(&D_0A000000_E35670[104], 2, 10),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(10, 2, 3, 0, 10, 3, 11, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A88_E380F8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[61], 2, 0),
    gsSPVertex(&D_0A000000_E35670[106], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002AE0_E38150[] = {
    gsSPDisplayList(D_0A002A88_E380F8),
    gsSPDisplayList(D_0A002A08_E38078),
    gsSPEndDisplayList(),
};

Gfx D_0A002AF8_E38168[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 1, 0),
    gsSPVertex(&D_0A000000_E35670[39], 1, 1),
    gsSPVertex(&D_0A000000_E35670[44], 1, 2),
    gsSPVertex(&D_0A000000_E35670[47], 1, 3),
    gsSPVertex(&D_0A000000_E35670[57], 2, 4),
    gsSPVertex(&D_0A000000_E35670[76], 4, 6),
    gsSPVertex(&D_0A000000_E35670[94], 4, 10),
    gsSPVertex(&D_0A000000_E35670[104], 2, 14),
    gsSP2Triangles(0, 10, 11, 0, 0, 11, 1, 0),
    gsSP2Triangles(2, 12, 13, 0, 2, 13, 3, 0),
    gsSP2Triangles(14, 4, 5, 0, 14, 5, 15, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B90_E38200[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[49], 2, 0),
    gsSPVertex(&D_0A000000_E35670[98], 6, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002BE0_E38250[] = {
    gsSPDisplayList(D_0A002B90_E38200),
    gsSPDisplayList(D_0A002AF8_E38168),
    gsSPEndDisplayList(),
};

Gfx D_0A002BF8_E38268[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 1, 0),
    gsSPVertex(&D_0A000000_E35670[39], 1, 1),
    gsSPVertex(&D_0A000000_E35670[44], 1, 2),
    gsSPVertex(&D_0A000000_E35670[47], 1, 3),
    gsSPVertex(&D_0A000000_E35670[76], 4, 4),
    gsSPVertex(&D_0A000000_E35670[94], 4, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C78_E382E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[25], 2, 0),
    gsSPVertex(&D_0A000000_E35670[84], 10, 2),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002CD0_E38340[] = {
    gsSPDisplayList(D_0A002C78_E382E8),
    gsSPDisplayList(D_0A002BF8_E38268),
    gsSPEndDisplayList(),
};

Gfx D_0A002CE8_E38358[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 8, 0),
    gsSPVertex(&D_0A000000_E35670[56], 4, 8),
    gsSPVertex(&D_0A000000_E35670[76], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D58_E383C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[60], 4, 0),
    gsSPVertex(&D_0A000000_E35670[80], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002DA8_E38418[] = {
    gsSPDisplayList(D_0A002D58_E383C8),
    gsSPDisplayList(D_0A002CE8_E38358),
    gsSPEndDisplayList(),
};

Gfx D_0A002DC0_E38430[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 12, 0),
    gsSPVertex(&D_0A000000_E35670[56], 4, 12),
    gsSPVertex(&D_0A000000_E35670[76], 4, 16),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002E38_E384A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[48], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002E78_E384E8[] = {
    gsSPDisplayList(D_0A002E38_E384A8),
    gsSPDisplayList(D_0A002DC0_E38430),
    gsSPEndDisplayList(),
};

Gfx D_0A002E90_E38500[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 12, 0),
    gsSPVertex(&D_0A000000_E35670[76], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002EF8_E38568[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[24], 4, 0),
    gsSPVertex(&D_0A000000_E35670[72], 4, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F48_E385B8[] = {
    gsSPDisplayList(D_0A002EF8_E38568),
    gsSPDisplayList(D_0A002E90_E38500),
    gsSPEndDisplayList(),
};

Gfx D_0A002F60_E385D0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 8, 0),
    gsSPVertex(&D_0A000000_E35670[56], 4, 8),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002FC0_E38630[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[60], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003010_E38680[] = {
    gsSPDisplayList(D_0A002FC0_E38630),
    gsSPDisplayList(D_0A002F60_E385D0),
    gsSPEndDisplayList(),
};

Gfx D_0A003028_E38698[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 12, 0),
    gsSPVertex(&D_0A000000_E35670[56], 4, 12),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003090_E38700[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[48], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0030D8_E38748[] = {
    gsSPDisplayList(D_0A003090_E38700),
    gsSPDisplayList(D_0A003028_E38698),
    gsSPEndDisplayList(),
};

Gfx D_0A0030F0_E38760[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[36], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003148_E387B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A001460_E36AD0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E35670[24], 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003198_E38808[] = {
    gsSPDisplayList(D_0A003148_E387B8),
    gsSPDisplayList(D_0A0030F0_E38760),
    gsSPEndDisplayList(),
};

Gfx* Entity_ShatteringHammer2Block_FragmentsRender[] = {
    D_0A003198_E38808,
    D_0A0030D8_E38748,
    D_0A003010_E38680,
    D_0A002F48_E385B8,
    D_0A002E78_E384E8,
    D_0A002DA8_E38418,
    D_0A002CD0_E38340,
    D_0A002BE0_E38250,
    D_0A002AE0_E38150,
    D_0A0029F0_E38060,
    D_0A002930_E37FA0,
    D_0A002868_E37ED8,
    D_0A0027A0_E37E10,
    D_0A0026D8_E37D48,
    D_0A002608_E37C78,
    D_0A002518_E37B88,
    D_0A002418_E37A88,
    D_0A002328_E37998,
    D_0A002260_E378D0,
    D_0A002190_E37800,
    D_0A0020C0_E37730,
    D_0A001FE8_E37658,
    D_0A001F10_E37580,
    D_0A001E30_E374A0,
    D_0A001D38_E373A8,
    D_0A001C30_E372A0,
};



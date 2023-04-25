#include "common.h"

#include "entity/model/ShatteringBrickBlock.vtx.inc.c"

#include "entity/model/ShatteringBrickBlock_texture.png.inc.c"
Gfx D_0A0022A0_E40500[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A001AA0_E3FD00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_ShatteringBrickBlock_FragmentsMatrices[] = {
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080014, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555D556, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000014, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000D556, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80014, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABD556, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080014, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555D556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000014, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000D556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80014, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABD556, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080014, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x5555D556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000014, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000D556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80014, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAABD556, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0008000C, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55558000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0000000C, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00008000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF8000C, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB8000, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0008000C, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55558000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF8000C, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB8000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0008000C, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55558000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0000000C, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00008000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF8000C, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB8000, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080004, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55552AAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000004, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00002AAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80004, 0x00080001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB2AAB, 0x55550000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080004, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55552AAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000004, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00002AAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80004, 0x00000001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB2AAB, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00080004, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x55552AAB, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00000004, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00002AAB, 0xAAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF80004, 0xFFF80001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xAAAB2AAB, 0xAAAB0000 }
        }
    },
};

Gfx D_0A002998_E40BF8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[310], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[313], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[335], 2, 2),
    gsSPVertex(&D_0A000000_E3E260[339], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[400], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[418], 8, 8),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(8, 2, 3, 0, 8, 3, 9, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A20_E40C80[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[410], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002A68_E40CC8[] = {
    gsSPDisplayList(D_0A002A20_E40C80),
    gsSPDisplayList(D_0A002998_E40BF8),
    gsSPEndDisplayList(),
};

Gfx D_0A002A80_E40CE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[302], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[305], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[310], 1, 2),
    gsSPVertex(&D_0A000000_E3E260[313], 1, 3),
    gsSPVertex(&D_0A000000_E3E260[315], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[319], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[398], 12, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(12, 4, 5, 0, 12, 5, 13, 0),
    gsSP2Triangles(14, 6, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B18_E40D78[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[394], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B58_E40DB8[] = {
    gsSPDisplayList(D_0A002B18_E40D78),
    gsSPDisplayList(D_0A002A80_E40CE0),
    gsSPEndDisplayList(),
};

Gfx D_0A002B70_E40DD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[168], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[171], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[246], 2, 2),
    gsSPVertex(&D_0A000000_E3E260[286], 1, 4),
    gsSPVertex(&D_0A000000_E3E260[289], 1, 5),
    gsSPVertex(&D_0A000000_E3E260[295], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[386], 8, 8),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 8, 9, 0, 4, 9, 5, 0),
    gsSP2Triangles(10, 6, 7, 0, 10, 7, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C00_E40E60[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[378], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C48_E40EA8[] = {
    gsSPDisplayList(D_0A002C00_E40E60),
    gsSPDisplayList(D_0A002B70_E40DD0),
    gsSPEndDisplayList(),
};

Gfx D_0A002C60_E40EC0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[311], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[330], 5, 2),
    gsSPVertex(&D_0A000000_E3E260[337], 2, 7),
    gsSPVertex(&D_0A000000_E3E260[341], 1, 9),
    gsSPVertex(&D_0A000000_E3E260[356], 2, 10),
    gsSPVertex(&D_0A000000_E3E260[370], 8, 12),
    gsSP2Triangles(10, 0, 1, 0, 10, 1, 11, 0),
    gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(6, 12, 13, 0, 6, 13, 7, 0),
    gsSP2Triangles(8, 14, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002CF0_E40F50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[366], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D30_E40F90[] = {
    gsSPDisplayList(D_0A002CF0_E40F50),
    gsSPDisplayList(D_0A002C60_E40EC0),
    gsSPEndDisplayList(),
};

Gfx D_0A002D48_E40FA8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[303], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[306], 4, 2),
    gsSPVertex(&D_0A000000_E3E260[311], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[314], 1, 8),
    gsSPVertex(&D_0A000000_E3E260[317], 2, 9),
    gsSPVertex(&D_0A000000_E3E260[321], 1, 11),
    gsSPVertex(&D_0A000000_E3E260[354], 12, 12),
    gsSP2Triangles(12, 0, 1, 0, 12, 1, 13, 0),
    gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(14, 6, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(8, 16, 17, 0, 8, 17, 9, 0),
    gsSP2Triangles(10, 18, 19, 0, 10, 19, 11, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002DE8_E41048[] = {
    gsSPDisplayList(D_0A002D48_E40FA8),
    gsSPEndDisplayList(),
};

Gfx D_0A002DF8_E41058[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[169], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[214], 2, 2),
    gsSPVertex(&D_0A000000_E3E260[287], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[290], 5, 6),
    gsSPVertex(&D_0A000000_E3E260[297], 1, 11),
    gsSPVertex(&D_0A000000_E3E260[346], 8, 12),
    gsSP2Triangles(2, 0, 1, 0, 2, 1, 3, 0),
    gsSP2Triangles(12, 4, 5, 0, 12, 5, 13, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 14, 15, 0, 10, 15, 11, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002E88_E410E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[342], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002EC8_E41128[] = {
    gsSPDisplayList(D_0A002E88_E410E8),
    gsSPDisplayList(D_0A002DF8_E41058),
    gsSPEndDisplayList(),
};

Gfx D_0A002EE0_E41140[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[310], 4, 0),
    gsSPVertex(&D_0A000000_E3E260[330], 12, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F48_E411A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[322], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A002F90_E411F0[] = {
    gsSPDisplayList(D_0A002F48_E411A8),
    gsSPDisplayList(D_0A002EE0_E41140),
    gsSPEndDisplayList(),
};

Gfx D_0A002FA8_E41208[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[302], 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003010_E41270[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[298], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003050_E412B0[] = {
    gsSPDisplayList(D_0A003010_E41270),
    gsSPDisplayList(D_0A002FA8_E41208),
    gsSPEndDisplayList(),
};

Gfx D_0A003068_E412C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[168], 4, 0),
    gsSPVertex(&D_0A000000_E3E260[286], 12, 4),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0030D0_E41330[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[278], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003118_E41378[] = {
    gsSPDisplayList(D_0A0030D0_E41330),
    gsSPDisplayList(D_0A003068_E412C8),
    gsSPEndDisplayList(),
};

Gfx D_0A003130_E41390[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[188], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[191], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[193], 2, 2),
    gsSPVertex(&D_0A000000_E3E260[197], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[260], 10, 6),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(8, 2, 3, 0, 8, 3, 9, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0031B0_E41410[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[270], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0031F8_E41458[] = {
    gsSPDisplayList(D_0A0031B0_E41410),
    gsSPDisplayList(D_0A003130_E41390),
    gsSPEndDisplayList(),
};

Gfx D_0A003210_E41470[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[180], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[183], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[188], 1, 2),
    gsSPVertex(&D_0A000000_E3E260[191], 1, 3),
    gsSPVertex(&D_0A000000_E3E260[193], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[197], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[258], 12, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(12, 4, 5, 0, 12, 5, 13, 0),
    gsSP2Triangles(14, 6, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0032A8_E41508[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[254], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0032E8_E41548[] = {
    gsSPDisplayList(D_0A0032A8_E41508),
    gsSPDisplayList(D_0A003210_E41470),
    gsSPEndDisplayList(),
};

Gfx D_0A003300_E41560[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[160], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[163], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[168], 1, 2),
    gsSPVertex(&D_0A000000_E3E260[171], 1, 3),
    gsSPVertex(&D_0A000000_E3E260[173], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[244], 10, 6),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(2, 8, 9, 0, 2, 9, 3, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003388_E415E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[236], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0033D0_E41630[] = {
    gsSPDisplayList(D_0A003388_E415E8),
    gsSPDisplayList(D_0A003300_E41560),
    gsSPEndDisplayList(),
};

Gfx D_0A0033E8_E41648[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[184], 4, 0),
    gsSPVertex(&D_0A000000_E3E260[189], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[192], 1, 6),
    gsSPVertex(&D_0A000000_E3E260[195], 2, 7),
    gsSPVertex(&D_0A000000_E3E260[199], 1, 9),
    gsSPVertex(&D_0A000000_E3E260[226], 10, 10),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(6, 12, 13, 0, 6, 13, 7, 0),
    gsSP2Triangles(8, 14, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003478_E416D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[222], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0034B8_E41718[] = {
    gsSPDisplayList(D_0A003478_E416D8),
    gsSPDisplayList(D_0A0033E8_E41648),
    gsSPEndDisplayList(),
};

Gfx D_0A0034D0_E41730[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[161], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[164], 4, 2),
    gsSPVertex(&D_0A000000_E3E260[169], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[172], 1, 8),
    gsSPVertex(&D_0A000000_E3E260[175], 1, 9),
    gsSPVertex(&D_0A000000_E3E260[212], 10, 10),
    gsSP2Triangles(10, 0, 1, 0, 10, 1, 11, 0),
    gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(12, 6, 7, 0, 12, 7, 13, 0),
    gsSP2Triangles(8, 14, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003560_E417C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[208], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0035A0_E41800[] = {
    gsSPDisplayList(D_0A003560_E417C0),
    gsSPDisplayList(D_0A0034D0_E41730),
    gsSPEndDisplayList(),
};

Gfx D_0A0035B8_E41818[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[184], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003618_E41878[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[200], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003660_E418C0[] = {
    gsSPDisplayList(D_0A003618_E41878),
    gsSPDisplayList(D_0A0035B8_E41818),
    gsSPEndDisplayList(),
};

Gfx D_0A003678_E418D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[180], 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0036E0_E41940[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[176], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003720_E41980[] = {
    gsSPDisplayList(D_0A0036E0_E41940),
    gsSPDisplayList(D_0A003678_E418D8),
    gsSPEndDisplayList(),
};

Gfx D_0A003738_E41998[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[160], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003798_E419F8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[152], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0037E0_E41A40[] = {
    gsSPDisplayList(D_0A003798_E419F8),
    gsSPDisplayList(D_0A003738_E41998),
    gsSPEndDisplayList(),
};

Gfx D_0A0037F8_E41A58[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[60], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[63], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[65], 2, 2),
    gsSPVertex(&D_0A000000_E3E260[69], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[134], 10, 6),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(8, 2, 3, 0, 8, 3, 9, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003878_E41AD8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[144], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0038C0_E41B20[] = {
    gsSPDisplayList(D_0A003878_E41AD8),
    gsSPDisplayList(D_0A0037F8_E41A58),
    gsSPEndDisplayList(),
};

Gfx D_0A0038D8_E41B38[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[52], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[55], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[60], 1, 2),
    gsSPVertex(&D_0A000000_E3E260[63], 1, 3),
    gsSPVertex(&D_0A000000_E3E260[65], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[69], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[132], 12, 8),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsSP2Triangles(12, 4, 5, 0, 12, 5, 13, 0),
    gsSP2Triangles(14, 6, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003970_E41BD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[128], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0039B0_E41C10[] = {
    gsSPDisplayList(D_0A003970_E41BD0),
    gsSPDisplayList(D_0A0038D8_E41B38),
    gsSPEndDisplayList(),
};

Gfx D_0A0039C8_E41C28[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[32], 1, 0),
    gsSPVertex(&D_0A000000_E3E260[35], 1, 1),
    gsSPVertex(&D_0A000000_E3E260[40], 1, 2),
    gsSPVertex(&D_0A000000_E3E260[43], 1, 3),
    gsSPVertex(&D_0A000000_E3E260[45], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[118], 10, 6),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(2, 8, 9, 0, 2, 9, 3, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003A50_E41CB0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[110], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003A98_E41CF8[] = {
    gsSPDisplayList(D_0A003A50_E41CB0),
    gsSPDisplayList(D_0A0039C8_E41C28),
    gsSPEndDisplayList(),
};

Gfx D_0A003AB0_E41D10[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[56], 4, 0),
    gsSPVertex(&D_0A000000_E3E260[61], 2, 4),
    gsSPVertex(&D_0A000000_E3E260[64], 1, 6),
    gsSPVertex(&D_0A000000_E3E260[67], 2, 7),
    gsSPVertex(&D_0A000000_E3E260[71], 1, 9),
    gsSPVertex(&D_0A000000_E3E260[96], 10, 10),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(10, 4, 5, 0, 10, 5, 11, 0),
    gsSP2Triangles(6, 12, 13, 0, 6, 13, 7, 0),
    gsSP2Triangles(8, 14, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003B40_E41DA0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[106], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003B80_E41DE0[] = {
    gsSPDisplayList(D_0A003B40_E41DA0),
    gsSPDisplayList(D_0A003AB0_E41D10),
    gsSPEndDisplayList(),
};

Gfx D_0A003B98_E41DF8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[53], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[56], 4, 2),
    gsSPVertex(&D_0A000000_E3E260[61], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[64], 1, 8),
    gsSPVertex(&D_0A000000_E3E260[67], 2, 9),
    gsSPVertex(&D_0A000000_E3E260[71], 1, 11),
    gsSPVertex(&D_0A000000_E3E260[94], 12, 12),
    gsSP2Triangles(12, 0, 1, 0, 12, 1, 13, 0),
    gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(14, 6, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(8, 16, 17, 0, 8, 17, 9, 0),
    gsSP2Triangles(10, 18, 19, 0, 10, 19, 11, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003C38_E41E98[] = {
    gsSPDisplayList(D_0A003B98_E41DF8),
    gsSPEndDisplayList(),
};

Gfx D_0A003C48_E41EA8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[33], 2, 0),
    gsSPVertex(&D_0A000000_E3E260[36], 4, 2),
    gsSPVertex(&D_0A000000_E3E260[41], 2, 6),
    gsSPVertex(&D_0A000000_E3E260[44], 1, 8),
    gsSPVertex(&D_0A000000_E3E260[47], 1, 9),
    gsSPVertex(&D_0A000000_E3E260[84], 10, 10),
    gsSP2Triangles(10, 0, 1, 0, 10, 1, 11, 0),
    gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(12, 6, 7, 0, 12, 7, 13, 0),
    gsSP2Triangles(8, 14, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003CD8_E41F38[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[80], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003D18_E41F78[] = {
    gsSPDisplayList(D_0A003CD8_E41F38),
    gsSPDisplayList(D_0A003C48_E41EA8),
    gsSPEndDisplayList(),
};

Gfx D_0A003D30_E41F90[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[56], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003D90_E41FF0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[72], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003DD8_E42038[] = {
    gsSPDisplayList(D_0A003D90_E41FF0),
    gsSPDisplayList(D_0A003D30_E41F90),
    gsSPEndDisplayList(),
};

Gfx D_0A003DF0_E42050[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[52], 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003E58_E420B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[48], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003E98_E420F8[] = {
    gsSPDisplayList(D_0A003E58_E420B8),
    gsSPDisplayList(D_0A003DF0_E42050),
    gsSPEndDisplayList(),
};

Gfx D_0A003EB0_E42110[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[32], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003F10_E42170[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(D_0A0022A0_E40500),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E3E260[24], 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003F58_E421B8[] = {
    gsSPDisplayList(D_0A003F10_E42170),
    gsSPDisplayList(D_0A003EB0_E42110),
    gsSPEndDisplayList(),
};

Gfx* Entity_ShatteringBrickBlock_FragmentsRender[] = {
    D_0A003F58_E421B8,
    D_0A003E98_E420F8,
    D_0A003DD8_E42038,
    D_0A003D18_E41F78,
    D_0A003C38_E41E98,
    D_0A003B80_E41DE0,
    D_0A003A98_E41CF8,
    D_0A0039B0_E41C10,
    D_0A0038C0_E41B20,
    D_0A0037E0_E41A40,
    D_0A003720_E41980,
    D_0A003660_E418C0,
    D_0A0035A0_E41800,
    D_0A0034B8_E41718,
    D_0A0033D0_E41630,
    D_0A0032E8_E41548,
    D_0A0031F8_E41458,
    D_0A003118_E41378,
    D_0A003050_E412B0,
    D_0A002F90_E411F0,
    D_0A002EC8_E41128,
    D_0A002DE8_E41048,
    D_0A002D30_E40F90,
    D_0A002C48_E40EA8,
    D_0A002B58_E40DB8,
    D_0A002A68_E40CC8,
};

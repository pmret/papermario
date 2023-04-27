#include "common.h"

#include "entity/model/WoodenCrate.vtx.inc.c"

#include "entity/model/WoodenCrate_img1.png.inc.c"
#include "entity/model/WoodenCrate_img1.pal.inc.c"
Gfx Entity_WoodenCrate_LoadTexture1[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A001D60_E533A0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_03, PM_CC_03),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A001560_E52BA0, G_IM_FMT_CI, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/WoodenCrate_img2.png.inc.c"
#include "entity/model/WoodenCrate_img2.pal.inc.c"
Gfx Entity_WoodenCrate_LoadTexture2[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A002628_E53C68),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A001E28_E53468, G_IM_FMT_CI, 64, 64, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_WoodenCrate_FragmentsMatrices[] = {
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF5001E, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC000A000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0006001E, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x4000A000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF40015, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC71CE000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00050015, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x471CE000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF6000A, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xEAABD555, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0006000B, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x92F7F1C7, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFFE0002, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x80008000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF50023, 0xFFF10001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC0000000, 0x60000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00060023, 0xFFF10001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x40000000, 0x60000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF40023, 0xFFFA0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC71C0000, 0x20000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00050023, 0xFFFA0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x471C0000, 0x20000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF60023, 0x00040001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xEAAB0000, 0x2AAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00060023, 0x00030001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x92F70000, 0x0E390000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFFE0023, 0x000C0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x80000000, 0x80000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC001E, 0xFFF50001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000A000, 0xC0000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC001E, 0x00060001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000A000, 0x40000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC0015, 0xFFF40001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000E000, 0xC71C0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC0015, 0x00050001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000E000, 0x471C0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC000A, 0xFFF60001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000D555, 0xEAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC000B, 0x00060001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000F1C7, 0x92F70000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC0002, 0xFFFE0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00008000, 0x80000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F001E, 0xFFF50001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000A000, 0xC0000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F001E, 0x00060001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000A000, 0x40000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F0015, 0xFFF40001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000E000, 0xC71C0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F0015, 0x00050001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000E000, 0x471C0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F000A, 0xFFF60001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000D555, 0xEAAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F000B, 0x00060001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x0000F1C7, 0x92F70000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F0002, 0xFFFE0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x00008000, 0x80000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF5001E, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC000A000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0006001E, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x4000A000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF40015, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC71CE000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00050015, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x471CE000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF6000A, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xEAABD555, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x0006000B, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x92F7F1C7, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFFE0002, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x80008000, 0x00000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF50000, 0xFFF10001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC0000000, 0x60000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00060000, 0xFFF10001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x40000000, 0x60000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF40000, 0xFFFA0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC71C0000, 0x20000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00050000, 0xFFFA0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x471C0000, 0x20000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFF60000, 0x00040001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xEAAB0000, 0x2AAB0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x00060000, 0x00030001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x92F70000, 0x0E390000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFFE0000, 0x000C0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x80000000, 0x80000000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC0011, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC7B18000, 0x384F0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F0011, 0x000F0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x384F8000, 0x384F0000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0x000F0011, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0x384F8000, 0xC7B10000 }
        }
    },
    {
        .m = {
            { 0x00010000, 0x00000000,
              0x00000001, 0x00000000 },
            { 0x00000000, 0x00010000,
              0xFFEC0011, 0xFFEC0001 },
            { 0x00000000, 0x00000000,
              0x00000000, 0x00000000 },
            { 0x00000000, 0x00000000,
              0xC7B18000, 0xC7B10000 }
        }
    },
};

Gfx D_0A003270_E548B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[274], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0032B0_E548F0[] = {
    gsSPDisplayList(D_0A003270_E548B0),
    gsSPEndDisplayList(),
};

Gfx D_0A0032C0_E54900[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[265], 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 8, 0),
    gsSP1Triangle(4, 8, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003318_E54958[] = {
    gsSPDisplayList(D_0A0032C0_E54900),
    gsSPEndDisplayList(),
};

Gfx D_0A003328_E54968[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[255], 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 6, 5, 0, 7, 5, 8, 0),
    gsSP1Triangle(7, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003388_E549C8[] = {
    gsSPDisplayList(D_0A003328_E54968),
    gsSPEndDisplayList(),
};

Gfx D_0A003398_E549D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[249], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0033E0_E54A20[] = {
    gsSPDisplayList(D_0A003398_E549D8),
    gsSPEndDisplayList(),
};

Gfx D_0A0033F0_E54A30[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[243], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003438_E54A78[] = {
    gsSPDisplayList(D_0A0033F0_E54A30),
    gsSPEndDisplayList(),
};

Gfx D_0A003448_E54A88[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[239], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003488_E54AC8[] = {
    gsSPDisplayList(D_0A003448_E54A88),
    gsSPEndDisplayList(),
};

Gfx D_0A003498_E54AD8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[235], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0034D8_E54B18[] = {
    gsSPDisplayList(D_0A003498_E54AD8),
    gsSPEndDisplayList(),
};

Gfx D_0A0034E8_E54B28[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[145], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003528_E54B68[] = {
    gsSPDisplayList(D_0A0034E8_E54B28),
    gsSPEndDisplayList(),
};

Gfx D_0A003538_E54B78[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[136], 9, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 5, 4, 0, 2, 4, 1, 0),
    gsSP2Triangles(5, 8, 7, 0, 5, 7, 6, 0),
    gsSP1Triangle(5, 6, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003590_E54BD0[] = {
    gsSPDisplayList(D_0A003538_E54B78),
    gsSPEndDisplayList(),
};

Gfx D_0A0035A0_E54BE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[126], 10, 0),
    gsSP2Triangles(4, 3, 2, 0, 4, 2, 1, 0),
    gsSP2Triangles(4, 1, 0, 0, 0, 1, 7, 0),
    gsSP2Triangles(0, 7, 6, 0, 0, 6, 5, 0),
    gsSP2Triangles(5, 6, 7, 0, 5, 7, 9, 0),
    gsSP1Triangle(5, 9, 8, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003600_E54C40[] = {
    gsSPDisplayList(D_0A0035A0_E54BE0),
    gsSPEndDisplayList(),
};

Gfx D_0A003610_E54C50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[120], 6, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 5, 4, 0, 2, 4, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003658_E54C98[] = {
    gsSPDisplayList(D_0A003610_E54C50),
    gsSPEndDisplayList(),
};

Gfx D_0A003668_E54CA8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[114], 6, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 1, 5, 0, 0, 5, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0036B0_E54CF0[] = {
    gsSPDisplayList(D_0A003668_E54CA8),
    gsSPEndDisplayList(),
};

Gfx D_0A0036C0_E54D00[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[110], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003700_E54D40[] = {
    gsSPDisplayList(D_0A0036C0_E54D00),
    gsSPEndDisplayList(),
};

Gfx D_0A003710_E54D50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[106], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003750_E54D90[] = {
    gsSPDisplayList(D_0A003710_E54D50),
    gsSPEndDisplayList(),
};

Gfx D_0A003760_E54DA0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[231], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0037A0_E54DE0[] = {
    gsSPDisplayList(D_0A003760_E54DA0),
    gsSPEndDisplayList(),
};

Gfx D_0A0037B0_E54DF0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[222], 9, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 5, 4, 0, 2, 4, 1, 0),
    gsSP2Triangles(5, 8, 7, 0, 5, 7, 6, 0),
    gsSP1Triangle(5, 6, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003808_E54E48[] = {
    gsSPDisplayList(D_0A0037B0_E54DF0),
    gsSPEndDisplayList(),
};

Gfx D_0A003818_E54E58[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[212], 10, 0),
    gsSP2Triangles(4, 3, 2, 0, 4, 2, 1, 0),
    gsSP2Triangles(4, 1, 0, 0, 0, 1, 7, 0),
    gsSP2Triangles(0, 7, 6, 0, 0, 6, 5, 0),
    gsSP2Triangles(5, 6, 7, 0, 5, 7, 9, 0),
    gsSP1Triangle(5, 9, 8, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003878_E54EB8[] = {
    gsSPDisplayList(D_0A003818_E54E58),
    gsSPEndDisplayList(),
};

Gfx D_0A003888_E54EC8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[206], 6, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 5, 4, 0, 2, 4, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0038D0_E54F10[] = {
    gsSPDisplayList(D_0A003888_E54EC8),
    gsSPEndDisplayList(),
};

Gfx D_0A0038E0_E54F20[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[200], 6, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 1, 5, 0, 0, 5, 4, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003928_E54F68[] = {
    gsSPDisplayList(D_0A0038E0_E54F20),
    gsSPEndDisplayList(),
};

Gfx D_0A003938_E54F78[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[196], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003978_E54FB8[] = {
    gsSPDisplayList(D_0A003938_E54F78),
    gsSPEndDisplayList(),
};

Gfx D_0A003988_E54FC8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[192], 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0039C8_E55008[] = {
    gsSPDisplayList(D_0A003988_E54FC8),
    gsSPEndDisplayList(),
};

Gfx D_0A0039D8_E55018[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[231], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003A18_E55058[] = {
    gsSPDisplayList(D_0A0039D8_E55018),
    gsSPEndDisplayList(),
};

Gfx D_0A003A28_E55068[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[222], 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 8, 0),
    gsSP1Triangle(4, 8, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003A80_E550C0[] = {
    gsSPDisplayList(D_0A003A28_E55068),
    gsSPEndDisplayList(),
};

Gfx D_0A003A90_E550D0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[212], 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(5, 7, 1, 0, 5, 1, 0, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP1Triangle(8, 6, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003AF0_E55130[] = {
    gsSPDisplayList(D_0A003A90_E550D0),
    gsSPEndDisplayList(),
};

Gfx D_0A003B00_E55140[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[206], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003B48_E55188[] = {
    gsSPDisplayList(D_0A003B00_E55140),
    gsSPEndDisplayList(),
};

Gfx D_0A003B58_E55198[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[200], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003BA0_E551E0[] = {
    gsSPDisplayList(D_0A003B58_E55198),
    gsSPEndDisplayList(),
};

Gfx D_0A003BB0_E551F0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[196], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003BF0_E55230[] = {
    gsSPDisplayList(D_0A003BB0_E551F0),
    gsSPEndDisplayList(),
};

Gfx D_0A003C00_E55240[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[192], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003C40_E55280[] = {
    gsSPDisplayList(D_0A003C00_E55240),
    gsSPEndDisplayList(),
};

Gfx D_0A003C50_E55290[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[188], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003C90_E552D0[] = {
    gsSPDisplayList(D_0A003C50_E55290),
    gsSPEndDisplayList(),
};

Gfx D_0A003CA0_E552E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[179], 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 8, 0),
    gsSP1Triangle(4, 8, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003CF8_E55338[] = {
    gsSPDisplayList(D_0A003CA0_E552E0),
    gsSPEndDisplayList(),
};

Gfx D_0A003D08_E55348[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[169], 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(5, 7, 1, 0, 5, 1, 0, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP1Triangle(8, 6, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003D68_E553A8[] = {
    gsSPDisplayList(D_0A003D08_E55348),
    gsSPEndDisplayList(),
};

Gfx D_0A003D78_E553B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[163], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003DC0_E55400[] = {
    gsSPDisplayList(D_0A003D78_E553B8),
    gsSPEndDisplayList(),
};

Gfx D_0A003DD0_E55410[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[157], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003E18_E55458[] = {
    gsSPDisplayList(D_0A003DD0_E55410),
    gsSPEndDisplayList(),
};

Gfx D_0A003E28_E55468[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[153], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003E68_E554A8[] = {
    gsSPDisplayList(D_0A003E28_E55468),
    gsSPEndDisplayList(),
};

Gfx D_0A003E78_E554B8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[149], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003EB8_E554F8[] = {
    gsSPDisplayList(D_0A003E78_E554B8),
    gsSPEndDisplayList(),
};

Gfx D_0A003EC8_E55508[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[145], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003F08_E55548[] = {
    gsSPDisplayList(D_0A003EC8_E55508),
    gsSPEndDisplayList(),
};

Gfx D_0A003F18_E55558[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[136], 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 8, 0),
    gsSP1Triangle(4, 8, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003F70_E555B0[] = {
    gsSPDisplayList(D_0A003F18_E55558),
    gsSPEndDisplayList(),
};

Gfx D_0A003F80_E555C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[126], 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(5, 7, 1, 0, 5, 1, 0, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP1Triangle(8, 6, 5, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A003FE0_E55620[] = {
    gsSPDisplayList(D_0A003F80_E555C0),
    gsSPEndDisplayList(),
};

Gfx D_0A003FF0_E55630[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[120], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A004038_E55678[] = {
    gsSPDisplayList(D_0A003FF0_E55630),
    gsSPEndDisplayList(),
};

Gfx D_0A004048_E55688[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[114], 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A004090_E556D0[] = {
    gsSPDisplayList(D_0A004048_E55688),
    gsSPEndDisplayList(),
};

Gfx D_0A0040A0_E556E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[110], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A0040E0_E55720[] = {
    gsSPDisplayList(D_0A0040A0_E556E0),
    gsSPEndDisplayList(),
};

Gfx D_0A0040F0_E55730[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[106], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A004130_E55770[] = {
    gsSPDisplayList(D_0A0040F0_E55730),
    gsSPEndDisplayList(),
};

Gfx D_0A004140_E55780[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture2),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E51640[9], 3, 0),
    gsSPVertex(&D_0A000000_E51640[24], 1, 3),
    gsSPVertex(&D_0A000000_E51640[30], 2, 4),
    gsSPVertex(&D_0A000000_E51640[48], 25, 6),
    gsSP2Triangles(0, 6, 7, 0, 2, 1, 7, 0),
    gsSP2Triangles(2, 7, 8, 0, 9, 10, 3, 0),
    gsSP2Triangles(11, 9, 5, 0, 11, 5, 4, 0),
    gsSP2Triangles(12, 11, 13, 0, 14, 15, 9, 0),
    gsSP2Triangles(14, 9, 11, 0, 13, 11, 16, 0),
    gsSP2Triangles(17, 10, 9, 0, 18, 10, 17, 0),
    gsSP2Triangles(19, 20, 21, 0, 21, 22, 19, 0),
    gsSP2Triangles(23, 22, 21, 0, 22, 24, 25, 0),
    gsSP2Triangles(22, 25, 26, 0, 27, 28, 24, 0),
    gsSP2Triangles(27, 24, 22, 0, 29, 30, 24, 0),
    gsSPVertex(&D_0A000000_E51640[49], 2, 0),
    gsSPVertex(&D_0A000000_E51640[66], 1, 2),
    gsSPVertex(&D_0A000000_E51640[72], 14, 3),
    gsSPVertex(&D_0A000000_E51640[88], 15, 17),
    gsSP2Triangles(2, 3, 4, 0, 5, 17, 18, 0),
    gsSP2Triangles(6, 19, 20, 0, 7, 10, 21, 0),
    gsSP2Triangles(7, 21, 22, 0, 8, 23, 10, 0),
    gsSP2Triangles(9, 24, 10, 0, 9, 10, 7, 0),
    gsSP2Triangles(10, 23, 25, 0, 11, 26, 12, 0),
    gsSP2Triangles(12, 7, 11, 0, 11, 7, 27, 0),
    gsSP2Triangles(13, 28, 29, 0, 14, 1, 16, 0),
    gsSP2Triangles(1, 0, 15, 0, 1, 15, 30, 0),
    gsSP1Triangle(16, 1, 31, 0),
    gsSPVertex(&D_0A000000_E51640[48], 2, 0),
    gsSPVertex(&D_0A000000_E51640[86], 2, 2),
    gsSPVertex(&D_0A000000_E51640[103], 3, 4),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 4, 0),
    gsSP1Triangle(3, 5, 6, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A004268_E558A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_WoodenCrate_LoadTexture1),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000000_E51640[0], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(8, 11, 12, 0, 8, 12, 13, 0),
    gsSP2Triangles(8, 13, 14, 0, 8, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(16, 19, 20, 0, 16, 20, 21, 0),
    gsSP2Triangles(16, 21, 22, 0, 16, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(24, 27, 28, 0, 24, 28, 29, 0),
    gsSP2Triangles(24, 29, 30, 0, 24, 30, 31, 0),
    gsSPVertex(&D_0A000000_E51640[32], 16, 0),
    gsSP2Triangles(0, 2, 3, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 4, 5, 0, 0, 5, 6, 0),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 8, 0),
    gsSP2Triangles(1, 9, 10, 0, 1, 10, 11, 0),
    gsSP2Triangles(1, 11, 12, 0, 1, 12, 13, 0),
    gsSP2Triangles(1, 13, 14, 0, 1, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_WoodenCrate_Render[] = {
    gsSPDisplayList(D_0A004268_E558A8),
    gsSPDisplayList(D_0A004140_E55780),
    gsSPEndDisplayList(),
};

Gfx* Entity_WoodenCrate_FragmentsRender[] = {
    D_0A004130_E55770,
    D_0A0040E0_E55720,
    D_0A004090_E556D0,
    D_0A004038_E55678,
    D_0A003FE0_E55620,
    D_0A003F70_E555B0,
    D_0A003F08_E55548,
    D_0A003EB8_E554F8,
    D_0A003E68_E554A8,
    D_0A003E18_E55458,
    D_0A003DC0_E55400,
    D_0A003D68_E553A8,
    D_0A003CF8_E55338,
    D_0A003C90_E552D0,
    D_0A003C40_E55280,
    D_0A003BF0_E55230,
    D_0A003BA0_E551E0,
    D_0A003B48_E55188,
    D_0A003AF0_E55130,
    D_0A003A80_E550C0,
    D_0A003A18_E55058,
    D_0A0039C8_E55008,
    D_0A003978_E54FB8,
    D_0A003928_E54F68,
    D_0A0038D0_E54F10,
    D_0A003878_E54EB8,
    D_0A003808_E54E48,
    D_0A0037A0_E54DE0,
    D_0A003750_E54D90,
    D_0A003700_E54D40,
    D_0A0036B0_E54CF0,
    D_0A003658_E54C98,
    D_0A003600_E54C40,
    D_0A003590_E54BD0,
    D_0A003528_E54B68,
    D_0A0034D8_E54B18,
    D_0A003488_E54AC8,
    D_0A003438_E54A78,
    D_0A0033E0_E54A20,
    D_0A003388_E549C8,
    D_0A003318_E54958,
    D_0A0032B0_E548F0,
};

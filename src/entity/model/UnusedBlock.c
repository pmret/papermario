#include "common.h"
#include "include_asset.h"

#include "entity/model/UnusedBlock.vtx.inc.c"

INCLUDE_IMG("entity/model/UnusedBlock_img1.png", D_0A0003C0_E3D190);
Gfx D_0A0007C0_E3D590[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A0003C0_E3D190, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/UnusedBlock_img2.png", D_0A000848_E3D618);
INCLUDE_PAL("entity/model/UnusedBlock_img2.pal", D_0A000948_E3D718);
Gfx D_0A000968_E3D738[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000848_E3D618, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000948_E3D718),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx D_0A000A20_E3D7F0 = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx D_0A000A60_E3D830[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPDisplayList(D_0A0007C0_E3D590),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000000_E3CDD0[4], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000AA8_E3D878[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPDisplayList(D_0A0007C0_E3D590),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_0A000AE0_E3D8B0[] = {
    gsSPDisplayList(D_0A000AA8_E3D878),
    gsSPVertex(&D_0A000000_E3CDD0[8], 28, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSPVertex(&D_0A000000_E3CDD0[36], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000B28_E3D8F8[] = {
    gsSPDisplayList(D_0A000AA8_E3D878),
    gsSPVertex(&D_0A000000_E3CDD0[8], 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSPVertex(&D_0A000000_E3CDD0[56], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPVertex(&D_0A000000_E3CDD0[36], 16, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000B78_E3D948[] = {
    gsSPDisplayList(D_0A000AA8_E3D878),
    gsSPVertex(&D_0A000000_E3CDD0[8], 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPVertex(&D_0A000000_E3CDD0[36], 16, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000BC0_E3D990[] = {
    gsSPDisplayList(D_0A000AA8_E3D878),
    gsSPVertex(&D_0A000000_E3CDD0[8], 28, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSPVertex(&D_0A000000_E3CDD0[56], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPVertex(&D_0A000000_E3CDD0[36], 16, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C10_E3D9E0[] = {
    gsSPDisplayList(D_0A000AA8_E3D878),
    gsSPVertex(&D_0A000000_E3CDD0[52], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C30_E3DA00[] = {
    gsSPDisplayList(D_0A000A60_E3D830),
    gsSPEndDisplayList(),
};

Gfx D_0A000C40_E3DA10[] = {
    gsSPDisplayList(D_0A000C10_E3D9E0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C50_E3DA20[] = {
    gsSPDisplayList(D_0A000AE0_E3D8B0),
    gsSPEndDisplayList(),
};

Gfx D_0A000C60_E3DA30[] = {
    gsSPDisplayList(D_0A000B28_E3D8F8),
    gsSPEndDisplayList(),
};

Gfx D_0A000C70_E3DA40[] = {
    gsSPDisplayList(D_0A000BC0_E3D990),
    gsSPEndDisplayList(),
};

Gfx D_0A000C80_E3DA50[] = {
    gsSPDisplayList(D_0A000B78_E3D948),
    gsSPEndDisplayList(),
};

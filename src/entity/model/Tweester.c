#include "common.h"
#include "include_asset.h"

#include "entity/model/Tweester_1.vtx.inc.c"
#include "entity/model/Tweester_2.vtx.inc.c"
#include "entity/model/Tweester_3.vtx.inc.c"
#include "entity/model/Tweester_4.vtx.inc.c"

INCLUDE_IMG("entity/model/Tweester_img1.png", D_0A000BF0_E57A50);
INCLUDE_IMG("entity/model/Tweester_img2.png", D_0A000FF0_E57E50);
Gfx Entity_Tweester_LoadTextures[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_ALT_INTERFERENCE, G_CC_MODULATEIA2),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000BF0_E57A50),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x007C, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000FF0_E57E50),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x007C, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0, 0x007C, 0x007C),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/Tweester_img3.png", D_0A0014A0_E58300);
INCLUDE_PAL("entity/model/Tweester_img3.pal", D_0A0018A0_E58700);
Gfx Entity_Tweester_LoadTextureFace[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A0018A0_E58700),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A0014A0_E58300, G_IM_FMT_CI, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_Tweester_mtxInnerWhirl = RDP_MATRIX(
    0.999848, 0.017457, 0.000000, 0.000000,
    -0.01746, 0.999848, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Mtx Entity_Tweester_mtxOuterWhirl = RDP_MATRIX(
    1.199997, 0.000000, 0.000000, 0.000000,
    0.000000, 0.899994, 0.000000, 0.000000,
    0.000000, 0.000000, 1.199997, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx D_0A0019E8_E58848[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPDisplayList(Entity_Tweester_LoadTextures),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000860_E576C0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP2Triangles(5, 1, 6, 0, 7, 1, 8, 0),
    gsSP2Triangles(9, 1, 10, 0, 11, 1, 12, 0),
    gsSP2Triangles(13, 1, 14, 0, 15, 1, 16, 0),
    gsSP2Triangles(17, 18, 2, 0, 17, 2, 19, 0),
    gsSP2Triangles(20, 21, 17, 0, 20, 17, 19, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
    gsSP2Triangles(24, 26, 14, 0, 24, 14, 25, 0),
    gsSP2Triangles(27, 28, 12, 0, 27, 12, 29, 0),
    gsSPVertex(&D_0A000860_E576C0[4], 1, 0),
    gsSPVertex(&D_0A000860_E576C0[6], 1, 1),
    gsSPVertex(&D_0A000860_E576C0[8], 1, 2),
    gsSPVertex(&D_0A000860_E576C0[16], 1, 3),
    gsSPVertex(&D_0A000860_E576C0[27], 1, 4),
    gsSPVertex(&D_0A000860_E576C0[29], 27, 5),
    gsSP2Triangles(6, 17, 3, 0, 6, 3, 18, 0),
    gsSP2Triangles(7, 19, 6, 0, 7, 6, 18, 0),
    gsSP2Triangles(8, 20, 4, 0, 8, 4, 5, 0),
    gsSP2Triangles(9, 21, 10, 0, 9, 10, 22, 0),
    gsSP2Triangles(10, 23, 0, 0, 10, 0, 22, 0),
    gsSP2Triangles(11, 24, 12, 0, 11, 12, 25, 0),
    gsSP2Triangles(12, 26, 1, 0, 12, 1, 25, 0),
    gsSP2Triangles(13, 27, 2, 0, 13, 2, 28, 0),
    gsSP2Triangles(14, 29, 13, 0, 14, 13, 28, 0),
    gsSP2Triangles(15, 30, 16, 0, 15, 16, 31, 0),
    gsSPVertex(&D_0A000860_E576C0[10], 1, 0),
    gsSPVertex(&D_0A000860_E576C0[40], 1, 1),
    gsSPVertex(&D_0A000860_E576C0[55], 2, 2),
    gsSP2Triangles(1, 3, 0, 0, 1, 0, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001B10_E58970[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000820_E57680, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001B50_E589B0[] = {
    gsSPDisplayList(D_0A001B10_E58970),
    gsSPDisplayList(D_0A0019E8_E58848),
    gsSPEndDisplayList(),
};

Gfx Entity_Tweester_RenderOuterWhirl[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000410_E57270, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 0, 3, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 8, 5, 0),
    gsSP2Triangles(7, 5, 6, 0, 9, 7, 10, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(12, 14, 15, 0, 13, 16, 14, 0),
    gsSP2Triangles(10, 12, 15, 0, 10, 15, 11, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(18, 21, 22, 0, 18, 22, 23, 0),
    gsSP2Triangles(19, 24, 25, 0, 19, 25, 20, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 26, 28, 0),
    gsSP2Triangles(29, 28, 30, 0, 22, 29, 30, 0),
    gsSP1Triangle(22, 30, 23, 0),
    gsSPVertex(&D_0A000410_E57270[9], 1, 0),
    gsSPVertex(&D_0A000410_E57270[21], 1, 1),
    gsSPVertex(&D_0A000410_E57270[24], 2, 2),
    gsSPVertex(&D_0A000410_E57270[31], 14, 4),
    gsSPVertex(&D_0A000410_E57270[47], 14, 18),
    gsSP2Triangles(1, 4, 13, 0, 1, 13, 18, 0),
    gsSP2Triangles(2, 5, 19, 0, 2, 19, 3, 0),
    gsSP2Triangles(5, 20, 19, 0, 6, 0, 16, 0),
    gsSP2Triangles(6, 16, 21, 0, 7, 8, 22, 0),
    gsSP2Triangles(7, 22, 23, 0, 8, 9, 24, 0),
    gsSP2Triangles(8, 24, 22, 0, 9, 25, 24, 0),
    gsSP2Triangles(4, 10, 7, 0, 4, 7, 23, 0),
    gsSP2Triangles(10, 6, 17, 0, 10, 17, 26, 0),
    gsSP2Triangles(11, 12, 27, 0, 11, 27, 28, 0),
    gsSP2Triangles(12, 29, 27, 0, 13, 11, 28, 0),
    gsSP2Triangles(13, 28, 18, 0, 14, 30, 31, 0),
    gsSPVertex(&D_0A000410_E57270[41], 6, 0),
    gsSPVertex(&D_0A000410_E57270[50], 1, 6),
    gsSPVertex(&D_0A000410_E57270[55], 1, 7),
    gsSPVertex(&D_0A000410_E57270[60], 5, 8),
    gsSP2Triangles(1, 0, 8, 0, 1, 8, 9, 0),
    gsSP2Triangles(2, 1, 9, 0, 2, 9, 6, 0),
    gsSP2Triangles(3, 4, 10, 0, 3, 10, 7, 0),
    gsSP2Triangles(4, 5, 11, 0, 4, 11, 10, 0),
    gsSP1Triangle(5, 12, 11, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001CD0_E58B30[] = {
    gsSPMatrix(&Entity_Tweester_mtxOuterWhirl, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_Tweester_RenderOuterWhirl),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_Tweester_RenderInnerWhirl[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E56E60, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 0, 3, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 8, 5, 0),
    gsSP2Triangles(7, 5, 6, 0, 9, 7, 10, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(12, 14, 15, 0, 13, 16, 14, 0),
    gsSP2Triangles(10, 12, 15, 0, 10, 15, 11, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(18, 21, 22, 0, 18, 22, 23, 0),
    gsSP2Triangles(19, 24, 25, 0, 19, 25, 20, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 26, 28, 0),
    gsSP2Triangles(29, 28, 30, 0, 22, 29, 30, 0),
    gsSP1Triangle(22, 30, 23, 0),
    gsSPVertex(&D_0A000000_E56E60[9], 1, 0),
    gsSPVertex(&D_0A000000_E56E60[21], 1, 1),
    gsSPVertex(&D_0A000000_E56E60[24], 2, 2),
    gsSPVertex(&D_0A000000_E56E60[31], 14, 4),
    gsSPVertex(&D_0A000000_E56E60[47], 14, 18),
    gsSP2Triangles(1, 4, 13, 0, 1, 13, 18, 0),
    gsSP2Triangles(2, 5, 19, 0, 2, 19, 3, 0),
    gsSP2Triangles(5, 20, 19, 0, 6, 0, 16, 0),
    gsSP2Triangles(6, 16, 21, 0, 7, 8, 22, 0),
    gsSP2Triangles(7, 22, 23, 0, 8, 9, 24, 0),
    gsSP2Triangles(8, 24, 22, 0, 9, 25, 24, 0),
    gsSP2Triangles(4, 10, 7, 0, 4, 7, 23, 0),
    gsSP2Triangles(10, 6, 17, 0, 10, 17, 26, 0),
    gsSP2Triangles(11, 12, 27, 0, 11, 27, 28, 0),
    gsSP2Triangles(12, 29, 27, 0, 13, 11, 28, 0),
    gsSP2Triangles(13, 28, 18, 0, 14, 30, 31, 0),
    gsSPVertex(&D_0A000000_E56E60[41], 6, 0),
    gsSPVertex(&D_0A000000_E56E60[50], 1, 6),
    gsSPVertex(&D_0A000000_E56E60[55], 1, 7),
    gsSPVertex(&D_0A000000_E56E60[60], 5, 8),
    gsSP2Triangles(1, 0, 8, 0, 1, 8, 9, 0),
    gsSP2Triangles(2, 1, 9, 0, 2, 9, 6, 0),
    gsSP2Triangles(3, 4, 10, 0, 3, 10, 7, 0),
    gsSP2Triangles(4, 5, 11, 0, 4, 11, 10, 0),
    gsSP1Triangle(5, 12, 11, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Tweester_Render[] = {
    gsSPDisplayList(D_0A001B50_E589B0),
    gsSPEndDisplayList(),
};

#include "common.h"
#include "include_asset.h"

#include "entity/model/PadlockRedFrame_1.vtx.inc.c"
#include "entity/model/PadlockRedFrame_2.vtx.inc.c"
#include "entity/model/PadlockRedFrame_3.vtx.inc.c"
#include "entity/model/PadlockRedFrame_4.vtx.inc.c"

INCLUDE_IMG("entity/model/PadlockRedFrame_keyhole.png", D_0A000540_E5D2C0);
INCLUDE_PAL("entity/model/PadlockRedFrame_keyhole.pal", D_0A000D40_E5DAC0);
Gfx Entity_PadlockRedFrame_LoadTextureKeyhole[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A000D40_E5DAC0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000540_E5D2C0, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 64, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/PadlockRedFrame_face.png", D_0A000FE8_E5DD68);
INCLUDE_PAL("entity/model/PadlockRedFrame_face.pal", D_0A0013E8_E5E168);
Gfx Entity_PadlockRedFrame_LoadTextureFace[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A0013E8_E5E168),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000FE8_E5DD68, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_PadlockRedFrame_mtxShackle = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx Entity_PadlockRedFrame_RenderShackleMain[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000280_E5D000, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(2, 4, 7, 0, 2, 7, 8, 0),
    gsSP2Triangles(3, 2, 8, 0, 3, 8, 9, 0),
    gsSP2Triangles(10, 9, 11, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 3, 9, 0, 13, 9, 10, 0),
    gsSP2Triangles(8, 7, 14, 0, 8, 14, 15, 0),
    gsSP2Triangles(11, 15, 16, 0, 11, 16, 17, 0),
    gsSP2Triangles(15, 14, 18, 0, 15, 18, 16, 0),
    gsSP2Triangles(12, 11, 17, 0, 12, 17, 19, 0),
    gsSP2Triangles(14, 20, 21, 0, 14, 21, 18, 0),
    gsSP2Triangles(7, 6, 20, 0, 7, 20, 14, 0),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_0A000280_E5D000[22], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000280_E5D000, 3, 0),
    gsSPVertex(&D_0A000280_E5D000[4], 2, 3),
    gsSPVertex(&D_0A000280_E5D000[8], 2, 5),
    gsSPVertex(&D_0A000280_E5D000[11], 1, 7),
    gsSPVertex(&D_0A000280_E5D000[15], 1, 8),
    gsSPVertex(&D_0A000280_E5D000[26], 18, 9),
    gsSP2Triangles(9, 10, 11, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 14, 10, 0, 13, 10, 9, 0),
    gsSP2Triangles(10, 15, 16, 0, 10, 16, 11, 0),
    gsSP2Triangles(14, 17, 15, 0, 14, 15, 10, 0),
    gsSP2Triangles(12, 11, 0, 0, 12, 0, 18, 0),
    gsSP2Triangles(11, 16, 1, 0, 11, 1, 0, 0),
    gsSP2Triangles(16, 19, 20, 0, 16, 20, 1, 0),
    gsSP2Triangles(19, 21, 22, 0, 19, 22, 20, 0),
    gsSP2Triangles(15, 23, 19, 0, 15, 19, 16, 0),
    gsSP2Triangles(23, 24, 21, 0, 23, 21, 19, 0),
    gsSP2Triangles(20, 22, 4, 0, 20, 4, 3, 0),
    gsSP2Triangles(1, 20, 3, 0, 1, 3, 2, 0),
    gsSP2Triangles(17, 25, 23, 0, 17, 23, 15, 0),
    gsSP2Triangles(25, 26, 24, 0, 25, 24, 23, 0),
    gsSP2Triangles(6, 5, 8, 0, 6, 8, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_RenderShackle[] = {
    gsSPDisplayList(Entity_PadlockRedFrame_RenderShackleMain),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_RenderKeyhole[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2),
    gsSPDisplayList(Entity_PadlockRedFrame_LoadTextureKeyhole),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000240_E5CFC0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_RenderFace[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_PadlockRedFrame_LoadTextureFace),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000200_E5CF80, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_RenderBody[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000000_E5CD80, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 6, 0),
    gsSP2Triangles(7, 8, 2, 0, 7, 2, 9, 0),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_RenderMain[] = {
    gsSPDisplayList(Entity_PadlockRedFrame_RenderBody),
    gsSPDisplayList(Entity_PadlockRedFrame_RenderFace),
    gsSPDisplayList(Entity_PadlockRedFrame_RenderKeyhole),
    gsSPEndDisplayList(),
};

Gfx Entity_PadlockRedFrame_Render[] = {
    gsSPDisplayList(Entity_PadlockRedFrame_RenderMain),
    gsSPDisplayList(Entity_PadlockRedFrame_RenderShackle),
    gsSPEndDisplayList(),
};

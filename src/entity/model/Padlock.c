#include "common.h"

#include "entity/model/Padlock_1.vtx.inc.c"
#include "entity/model/Padlock_2.vtx.inc.c"
#include "entity/model/Padlock_3.vtx.inc.c"
#include "entity/model/Padlock_4.vtx.inc.c"

#include "entity/model/Padlock_face.png.inc.c"
#include "entity/model/Padlock_face.pal.inc.c"
Gfx Entity_Padlock_LoadTextureFace[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A000B00_E5B650),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000700_E5B250, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/Padlock_keyhole.png.inc.c"
#include "entity/model/Padlock_keyhole.pal.inc.c"
Gfx Entity_Padlock_LoadTextureKeyhole[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A0015A8_E5C0F8),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000DA8_E5B8F8, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 64, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/Padlock_body.png.inc.c"
#include "entity/model/Padlock_body.pal.inc.c"
Gfx Entity_Padlock_LoadTextureBody[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A001C50_E5C7A0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A001850_E5C3A0, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_Padlock_mtxShackle = RDP_MATRIX(
    1.000000, 0.000000, 0.000000,  0.000000,
    0.000000, 1.000000, 0.000000, 22.500000,
    0.000000, 0.000000, 1.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  1.000000
);

Gfx Entity_Padlock_RenderShackleMain[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_0A000660_E5B1B0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(6, 0, 3, 0, 6, 3, 7, 0),
    gsSP2Triangles(8, 9, 6, 0, 8, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Padlock_RenderShackle[] = {
    gsSPDisplayList(Entity_Padlock_RenderShackleMain),
    gsSPEndDisplayList(),
};

Gfx Entity_Padlock_RenderKeyhole[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2),
    gsSPDisplayList(Entity_Padlock_LoadTextureKeyhole),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000620_E5B170, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Padlock_RenderFace[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Padlock_LoadTextureFace),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0005C0_E5B110, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Padlock_RenderBody[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Padlock_LoadTextureBody),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E5AB50, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(7, 10, 11, 0, 7, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 12, 0, 16, 12, 18, 0),
    gsSP2Triangles(14, 19, 20, 0, 14, 20, 21, 0),
    gsSP2Triangles(14, 21, 22, 0, 14, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(24, 27, 28, 0, 24, 28, 29, 0),
    gsSPVertex(&D_0A000000_E5AB50[1], 1, 1),
    gsSPVertex(&D_0A000000_E5AB50[17], 1, 2),
    gsSPVertex(&D_0A000000_E5AB50[23], 1, 3),
    gsSPVertex(&D_0A000000_E5AB50[27], 2, 4),
    gsSPVertex(&D_0A000000_E5AB50[30], 11, 6),
    gsSPVertex(&D_0A000000_E5AB50[54], 13, 17),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 7, 10, 17, 0),
    gsSP2Triangles(10, 14, 18, 0, 10, 18, 19, 0),
    gsSP2Triangles(10, 19, 8, 0, 10, 8, 17, 0),
    gsSP2Triangles(11, 20, 1, 0, 11, 1, 0, 0),
    gsSP2Triangles(12, 21, 22, 0, 12, 22, 2, 0),
    gsSP2Triangles(13, 12, 23, 0, 13, 23, 24, 0),
    gsSP2Triangles(9, 25, 26, 0, 9, 26, 27, 0),
    gsSP2Triangles(14, 27, 15, 0, 14, 15, 18, 0),
    gsSP2Triangles(15, 28, 5, 0, 15, 5, 19, 0),
    gsSP2Triangles(16, 13, 29, 0, 16, 29, 3, 0),
    gsSPVertex(&D_0A000000_E5AB50[6], 1, 0),
    gsSPVertex(&D_0A000000_E5AB50[9], 1, 1),
    gsSPVertex(&D_0A000000_E5AB50[19], 4, 2),
    gsSPVertex(&D_0A000000_E5AB50[24], 3, 6),
    gsSPVertex(&D_0A000000_E5AB50[29], 1, 9),
    gsSPVertex(&D_0A000000_E5AB50[41], 9, 10),
    gsSPVertex(&D_0A000000_E5AB50[67], 13, 19),
    gsSP2Triangles(10, 19, 11, 0, 10, 11, 20, 0),
    gsSP2Triangles(11, 17, 21, 0, 11, 21, 20, 0),
    gsSP2Triangles(12, 22, 0, 0, 12, 0, 1, 0),
    gsSP2Triangles(2, 13, 23, 0, 2, 23, 3, 0),
    gsSP2Triangles(4, 14, 24, 0, 4, 24, 5, 0),
    gsSP2Triangles(6, 9, 15, 0, 6, 15, 25, 0),
    gsSP2Triangles(7, 16, 26, 0, 7, 26, 8, 0),
    gsSP2Triangles(17, 27, 28, 0, 17, 28, 21, 0),
    gsSP2Triangles(18, 29, 30, 0, 18, 30, 31, 0),
    gsSPVertex(&D_0A000000_E5AB50[50], 4, 0),
    gsSPVertex(&D_0A000000_E5AB50[80], 12, 4),
    gsSP2Triangles(0, 4, 5, 0, 0, 5, 6, 0),
    gsSP2Triangles(1, 7, 8, 0, 1, 8, 9, 0),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 12, 0),
    gsSP2Triangles(3, 13, 14, 0, 3, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Padlock_Render[] = {
    gsSPDisplayList(Entity_Padlock_RenderBody),
    gsSPDisplayList(Entity_Padlock_RenderFace),
    gsSPDisplayList(Entity_Padlock_RenderKeyhole),
    gsSPEndDisplayList(),
};

#include "common.h"

#include "entity/model/SaveBlock_1.vtx.inc.c"
#include "entity/model/SaveBlock_2.vtx.inc.c"
#include "entity/model/SaveBlock_3.vtx.inc.c"

#include "entity/model/SaveBlock_star.png.inc.c"
Gfx Entity_SaveBlock_LoadTextureStar[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000900_E4BBE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#if !VERSION_PAL
#include "entity/model/SaveBlock_face.png.inc.c"
Gfx Entity_SaveBlock_LoadTextureFace[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A001170_E4C450, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};
#endif

#include "entity/model/SaveBlock_letterS.png.inc.c"
#if VERSION_PAL
#include "entity/model/SaveBlock_letterG.png.inc.c"
#endif

Gfx Entity_SaveBlock_LoadTextureLetterS[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A0021E8_E4D4C8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#if VERSION_PAL
Gfx Entity_SaveBlock_LoadTextureLetterG[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_PAL_0A002170_EBA460, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};
#endif

Mtx Entity_SaveBlock_Mtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx Entity_SaveBlock_RenderLetterS[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SaveBlock_LoadTextureLetterS),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0006C0_E4B9A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 0, 0, 4, 0, 3, 0),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSP2Triangles(8, 4, 3, 0, 8, 3, 7, 0),
    gsSP2Triangles(9, 10, 11, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 14, 9, 0, 13, 9, 12, 0),
    gsSP2Triangles(12, 11, 15, 0, 12, 15, 16, 0),
    gsSP2Triangles(17, 13, 12, 0, 17, 12, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
    gsSP2Triangles(20, 22, 23, 0, 20, 23, 21, 0),
    gsSP2Triangles(24, 25, 21, 0, 24, 21, 23, 0),
    gsSP2Triangles(25, 26, 18, 0, 25, 18, 21, 0),
    gsSP2Triangles(27, 28, 29, 0, 27, 29, 30, 0),
    gsSPVertex(&D_0A0006C0_E4B9A0[28], 8, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 1, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 5, 1, 0),
    gsSP2Triangles(5, 7, 2, 0, 5, 2, 1, 0),
    gsSPEndDisplayList(),
};

#if VERSION_PAL
Gfx Entity_SaveBlock_RenderLetterG[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SaveBlock_LoadTextureLetterG),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0006C0_E4B9A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 0, 0, 4, 0, 3, 0),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSP2Triangles(8, 4, 3, 0, 8, 3, 7, 0),
    gsSP2Triangles(9, 10, 11, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 14, 9, 0, 13, 9, 12, 0),
    gsSP2Triangles(12, 11, 15, 0, 12, 15, 16, 0),
    gsSP2Triangles(17, 13, 12, 0, 17, 12, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
    gsSP2Triangles(20, 22, 23, 0, 20, 23, 21, 0),
    gsSP2Triangles(24, 25, 21, 0, 24, 21, 23, 0),
    gsSP2Triangles(25, 26, 18, 0, 25, 18, 21, 0),
    gsSP2Triangles(27, 28, 29, 0, 27, 29, 30, 0),
    gsSPVertex(&D_0A0006C0_E4B9A0[28], 8, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 1, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 5, 1, 0),
    gsSP2Triangles(5, 7, 2, 0, 5, 2, 1, 0),
    gsSPEndDisplayList(),
};
#endif

Gfx Entity_SaveBlock_RenderFaces[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000370_E4B650, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(2, 4, 5, 0, 2, 5, 3, 0),
    gsSP2Triangles(1, 6, 7, 0, 1, 7, 2, 0),
    gsSP2Triangles(7, 8, 4, 0, 7, 4, 2, 0),
    gsSP2Triangles(9, 10, 11, 0, 9, 11, 12, 0),
    gsSP2Triangles(11, 13, 14, 0, 11, 14, 12, 0),
    gsSP2Triangles(15, 16, 12, 0, 15, 12, 14, 0),
    gsSP2Triangles(16, 17, 9, 0, 16, 9, 12, 0),
    gsSP2Triangles(18, 16, 19, 0, 18, 19, 20, 0),
    gsSP2Triangles(16, 21, 22, 0, 16, 22, 19, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 19, 0),
    gsSP2Triangles(24, 25, 20, 0, 24, 20, 19, 0),
    gsSP2Triangles(26, 27, 28, 0, 26, 28, 29, 0),
    gsSPVertex(&D_0A000370_E4B650[27], 26, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 1, 0),
    gsSP2Triangles(4, 14, 5, 0, 4, 5, 1, 0),
    gsSP2Triangles(5, 15, 2, 0, 5, 2, 1, 0),
    gsSP2Triangles(6, 16, 7, 0, 6, 7, 8, 0),
    gsSP2Triangles(7, 17, 18, 0, 7, 18, 8, 0),
    gsSP2Triangles(8, 18, 19, 0, 8, 19, 20, 0),
    gsSP2Triangles(9, 6, 8, 0, 9, 8, 20, 0),
    gsSP2Triangles(10, 21, 22, 0, 10, 22, 23, 0),
    gsSP2Triangles(11, 24, 10, 0, 11, 10, 23, 0),
    gsSP2Triangles(12, 13, 23, 0, 12, 23, 22, 0),
    gsSP2Triangles(13, 25, 11, 0, 13, 11, 23, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SaveBlock_RenderStar[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SaveBlock_LoadTextureStar),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000000_E4B2E0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 5, 1, 0),
    gsSP2Triangles(0, 4, 6, 0, 1, 7, 2, 0),
    gsSP2Triangles(2, 8, 3, 0, 3, 9, 4, 0),
    gsSP2Triangles(10, 11, 12, 0, 11, 13, 14, 0),
    gsSP2Triangles(11, 14, 15, 0, 11, 15, 12, 0),
    gsSP2Triangles(11, 16, 13, 0, 15, 17, 12, 0),
    gsSP2Triangles(13, 18, 14, 0, 14, 19, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SaveBlock_RenderContent[] = {
    gsSPDisplayList(Entity_SaveBlock_RenderStar),
    gsSPEndDisplayList(),
};

Gfx Entity_SaveBlock_RenderBlock[] = {
    gsSPDisplayList(Entity_SaveBlock_RenderFaces),
    gsSPDisplayList(Entity_SaveBlock_RenderLetterS),
    gsSPEndDisplayList(),
};

#if VERSION_PAL
Gfx Entity_SaveBlock_RenderBlock_es[] = {
    gsSPDisplayList(Entity_SaveBlock_RenderFaces),
    gsSPDisplayList(Entity_SaveBlock_RenderLetterG),
    gsSPEndDisplayList(),
};
#endif

Gfx Entity_SaveBlock_RenderNone[] = {
    gsSPEndDisplayList(),
};

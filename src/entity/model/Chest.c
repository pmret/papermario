#include "common.h"

Vtx Entity_Chest_vtxBox[] = {
    {{{   -26,    29,    23 }, 0, {  1024,  1024 }, { 151, 132, 105, 255 }}},
    {{{   -26,    29,   -23 }, 0, {     0,  1024 }, { 151, 132, 105, 255 }}},
    {{{   -23,     0,   -21 }, 0, {     0,     0 }, { 151, 132, 105, 255 }}},
    {{{   -23,     0,    21 }, 0, {  1024,     0 }, { 151, 132, 105, 255 }}},
    {{{   -23,     0,   -21 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    23,     0,   -21 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{    23,     0,    21 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -23,     0,    21 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{    23,     0,    21 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    26,    22,    22 }, 0, {  1012,   777 }, { 255, 255, 255, 255 }}},
    {{{   -26,    22,    22 }, 0, {    12,   777 }, { 255, 255, 255, 255 }}},
    {{{    26,    29,    23 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{     9,    29,    23 }, 0, {   704,  1024 }, { 255, 255, 255, 255 }}},
    {{{     8,    22,    22 }, 0, {   666,   777 }, { 255, 255, 255, 255 }}},
    {{{    -6,    29,    23 }, 0, {   384,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -26,    29,    23 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{    -4,    22,    22 }, 0, {   410,   777 }, { 255, 255, 255, 255 }}},
    {{{    23,     0,    21 }, 0, {     0,     0 }, { 151, 132, 105, 255 }}},
    {{{    23,     0,   -21 }, 0, {  1024,     0 }, { 151, 132, 105, 255 }}},
    {{{    26,    29,   -23 }, 0, {  1024,  1024 }, { 151, 132, 105, 255 }}},
    {{{    26,    29,    23 }, 0, {     0,  1024 }, { 151, 132, 105, 255 }}},
    {{{   -26,    29,   -23 }, 0, {     0,  1024 }, { 114, 100,  79, 255 }}},
    {{{    26,    29,   -23 }, 0, {  1024,  1024 }, { 114, 100,  79, 255 }}},
    {{{    23,     0,   -21 }, 0, {  1024,     0 }, { 114, 100,  79, 255 }}},
    {{{   -23,     0,   -21 }, 0, {     0,     0 }, { 114, 100,  79, 255 }}},
};

Vtx Entity_Chest_vtxLockTopHalf[] = {
    {{{     8,    22,    22 }, 0, {   896,   184 }, { 255, 255, 255, 255 }}},
    {{{     8,    22,    24 }, 0, {   896,   108 }, { 255, 255, 255, 255 }}},
    {{{    -4,    22,    24 }, 0, {   128,   108 }, { 255, 255, 255, 255 }}},
    {{{    -4,    22,    22 }, 0, {   128,   184 }, { 255, 255, 255, 255 }}},
    {{{    -6,    29,    24 }, 0, {    32,   642 }, { 255, 255, 255, 255 }}},
    {{{    -6,    29,    23 }, 0, {    32,   719 }, { 255, 255, 255, 255 }}},
    {{{     9,    29,    24 }, 0, {   992,   642 }, { 255, 255, 255, 255 }}},
    {{{     9,    29,    23 }, 0, {   992,   719 }, { 255, 255, 255, 255 }}},
};

Vtx Entity_Chest_vtxLid[] = {
    {{{    -4,     4,    43 }, 0, {   416,    87 }, { 255, 255, 255, 255 }}},
    {{{     8,     4,    43 }, 0, {   672,    87 }, { 255, 255, 255, 255 }}},
    {{{     9,     0,    46 }, 0, {   704,     0 }, { 255, 255, 255, 255 }}},
    {{{    -6,     0,    46 }, 0, {   384,    48 }, { 255, 255, 255, 255 }}},
    {{{    26,     0,    46 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    26,     4,    43 }, 0, {  1024,    87 }, { 255, 255, 255, 255 }}},
    {{{   -26,     0,    46 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{    -6,     0,    46 }, 0, {   384,    68 }, { 255, 255, 255, 255 }}},
    {{{    -4,     4,    43 }, 0, {   416,    87 }, { 255, 255, 255, 255 }}},
    {{{   -26,     4,    43 }, 0, {     0,    87 }, { 255, 255, 255, 255 }}},
    {{{   -25,     6,    43 }, 0, {     0,   128 }, { 255, 255, 255, 255 }}},
    {{{   -24,    12,    37 }, 0, {     0,   384 }, { 255, 255, 255, 255 }}},
    {{{   -24,    15,    28 }, 0, {     0,   768 }, { 255, 255, 255, 255 }}},
    {{{   -24,    15,    19 }, 0, {     0,  1152 }, { 255, 255, 255, 255 }}},
    {{{   -24,    12,     9 }, 0, {     0,  1536 }, { 255, 255, 255, 255 }}},
    {{{   -25,     6,     3 }, 0, {     0,  1792 }, { 255, 255, 255, 255 }}},
    {{{   -26,     0,     0 }, 0, {     0,  1920 }, { 255, 255, 255, 255 }}},
    {{{    25,     6,    43 }, 0, {  1024,   128 }, { 255, 255, 255, 255 }}},
    {{{    26,     0,     0 }, 0, {  1024,  1920 }, { 255, 255, 255, 255 }}},
    {{{    25,     6,     3 }, 0, {  1024,  1792 }, { 255, 255, 255, 255 }}},
    {{{    24,    12,     9 }, 0, {  1024,  1536 }, { 255, 255, 255, 255 }}},
    {{{    24,    15,    19 }, 0, {  1024,  1152 }, { 255, 255, 255, 255 }}},
    {{{    24,    15,    28 }, 0, {  1024,   768 }, { 255, 255, 255, 255 }}},
    {{{    24,    12,    37 }, 0, {  1024,   384 }, { 255, 255, 255, 255 }}},
};

Vtx Entity_Chest_vtxLockBottomHalf[] = {
    {{{     9,     0,    47 }, 0, {   992,   642 }, { 255, 255, 255, 255 }}},
    {{{     9,     0,    46 }, 0, {   992,   719 }, { 255, 255, 255, 255 }}},
    {{{     8,     4,    43 }, 0, {   896,  1108 }, { 255, 255, 255, 255 }}},
    {{{     8,     4,    46 }, 0, {   896,  1024 }, { 255, 255, 255, 255 }}},
    {{{    -4,     4,    46 }, 0, {   128,  1024 }, { 255, 255, 255, 255 }}},
    {{{    -6,     0,    47 }, 0, {    32,   642 }, { 255, 255, 255, 255 }}},
    {{{    -4,     4,    43 }, 0, {   128,  1108 }, { 255, 255, 255, 255 }}},
    {{{    -6,     0,    46 }, 0, {    32,   718 }, { 255, 255, 255, 255 }}},
};

#include "entity/model/Chest_tex1.png.inc.c"
Gfx Entity_Chest_LoadTexture1[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000410_E64CE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

#include "entity/model/Chest_tex2.png.inc.c"
#include "entity/model/Chest_tex2.pal.inc.c"
Gfx Entity_Chest_LoadTexture2[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000898_E65168, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000998_E65268),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

#include "entity/model/Chest_lock.png.inc.c"
#include "entity/model/Chest_lock.pal.inc.c"
Gfx Entity_Chest_LoadTextureLock[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000A70_E65340, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000B70_E65440),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx Entity_Chest_lidMtx = {
    .m = {
        { 0x00010000, 0x00000000,
          0x00000001, 0x00000000 },
        { 0x00000000, 0x00010000,
          0x0000001D, 0xFFE90001 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 }
    }
};

Gfx Entity_Chest_RenderLidLock[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTextureLock),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_Chest_vtxLockBottomHalf, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(3, 2, 6, 0, 3, 6, 4, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderLidWooden[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTexture2),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_Chest_vtxLid, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(&Entity_Chest_vtxLid[1], 2, 0),
    gsSPVertex(&Entity_Chest_vtxLid[4], 20, 2),
    gsSP2Triangles(1, 2, 3, 0, 1, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(4, 8, 9, 0, 4, 9, 10, 0),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 12, 0),
    gsSP2Triangles(4, 12, 13, 0, 4, 13, 14, 0),
    gsSP2Triangles(3, 15, 8, 0, 3, 8, 7, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(16, 19, 20, 0, 16, 20, 21, 0),
    gsSP2Triangles(16, 21, 15, 0, 16, 15, 2, 0),
    gsSP2Triangles(8, 15, 21, 0, 8, 21, 9, 0),
    gsSP2Triangles(9, 21, 20, 0, 9, 20, 10, 0),
    gsSP2Triangles(10, 20, 19, 0, 10, 19, 11, 0),
    gsSP2Triangles(11, 19, 18, 0, 11, 18, 12, 0),
    gsSP2Triangles(12, 18, 17, 0, 12, 17, 13, 0),
    gsSP2Triangles(13, 17, 16, 0, 13, 16, 14, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderLid[] = {
    gsSPDisplayList(Entity_Chest_RenderLidWooden),
    gsSPDisplayList(Entity_Chest_RenderLidLock),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBoxLock[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTextureLock),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_Chest_vtxLockTopHalf, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 1, 6, 0, 2, 6, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 1, 0, 7, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBoxWooden[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(Entity_Chest_vtxBox, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 8, 9, 0, 7, 9, 10, 0),
    gsSP2Triangles(9, 11, 12, 0, 9, 12, 13, 0),
    gsSP2Triangles(14, 15, 10, 0, 14, 10, 16, 0),
    gsSP2Triangles(12, 14, 16, 0, 12, 16, 13, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 21, 23, 24, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBox[] = {
    gsSPDisplayList(Entity_Chest_RenderBoxWooden),
    gsSPDisplayList(Entity_Chest_RenderBoxLock),
    gsSPEndDisplayList(),
};

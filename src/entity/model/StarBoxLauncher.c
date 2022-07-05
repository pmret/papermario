#include "common.h"

Vtx Entity_StarBoxLauncher_vtxBox[] = {
    {{{    16,     0,   -17 }, 0, {    29,     0 }, { 129, 160, 167, 255 }}},
    {{{    16,    25,   -17 }, 0, {    29,   731 }, {  82, 102, 107, 255 }}},
    {{{    16,    25,    16 }, 0, {   995,   731 }, {  82, 102, 107, 255 }}},
    {{{    16,     0,    16 }, 0, {   995,     0 }, { 129, 160, 167, 255 }}},
    {{{   -17,     0,    16 }, 0, {   995,     0 }, { 129, 160, 167, 255 }}},
    {{{   -17,    25,    16 }, 0, {   995,   731 }, {  82, 102, 107, 255 }}},
    {{{   -17,    25,   -17 }, 0, {    29,   731 }, {  82, 102, 107, 255 }}},
    {{{   -17,     0,   -17 }, 0, {    29,     0 }, { 129, 160, 167, 255 }}},
    {{{   -17,    25,   -17 }, 0, {    29,   731 }, { 129, 160, 167, 255 }}},
    {{{    16,    25,   -17 }, 0, {   995,   731 }, { 129, 160, 167, 255 }}},
    {{{    16,     0,   -17 }, 0, {   995,     0 }, { 129, 160, 167, 255 }}},
    {{{    16,     0,    16 }, 0, {   995,     0 }, { 255, 255, 255, 255 }}},
    {{{    16,    25,    16 }, 0, {   995,   731 }, { 129, 160, 167, 255 }}},
    {{{   -17,    25,    16 }, 0, {    29,   731 }, { 129, 160, 167, 255 }}},
    {{{   -17,     0,    16 }, 0, {    29,     0 }, { 255, 255, 255, 255 }}},
};

Vtx Entity_StarBoxLauncher_vtxBoxCover[] = {
    {{{   -18,    25,    18 }, 0, {  1024,   731 }, { 129, 160, 167, 255 }}},
    {{{   -18,    35,    18 }, 0, {  1024,  1024 }, { 129, 160, 167, 255 }}},
    {{{   -18,    35,   -18 }, 0, {     0,  1024 }, { 129, 160, 167, 255 }}},
    {{{   -18,    25,   -18 }, 0, {     0,   731 }, { 129, 160, 167, 255 }}},
    {{{    18,    35,   -18 }, 0, {  1024,  1024 }, { 129, 160, 167, 255 }}},
    {{{    18,    25,   -18 }, 0, {  1024,   731 }, { 129, 160, 167, 255 }}},
    {{{    18,    25,   -18 }, 0, {     0,   731 }, { 129, 160, 167, 255 }}},
    {{{    18,    35,   -18 }, 0, {     0,  1024 }, { 129, 160, 167, 255 }}},
    {{{    18,    35,    18 }, 0, {  1024,  1024 }, { 129, 160, 167, 255 }}},
    {{{    18,    25,    18 }, 0, {  1024,   731 }, { 129, 160, 167, 255 }}},
    {{{    18,    25,    18 }, 0, {  1024,   731 }, { 255, 255, 255, 255 }}},
    {{{    18,    35,    18 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -18,    35,    18 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -18,    25,    18 }, 0, {     0,   731 }, { 255, 255, 255, 255 }}},
    {{{   -18,    35,   -18 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -18,    35,    18 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{    18,    35,    18 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    18,    35,   -18 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
};

Vtx Entity_StarBoxLauncher_vtxFace[] = {
    {{{   -18,    -7,     0 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{    18,    -7,     0 }, 0, {  1024,     0 }, { 127, 158, 158, 255 }}},
    {{{    18,    29,     0 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -18,    29,     0 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
};

Vtx Entity_StarBoxLauncher_vtxChain[] = {
    {{{    -5,   -52,     0 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{     5,   -52,     0 }, 0, {   512,     0 }, { 127, 158, 158, 255 }}},
    {{{     5,    -6,     0 }, 0, {   512,  2336 }, { 127, 158, 158, 255 }}},
    {{{    -5,    -6,     0 }, 0, {     0,  2336 }, { 255, 255, 255, 255 }}},
};

#include "entity/model/StarBoxLauncher_link.png.inc.c"
Gfx Entity_StarBoxLauncher_LoadTextureLink[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000290_E55CD0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/StarBoxLauncher_face.png.inc.c"
#include "entity/model/StarBoxLauncher_face.pal.inc.c"
Gfx Entity_StarBoxLauncher_LoadTextureFace[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000D08_E56748),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000508_E55F48, G_IM_FMT_CI, 128, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/StarBoxLauncher_box.png.inc.c"
#include "entity/model/StarBoxLauncher_box.pal.inc.c"
Gfx Entity_StarBoxLauncher_LoadTextureBox[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000ED0_E56910),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000DD0_E56810, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_StarBoxLauncher_mtx = {
    .m = {
        { 0x00010000, 0x00000000,
          0x00000001, 0x00000000 },
        { 0x00000000, 0x00010000,
          0x00000000, 0x00000001 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 }
    }
};

Gfx Entity_StarBoxLauncher_RenderChain[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(Entity_StarBoxLauncher_LoadTextureLink),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_StarBoxLauncher_vtxChain, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_StarBoxLauncher_RenderFace[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(Entity_StarBoxLauncher_vtxFace, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_StarBoxLauncher_RenderBoxCover[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_StarBoxLauncher_LoadTextureBox),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(Entity_StarBoxLauncher_vtxBoxCover, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_StarBoxLauncher_RenderTop[] = {
    gsSPDisplayList(Entity_StarBoxLauncher_RenderFace),
    gsSPDisplayList(Entity_StarBoxLauncher_RenderBoxCover),
    gsSPDisplayList(Entity_StarBoxLauncher_RenderChain),
    gsSPEndDisplayList(),
};

Gfx Entity_StarBoxLauncher_RenderBox[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_StarBoxLauncher_LoadTextureBox),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(Entity_StarBoxLauncher_vtxBox, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 8, 9, 0, 7, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 11, 13, 14, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_StarBoxLauncher_RenderBottom[] = {
    gsSPDisplayList(Entity_StarBoxLauncher_RenderBox),
    gsSPEndDisplayList(),
};


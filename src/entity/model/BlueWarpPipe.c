#include "common.h"
#include "include_asset.h"

#include "entity/model/BlueWarpPipe_1.vtx.inc.c"
#include "entity/model/BlueWarpPipe_2.vtx.inc.c"
#include "entity/model/BlueWarpPipe_3.vtx.inc.c"

INCLUDE_IMG("entity/model/BlueWarpPipe_texBase.png", D_0A000320_E58FF0);
INCLUDE_PAL("entity/model/BlueWarpPipe_texBase.pal", D_0A0003A0_E59070);
Gfx Entity_BlueWarpPipe_LoadTextureBase[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000320_E58FF0, G_IM_FMT_CI, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A0003A0_E59070),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/BlueWarpPipe_texPipe.png", D_0A000470_E59140);
INCLUDE_PAL("entity/model/BlueWarpPipe_texPipe.pal", D_0A000570_E59240);
Gfx Entity_BlueWarpPipe_LoadTexturePipe[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000470_E59140, G_IM_FMT_CI, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000570_E59240),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx Entity_BlueWarpPipe_mtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000,   0.000000,
    0.000000, 1.000000, 0.000000, -55.000000,
    0.000000, 0.000000, 1.000000,   0.000000,
    0.000000, 0.000000, 0.000000,   1.000000
);

Gfx Entity_BlueWarpPipe_RenderBase[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Entity_BlueWarpPipe_LoadTextureBase),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A0002E0_E58FB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueWarpPipe_RenderPipe[] = {
    gsDPPipeSync(),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E58CD0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSPDisplayList(Entity_BlueWarpPipe_LoadTexturePipe),
    gsSPVertex(D_0A000060_E58D30, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSP2Triangles(3, 2, 6, 0, 3, 6, 7, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
    gsSP2Triangles(17, 16, 18, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 5, 0, 20, 5, 4, 0),
    gsSP2Triangles(9, 8, 21, 0, 9, 21, 20, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
    gsSP2Triangles(25, 24, 26, 0, 25, 26, 27, 0),
    gsSP2Triangles(27, 26, 28, 0, 27, 28, 29, 0),
    gsSPVertex(&D_0A000060_E58D30[10], 2, 0),
    gsSPVertex(&D_0A000060_E58D30[22], 2, 2),
    gsSPVertex(&D_0A000060_E58D30[30], 10, 4),
    gsSP2Triangles(4, 9, 10, 0, 4, 10, 6, 0),
    gsSP2Triangles(5, 11, 9, 0, 5, 9, 4, 0),
    gsSP2Triangles(6, 10, 3, 0, 6, 3, 2, 0),
    gsSP2Triangles(7, 12, 13, 0, 7, 13, 8, 0),
    gsSP2Triangles(8, 13, 1, 0, 8, 1, 0, 0),
    gsSPEndDisplayList(),
};

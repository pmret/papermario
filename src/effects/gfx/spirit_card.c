#include "PR/gbi.h"

#include "effects/gfx/star_cards/card_front.png.inc.c"
#include "effects/gfx/star_cards/card_front.pal.inc.c"

char D_09000220_3FA6D0[0x1E0] = { 0 };

#include "effects/gfx/star_cards/card_back.png.inc.c"
#include "effects/gfx/star_cards/card_back.pal.inc.c"

char D_09000820_3FACD0[0x1E0] = { 0 };

#include "effects/gfx/star_cards/wave.png.inc.c"
#include "effects/gfx/star_cards/wave.pal.inc.c"

char D_09000C20_3FB0D0[0x1E0] = { 0 };

#include "effects/gfx/star_cards/squares.png.inc.c"
#include "effects/gfx/star_cards/squares.pal.inc.c"

char D_09000EA0_3FB350[0x1E0] = { 0 };

#include "effects/gfx/star_cards/eldstar.png.inc.c"
#include "effects/gfx/star_cards/eldstar.pal.inc.c"

char D_09001520_3FB9D0[0x1E0] = { 0 };

#include "effects/gfx/star_cards/mamar.png.inc.c"
#include "effects/gfx/star_cards/mamar.pal.inc.c"

char D_09001BA0_3FC050[0x1E0] = { 0 };

#include "effects/gfx/star_cards/skolar.png.inc.c"
#include "effects/gfx/star_cards/skolar.pal.inc.c"

char D_09002220_3FC6D0[0x1E0] = { 0 };

#include "effects/gfx/star_cards/muskular.png.inc.c"
#include "effects/gfx/star_cards/muskular.pal.inc.c"

char D_090028A0_3FCD50[0x1E0] = { 0 };

#include "effects/gfx/star_cards/misstar.png.inc.c"
#include "effects/gfx/star_cards/misstar.pal.inc.c"

char D_09002F20_3FD3D0[0x1E0] = { 0 };

#include "effects/gfx/D_09003100_3FD5B0.png.inc.c"
#include "effects/gfx/D_09003100_3FD5B0.pal.inc.c"

char D_090035A0_3FDA50[0x1E0] = { 0 };

#include "effects/gfx/star_cards/klevar.png.inc.c"
#include "effects/gfx/star_cards/klevar.pal.inc.c"

char D_09003C20_3FE0D0[0x1E0] = { 0 };

char D_09003E00_3FE2B0[] = {
    0xFF, 0xF1, 0xFF, 0xE9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE1, 0x0, 0x6, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0xF, 0xFF, 0xE9, 0x0, 0x0, 0x0, 0x0, 0x7, 0x1F, 0x0, 0x6, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0x10, 0xFF, 0xEA, 0x0, 0x0, 0x0, 0x0, 0x7, 0x6D, 0x0, 0x23, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0x11, 0xFF, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x7, 0x9A, 0x0, 0x65, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0x11, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x7, 0x9A, 0x7, 0x6B, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0x10, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x7, 0x6D, 0x7, 0xAD, 0x0, 0x0, 0x7F, 0xFF, 0x0, 0xF, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x7, 0x1F, 0x7, 0xCA, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xF1, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE1, 0x7, 0xCA, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xF0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0x7, 0xAD, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xEF, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x7, 0x6B, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xEF, 0xFF, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x0, 0x65, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xF0, 0xFF, 0xEA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0x0, 0x23, 0x0, 0x0, 0x7F, 0xFF, 0xFF, 0xF0, 0xFF, 0xEA, 0x0, 0x0, 0x0, 0x0, 0x7, 0xCF, 0x0, 0x1D, 0x0, 0x0, 0x80, 0xFF, 0xFF, 0xEF, 0xFF, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x62, 0x0, 0x0, 0x80, 0xFF, 0xFF, 0xEF, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x7, 0x9E, 0x0, 0x0, 0x80, 0xFF, 0xFF, 0xF0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x7, 0xCF, 0x7, 0xE3, 0x0, 0x0, 0x80, 0xFF, 0xFF, 0xF1, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x7, 0x77, 0x8, 0x0, 0x0, 0x0, 0x80, 0xFF, 0x0, 0xF, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x0, 0x89, 0x8, 0x0, 0x0, 0x0, 0x80, 0xFF, 0x0, 0x10, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x31, 0x7, 0xE3, 0x0, 0x0, 0x80, 0xFF, 0x0, 0x11, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0x9E, 0x0, 0x0, 0x80, 0xFF, 0x0, 0x11, 0xFF, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x62, 0x0, 0x0, 0x80, 0xFF, 0x0, 0x10, 0xFF, 0xEA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x31, 0x0, 0x1D, 0x0, 0x0, 0x80, 0xFF, 0x0, 0xF, 0xFF, 0xE9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x89, 0x0, 0x0, 0x0, 0x0, 0x80, 0xFF, 0xFF, 0xF1, 0xFF, 0xE9, 0, 0, 0, 0, 0x7, 0x77, 0x0, 0x0, 0x0, 0, 0x80, 0xFF, 0xC8, 0xC8, 0xC8, 0, 0xC8, 0xC8, 0xC8, 0
};

extern Lights1 D_09003F80_3FE430;

// Lights1 D_09003F80_3FE430 = {
//     .a = {
//         .l = {
//             .col = {255, 255, 255},
//             .colc = {255, 255, 255}
//         }
//     },
//     .l = {
//         {
//             {
//                 .col = {0xE7, 0x5D, 0x52}
//             }
//         }
//     }
// };

char fake_09003F80_3FE430[] = {
    0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0x5D, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00
};

#include "effects/gfx/D_09003F98_3FE448.gfx.inc.c"
#include "effects/gfx/D_09004010_3FE4C0.gfx.inc.c"
#include "effects/gfx/D_09004088_3FE538.gfx.inc.c"
#include "effects/gfx/D_09004100_3FE5B0.gfx.inc.c"
#include "effects/gfx/D_09004178_3FE628.gfx.inc.c"
#include "effects/gfx/D_090041F0_3FE6A0.gfx.inc.c"
#include "effects/gfx/D_09004268_3FE718.gfx.inc.c"

//#include "effects/gfx/D_090042E0_3FE790.gfx.inc.c"
Gfx D_090042E0_3FE790[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsSPSetLights1(D_09003F80_3FE430),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

#include "effects/gfx/D_09004360_3FE810.gfx.inc.c"
#include "effects/gfx/D_090043D8_3FE888.vtx.inc.c"
#include "effects/gfx/D_09004418_3FE8C8.gfx.inc.c"
#include "effects/gfx/D_09004438_3FE8E8.gfx.inc.c"
#include "effects/gfx/D_09004458_3FE908.gfx.inc.c"
#include "effects/gfx/D_09004508_3FE9B8.gfx.inc.c"
#include "effects/gfx/D_09004600_3FEAB0.gfx.inc.c"

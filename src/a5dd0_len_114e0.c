#include "common.h"
#include "model.h"
#include "ld_addrs.h"

typedef struct GameMode {
    /* 0x00 */ u16 flags;
    /* 0x04 */ void (*init)(void);
    /* 0x08 */ void (*step)(void);
    /* 0x0C */ UNK_FUN_PTR(unk_0C);
    /* 0x10 */ void (*render)(void);
    /* 0x14 */ void (*renderAux)(void); ///< @see state_render_frontUI
} GameMode; // size = 0x18

typedef struct Fog {
    /* 0x00 */ s32 enabled;
    /* 0x04 */ s32 r;
    /* 0x08 */ s32 g;
    /* 0x0C */ s32 b;
    /* 0x10 */ s32 a;
    /* 0x14 */ s32 startDistance;
    /* 0x18 */ s32 endDistance;
} Fog; // size = 0x1C

extern Gfx D_8014B7F8[];
extern Gfx D_8014B820[];
extern Gfx D_8014B848[];
extern Gfx D_8014B870[];
extern Gfx D_8014B898[];
extern Gfx D_8014B8C0[];
extern Gfx D_8014B8E8[];
extern Gfx D_8014B910[];
extern Gfx D_8014B938[];
extern Gfx D_8014B960[];
extern Gfx D_8014B988[];
extern Gfx D_8014B9B0[];
extern Gfx D_8014B9D8[];
extern Gfx D_8014BA00[];
extern Gfx D_8014BA20[];
extern Gfx D_8014BA48[];
extern Gfx D_8014BA70[];
extern Gfx D_8014BA98[];
extern Gfx D_8014BAC0[];
extern Gfx D_8014BAE8[];
extern Gfx D_8014BB10[];
extern Gfx D_8014BB38[];
extern Gfx D_8014BB60[];
extern Gfx D_8014BB88[];
extern Gfx D_8014BBB0[];
extern Gfx D_8014BBD8[];
extern Gfx D_8014BC00[];
extern Gfx D_8014BC28[];
extern Gfx D_8014BC50[];
extern Gfx D_8014BC78[];
extern Gfx D_8014BCA0[];
extern Gfx D_8014BCC8[];
extern Gfx D_8014BCF8[];
extern Gfx D_8014BD18[];
extern Gfx D_8014BD40[];
extern Gfx D_8014BD68[];
extern Gfx D_8014BD88[];
extern Gfx D_8014BDB0[];
extern Gfx D_8014BDD8[];
extern Gfx D_8014BE00[];
extern Gfx D_8014BE28[];
extern Gfx D_8014BE50[];
extern Gfx D_8014BE78[];
extern Gfx D_8014BEA0[];
extern Gfx D_8014BEC8[];
extern Gfx D_8014BEF0[];
extern Gfx D_8014BF18[];
extern Gfx D_8014BF40[];
extern Gfx D_8014BF68[];
extern Gfx D_8014BF90[];
extern Gfx D_8014BFB8[];
extern Gfx D_8014BFE0[];
extern Gfx D_8014C008[];
extern Gfx D_8014C028[];
extern Gfx D_8014C050[];
extern Gfx D_8014C078[];
extern Gfx D_8014C098[];
extern Gfx D_8014C0C0[];
extern Gfx D_8014C0E8[];
extern Gfx D_8014C110[];
extern Gfx D_8014C138[];
extern Gfx D_8014C160[];

s32 D_8014AFB0 = 0xFF;

s32 D_8014AFB4[] = {0, 0, 0};

Gfx* D_8014AFC0[] = { D_8014B7F8, D_8014B910, D_8014B820, D_8014B938, D_8014B848, D_8014B960, D_8014B870, D_8014B988, D_8014B898, D_8014BA20, D_8014B9B0, D_8014BAC0, D_8014B8C0, D_8014B9D8, D_8014B8E8, D_8014BA00 };

Gfx* D_8014B000[] = { D_8014BB60, D_8014BC78, D_8014BB88, D_8014BCA0, D_8014BBB0, D_8014BCC8, D_8014BBD8, D_8014BCF8, D_8014BC00, D_8014BD88, D_8014BD18, D_8014BC28, D_8014BD40, D_8014BC50, D_8014BD68, D_8014BE78, D_8014BF90, D_8014BEA0, D_8014BFB8, D_8014BEC8, D_8014BFE0, D_8014BEF0, D_8014C008, D_8014BF18, D_8014C098, D_8014C028, D_8014BF40, D_8014C050, D_8014BF68, D_8014C078, D_8014BA48, D_8014BA70, D_8014BA98, D_8014BDB0, D_8014BDD8, D_8014BE00, D_8014C0C0, D_8014C0E8, D_8014C110, D_8014BB10, D_8014BB38, D_8014BE28, D_8014BE50, D_8014C138, D_8014C160, NULL };

s32 D_8014B0B8 = 0xFCFFFFFF;

s32 D_8014B0BC[] = { 0xFFFE793C, 0xFCFFFFFF, 0xFFFE7838, 0xFCFFFFFF, 0xFFFE7838, 0xFC457FFF, 0xFFFDF838, 0xFC41FFFF, 0xFFFEF838, 0xFC121824, 0xFF33FFFF, 0xFC127FFF, 0xFFFFF238, 0xFC1219FF, 0xFFFFFE38, 0xFC127E0A, 0xF3FFF238, 0xFC121803, 0xFFFFFF78, 0xFC147E28, 0x44FE793C, 0xFC147FFF, 0x4FFE7838, 0xFC147FFF, 0x4FFE7838, 0xFC147E0A, 0x4FFE72F8, 0xFC147E03, 0x4FFE7978, 0xFCFFFFFF, 0xFFFCF279, 0xFCFFFFFF, 0xFFFCF238, 0xFCFFFFFF, 0xFFFCF238, 0xFC157FFF, 0xFFFDF238, 0xFCFFFE03, 0xFFFCF378, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFF13FFFF, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFF13FFFF, 0xFC20A204, 0xFF13FFFF, 0xFC20A203, 0xFF13FF7F, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF9883, 0xFFFFAF78, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FE03, 0x2FFD7378, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61FEC3, 0x11FCF279, 0xFC61FFFF, 0x1FFCF238, 0xFC61FFFF, 0x1FFCF238, 0xFC61FFFF, 0x1FFCF238, 0xFC61FE03, 0x1FFCF378, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, };

s32 D_8014B400 = 0xFCFFFFFF;

s32 D_8014B404[] = { 0xFFFE793C, 0xFCFFFFFF, 0xFFFE7838, 0xFCFFFFFF, 0xFFFE7838, 0xFC457FFF, 0xFFFDF838, 0xFC41FFFF, 0xFFFEF838, 0xFC127E24, 0xFFFFF3F9, 0xFC127FFF, 0xFFFFF238, 0xFC127FFF, 0xFFFFF238, 0xFC127E0A, 0xF3FFF238, 0xFC127E03, 0xFFFFF378, 0xFC147E28, 0x44FE793C, 0xFC147FFF, 0x4FFE7838, 0xFC147FFF, 0x4FFE7838, 0xFC147E0A, 0x4FFE72F8, 0xFC147E03, 0x4FFE7978, 0xFCFFFFFF, 0xFFFCF279, 0xFCFFFFFF, 0xFFFCF238, 0xFCFFFFFF, 0xFFFCF238, 0xFC157FFF, 0xFFFDF238, 0xFCFFFE03, 0xFFFCF378, 0xFC26A004, 0x1FFC93FC, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1FFC93FC, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC93F8, 0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1FFC92F8, 0xFC26A003, 0x1FFC9378, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFF13FF7F, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFFFFFF78, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFFFFFF78, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFFFFFF78, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFFFFFF78, 0xFC20A204, 0xFFFFFFF8, 0xFC111404, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A204, 0xFFFFFFF8, 0xFC20A203, 0xFFFFFF78, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF99FF, 0xFFFFAF38, 0xFCFF9883, 0xFFFFAF78, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FFFF, 0x2FFD7238, 0xFC15FE03, 0x2FFD7378, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61E4C1, 0x12FC9238, 0xFC61FEC3, 0x11FCF279, 0xFC61FFFF, 0x1FFCF238, 0xFC61FFFF, 0x1FFCF238, 0xFC61FFFF, 0x1FFCF238, 0xFC61FE03, 0x1FFCF378, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC10E228, 0x40C8A449, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, 0xFC75FEEB, 0xFFFFFDFE, };

s32 mdl_textureBaseAddress = 0x8028E000;

s8 mdl_bgMultiplyColorA = 0;
s8 mdl_bgMultiplyColorR = 0;
s8 mdl_bgMultiplyColorG = 0;
s8 mdl_bgMultiplyColorB = 0;

s8 mdl_renderModelFogPrimColorR = 0;
s8 mdl_renderModelFogPrimColorG = 0;
s8 mdl_renderModelFogPrimColorB = 0;
s8 mdl_renderModelFogPrimColorA = 0;

s8 mdl_renderModelFogColorR = 0;
s8 mdl_renderModelFogColorG = 0;
s8 mdl_renderModelFogColorB = 0;
s8 mdl_renderModelFogColorA = 0; // unused?

s32 mdl_renderModelFogStart = 950;
s32 mdl_renderModelFogEnd = 1000;

s8 gRenderModelPrimR = 255;
s8 gRenderModelPrimG = 255;
s8 gRenderModelPrimB = 255;
s8 gRenderModelEnvR = 0;
s8 gRenderModelEnvG = 0;
s8 gRenderModelEnvB = 0;
s8 D_8014B766 = 0;
s8 D_8014B767 = 0;

Matrix4s mdl_RDPIdentity = {
    .whole = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    },
    .frac = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

s32 D_8014B7A8[] = { 0x00000006, 0x00000000, 0x00000005, 0x00020000, 0x00000004, 0x00030000, 0x00000003, 0x00038000, 0x00000002, 0x0003C000, 0x00000001, 0x0003E000, 0x00000000, 0x0003F000, 0x00000000, 0x0003F800, 0x00000000, 0x00000000, };

s32 D_8014B7F0[] = { 0x00000000, 0x00000000, };

Gfx D_8014B7F8[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B820[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_DECAL, G_RM_AA_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B848[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B870[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B898[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B8C0[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B8E8[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_INTER, G_RM_AA_ZB_XLU_INTER2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B910[] = {
    gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B938[] = {
    gsDPSetRenderMode(G_RM_ZB_OPA_DECAL, G_RM_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B960[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

Gfx D_8014B988[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B9B0[] = {
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014B9D8[] = {
    gsDPSetRenderMode(G_RM_ZB_OVL_SURF, G_RM_ZB_OVL_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BA00[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BA20[] = {
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                      GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | Z_UPD | IM_RD |
                      CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                      GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BA48[] = {
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BA70[] = {
    gsDPSetRenderMode(G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BA98[] = {
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BAC0[] = {
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                      GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | Z_UPD | IM_RD |
                      CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                      GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BAE8[] = {
    gsDPSetRenderMode(IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                      GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU |
                      FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BB10[] = {
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BB38[] = {
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BB60[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BB88[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BBB0[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BBD8[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BC00[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BC28[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BC50[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BC78[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BCA0[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BCC8[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

Gfx D_8014BCF8[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BD18[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BD40[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BD68[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BD88[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BDB0[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BDD8[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BE00[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BE28[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BE50[] = {
    gsDPSetRenderMode(G_RM_PASS, G_RM_CLD_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BE78[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BEA0[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BEC8[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BEF0[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BF18[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BF40[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BF68[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BF90[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BFB8[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014BFE0[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C008[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C028[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C050[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_DECAL2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C078[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C098[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C0C0[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C0E8[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_TEX_EDGE2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C110[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_XLU_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C138[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_CLD_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_8014C160[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_CLD_SURF2),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

s32 D_8014C188[] = { 0xFFFE7960, 0x000F4240, 0x000F4240, 0x000F4240, 0x00000000, 0x000F4240, 0x000F4240, 0x000F4240, 0x00000000, 0x000F4240, 0x000F4240, 0x000F4240, 0x00000000, 0x000F4240, 0x000F4240, 0x000F4240, 0x00000000, 0x007A1200, 0x007A1200, 0x007A1200, 0x00000000, 0x007A1200, 0x007270E0, 0x007270E0, 0x007270E0, 0x00000000, 0x006ACFC0, 0x006ACFC0, 0x006ACFC0, 0x006ACFC0, 0x00632EA0, 0x00632EA0, 0x00632EA0, 0x00000000, 0x005B8D80, 0x005B8D80, 0x005B8D80, 0x00000000, 0x0053EC60, 0x0053EC60, 0x0053EC60, 0x007A1200, 0x003D0900, 0x0040D990, 0x0044AA20, 0x0044AA20, 0x007A1200, 0x000AAE60, };  // render mode -> distance map?

s8 D_8014C248[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

// TODO BSS to sort out
extern ModelNode** gCurrentModelTreeRoot;
extern ModelTransformGroupList wTransformGroups;
extern ModelTransformGroupList bTransformGroups;

// BSS
static s32 B_801512B0[2];
static ModelCustomGfxBuilderList* gCurrentCustomModelGfxBuildersPtr;
static s32 D_801512BC;
static s32 D_801512C0;
static s32 gEntityHeapBase;
static s32 D_801512C8;
BSS ModelList* gCurrentModels;
static s32 D_801512D0[4];
static ModelTransformGroupList* gCurrentTransformGroups;
static s8 gMsgGlobalWaveCounter[0x4];
static ModelCustomGfxList* gCurrentCustomModelGfxPtr;
static s32 gLastCreatedEntityIndex;
static s8 B_801512F0[0x410];
static GameMode gMainGameState[2]; // TODO rename

extern s32 D_80151324;
extern s32 D_8015132C;
extern s32 D_80151330;

extern s32 wStaticEntityDataSize;
extern s32 bStaticEntityDataSize;

extern StaticEntityData* wStaticEntityData[30];
extern StaticEntityData* bStaticEntityData[4];

extern TileDescriptor gCurrentTileDescriptor;

extern ModelList wModelList;
extern ModelList bModelList;

// TODO: potentially a display list, figure this out
extern u32* wModelSpecialDls[32];
extern u32* bModelSpecialDls[32];


extern ModelCustomGfxBuilder wCustomModelGfxBuilders;
extern ModelCustomGfxBuilder bCustomModelGfxBuilders;
extern ModelLocalVertexCopy** D_80152190;
extern ModelLocalVertexCopy** D_801521D0;

extern ModelLocalVertexCopy** gCurrentModelLocalVtxBuffers;
extern ModelNode* D_80152214;
extern ModelNode* D_80152218;
extern ModelTreeInfoList D_80152220;
extern ModelTreeInfoList D_80152A20;

extern s8 wBgRenderType;
extern s8 bBgRenderType;
extern s32 mdl_treeIterPos;
extern Fog wFogSettings;
extern Fog bFogSettings;
extern Fog* gCurrentFogSettings;
extern s32 texPannerMainU[MAX_TEX_PANNERS];
extern s32 texPannerMainV[MAX_TEX_PANNERS];
extern s32 texPannerAuxU[MAX_TEX_PANNERS];
extern s32 texPannerAuxV[MAX_TEX_PANNERS];
extern u16 mdl_currentTransformGroupChildIndex;
extern ModelNode* D_80153370;
extern u16 D_80153374;
extern u16 D_80153376;
extern s16 D_8015336E;
extern RenderTask* mdl_renderTaskLists[3];
extern s32 mdl_renderTaskMode;
extern s32 mdl_renderTaskCount; // num render task entries?

extern s8 D_8015A578;
extern TextureHandle mdl_textureHandles[128];
extern RenderTask mdl_clearRenderTasks[3][0x100];

void update_shadows(void);
s32 step_entity_commandlist(Entity* entity);
void render_shadows(void);
void update_entity_transform_matrix(Entity* entity);
void update_shadow_transform_matrix(Shadow* shadow);
void update_entity_inverse_rotation_matrix(Entity* entity);
void delete_entity(s32 entityIndex);
void delete_entity_and_unload_data(s32 entityIndex);
void _delete_shadow(s32 shadowIndex);
s32 entity_get_collision_flags(Entity* entity);
void entity_free_static_data(StaticEntityData* data);
void update_entity_shadow_position(Entity* entity);
void load_model_transforms(ModelNode* model, ModelNode* parent, Matrix4f mdlTxMtx, s32 treeDepth);
void enable_transform_group(u16 modelID);

void update_entities(void) {
    s32 i;

    D_801512BC = 0;
    D_801512C0 = 0;
    D_80151330++;

    for (i = 0; i < MAX_ENTITIES; i++) {
        Entity* entity = get_entity_by_index(i);

        if (entity != NULL) {
            D_801512C0++;

            if (!(entity->flags & 0x40000000)) {
                if (entity->flags & 0x1000000) {
                    entity->flags &= ~0x1000000;
                    if (!(entity->flags & 0x8000)) {
                        entity->flags |= 0x2000000;
                    }
                    entity->boundScript = start_script(entity->boundScriptBytecode, 0xA, 0x20);
                }

                if (entity->flags & 0x2000000) {
                    if (does_script_exist(entity->boundScript->id)) {
                        if (entity->flags & 8) {
                            update_model_animator(entity->virtualModelIndex);
                        } else {
                            exec_entity_model_commandlist(entity->virtualModelIndex);
                        }

                        if (entity->flags & 0x2000) {
                            entity->rotation.y = -gCameras[gCurrentCameraID].currentYaw;
                        }

                        if (!(entity->flags & 0x10)) {
                            update_entity_transform_matrix(entity);
                        }
                        continue;
                    } else {
                        entity->flags &= ~0x2000000;
                    }
                }

                if (entity->unk_07 == 0) {
                    entity->collisionFlags = entity_get_collision_flags(entity);

                    if (entity->collisionFlags) {
                        EntityCallback entityCallback = entity->staticData->unk_data_ptr2;

                        if (entityCallback != NULL && entityCallback(entity) != 0) {
                            entity->unk_07 = 0xA;
                            entity->flags |= 0x10000;
                        }
                    }
                } else {
                    entity->unk_07--;
                    if (entity->flags & 0x40) {
                        if (entity->unk_07 == 0) {
                            entity->flags &= ~0x60;
                        } else {
                            entity->flags |= 0x20;
                        }
                    } else if (entity->unk_07 == 0) {
                        entity->flags &= ~0x10000;
                        entity->flags &= ~0x20000;
                        entity->collisionFlags = 0;
                    }
                }

                if (entity->flags & 0x2000) {
                    entity->rotation.y = -gCameras[gCurrentCameraID].currentYaw;
                }

                if (!gGameStatusPtr->disableScripts) {
                    if (entity->updateScriptCallback != NULL) {
                        entity->updateScriptCallback(entity);
                    }

                    if (entity->scriptReadPos != NULL) {
                        if (entity->hasEntityScript) {
                            entity->hasEntityScript--;
                            if (!(entity->hasEntityScript)) {
                                while (step_entity_commandlist(entity));
                            }
                        }
                    }
                }

                if (!(entity->flags & 0x10)) {
                    update_entity_transform_matrix(entity);
                }

                if (!(entity->flags & 0x20)) {
                    update_entity_inverse_rotation_matrix(entity);
                }

                if (entity->flags & 8) {
                    update_model_animator(entity->virtualModelIndex);
                } else {
                    exec_entity_model_commandlist(entity->virtualModelIndex);
                }

                if (entity->shadowIndex >= 0) {
                    update_entity_shadow_position(entity);
                }

                if (entity->flags & 0x20000000) {
                    delete_entity(entity->listIndex);
                }

                if (entity->flags & 0x4000000) {
                    delete_entity_and_unload_data(entity->listIndex);
                }
            }
        }
    }

    update_shadows();
    D_8015A578 = 0;
}

void update_shadows(void) {
    s32 i;

    D_80151324 = 0;

    for (i = 0; i < MAX_SHADOWS; i++) {
        Shadow* shadow = get_shadow_by_index(i);

        if (shadow != NULL) {
            D_80151324++;

            if (!(shadow->flags & 0x40000000)) {
                if (shadow->flags & 0x2000) {
                    shadow->rotation.y = -gCameras[gCurrentCameraID].currentYaw;
                }

                update_shadow_transform_matrix(shadow);

                if (shadow->flags & 8) {
                    update_model_animator(shadow->entityModelID);
                } else {
                    exec_entity_model_commandlist(shadow->entityModelID);
                }

                if (shadow->flags & 0x20000000) {
                    _delete_shadow(shadow->listIndex);
                }
            }
        }
    }
}

void set_entity_commandlist(Entity* entity, s32* entityScript) {
    entity->scriptReadPos = entityScript;
    entity->hasEntityScript = TRUE;
    entity->savedReadPos = entity->scriptReadPos;
}

// Ordering issues with the savedReadPos cases (4 and 5)
#ifdef NON_MATCHING
s32 step_entity_commandlist(Entity* entity) {
    s32* args = entity->scriptReadPos;
    s32 ret;
    s32 a1;
    s32 (*tempfunc)(Entity*);

    switch (*args++) {
        case 0:
            entity->hasEntityScript = -1;
            entity->updateScriptCallback = NULL;
            entity->scriptReadPos = NULL;
            ret = FALSE;
            break;
        case 1:
            entity->scriptReadPos = *args;
            entity->hasEntityScript = 1;
            entity->savedReadPos = entity->scriptReadPos;
            ret = TRUE;
            break;
        case 2:
            tempfunc = *args++;
            entity->scriptReadPos = args;
            (tempfunc)(entity);
            ret = TRUE;
            break;
        case 3:
            entity->hasEntityScript = *args++;
            entity->updateScriptCallback = (s32 (*)(Entity*)) *args++;
            entity->scriptReadPos = args++;
            ret = FALSE;
            break;
        case 4:
            entity->scriptReadPos = entity->savedReadPos[*args++];
            ret = TRUE;
            break;
        case 5:
            a1 = *args++;
            entity->savedReadPos[a1] = args;
            entity->scriptReadPos = args;
            ret = TRUE;
            break;
        case 6:
            if (entity->boundScriptBytecode != NULL) {
                entity->flags |= 0x1000000;
            }
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case 7:
            entity->flags |= *args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case 8:
            entity->flags &= ~*args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case 9:
            sfx_play_sound(*args++);
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        default:
            args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
    }
    return ret;
}
#else
INCLUDE_ASM(s32, "a5dd0_len_114e0", step_entity_commandlist, Entity* entity);
#endif

void exec_entity_commandlist(Entity* entity) {
    while (step_entity_commandlist(entity));
}

void func_8010FD98(s32 arg0, s32 alpha) {
    if (alpha >= 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
    }
}

void func_8010FE44(s32 arg0) {
    func_8010FD98(arg0, D_8014AFB0);
}

void entity_model_set_shadow_color(s32 alpha) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
}

void render_entities(void) {
    s32 i;

    for (i = 0; i < MAX_ENTITIES; i++) {
        Entity* entity = get_entity_by_index(i);

        if (entity != NULL) {
            if (!gGameStatusPtr->isBattle) {
                if (D_80151310 != 0 &&
                    !(entity->flags & 0x80000) &&
                    dist2D(gPlayerStatusPtr->position.x,
                           gPlayerStatusPtr->position.z,
                           entity->position.x,
                           entity->position.z) > 200.0f
                   ) {
                    continue;
                }

                if (D_80151310 == 1) {
                    if (!(entity->flags & 2)) {
                        continue;
                    }
                } else if (D_80151310 == 2) {
                    if (!(entity->flags & 0x40000)) {
                        continue;
                    }
                }
            }

            if (!(entity->flags & 1)) {
                if (entity->flags & 8) {
                    if (D_8014AFB0 == 0xFF) {
                        if (entity->renderSetupFunc != NULL) {
                            set_animator_render_callback(entity->virtualModelIndex, entity->listIndex, entity->renderSetupFunc);
                        }
                    } else {
                        set_animator_render_callback(entity->virtualModelIndex, entity->listIndex, func_8010FE44);
                    }

                    if (entity->vertexData == NULL) {
                        render_animated_model(entity->virtualModelIndex, &entity->transformMatrix);
                    } else {
                        render_animated_model_with_vertices(entity->virtualModelIndex,
                                      &entity->transformMatrix,
                                      entity->vertexSegment,
                                      entity->vertexData);
                    }
                } else {
                    if (D_8014AFB0 == 0xFF) {
                        if (entity->renderSetupFunc != NULL) {
                            bind_entity_model_setupGfx(entity->virtualModelIndex,
                                                       entity->listIndex,
                                                       entity->renderSetupFunc);
                        } else {
                            get_entity_model(entity->virtualModelIndex)->fpSetupGfxCallback = NULL;
                        }
                    } else {
                        bind_entity_model_setupGfx(entity->virtualModelIndex, entity->listIndex, func_8010FE44);
                    }

                    if (entity->vertexData == NULL) {
                        draw_entity_model_A(entity->virtualModelIndex, &entity->transformMatrix);
                    } else {
                        draw_entity_model_B(entity->virtualModelIndex,
                                               &entity->transformMatrix,
                                               entity->vertexSegment,
                                               entity->vertexData);
                    }
                }
            }
        }
    }

    render_shadows();
}

void render_shadows(void) {
    s32 i;

    for (i = 0; i < MAX_SHADOWS; i++) {
        Shadow* shadow = get_shadow_by_index(i);

        if (shadow != NULL) {
            if (shadow->flags & 1) {
                if (shadow->flags & 0x10000000) {
                    shadow->unk_05 -= 20;
                    if (shadow->unk_05 <= 20) {
                        shadow->flags |= 0x20000000;
                    }
                }
            } else if (shadow->flags & 8) {
                if (shadow->vertexArray == NULL) {
                    render_animated_model(shadow->entityModelID, &shadow->transformMatrix);
                } else {
                    render_animated_model_with_vertices(shadow->entityModelID,
                                  &shadow->transformMatrix,
                                  shadow->vertexSegment,
                                  shadow->vertexArray);
                }
            } else {
                if (shadow->flags & 0x10000000) {
                    shadow->unk_05 -= 20;
                    if (shadow->unk_05 <= 20) {
                        shadow->flags |=  0x20000000;
                    }
                }

                bind_entity_model_setupGfx(shadow->entityModelID, shadow->unk_05, entity_model_set_shadow_color);

                if (shadow->vertexArray == NULL) {
                    draw_entity_model_A(shadow->entityModelID, &shadow->transformMatrix);
                } else {
                    draw_entity_model_B(shadow->entityModelID,
                                           &shadow->transformMatrix,
                                           shadow->vertexSegment,
                                           shadow->vertexArray);
                }
            }
        }
    }
}

INCLUDE_ASM(void, "a5dd0_len_114e0", update_entity_transform_matrix, Entity* entity);

INCLUDE_ASM(void, "a5dd0_len_114e0", update_shadow_transform_matrix, Shadow* shadow);

INCLUDE_ASM(void, "a5dd0_len_114e0", update_entity_inverse_rotation_matrix, Entity* entity);

Entity* get_entity_by_index(s32 index) {
    return (*gCurrentEntityListPtr)[index & 0xFFF];
}

Shadow* get_shadow_by_index(s32 index) {
    return (*gCurrentShadowListPtr)[index & 0xFFF];
}

EntityList* get_entity_list(void) {
    EntityList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldEntityList;
    } else {
        ret = &gBattleEntityList;
    }
    return ret;
}

ShadowList* get_shadow_list(void) {
    ShadowList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldShadowList;
    } else {
        ret = &gBattleShadowList;
    }
    return ret;
}

s32 entity_start_script(Entity* entity) {
    if (entity->boundScriptBytecode != NULL) {
        entity->flags |= 0x1000000;
        return 1;
    }
    return 0;
}

u32 get_entity_type(s32 index) {
    Entity* entity = get_entity_by_index(index);

    if (entity == NULL) {
        return -1;
    } else {
        return entity->staticData->entityType;
    }
}

void delete_entity(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);

    if (entity->dataBuf != NULL) {
        heap_free(entity->dataBuf);
    }

    if (!(entity->flags & 8)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        delete_model_animator(get_animator_by_index(entity->virtualModelIndex));
    }

    if (entity->shadowIndex >= 0) {
        Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

        shadow->flags |= 0x10000000;
    }

    heap_free((*gCurrentEntityListPtr)[entityIndex]);
    (*gCurrentEntityListPtr)[entityIndex] = NULL;
}

void delete_entity_and_unload_data(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);

    if (entity->dataBuf != NULL) {
        heap_free(entity->dataBuf);
    }

    if (!(entity->flags & 8)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        delete_model_animator(get_animator_by_index(entity->virtualModelIndex));
    }

    entity_free_static_data(entity->staticData);

    if (entity->shadowIndex >= 0) {
        Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

        shadow->flags |= 0x10000000;
    }

    heap_free((*gCurrentEntityListPtr)[entityIndex]);
    (*gCurrentEntityListPtr)[entityIndex] = NULL;
}

void _delete_shadow(s32 shadowIndex) {
    Shadow* shadow = get_shadow_by_index(shadowIndex);

    free_entity_model_by_index(shadow->entityModelID);
    heap_free((*gCurrentShadowListPtr)[shadowIndex]);
    (*gCurrentShadowListPtr)[shadowIndex] = NULL;
}

s32 entity_get_collision_flags(Entity* entity) {
    u32 listIndex = entity->listIndex;
    s32 ret = 0;
    u32 flag;

    if (entity->flags & 0x20000) {
        ret = 0x80;
        entity->flags &= ~0x20000;
    }

    flag = gCollisionStatus.currentFloor;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag) {
        ret |= 1;
    }

    flag = gCollisionStatus.lastTouchedFloor;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag) {
        ret |= 0x100;
    }

    flag = gCollisionStatus.currentCeiling;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag) {
        ret |= 0x4;
    }

    flag = gCollisionStatus.pushingAgainstWall;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag) {
        ret |= 0x10;
    }

    flag = gCollisionStatus.lastWallHammered;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag) {
        ret |= 0x40;
    }

    flag = gCollisionStatus.currentWall;
    if (flag != -1 && (flag & 0x4000) && listIndex == (u8)flag && gPlayerStatusPtr->pressedButtons & 0x8000) {
        ret |= 8;
    }

    return ret;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", entity_interacts_with_current_partner);

// float bs
#ifdef NON_MATCHING
s32 test_player_entity_aabb(Entity* entity) {
    f32 temp_f4;
    f32 colliderDiameter;

    temp_f4 = entity->position.y - (gPlayerStatus.position.y + gPlayerStatus.colliderHeight);
    if (temp_f4 > 0.0f || gPlayerStatus.colliderHeight + entity->aabb.y < fabsf(temp_f4)) {
        return 0;
    }

    if ((gPlayerStatus.colliderDiameter + entity->aabb.x) * 0.5 < fabsf(gPlayerStatus.position.x - entity->position.x)) {
        return 0;
    }
    if ((gPlayerStatus.colliderDiameter + entity->aabb.z) * 0.5 < fabsf(gPlayerStatus.position.z - entity->position.z)) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM(s32, "a5dd0_len_114e0", test_player_entity_aabb);
#endif

s32 is_player_action_state(ActionState actionState) {
    return actionState == gPlayerActionState;
}

void entity_set_render_script(Entity* entity, u32* commandList) {
    if (!(entity->flags & 8)) {
        set_entity_model_render_command_list(entity->virtualModelIndex, commandList);
    }
}

void func_80110BF8(Entity* entity) {
    entity->unk_07 = 0;
    entity->flags &= ~0x00010000;
}

#ifdef NON_MATCHING
#define AREA_SPECIFIC_ENTITY_VRAM &entity_default_VRAM
#else
#define AREA_SPECIFIC_ENTITY_VRAM 0x802BAE00
#endif

void load_area_specific_entity_data(void) {
    if (D_8015132C == 0) {
        if (gGameStatusPtr->areaID == AREA_JAN || gGameStatusPtr->areaID == AREA_IWA) {
            dma_copy(entity_jan_iwa_ROM_START, entity_jan_iwa_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        } else if (gGameStatusPtr->areaID == AREA_SBK || gGameStatusPtr->areaID == AREA_OMO) {
            dma_copy(entity_sbk_omo_ROM_START, entity_sbk_omo_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        } else {
            dma_copy(entity_default_ROM_START, entity_default_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        }

        D_8015132C = 1;
    }
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", clear_entity_data);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80110E58);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80110F10);

INCLUDE_ASM(s32, "a5dd0_len_114e0", entity_anim_make_vertex_pointers);

s32 is_entity_data_loaded(Entity* entity, StaticEntityData* entityData, s32* loadedStart, s32* loadedEnd);
INCLUDE_ASM(s32, "a5dd0_len_114e0", is_entity_data_loaded);

void load_simple_entity_data(Entity* entity, StaticEntityData* entityData) {
    s32 loadedStart;
    s32 loadedEnd;
    s32 entitySize;
    u32 temp;
    s32 sizeTemp;

    entity->vertexSegment = 10;
    if (!gGameStatusPtr->isBattle) {
        sizeTemp = wStaticEntityDataSize;
    } else {
        sizeTemp = bStaticEntityDataSize;
    }

    if (is_entity_data_loaded(entity, entityData, &loadedStart, &loadedEnd)) {
        if (sizeTemp + ((entityData->dmaEnd - entityData->dmaStart) >> 2) >= 0x5FFDU) {
            get_entity_type(entity->listIndex);
            get_entity_type(entity->listIndex);
            PANIC();
        }
        entitySize = (entityData->dmaEnd - entityData->dmaStart) >> 2;
        entity->vertexData = (gEntityHeapBase - (sizeTemp * 4)) - (entitySize * 4);
        temp = dma_copy(entityData->dmaStart, entityData->dmaEnd, entity->vertexData);
        sizeTemp += temp / 4;
        get_entity_type(entity->listIndex);
    } else {
        entitySize = (entityData->dmaEnd - entityData->dmaStart) >> 2;
        entity->vertexData = (gEntityHeapBase - (loadedStart * 4)) - (entitySize * 4);
        get_entity_type(entity->listIndex);
    }

    if (!gGameStatusPtr->isBattle) {
        wStaticEntityDataSize = sizeTemp;
    } else {
        bStaticEntityDataSize = sizeTemp;
    }
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", load_split_entity_data);

s32 func_80111790(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentEntityListPtr); i++) {
        Entity* entity = (*gCurrentEntityListPtr)[i];

        if (entity != NULL && entity->staticData->dmaStart != NULL) {
            if (entity->staticData->dmaStart == entity->staticData) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

INCLUDE_ASM(void, "a5dd0_len_114e0", entity_free_static_data, StaticEntityData* data);

INCLUDE_ASM(s32, "a5dd0_len_114e0", create_entity, StaticEntityData* data, s32 x, s32 y, s32 z, s32 arg4,
            ...);

s32 create_shadow_from_data(StaticShadowData* data, f32 x, f32 y, f32 z) {
    Shadow* shadow;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentShadowListPtr); i++) {
        if ((*gCurrentShadowListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < 60);

    shadow = heap_malloc(sizeof(*shadow));
    (*gCurrentShadowListPtr)[i] = shadow;
    mem_clear(shadow, sizeof(*shadow));
    shadow->listIndex = i;
    shadow->flags = data->flags | 0x80000000;
    shadow->unk_05 = 0x80;
    shadow->unk_06 = 0x80;
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->scale.x = 1.0f;
    shadow->scale.y = 1.0f;
    shadow->scale.z = 1.0f;

    if (data->animModelNode != NULL) {
        shadow->flags |= 8;
        shadow->entityModelID = create_model_animator(data->unk_04);
        load_model_animator_tree(shadow->entityModelID, data->animModelNode);
    } else {
        shadow->entityModelID = load_entity_model(data->unk_04);
    }

    if (data->onCreateCallback != NULL) {
        data->onCreateCallback(shadow);
    }
    update_shadow_transform_matrix(shadow);
    return shadow->listIndex;
}

s32 MakeEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    StaticEntityData* entityData;
    s32 x, y, z;
    s32 flags;
    s32 temp_v0;
    s32 entityIndex;
    s32 t80000000;
    s32* temp;

    if (isInitialCall != TRUE) {
        return ApiStatus_DONE2;
    }

    entityData = (StaticEntityData*)evt_get_variable(script, *args++);
    temp = &D_8015C7D0[2];
    t80000000 = 0x80000000;
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    flags = evt_get_variable(script, *args++);

    *temp-- = 0;
    *temp-- = 0;
    *temp = 0;

    do {
        temp_v0 = evt_get_variable(script, *args++);

        if (temp_v0 != t80000000) {
            *temp++ = temp_v0;
        }
    } while (temp_v0 != t80000000);

    entityIndex = create_entity(entityData, x, y, z, flags, D_8015C7D0[0], D_8015C7D0[1], D_8015C7D0[2], t80000000);
    gLastCreatedEntityIndex = entityIndex;
    script->varTable[0] = entityIndex;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", SetEntityCullMode);

ApiStatus UseDynamicShadow(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);

    if (evt_get_variable(script, *script->ptrReadPos)) {
        Shadow* shadow;

        entity->flags |= 4;
        shadow = get_shadow_by_index(entity->shadowIndex);
        shadow->flags |= 0x400000;
    } else {
        entity->flags &= ~4;
    }

    return ApiStatus_DONE2;
}

ApiStatus AssignScript(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        Bytecode* toBind = (Bytecode*)evt_get_variable(script, *args++);

        get_entity_by_index(gLastCreatedEntityIndex)->boundScriptBytecode = toBind;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignAreaFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        s32 temp_s0 = evt_get_variable(script, *args++);
        Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);

        // TODO find proper struct for the dataBuf
        ((s16*)(entity->dataBuf))[16] = temp_s0;
        if (get_area_flag(temp_s0) != 0) {
            entity->flags |= 0x20000000;
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignBlockFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        s32 temp_s0 = evt_get_variable_index(script, *args++);
        Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);

        // TODO find proper struct for the dataBuf
        ((s16*)(entity->dataBuf))[5] = temp_s0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        Trigger* trigger = (Trigger*)get_entity_by_index(gLastCreatedEntityIndex)->dataBuf;
        trigger->flags.bytes.genericFlagIndex = evt_get_variable_index(script, *args);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignPanelFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        // TODO find proper struct for the dataBuf
        s16* dataBuf = (s16*)get_entity_by_index(gLastCreatedEntityIndex)->dataBuf;

        dataBuf[3] = evt_get_variable_index(script, *args++);
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignCrateFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        // TODO find proper struct for the dataBuf
        s16* dataBuf = (s16*)get_entity_by_index(gLastCreatedEntityIndex)->dataBuf;

        dataBuf[2] = evt_get_variable_index(script, *args++);
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", create_entity_shadow);

INCLUDE_ASM(Shadow*, "a5dd0_len_114e0", create_shadow_type, s32 type, f32 x, f32 y, f32 z);

void delete_shadow(s32 shadowIndex) {
    _delete_shadow(shadowIndex);
}

void update_entity_shadow_position(Entity* entity) {
    Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

    if (shadow != NULL) {
        f32 rayX;
        f32 rayY;
        f32 rayZ;
        f32 hitYaw;
        f32 hitPitch;
        f32 hitLength;
        f32 origHitLength;

        if (entity->alpha < 255) {
            shadow->unk_05 = entity->alpha / 2;
        } else {
            u8 alphaTemp;

            if (shadow->flags & 0x800000) {
                alphaTemp = 160;
            } else {
                alphaTemp = 128;
            }
            shadow->unk_05 = alphaTemp;
        }

        if (!(entity->flags & 4)) {
            if (shadow->flags & 0x400000) {
                shadow->flags &= ~0x400000;
            } else {
                return;
            }
        }

        rayX = entity->position.x;
        rayY = entity->position.y;
        rayZ = entity->position.z;

        if (!entity_raycast_down(&rayX, &rayY, &rayZ, &hitYaw, &hitPitch, &hitLength) && hitLength == 32767.0f) {
            hitLength = 0.0f;
        }

        origHitLength = hitLength;

        if (shadow->flags & 0x200) {
            hitLength = 212.5f;
            shadow->scale.x = entity->aabb.x / hitLength;
            shadow->scale.z = entity->aabb.z / hitLength;
        } else {
            hitLength = ((hitLength / 150.0f) + 0.95) * 250.0;
            shadow->scale.x = (entity->aabb.x / hitLength) * entity->scale.x;
            shadow->scale.z = (entity->aabb.z / hitLength) * entity->scale.z;
        }

        shadow->position.x = entity->position.x;
        shadow->position.z = entity->position.z;
        shadow->position.y = rayY;
        entity->shadowPosY = rayY;
        shadow->rotation.x = hitYaw;
        shadow->rotation.z = hitPitch;
        shadow->rotation.y = entity->rotation.y;

        if (entity->position.y < rayY) {
            shadow->flags |= 0x40000000;
            entity->position.y = rayY + 10.0f;
        } else {
            shadow->flags &= ~0x40000000;
        }

        shadow->flags = (shadow->flags & ~1) | ((u16)entity->flags & 1);
        if (!(entity->flags & 0x400) && origHitLength == 0.0f) {
            shadow->flags |= 1;
        }
    } else {
        entity->shadowPosY = 0.0f;
    }
}

s32 entity_raycast_down(f32* x, f32* y, f32* z, f32* hitYaw, f32* hitPitch, f32* hitLength) {
    f32 hitX, hitY, hitZ;
    f32 hitDepth;
    f32 hitNx, hitNy, hitNz;
    s32 entityID;
    s32 colliderID;
    s32 hitID;
    s32 ret;

    hitDepth = 32767.0f;
    *hitLength = 32767.0f;
    entityID = test_ray_entities(*x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    hitID = -1;
    ret = FALSE;

    if ((entityID >= 0) && ((get_entity_type(entityID) != 0xC) || (hitNx == 0.0f && hitNz == 0.0f && hitNy == 1.0))) {
        hitID = entityID | 0x4000;
    }

    colliderID = test_ray_colliders(0x10000, *x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx,
                                    &hitNy, &hitNz);
    if (colliderID >= 0) {
        hitID = colliderID;
    }

    if (hitID >= 0) {
        *hitLength = hitDepth;
        *y = hitY;
        *hitYaw = -atan2(0.0f, 0.0f, hitNz * 100.0f, hitNy * 100.0f);
        *hitPitch = -atan2(0.0f, 0.0f, hitNx * 100.0f, hitNy * 100.0f);
        ret = TRUE;
    } else {
        *hitYaw = 0.0f;
        *hitPitch = 0.0f;
    }
    return ret;
}

INCLUDE_ASM(void, "a5dd0_len_114e0", set_standard_shadow_scale, Shadow* shadow, f32 scale);

INCLUDE_ASM(s32, "a5dd0_len_114e0", set_npc_shadow_scale);

INCLUDE_ASM(void, "a5dd0_len_114e0", set_peach_shadow_scale, Shadow* shadow, f32 scale);

INCLUDE_ASM(s32, "a5dd0_len_114e0", is_block_on_ground);

void state_delegate_NOP(void) {
}

// Dumb temp and weird i decrement and temp increment stuff needed to match
void clear_game_modes(void) {
    GameMode* state = &gMainGameState[0];
    s32 i;

    for (i = ARRAY_COUNT(gMainGameState) - 1; i >= 0; i--, state++) {
        state->flags = 0;
    }
}

// weird ordering at the beginning
#ifndef NON_MATCHING
INCLUDE_ASM(s32, "a5dd0_len_114e0", set_next_game_mode);
#else
GameMode* set_next_game_mode(GameMode* arg0) {
    GameMode* gameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++) {
        gameMode = &gMainGameState[i];
        if (gameMode->flags == 0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 1 | 2;
    gameMode->init = arg0->init;
    gameMode->step = arg0->step;
    gameMode->render = arg0->render;
    gameMode->unk_0C = NULL;

    if (gameMode->init == NULL) {
        gameMode->init = state_delegate_NOP;
    }
    if (gameMode->step == NULL) {
        gameMode->step = state_delegate_NOP;
    }
    if (gameMode->unk_0C == NULL) {
        gameMode->unk_0C = state_delegate_NOP;
    }
    if (gameMode->render == NULL) {
        gameMode->render = state_delegate_NOP;
    }

    gameMode->renderAux = state_delegate_NOP;
    gameMode->init();

    return gameMode;
}
#endif

GameMode* set_game_mode_slot(s32 i, GameMode* arg0) {
    GameMode* gameMode = &gMainGameState[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 1 | 2;
    gameMode->init = arg0->init;
    gameMode->step = arg0->step;
    gameMode->render = arg0->render;
    gameMode->unk_0C = NULL;
    if (gameMode->init == NULL) gameMode->init = state_delegate_NOP;
    if (gameMode->step == NULL) gameMode->step = state_delegate_NOP;
    if (gameMode->unk_0C == NULL) gameMode->unk_0C = state_delegate_NOP;
    if (gameMode->render == NULL) gameMode->render = state_delegate_NOP;

    gameMode->renderAux = state_delegate_NOP;
    gameMode->init();

    return gameMode;
}

void game_mode_set_fpDrawAuxUI(s32 i, void (*fn)(void)) {
    GameMode* gameMode = &gMainGameState[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->renderAux = fn;
    gameMode->flags |= 0x20;

    if (fn == NULL) {
        gameMode->renderAux = state_delegate_NOP;
    }
}

void func_80112DD4(s32 i) {
    gMainGameState[i].flags |= 4;
}

void func_80112DFC(s32 i) {
    gMainGameState[i].flags |= 8;
}

void func_80112E24(s32 i) {
    gMainGameState[i].flags &= ~0x1C;
}

void func_80112E4C(s32 i) {
    gMainGameState[i].flags &= ~0x0C;
    gMainGameState[i].flags |= 0x10;
}

void step_current_game_mode(void) {
    GameMode* gameMode = gMainGameState;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 8)) {
                    gameMode->flags &= ~2;
                    gameMode->step();
                }
            }
        }
    }
}

// similar to step_current_game_mode, but calls unk_0C
INCLUDE_ASM(s32, "a5dd0_len_114e0", state_do_unk);

// similar to step_current_game_mode, but calls render
INCLUDE_ASM(s32, "a5dd0_len_114e0", state_render_backUI);

// calls renderAux and render
INCLUDE_ASM(s32, "a5dd0_len_114e0", state_render_frontUI);

void appendGfx_model(Model* model);
INCLUDE_ASM(void, "a5dd0_len_114e0", appendGfx_model, Model*);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80114B58);

void load_tile_header(char* textureName, s32 romOffset, s32 size);
INCLUDE_ASM(s32, "a5dd0_len_114e0", load_tile_header);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80115498);

// Goofy temps needed to match
ModelNodeProperty* get_model_property(ModelNode* node, ModelPropertyKeys key) {
    s32 numProperties = node->numProperties;
    ModelNodeProperty* propertyList = node->propertyList;
    s32 i;

    for (i = 0; i < numProperties; i++, propertyList++) {
        if (propertyList->key == key) {
            return propertyList;
        }
    }
    return NULL;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", _load_model_textures);

INCLUDE_ASM(s32, "a5dd0_len_114e0", load_model_textures);

s32 mdl_get_child_count(ModelNode* model) {
    s32 ret = 0;

    if (model->type != 2 && model->groupData != NULL) {
        s32 numChildren = model->groupData->numChildren;

        if (numChildren != 0) {
            s32 i;

            ret += numChildren;
            for (i = 0; i < numChildren; i++) {
                ret += mdl_get_child_count(model->groupData->childList[i]);
            }
        }
    }
    return ret;
}

// Issue with pointer advancement in the gCurrentCustomModelGfxPtr loop (adding 8 bytes instead of 4)
#ifdef NON_MATCHING
void clear_model_data(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentModels = wModelList;
        gCurrentTransformGroups = wTransformGroups;
        gCurrentCustomModelGfxPtr = wModelSpecialDls;
        gCurrentCustomModelGfxBuildersPtr = &wCustomModelGfxBuilders;
        gCurrentModelTreeRoot = &D_80152214;
        gCurrentModelLocalVtxBuffers = &D_80152190;
        mdl_currentModelTreeNodeInfo = D_80152220;
        D_801512F0 = &wBgRenderType;
        mdl_bgMultiplyColorA = 0;
        mdl_bgMultiplyColorR = 0;
        mdl_bgMultiplyColorG = 0;
        mdl_bgMultiplyColorB = 0;
        gCurrentFogSettings = &wFogSettings;
    } else {
        gCurrentModels = bModelList;
        gCurrentTransformGroups = bTransformGroups;
        gCurrentCustomModelGfxPtr = bModelSpecialDls;
        gCurrentCustomModelGfxBuildersPtr = &bCustomModelGfxBuilders;
        gCurrentModelTreeRoot = &D_80152218;
        gCurrentModelLocalVtxBuffers = &D_801521D0;
        mdl_currentModelTreeNodeInfo = D_80152A20;
        D_801512F0 = &bBgRenderType;
        gCurrentFogSettings = &bFogSettings;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentModels); i++) {
        (*gCurrentModels)[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTransformGroups); i++) {
        (*gCurrentTransformGroups)[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentCustomModelGfxPtr); i++) {
        (*gCurrentCustomModelGfxPtr)[i].pre = 0;
        (*gCurrentCustomModelGfxBuildersPtr)[i].pre = 0;
    }

    *gCurrentModelTreeRoot = NULL;

    for (i = 0; i < ARRAY_COUNT(*mdl_currentModelTreeNodeInfo); i++) {
        (*mdl_currentModelTreeNodeInfo)[i].modelIndex = -1;
        (*mdl_currentModelTreeNodeInfo)[i].treeDepth = 0;
        (*mdl_currentModelTreeNodeInfo)[i].textureID = 0;
    }

    *D_801512F0 = 0;
    gCurrentFogSettings->r = 10;
    gCurrentFogSettings->g = 10;
    gCurrentFogSettings->b = 10;
    gCurrentFogSettings->startDistance = 950;
    gCurrentFogSettings->enabled = FALSE;
    gCurrentFogSettings->a = 0;
    gCurrentFogSettings->endDistance = 1000;

    for (i = 0; i < ARRAY_COUNT(texPannerAuxV); i++) {
        texPannerAuxV[i] = 0;
        texPannerAuxU[i] = 0;
        texPannerMainV[i] = 0;
        texPannerMainU[i] = 0;
    }
}
#else
INCLUDE_ASM(s32, "a5dd0_len_114e0", clear_model_data);
#endif

void init_model_data(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentModels = &wModelList;
        gCurrentTransformGroups = &wTransformGroups;
        gCurrentCustomModelGfxPtr = wModelSpecialDls;
        gCurrentCustomModelGfxBuildersPtr = &wCustomModelGfxBuilders;
        gCurrentModelTreeRoot = &D_80152214;
        gCurrentModelLocalVtxBuffers = &D_80152190;
        mdl_currentModelTreeNodeInfo = &D_80152220;
        D_801512F0 = &wBgRenderType;
        gCurrentFogSettings = &wFogSettings;
    } else {
        gCurrentModels = &bModelList;
        gCurrentTransformGroups = &bTransformGroups;
        gCurrentCustomModelGfxPtr = bModelSpecialDls;
        gCurrentCustomModelGfxBuildersPtr = &bCustomModelGfxBuilders;
        gCurrentModelTreeRoot = &D_80152218;
        gCurrentModelLocalVtxBuffers = &D_801521D0;
        mdl_currentModelTreeNodeInfo = &D_80152A20;
        D_801512F0 = &bBgRenderType;
        gCurrentFogSettings = &bFogSettings;
    }
}

void calculate_model_sizes(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentModels); i++) {
        Model* model = (*gCurrentModels)[i];

        if (model != NULL) {
            ModelBoundingBox* bb = (ModelBoundingBox*)get_model_property(model->modelNode, MODEL_PROP_KEY_BOUNDING_BOX);

            bb->halfSizeX = (bb->maxX - bb->minX) * 0.5;
            bb->halfSizeY = (bb->maxY - bb->minY) * 0.5;
            bb->halfSizeZ = (bb->maxZ - bb->minZ) * 0.5;
            model->flags |= 0x1000;
        }
    }
}

void mdl_create_model(ModelBlueprint* bp, s32 arg1);
INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_create_model);

// The global here is getting optimized out because nothing is happening to it. Very weird
#ifdef NON_MATCHING
void func_80116674(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentModels); i++) {
        Model* m = (*gCurrentModels)[i];
    }
}
#else
INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80116674);
#endif

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_80116698);

INCLUDE_ASM(s32, "a5dd0_len_114e0", render_models);

void appendGfx_model_group(Model* model);
INCLUDE_ASM(void, "a5dd0_len_114e0", appendGfx_model_group, Model*);

void func_80117D00(Model* model) {
    Model* mdl = model; // temps needed to match
    ModelNode* modelNode = mdl->modelNode;

    if (model->modelNode->type != SHAPE_TYPE_MODEL) {
        if (modelNode->groupData != NULL) {
            s32 numChildren = modelNode->groupData->numChildren;

            if (numChildren != 0) {
                s32 i;

                for (i = 0; i < numChildren; i++, mdl_treeIterPos++) {
                    Model newModel = *mdl;
                    ModelNodeProperty* prop;

                    newModel.flags = mdl->flags;
                    newModel.currentSpecialMatrix = mdl->currentSpecialMatrix;
                    newModel.modelNode = modelNode->groupData->childList[i];
                    newModel.texPannerID = mdl->texPannerID;
                    newModel.specialDisplayListID = mdl->specialDisplayListID;

                    if (newModel.modelNode->type == SHAPE_TYPE_MODEL) {
                        prop = get_model_property(newModel.modelNode, MODEL_PROP_KEY_RENDER_MODE);
                    } else {
                        prop = NULL;
                    }

                    if (prop != NULL) {
                        newModel.renderMode = prop->data.s;
                    } else {
                        newModel.renderMode = 0;
                    }

                    newModel.textureID = (*mdl_currentModelTreeNodeInfo)[mdl_treeIterPos].textureID;
                    newModel.unk_A9 = 0;
                    func_80117D00(&newModel);
                }
            }
        }
    } else {
        appendGfx_model(mdl);
    }
}

// this looks like a switch, but I can't figure it out
void render_transform_group_node(ModelNode* node) {
    Gfx** gfx = &gMasterGfxPos;
    Model* model;

    if (node != NULL) {
        if (node->type == SHAPE_TYPE_GROUP) {
            ModelNodeProperty* groupTypeProp = get_model_property(node, MODEL_PROP_KEY_GROUP_TYPE);

            if (groupTypeProp != NULL && groupTypeProp->data.s != 0) {
                model = get_model_from_list_index(mdl_currentTransformGroupChildIndex);
                if (!(model->flags & 2)) {
                    appendGfx_model_group(model);
                }
                mdl_currentTransformGroupChildIndex++;
                return;
            }
        }
        if (node->type != SHAPE_TYPE_MODEL) {
            if (node->groupData != NULL) {
                s32 numChildren;
                s32 i;

                if (node->groupData->transformMatrix != NULL) {
                    gSPMatrix((*gfx)++, node->groupData->transformMatrix,
                              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                }

                numChildren = node->groupData->numChildren;
                if (numChildren != 0) {
                    for (i = 0; i < numChildren; i++) {
                        render_transform_group_node(node->groupData->childList[i]);
                    }
                }

                if (node->groupData->transformMatrix != NULL) {
                    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
                }
            }
            return;
        }

        model = get_model_from_list_index(mdl_currentTransformGroupChildIndex);
        if (!(model->flags & 2)) {
            appendGfx_model(model);
        }
        mdl_currentTransformGroupChildIndex++;
    }
}


// arg0 and gfx temps needed
void render_transform_group(ModelTransformGroup* group) {
    ModelTransformGroup* mtg = group;
    Gfx** gfx = &gMasterGfxPos;

    if (!(mtg->flags & 4)) {
        mdl_currentTransformGroupChildIndex = mtg->minChildModelIndex;
        if (!(mtg->flags & 0x2000)) {
            gSPMatrix((*gfx)++, mtg->transformMtx, (G_MTX_PUSH | G_MTX_LOAD) | G_MTX_MODELVIEW);
        }

        render_transform_group_node(mtg->modelNode);
        if (!(mtg->flags & 0x2000)) {
            gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
        }
        gDPPipeSync((*gfx)++);
    }
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_801180E8);

Model* get_model_from_list_index(s32 listIndex) {
    return (*gCurrentModels)[listIndex];
}

void load_data_for_models(ModelNode* model, s32 romOffset, s32 size) {
    Matrix4f mtx;

    guMtxIdentF(mtx);

    if (romOffset != 0) {
        load_model_textures(model, romOffset, size);
    }

    *gCurrentModelTreeRoot = model;
    mdl_treeIterPos = 0;

    if (model != NULL) {
        load_model_transforms(model, NULL, mtx, 0);
    }
}

// tiny reg swap in the first loop
#ifdef NON_MATCHING
void load_model_transforms(ModelNode* model, ModelNode* parent, Matrix4f mdlTxMtx, s32 treeDepth) {
    Matrix4f sp10;
    Matrix4f sp50;
    ModelBlueprint modelBP;
    ModelBlueprint* modelBPptr = &modelBP;
    ModelNodeProperty* groupTypeProperty;
    s32 i;

    if (model->groupData != NULL && model->groupData->numChildren != 0) {
        s32 groupType;

        if (model->groupData->transformMatrix != NULL) {
            Matrix4f spA0;

            guMtxL2F(spA0, model->groupData->transformMatrix);
            guMtxCatF(spA0, mdlTxMtx, sp10);
        }
        groupTypeProperty = get_model_property(model, MODEL_PROP_KEY_GROUP_TYPE);

        if (groupTypeProperty == NULL) {
            groupType = 0;
        } else {
            groupType = groupTypeProperty->data.s;
        }

        if (model->type != 5 || groupType == 0) {
            for (i = 0; i < model->groupData->numChildren; i++) {
                ModelNode** modelTemp;
                Matrix4f* txMtx;

                modelTemp = &model->groupData->childList[i];

                if (model->groupData->transformMatrix != NULL) {
                    txMtx = sp10;
                } else {
                    txMtx = mdlTxMtx;
                }

                load_model_transforms(*modelTemp, model, txMtx, treeDepth + 1);
            }

            (*mdl_currentModelTreeNodeInfo)[mdl_treeIterPos].modelIndex = -1;
            (*mdl_currentModelTreeNodeInfo)[mdl_treeIterPos].treeDepth = treeDepth;
            mdl_treeIterPos += 1;
            return;
        }
    }

    guMtxF2L(mdlTxMtx, sp50);
    modelBPptr->flags = 0;
    modelBPptr->mdlNode = model;
    modelBPptr->groupData = parent->groupData;
    modelBPptr->mtx = sp50;

    if (model->type == 5) {
        s32 childCount = mdl_get_child_count(model);

        for (i = mdl_treeIterPos; i < mdl_treeIterPos + childCount; i++) {
            (*mdl_currentModelTreeNodeInfo)[i].modelIndex = -1;
            (*mdl_currentModelTreeNodeInfo)[i].treeDepth = treeDepth + 1;
        }
        mdl_treeIterPos += childCount;
    }

    mdl_create_model(modelBPptr, 4);
    (*mdl_currentModelTreeNodeInfo)[mdl_treeIterPos].treeDepth = treeDepth;
    mdl_treeIterPos += 1;
}
#else
INCLUDE_ASM(s32, "a5dd0_len_114e0", load_model_transforms);
#endif

s32 get_model_list_index_from_tree_index(s32 treeIndex) {
    s32 i;

    if (treeIndex < 0x100) {
        u8 modelIndex = (*mdl_currentModelTreeNodeInfo)[treeIndex].modelIndex;

        if (modelIndex != (u8)-1) {
            return modelIndex;
        }
    }

    for (i = 0; i < 0x100; i++) {
        Model* model = get_model_from_list_index(i);

        if (model != NULL && model->modelID == treeIndex) {
            return i;
        }
    }
    return 0;
}

s32 get_transform_group_index(s32 modelID) {
    ModelTransformGroup* group;
    s32 i;

    for (i = 0; i < MAX_MODEL_TRANSFORM_GROUPS; i++) {
        group = get_transform_group(i);

        if (group != NULL && group->groupModelID == modelID) {
            return i;
        }
    }

    return -1;
}

// TODO this seems to be returning center for the model and center for the BB (not the size)
void get_model_center_and_size(u16 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY, f32* sizeZ) {
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));
    ModelNode* node = model->modelNode;
    ModelBoundingBox* bb;

    *centerX = model->center.x;
    *centerY = model->center.y;
    *centerZ = model->center.z;

    bb = (ModelBoundingBox*)get_model_property(node, MODEL_PROP_KEY_BOUNDING_BOX);

    if (bb != NULL) {
        *sizeX = bb->halfSizeX;
        *sizeY = bb->halfSizeY;
        *sizeZ = bb->halfSizeZ;
    } else {
        *sizeX = *sizeY = *sizeZ = 0.0f;
    }
}

ModelTransformGroup* get_transform_group(s32 index) {
    return (*gCurrentTransformGroups)[index];
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_8011B1D8);

void make_transform_group(u16 modelID) {
    mdl_treeIterPos = 0;
    D_80153370 = NULL;
    D_8015336E = modelID;
    D_80153376 = 0;
    D_80153374 = 0;
    func_8011B1D8(*gCurrentModelTreeRoot);

    if (D_80153370 != 0) {
        ModelTransformGroup* newMtg;
        ModelNode* node;
        ModelNodeProperty* prop;
        ModelBoundingBox* bb;
        f32 x, y, z;
        s32 i;

        for (i = 0; i < ARRAY_COUNT(*gCurrentTransformGroups); i++) {
            if ((*gCurrentTransformGroups)[i] == NULL) {
                break;
            }
        }

        (*gCurrentTransformGroups)[i] = newMtg = heap_malloc(sizeof(ModelTransformGroup));
        newMtg->flags = 1;
        newMtg->groupModelID = modelID;
        newMtg->minChildModelIndex = get_model_list_index_from_tree_index(D_80153374);
        newMtg->maxChildModelIndex = get_model_list_index_from_tree_index(D_80153376);
        newMtg->matrixMode = 0;
        newMtg->matrixRDP_N = NULL;
        newMtg->modelNode = D_80153370;
        guMtxIdent(&newMtg->matrixA);
        newMtg->flags |= 0x2000;
        guMtxIdentF(newMtg->matrixB);

        node = newMtg->modelNode;

        if (node->type != SHAPE_TYPE_GROUP) {
            prop = get_model_property(node, MODEL_PROP_KEY_RENDER_MODE);
        } else {
            prop = get_model_property(node, MODEL_PROP_KEY_GROUP_TYPE);

            if (prop != NULL) {
                prop = &prop[1];
            }
        }

        if (prop != NULL) {
            newMtg->renderMode = prop->data.s;
        } else {
            newMtg->renderMode = 1;
        }

        bb = (ModelBoundingBox*)get_model_property(node, MODEL_PROP_KEY_BOUNDING_BOX);
        if (bb != NULL) {
            x = (bb->minX + bb->maxX) * 0.5f;
            y = (bb->minY + bb->maxY) * 0.5f;
            z = (bb->minZ + bb->maxZ) * 0.5f;
        } else {
            x = y = z = 0.0f;
        }

        if (newMtg->matrixRDP_N != NULL) {
            guMtxXFML(newMtg->matrixRDP_N, x, y, z, &x, &y, &z);
        }

        newMtg->center.x = x;
        newMtg->center.y = y;
        newMtg->center.z = z;
        enable_transform_group(modelID);
    }
}

void enable_transform_group(u16 modelID) {
    ModelTransformGroup* group = get_transform_group(get_transform_group_index(modelID));
    s32 i;

    group->flags &= ~0x4;

    for (i = group->minChildModelIndex; i <= group->maxChildModelIndex; i++) {
        Model* model = get_model_from_list_index(i);

        model->flags |= 0x8;

        if (model->currentMatrix != NULL) {
            model->flags |= 0x1000;
        }
    }
}

void disable_transform_group(u16 modelID) {
    ModelTransformGroup* group = get_transform_group(get_transform_group_index(modelID));
    s32 i;

    group->flags |= 0x4;

    for (i = group->minChildModelIndex; i <= group->maxChildModelIndex; i++) {
        Model* model = get_model_from_list_index(i);

        model->flags &= ~0x8;

        if (model->currentMatrix != NULL) {
            model->flags |= 0x1000;
        }
    }
}

void clone_model(u16 srcModelID, u16 newModelID) {
    Model* srcModel = get_model_from_list_index(get_model_list_index_from_tree_index(srcModelID));
    Model* newModel;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentModels); i++) {
        if ((*gCurrentModels)[i] == NULL) {
            break;
        }
    }

    (*gCurrentModels)[i] = newModel = heap_malloc(sizeof(Model));
    *newModel = *srcModel;
    newModel->modelID = newModelID;
}

INCLUDE_ASM(void, "a5dd0_len_114e0", func_8011B7C0, u16 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_8011B950);

void func_8011BAE8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentModels); i++) {
        Model* model = (*gCurrentModels)[i];

        if (model != NULL) {
            model->flags &= ~0x0400;
        }
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTransformGroups); i++) {
        ModelTransformGroup* transformGroup = (*gCurrentTransformGroups)[i];

        if (transformGroup != NULL) {
            transformGroup->flags &= ~0x0400;
        }
    }
}

void enable_world_fog(void) {
    gCurrentFogSettings->enabled = TRUE;
}

void disable_world_fog(void) {
    gCurrentFogSettings->enabled = FALSE;
}

void set_world_fog_dist(s32 start, s32 end) {
    gCurrentFogSettings->startDistance = start;
    gCurrentFogSettings->endDistance = end;
}

void set_world_fog_color(s32 r, s32 g, s32 b, s32 a) {
    gCurrentFogSettings->r = r;
    gCurrentFogSettings->g = g;
    gCurrentFogSettings->b = b;
    gCurrentFogSettings->a = a;
}

s32 is_world_fog_enabled(void) {
    return gCurrentFogSettings->enabled;
}

void get_world_fog_distance(s32* start, s32* end) {
    *start = gCurrentFogSettings->startDistance;
    *end = gCurrentFogSettings->endDistance;
}

void get_world_fog_color(s32* r, s32* g, s32* b, s32* a) {
    *r = gCurrentFogSettings->r;
    *g = gCurrentFogSettings->g;
    *b = gCurrentFogSettings->b;
    *a = gCurrentFogSettings->a;
}

void set_tex_panner(Model* model, s8 texPannerID) {
    model->texPannerID = texPannerID;
}

void set_main_pan_u(s32 texPannerID, s32 value) {
    texPannerMainU[texPannerID] = value;
}

void set_main_pan_v(s32 texPannerID, s32 value) {
    texPannerMainV[texPannerID] = value;
}

void set_aux_pan_u(s32 texPannerID, s32 value) {
    texPannerAuxU[texPannerID] = value;
}

void set_aux_pan_v(s32 texPannerID, s32 value) {
    texPannerAuxV[texPannerID] = value;
}

void set_mdl_custom_gfx_set(Model* model, s32 customGfxIndex, u32 fogType) {
    if (customGfxIndex == -1) {
        customGfxIndex = model->specialDisplayListID & 15;
    }

    if (fogType == -1) {
        fogType = model->specialDisplayListID / 16;
    }

    model->specialDisplayListID = (customGfxIndex & 15) + ((fogType & 15) * 16);
}

void set_custom_gfx(s32 customGfxIndex, Gfx* pre, Gfx* post) {
    (*gCurrentCustomModelGfxPtr)[customGfxIndex].pre = pre;
    (*gCurrentCustomModelGfxPtr)[customGfxIndex].post = post;
}

void set_custom_gfx_builders(s32 customGfxIndex, ModelCustomGfxBuilderFunc pre, ModelCustomGfxBuilderFunc post) {
    (*gCurrentCustomModelGfxBuildersPtr)[customGfxIndex].pre = pre;
    (*gCurrentCustomModelGfxBuildersPtr)[customGfxIndex].post = post;
}

void build_custom_gfx(void) {
    Gfx* gfx = gMasterGfxPos;
    ModelCustomGfxBuilderFunc preFunc;
    ModelCustomGfxBuilderFunc postFunc;
    s32 i;

    gSPBranchList(gMasterGfxPos++, 0x00000000);

    for (i = 0; i < 0x10; i++) {
        preFunc = (*gCurrentCustomModelGfxBuildersPtr)[i].pre;

        if (preFunc != NULL) {
            (*gCurrentCustomModelGfxPtr)[i].pre = gMasterGfxPos;
            preFunc(i);
            gSPEndDisplayList(gMasterGfxPos++);
        }

        postFunc = (*gCurrentCustomModelGfxBuildersPtr)[i].post;
        if (postFunc != NULL) {
            (*gCurrentCustomModelGfxPtr)[i].post = gMasterGfxPos;
            postFunc(i);
            gSPEndDisplayList(gMasterGfxPos++);
        }
    }

    gSPBranchList(gfx, gMasterGfxPos);
}

// weird temps necessary to match
/// @returns TRUE if mtx is NULL or identity.
s32 is_identity_fixed_mtx(Matrix4s* mtx) {
    s32* mtxIt = (s32*)mtx;
    s32* identityIt;
    s32 i;

    if (mtx == NULL) {
        return TRUE;
    }

    identityIt = (s32*)&mdl_RDPIdentity;

    for (i = 0; i < 16; i++, mtxIt++, identityIt++) {
        if (*mtxIt != *identityIt) {
            return FALSE;
        }
    }

    return TRUE;
}

void set_background_color_blend(u8 r, u8 g, u8 b, u8 a) {
    mdl_bgMultiplyColorR = r;
    mdl_bgMultiplyColorG = g;
    mdl_bgMultiplyColorB = b;
    mdl_bgMultiplyColorA = a;
}

void get_background_color_blend(u8* r, u8* g, u8* b, u8* a) {
    *r = mdl_bgMultiplyColorR;
    *g = mdl_bgMultiplyColorG;
    *b = mdl_bgMultiplyColorB;
    *a = mdl_bgMultiplyColorA;
}

void set_model_fog_color_parameters(s8 primR, s8 primG, s8 primB, s8 primA, s32 fogR, s32 fogG, s32 fogB, s32 fogStart,
                                    s32 fogEnd) {
    mdl_renderModelFogPrimColorR = primR;
    mdl_renderModelFogPrimColorG = primG;
    mdl_renderModelFogPrimColorB = primB;
    mdl_renderModelFogPrimColorA = primA;
    mdl_renderModelFogColorR = fogR;
    mdl_renderModelFogColorG = fogG;
    mdl_renderModelFogColorB = fogB;
    mdl_renderModelFogStart = fogStart;
    mdl_renderModelFogEnd = fogEnd;
}

void get_model_fog_color_parameters(u8* primR, u8* primG, u8* primB, u8* primA, u8* fogR, u8* fogG, u8* fogB,
                                    s32* fogStart, s32* fogEnd) {
    *primR = mdl_renderModelFogPrimColorR;
    *primG = mdl_renderModelFogPrimColorG;
    *primB = mdl_renderModelFogPrimColorB;
    *primA = mdl_renderModelFogPrimColorA;
    *fogR = mdl_renderModelFogColorR;
    *fogG = mdl_renderModelFogColorG;
    *fogB = mdl_renderModelFogColorB;
    *fogStart = mdl_renderModelFogStart;
    *fogEnd = mdl_renderModelFogEnd;
}

void set_model_env_color_parameters(u8 primR, u8 primG, u8 primB, u8 envR, s32 envG, s32 envB) {
    gRenderModelPrimR = primR;
    gRenderModelPrimG = primG;
    gRenderModelPrimB = primB;
    gRenderModelEnvR = envR;
    gRenderModelEnvG = envG;
    gRenderModelEnvB = envB;
}

void get_model_env_color_parameters(u8* primR, u8* primG, u8* primB, u8* envR, u8* envG, u8* envB) {
    *primR = gRenderModelPrimR;
    *primG = gRenderModelPrimG;
    *primB = gRenderModelPrimB;
    *envR = gRenderModelEnvR;
    *envG = gRenderModelEnvG;
    *envB = gRenderModelEnvB;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_get_vertex_count);

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_local_gfx_update_vtx_pointers);

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_local_gfx_copy_vertices);

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_make_local_vertex_copy);

void mdl_get_copied_vertices(s32 copyIndex, Vtx** firstVertex, Vtx** copiedVertices, s32* numCopied) {
    ModelLocalVertexCopy* mlvc = gCurrentModelLocalVtxBuffers[copyIndex];
    s32 selector = mlvc->selector;

    *firstVertex = mlvc->minVertexAddr;
    *copiedVertices = mlvc->vtxCopy[selector];
    *numCopied = mlvc->numVertices;
}

Gfx* mdl_get_copied_gfx(s32 copyIndex) {
    ModelLocalVertexCopy* mlvc = gCurrentModelLocalVtxBuffers[copyIndex];
    s32 selector = mlvc->selector;
    Gfx* gfxCopy = mlvc->gfxCopy[selector];

    mlvc->selector++;
    if (mlvc->selector >= 2) {
        mlvc->selector = 0;
    }

    return gfxCopy;
}

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f* destMtx, Vtx* destVertices);
INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_project_tex_coords);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_8011C80C);

INCLUDE_ASM(s32, "a5dd0_len_114e0", func_8011CFBC);

void mdl_draw_hidden_panel_surface(Gfx** arg0, u16 treeIndex) {
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
    Model copied = *model;
    Gfx* oldGfxPos;
    s32 flag;

    if (*arg0 == gMasterGfxPos) {
        flag = 1;
    }

    oldGfxPos = gMasterGfxPos;
    gMasterGfxPos = *arg0;

    copied.flags = 0x81;
    appendGfx_model(&copied);

    *arg0 = gMasterGfxPos;

    if (flag == 0) {
        gMasterGfxPos = oldGfxPos;
    }
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_get_next_texture_address);

INCLUDE_ASM(s32, "a5dd0_len_114e0", mdl_set_all_fog_mode);

void clear_render_tasks(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        mdl_renderTaskLists[i] = mdl_clearRenderTasks[i];
    }

    mdl_renderTaskMode = 0;
    mdl_renderTaskCount = 0;
}

void clear_render_tasks_alt(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        mdl_renderTaskLists[i] = mdl_clearRenderTasks[i];
    }

    mdl_renderTaskMode = 0;
    mdl_renderTaskCount = 0;
}

RenderTask* queue_render_task(RenderTask* task) {
    RenderTask* ret = mdl_renderTaskLists[mdl_renderTaskMode];

    ASSERT(mdl_renderTaskCount < 0x100);

    ret = &ret[mdl_renderTaskCount++];

    ret->renderMode = 1;
    if (task->renderMode == 0x2D) {
        ret->renderMode = 0x21;
    }

    ret->appendGfxArg = task->appendGfxArg;
    ret->appendGfx = task->appendGfx;
    ret->distance = D_8014C188[task->renderMode] - task->distance;

    return ret;
}

INCLUDE_ASM(s32, "a5dd0_len_114e0", execute_render_tasks);

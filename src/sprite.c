#include "common.h"

struct D_802DF588 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
}; // size = 0xC

struct D_802DFA48 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
}; // size = 0x14

extern s32 D_802DF524;
extern s32 D_802DF578[];
extern s32 D_802DF580;
extern s32 D_802DF5B0[];
extern struct D_802DF588 D_802DF588[]; // len 3?
extern struct D_802DFA48 D_802DFA48[]; // len 0x33?
extern u8 D_802DF958[];
extern s32 gSpriteHeapPtr;

void func_802DED60(s32 cacheSize, s32 maxRasterSize);

s32 D_802DF390[] = { 0xFFF00038, 0x00000000, 0x00000000, 0xF0F0F0FF, 0x00100038, 0x00000000, 0x04000000, 0x787878FF,
                     0x00100000, 0x00000000, 0x04000700, 0x000000FF, 0xFFF00000, 0x00000000, 0x00000700, 0x787878FF,
                   };

s32 D_802DF3D0[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 D_802DF3E0[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x02000000, };

Gfx D_802DF3F0[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_NPRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_802DF428[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_NPRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_802DF460[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | G_RM_PASS, AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_802DF490[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
    gsSPEndDisplayList(),
};

f32 D_802DF4C0 = 1.0f;

struct D_802DF4C4 {
    s32 cacheSize;
    s32 rasterSize;
    s32 unk_08;
}; // size = 0xC

// player sprite config?
struct D_802DF4C4 D_802DF4C4[] = {
    { 0x00000006, 0x00000700, 0x000003C6 }, // default
    { 0x00000012, 0x00000700, 0x000003C6 },
    { 0x0000000A, 0x00000900, 0x00003FC6 },
    { 0x00000003, 0x00000700, 0x00000006 },
    { 0x00000006, 0x00000900, 0x00003C00 }, // peach
    { 0x00000006, 0x00000700, 0x0000003E },
    { 0x00000006, 0x00000900, 0x00003C00 },
    { 0x00000000, 0x00000000 } // ?
};


INCLUDE_ASM(s32, "sprite", func_802DBD40);

// extern s32* gSpriteHeapPtr;
// extern s32** D_802DFE44;
// extern s32* D_802DFE9C;

// void func_802DBD40(void) {
//     s32 i;
//     s32* phi_v0;
//     D_802DFE44 = _heap_malloc(&gSpriteHeapPtr, 0x580);

//     for (i = 21; i >= 0; i--) {
//         D_802DFE44[i] = -1;
//     }
// }

INCLUDE_ASM(s32, "sprite", func_802DBD8C);

INCLUDE_ASM(s32, "sprite", func_802DBDBC);

INCLUDE_ASM(s32, "sprite", func_802DBE78);

INCLUDE_ASM(s32, "sprite", func_802DBFC0);

INCLUDE_ASM(s32, "sprite", func_802DC008);

INCLUDE_ASM(s32, "sprite", spr_appendMDL_component);

void spr_transform_point(s32 rotX, s32 rotY, s32 rotZ, f32 inX, f32 inY, f32 inZ, f32* outX, f32* outY, f32* outZ) {
    if (rotX == 0 && rotY == 0 && rotZ == 0) {
        *outX = inX;
        *outY = inY;
        *outZ = inZ;
    } else {
        Matrix4f mtx, mtx2;
        f32 f1, f2, f3, f4, f5, f6, f7, f8, f9;

        guRotateF(&mtx, rotY, 0.0f, 1.0f, 0.0f);
        guRotateF(&mtx2, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(&mtx2, &mtx, &mtx);
        guRotateF(&mtx2, rotX, 1.0f, 0.0f, 0.0f);
        guMtxCatF(&mtx2, &mtx, &mtx);

        f1 = (mtx[0][0] * inX);
        f2 = (mtx[1][0] * inY);
        f3 = (mtx[2][0] * inZ);
        f4 = (mtx[0][1] * inX);
        f5 = (mtx[1][1] * inY);
        f6 = (mtx[2][1] * inZ);
        f7 = (mtx[0][2] * inX);
        f8 = (mtx[1][2] * inY);
        f9 = (mtx[2][2] * inZ);

        *outX = f1 + f2 + f3;
        *outY = f4 + f5 + f6;
        *outZ = f7 + f8 + f9;
    }
}

INCLUDE_ASM(s32, "sprite", spr_draw_component);

s32 _spr_sign_extend_12bit(u16 val) {
    s32 temp = val & 0xFFF;

    if (temp & 0x800) {
        return temp | ~0xFFF;
    } else {
        return temp;
    }
}

s32 _spr_sign_extend_16bit(u16 val) {
    s32 temp = val & 0xFFFF;

    if (temp & 0x8000) {
        return temp | ~0xFFFF;
    } else {
        return temp;
    }
}

INCLUDE_ASM(s32, "sprite", update_component);

INCLUDE_ASM(s32, "sprite", func_802DD634);

INCLUDE_ASM(s32, "sprite", func_802DD6DC);

INCLUDE_ASM(s32, "sprite", func_802DD7B0);

INCLUDE_ASM(s32, "sprite", func_802DD820);

void set_anim_timescale(f32 arg0) {
    D_802DF4C0 = arg0 * 2.0f;
}

INCLUDE_ASM(s32, "sprite", func_802DD89C);

// spr_init_sprites
//INCLUDE_ASM(s32, "sprite", func_802DD8F8);
void func_802DD8F8(s32 playerSpriteSet) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s1;
    struct D_802DF4C4* temp_v0;
    void *phi_v0;
    s32 phi_s0;
    s32 phi_s1;
    s32 phi_v0_2;
    s32 phi_s0_2;
    struct D_802DF588* phi_v1;
    s32 phi_s0_3;
    s32* phi_v1_2;
    s32 phi_s0_4;
    struct D_802DFA48* phi_v1_3;
    s32 phi_s0_5;

    s32 i;

    D_802DF524 = 0;
    _heap_create(&gSpriteHeapPtr, 0x40000U);
    func_8013A37C();


    for (i = 0; i < 0xD; i++) {
        s32* d802DF578 = D_802DF578;
        d802DF578[i] = 0;
    }

    D_802DF580 = 0;

    if (gGameStatusPtr->peachFlags & 1) {
        playerSpriteSet = 4;
    }

    temp_s1 = (&D_802DF4C4[playerSpriteSet])->unk_08;
    func_802DED60((&D_802DF4C4[playerSpriteSet])->cacheSize, (&D_802DF4C4[playerSpriteSet])->rasterSize);

    for (i = 1; i < 0xE; i++) {
        if ((temp_s1 >> i) & 1) {
            func_802DD89C(i); // spr_load_player_sprite
        }
    }

    for (i = 0; i < 3; i++) {
        phi_v1 = &D_802DF588[i];
        phi_v1->unk_00 = 0;
        phi_v1->unk_04 = -1;
    }

    for (i = 0; i < 0xEA; i++) {
        s32* d802DF5B0 = D_802DF5B0;
        u8* d802DF958 = D_802DF958;

        d802DF5B0[i] = 0;
        d802DF958[i] = 0;
    }

    for (i = 0; i < 0x33; i++) {
        phi_v1_3 = &D_802DFA48[i];
        phi_v1_3->unk_00 = 0;
        phi_v1_3->unk_04 = 0;
        phi_v1_3->unk_08 = 0;
        phi_v1_3->unk_0C = -1;
        phi_v1_3->unk_10 = 0;
    }

    func_802DBD40(); // spr_init_quad_cache
}

void func_802DDA60(void) {
    func_802DEFB4();
    func_802DBFC0();
}

s32 func_802DDA84(void) {
    return 0;
}

INCLUDE_ASM(s32, "sprite", func_802DDA8C);

INCLUDE_ASM(s32, "sprite", render_sprite);

INCLUDE_ASM(s32, "sprite", func_802DDEC4);

INCLUDE_ASM(s32, "sprite", func_802DDEE4);

INCLUDE_ASM(s32, "sprite", func_802DDFF8);

INCLUDE_ASM(s32, "sprite", func_802DE044);

INCLUDE_ASM(s32, "sprite", func_802DE0C0);

INCLUDE_ASM(s32, "sprite", func_802DE0EC);

INCLUDE_ASM(s32, "sprite", func_802DE2AC, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(s32, "sprite", func_802DE3D8);

INCLUDE_ASM(s32, "sprite", func_802DE5C8);

INCLUDE_ASM(s32, "sprite", func_802DE5E8);

INCLUDE_ASM(s32, "sprite", func_802DE748);

INCLUDE_ASM(s32, "sprite", func_802DE780);

INCLUDE_ASM(s32, "sprite", func_802DE894);

INCLUDE_ASM(s32, "sprite", func_802DE8DC);

INCLUDE_ASM(s32, "sprite", func_802DE9D8);

INCLUDE_ASM(s32, "sprite", func_802DEA40);

INCLUDE_ASM(s32, "sprite", func_802DEA6C);

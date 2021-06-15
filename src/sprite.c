#include "common.h"

struct spr_playerCurrentAnimInfo {
    /* 0x00 */ SpriteComponent** componentList;
    /* 0x04 */ s32 animID;
    /* 0x08 */ s32 unk_08;
}; // size = 0xC

struct D_802DFA48 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
}; // size = 0x14

typedef struct PlayerSpriteSet {
    /// Number of cache entries.
    /* 0x00 */ s32 cacheSize;

    /// Maximum raster size.
    /* 0x04 */ s32 rasterSize;

    /// Flags saying which rasters to load into the cache in spr_init_sprites(), with each bit corresponding to the Nth
    /// raster (with LSB = raster 0).
    /* 0x08 */ s32 initiallyLoaded;
} PlayerSpriteSet; // size = 0xC

/// Sprite data header.
typedef struct SpriteAnimData {
    /* 0x00 */ s32** rastersOffset;
    /* 0x04 */ s32** palettesOffset;
    /* 0x08 */ s32 maxComponents;
    /* 0x0C */ s32 colorVariations;
} SpriteAnimData; // size = 0x10

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern SpriteAnimData* spr_playerSprites[13];
extern s32 spr_playerMaxComponents;
extern SpriteAnimData* spr_npcSprites[0xEA];
extern struct spr_playerCurrentAnimInfo spr_playerCurrentAnimInfo[3];
extern struct D_802DFA48 D_802DFA48[51];
extern u8 spr_npcSpriteInstanceCount[];
extern s32 gSpriteHeapPtr;

void func_802DED60(s32 cacheSize, s32 maxRasterSize);

Vtx spr_defaultQuad[] = {
    {{{ -16, 56, 0 }, FALSE, {    0,    0 }, { 240, 240, 240, 255 }}},
    {{{  16, 56, 0 }, FALSE, { 1024,    0 }, { 120, 120, 120, 255 }}},
    {{{  16,  0, 0 }, FALSE, { 1024, 1792 }, {   0,   0,   0, 255 }}},
    {{{ -16,  0, 0 }, FALSE, {    0, 1792 }, { 120, 120, 120, 255 }}},
};

Vp D_802DF3D0 = {{
        { 640, 480, 511, 0 },
        { 640, 480, 511, 0 },
    }
};

Vp D_802DF3E0 = {{
        { 640, 480, 511, 0 },
        { 640, 480, 512, 0 },
    }
};

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

f32 spr_animUpdateTimeScale = 1.0f;

// TODO(player raster splat header generation):
// - macroify rasterSize based on the biggest raster
// - OR values of a generated player raster name enum together for initiallyLoaded bits
PlayerSpriteSet spr_playerSpriteSets[] = {
    /* Mario */ {  6, 0x700, 0x000003C6 },
    /* Mario */ { 18, 0x700, 0x000003C6 },
    /* Mario */ { 10, 0x900, 0x00003FC6 },
    /* Mario */ {  3, 0x700, 0x00000006 },
    /* Peach */ {  6, 0x900, 0x00003C00 },
    /* Peach */ {  6, 0x700, 0x0000003E },
    /* Peach */ {  6, 0x900, 0x00003C00 },
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

        guRotateF(mtx, rotY, 0.0f, 1.0f, 0.0f);
        guRotateF(mtx2, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtx2, mtx, mtx);
        guRotateF(mtx2, rotX, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtx2, mtx, mtx);

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
    spr_animUpdateTimeScale = arg0 * 2.0f;
}

INCLUDE_ASM(s32, "sprite", func_802DD89C);

void spr_init_sprites(s32 playerSpriteSet) {
    s32 i;
    s32 flags;

    spr_allocateBtlComponentsOnWorldHeap = FALSE;
    _heap_create(&gSpriteHeapPtr, 0x40000);
    func_8013A37C();

    for (i = 0; i < ARRAY_COUNT(spr_playerSprites); i++) {
        SpriteAnimData** playerSprites = spr_playerSprites;
        playerSprites[i] = 0;
    }

    spr_playerMaxComponents = 0;

    if (gGameStatusPtr->peachFlags & 1) {
        playerSpriteSet = 4;
    }

    flags = (&spr_playerSpriteSets[playerSpriteSet])->initiallyLoaded;
    func_802DED60((&spr_playerSpriteSets[playerSpriteSet])->cacheSize,
                  (&spr_playerSpriteSets[playerSpriteSet])->rasterSize);

    for (i = 1; i < 0xE; i++) {
        if ((flags >> i) & 1) {
            func_802DD89C(i); // spr_load_player_sprite
        }
    }

    for (i = 0; i < ARRAY_COUNT(spr_playerCurrentAnimInfo); i++) {
        struct spr_playerCurrentAnimInfo* d = &spr_playerCurrentAnimInfo[i];
        d->componentList = 0;
        d->animID = -1;
    }

    for (i = 0; i < ARRAY_COUNT(spr_npcSprites); i++) {
        s32* npcSprites = spr_npcSprites;
        u8* npcSpriteInstanceCount = spr_npcSpriteInstanceCount;

        npcSprites[i] = 0;
        npcSpriteInstanceCount[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_802DFA48); i++) {
        struct D_802DFA48* d = &D_802DFA48[i];
        d->unk_00 = 0;
        d->unk_04 = 0;
        d->unk_08 = 0;
        d->unk_0C = -1;
        d->unk_10 = 0;
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

INCLUDE_ASM(void, "sprite", func_802DDA8C, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(void, "sprite", render_sprite, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

INCLUDE_ASM(s32, "sprite", func_802DDEC4);

INCLUDE_ASM(s32, "sprite", func_802DDEE4);

INCLUDE_ASM(s32, "sprite", func_802DDFF8);

INCLUDE_ASM(s32, "sprite", func_802DE044);

INCLUDE_ASM(s32, "sprite", func_802DE0C0);

INCLUDE_ASM(s32, "sprite", func_802DE0EC);

INCLUDE_ASM(s32, "sprite", spr_update_sprite, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(void, "sprite", func_802DE3D8, s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f* arg4);

INCLUDE_ASM(s32, "sprite", func_802DE5C8);

INCLUDE_ASM(s32, "sprite", func_802DE5E8);

INCLUDE_ASM(s32, "sprite", func_802DE748);

INCLUDE_ASM(s32, "sprite", func_802DE780);

INCLUDE_ASM(s32, "sprite", func_802DE894);

INCLUDE_ASM(s32, "sprite", func_802DE8DC);

INCLUDE_ASM(s32, "sprite", func_802DE9D8);

INCLUDE_ASM(s32*, "sprite", func_802DEA40, u16 arg0);

INCLUDE_ASM(s32, "sprite", func_802DEA6C);

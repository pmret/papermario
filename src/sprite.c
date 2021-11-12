#include "sprite.h"

extern s32 D_802DF590[];
extern s32 D_802DFA58[];
extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern SpriteAnimData* spr_playerSprites[13];
extern s32 spr_playerMaxComponents;
extern SpriteAnimData* spr_npcSprites[0xEA];
extern struct spr_playerCurrentAnimInfo spr_playerCurrentAnimInfo[3];
extern struct D_802DFA48 D_802DFA48[51];
extern u8 spr_npcSpriteInstanceCount[];

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize);

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

INCLUDE_ASM(s32, "sprite", spr_init_quad_cache);

// extern s32* gSpriteHeapPtr;
// extern s32** D_802DFE44;
// extern s32* D_802DFE9C;

// void spr_init_quad_cache(void) {
//     s32 i;
//     s32* phi_v0;
//     D_802DFE44 = _heap_malloc(&gSpriteHeapPtr, 0x580);

//     for (i = 21; i >= 0; i--) {
//         D_802DFE44[i] = -1;
//     }
// }

INCLUDE_ASM(s32, "sprite", spr_get_cached_quad);

INCLUDE_ASM(s32, "sprite", spr_make_quad_for_size);

INCLUDE_ASM(s32, "sprite", spr_get_quad_for_size);

INCLUDE_ASM(s32, "sprite", spr_clear_quad_cache);

INCLUDE_ASM(s32, "sprite", spr_appendGfx_component_flat);

INCLUDE_ASM(s32, "sprite", spr_appendGfx_component);

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

s32 spr_sign_extend_12bit(u16 val) {
    s32 temp = val & 0xFFF;

    if (temp & 0x800) {
        return temp | ~0xFFF;
    } else {
        return temp;
    }
}

s32 spr_sign_extend_16bit(u16 val) {
    s32 temp = val & 0xFFFF;

    if (temp & 0x8000) {
        return temp | ~0xFFFF;
    } else {
        return temp;
    }
}

INCLUDE_ASM(s32, "sprite", spr_component_update_commands);

#ifdef NON_EQUIVALENT

void spr_component_update_finish(SpriteComponent* comp, SpriteComponent** compList, s32 arg2, s32 palette) {
    s32 temp_t0;
    s32 temp_v0_2;
    s8 temp_v0_3;
    SpriteComponent* temp_v0;

    if (comp->initialized) {
        temp_t0 = comp->unk_04;
        comp->compPos.x = comp->posOffset.x;
        comp->compPos.y = comp->posOffset.y;
        comp->compPos.z = comp->posOffset.z;
        if ((temp_t0 & 0xF00) == 0x100) {
            temp_v0 = compList[temp_t0 & 0xFF];
            comp->compPos.x = comp->posOffset.x + temp_v0->compPos.x;
            comp->compPos.y = comp->posOffset.y + temp_v0->compPos.y;
            comp->compPos.z = comp->posOffset.z + temp_v0->compPos.z;
        }
        temp_v0_2 = comp->currentRaster;
        if ((temp_v0_2 != -1) && (comp->currentRaster == -1)) {
            temp_v0_3 = (*((temp_v0_2 * 4) + arg2))->unk6;
            comp->unk18 = (s32) temp_v0_3;
            if ((palette != 0) && (temp_v0_3 == 0)) {
                comp->unk18 = palette;
            }
        }
    }
}

#else

INCLUDE_ASM(s32, "sprite", spr_component_update_finish);

#endif

INCLUDE_ASM(s32, "sprite", spr_component_update);

void spr_init_component_anim_state(SpriteComponent* comp, s16*** anim) {
    if (anim == -1) {
        comp->initialized = FALSE;
        return;
    }

    comp->initialized = TRUE;
    comp->unk_04 = 0;
    comp->readPos = *anim;
    comp->waitTime = 0;
    comp->loopCounter = 0;
    comp->currentRaster = -1;
    comp->currentPalette = -1;
    comp->posOffset.x = 0.0f;
    comp->posOffset.y = 0.0f;
    comp->posOffset.z = 0.0f;
    comp->compPos.x = 0.0f;
    comp->compPos.y = 0.0f;
    comp->compPos.z = 0.0f;
    comp->rotation.x = 0.0f;
    comp->rotation.y = 0.0f;
    comp->rotation.z = 0.0f;
    comp->scale.x = 1.0f;
    comp->scale.y = 1.0f;
    comp->scale.z = 1.0f;
}

INCLUDE_ASM(s32, "sprite", spr_init_anim_state);

void spr_set_anim_timescale(f32 timescale) {
    spr_animUpdateTimeScale = timescale * 2.0f;
}

void spr_load_player_sprite(s32 spriteIndex) {
    s32 ind = spriteIndex - 1;
    SpriteAnimData* playerSprite = spr_load_sprite(ind, 1, 0);

    spr_playerSprites[ind] = playerSprite;
    if (spr_playerMaxComponents < playerSprite->maxComponents) {
        spr_playerMaxComponents = playerSprite->maxComponents;
    }
}

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
    spr_init_player_raster_cache((&spr_playerSpriteSets[playerSpriteSet])->cacheSize,
                  (&spr_playerSpriteSets[playerSpriteSet])->rasterSize);

    for (i = 1; i < 0xE; i++) {
        if ((flags >> i) & 1) {
            spr_load_player_sprite(i); // spr_load_player_sprite
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

    spr_init_quad_cache(); // spr_init_quad_cache
}

void spr_render_init(void) {
    spr_update_player_raster_cache();
    spr_clear_quad_cache();
}

s32 func_802DDA84(void) {
    return 0;
}

INCLUDE_ASM(void, "sprite", spr_update_player_sprite, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(void, "sprite", spr_draw_player_sprite, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

s32 func_802DDEC4(s32 arg0) {
    return D_802DF590[arg0 * 3]; // The struct of D_802DF590 is probably 0xC in size with this taking the first field.
}

INCLUDE_ASM(s32, "sprite", func_802DDEE4);

#ifdef NON_EQUIVALENT

// There's a problem here: this matches if arg6 is an s32, but the uses of this function match if it is a u16...
s32 func_802DDFF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6) {
    return func_802DDEE4(0, -1, arg1, arg2, arg3, arg4, arg5, arg6);
}

#else

INCLUDE_ASM(s32, "sprite", func_802DDFF8);

#endif

INCLUDE_ASM(s32, "sprite", spr_get_player_raster_info);

INCLUDE_ASM(s32, "sprite", spr_get_player_palettes);

INCLUDE_ASM(s32, "sprite", spr_load_npc_sprite);

INCLUDE_ASM(s32, "sprite", spr_update_sprite, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(void, "sprite", spr_draw_npc_sprite, s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f* arg4);

s32 func_802DE5C8(s32 arg0) {
    return D_802DFA58[arg0 * 5]; // The struct of D_802DFA58 is probably 0x14 in size with this taking the first field.
}

INCLUDE_ASM(s32, "sprite", spr_free_sprite);

INCLUDE_ASM(s32, "sprite", func_802DE748);

INCLUDE_ASM(s32, "sprite", func_802DE780);

s32 func_802DE894(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_802DE780(arg0, -1, arg1, arg2, arg3, arg4, arg5, arg6);
}

INCLUDE_ASM(s32, "sprite", func_802DE8DC);

#ifdef NON_EQUIVALENT

// Some WIP work on sprite raster stuff.
s32 spr_get_npc_raster_info(spr_raster_info* outInfo, int npcSpriteID, int rasterIndex) {
    SpriteAnimData* sprite;
    void *temp_v1;

    sprite = spr_npcSprites[npcSpriteID];
    if (sprite == 0) {
        return FALSE;
    }
    temp_v1 = sprite->rastersOffset[rasterIndex];
    outInfo->unk0 = (s32)temp_v1->unk0;
    outInfo->unk8 = (s32)temp_v1->unk4;
    outInfo->unkC = (s32)temp_v1->unk5;
    outInfo->unk4 = sprite->unk4[temp_v1->unk6];
    return TRUE;
}

#else

INCLUDE_ASM(s32, "sprite", spr_get_npc_raster_info);

#endif

s32** spr_get_npc_palettes(s32 npcSpriteID) {
    SpriteAnimData* sprite = spr_npcSprites[npcSpriteID];

    if (sprite != NULL) {
        return sprite->palettesOffset;
    }
    return NULL;
}

s32 spr_get_npc_color_variations(s32 npcSpriteID) {
    SpriteAnimData* sprite = spr_npcSprites[npcSpriteID];

    if (sprite != NULL) {
        return sprite->colorVariations;
    }
    return -1;
}

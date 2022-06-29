#include "sprite.h"

extern s32 spr_allocateBtlComponentsOnWorldHeap;
// extern union {
//     s32 s32;
//     u8 b[4];
// } D_802DF540;
extern s32 D_802DF540;
extern SpriteAnimData* spr_playerSprites[13];
extern s32 D_802DF57C;
extern s32 spr_playerMaxComponents;
extern PlayerCurrentAnimInfo spr_playerCurrentAnimInfo[3];
extern SpriteAnimData* spr_npcSprites[0xEA];

extern u8 spr_npcSpriteInstanceCount[];
extern SpriteInstance D_802DFA48[51];

extern Quad* D_802DFE44;
extern s32 D_802DFE48[22];
extern s32 D_802DFEA0[3];
extern s32 D_802DFEAC;

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize);

Quad spr_defaultQuad = {
    {
    {{{ -16, 56, 0 }, FALSE, {    0,    0 }, { 240, 240, 240, 255 }}},
    {{{  16, 56, 0 }, FALSE, { 1024,    0 }, { 120, 120, 120, 255 }}},
    {{{  16,  0, 0 }, FALSE, { 1024, 1792 }, {   0,   0,   0, 255 }}},
    {{{ -16,  0, 0 }, FALSE, {    0, 1792 }, { 120, 120, 120, 255 }}},
    }
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

void spr_appendGfx_component_flat(
    Quad* vertices,
    void* raster, void* palette,
    s32 width, s32 height,
    f32 arg5,
    Matrix4f mtx,
    s32 alpha
);

void spr_init_quad_cache(void) {
    s32 i;

    D_802DFE44 = _heap_malloc(&gSpriteHeapPtr, ARRAY_COUNT(D_802DFE48) * sizeof(*D_802DFE44));

    for (i = 0; i < ARRAY_COUNT(D_802DFE48); i++) {
        D_802DFE48[i] = -1;
    }
}

Quad* spr_get_cached_quad(s32 quadIndex) {
    s32* temp_v1 = &D_802DFE48[quadIndex];

    *temp_v1 |= 0x1F;
    return &D_802DFE44[quadIndex];
}

void spr_make_quad_for_size(Quad* quad, s32 width, s32 height) {
    Vtx* vtx = &quad->v[0];
    s32 w = width; // required to match

    *quad = spr_defaultQuad;

    vtx->v.ob[0] = -w / 2;
    vtx->v.ob[1] = height;
    vtx->v.tc[0] = 0x2000;
    vtx->v.tc[1] = 0x2000;

    vtx++;
    vtx->v.ob[0] = w / 2;
    vtx->v.ob[1] = height;
    vtx->v.tc[0] = (w + 256) * 32;
    vtx->v.tc[1] = 0x2000;

    vtx++;
    vtx->v.tc[0] = (w + 256) * 32;
    vtx->v.ob[0] = w / 2;
    vtx->v.tc[1] = (height + 256) * 32;

    vtx++;
    vtx->v.ob[0] = -w / 2;
    vtx->v.tc[0] = 0x2000;
    vtx->v.tc[1] = (height + 256) * 32;
}

Quad* spr_get_quad_for_size(s32* quadIndex, s32 width, s32 height) {
    Quad* quad;
    s32 qi;
    s32 widthHeight;
    s32 i;

    if ((width * height) / 2 <= 0x800) {
        widthHeight = (width << 0x18) + (height << 0x10);
        qi = *quadIndex;
        if (qi != -1 && (widthHeight == (D_802DFE48[qi] & 0xFFFF0000))) {
            return spr_get_cached_quad(qi);
        }

        for (i = 0; i < ARRAY_COUNT(D_802DFE48); i++) {
            if (widthHeight == (D_802DFE48[i] & 0xFFFF0000)) {
                *quadIndex = i;
                return spr_get_cached_quad(i);
            }
        }

        for (i = 0; i < ARRAY_COUNT(D_802DFE48); i++) {
            if (D_802DFE48[i] == -1) {
                break;
            }
        }

        if (i != ARRAY_COUNT(D_802DFE48)) {
            *quadIndex = i;
            D_802DFE48[i] = widthHeight;
            quad = spr_get_cached_quad(i);
            spr_make_quad_for_size(quad, width, height);
            return quad;
        }
    }
    return NULL;
}

void spr_clear_quad_cache(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_802DFE48); i++) {
        if (D_802DFE48[i] != -1) {
            D_802DFE48[i]--;
            if (!(D_802DFE48[i] & 0xFFFF)) {
                D_802DFE48[i] = -1;
            }
        }
    }
}

INCLUDE_ASM(s32, "sprite", spr_appendGfx_component_flat);

void spr_appendGfx_component(
    SpriteRasterCacheEntry* cache,
    f32 dx, f32 dy, f32 dz,
    f32 rotX, f32 rotY, f32 rotZ,
    f32 scaleX, f32 scaleY, f32 scaleZ,
    s32 opacity, void* palette, Matrix4f mtx)
{
    Matrix4f sp20;
    Matrix4f sp60;
    FoldImageRecPart spA0;
    s32 quadIndex;
    Quad* quad;
    u32 temp_v1;
    s32 width;
    s32 height;

    guTranslateF(sp60, dx, dy, dz);
    guMtxCatF(sp60, mtx, sp20);

    if (rotY != 0.0f) {
        guRotateF(sp60, rotY, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
    }
    if (rotZ != 0.0f) {
        guRotateF(sp60, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp60, sp20, sp20);
    }
    if (rotX != 0.0f) {
        guRotateF(sp60, rotX, 1.0f, 0.0f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
    }

    if (scaleX != 1.0f || scaleY != 1.0f || scaleZ != 1.0f) {
        guScaleF(sp60, scaleX, scaleY, scaleZ);
        guMtxCatF(sp60, sp20, sp20);
    }

    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (D_80151328->flags & 1) {
        if ((u8) opacity == 255) {
            gSPDisplayList(gMasterGfxPos++, D_802DF460);
        } else {
            gSPDisplayList(gMasterGfxPos++, D_802DF490);
        }
    } else {
        if ((u8) opacity == 255) {
            gSPDisplayList(gMasterGfxPos++, D_802DF3F0);
        } else {
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (u8) opacity);
            gSPDisplayList(gMasterGfxPos++, D_802DF428);
        }
    }

    width = cache->width;
    height = cache->height;
    quadIndex = cache->quadCacheIndex;
    quad = NULL;
    if (!(D_802DF540 & (0x80000000 | 0x40000000 | 0x20000000 | 0x10000000))) {
        quad = spr_get_quad_for_size(&quadIndex, width, height);
        cache->quadCacheIndex = quadIndex;
    }

    if (quad != NULL) {
        spr_appendGfx_component_flat(quad, cache->image, palette, width, height, rotY, sp20, (u8) opacity);
    } else {
        spA0.raster = cache->image;
        spA0.palette = palette;
        spA0.width = width;
        spA0.height = height;
        spA0.xOffset = -(width / 2);
        spA0.yOffset = height;
        spA0.opacity = opacity;
        if (fold_appendGfx_component((u8) (u16) D_802DF540, &spA0, 0x80000, sp20) == 1) { // todo bitfield?
            D_802DF540 &= ~(0x80000000 | 0x40000000 | 0x20000000 | 0x10000000);
        }
    }
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

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

// void spr_draw_component(s32, SpriteComponent*, SpriteComponent*, SpriteRasterCacheEntry**, s16**, f32, Matrix4f);
// INCLUDE_ASM(s32, "sprite", spr_draw_component);
void spr_draw_component(s32 opacity, SpriteComponent* component, UnkSpriteThing* arg2, SpriteRasterCacheEntry** cache, s16** arg4, f32 arg5, Matrix4f mtx) {
    f32 dx;
    f32 dy;
    f32 dz;
    SpriteRasterCacheEntry* cacheEntry;
    s32 paletteIdx;
    void* pal;
    f32 rotX;
    f32 rotY;
    f32 rotZ;
    f32 inX;
    f32 inY;
    f32 inZ;

    if (component->initialized && component->currentRaster != -1) {
        rotX = D_802DFEA0[0];
        rotY = D_802DFEA0[1];
        rotZ = D_802DFEA0[2];
        inX = component->compPos.x + arg2->unk_06.x;
        inY = component->compPos.y + arg2->unk_06.y;
        inZ = component->compPos.z + arg2->unk_06.z;

        spr_transform_point(rotX, rotY, rotZ, inX, inY, inZ * arg5, &dx, &dy, &dz);
        cacheEntry = cache[component->currentRaster];
        paletteIdx = component->currentPalette;
        if (opacity & 0x08000000) {
            cacheEntry->image = spr_get_player_raster(component->currentRaster & 0xFFF, D_802DF57C);
        }
        D_802DF540 = component->unk_4C;
        pal = arg4[paletteIdx];

        spr_appendGfx_component(
            cacheEntry,
            dx, dy, dz,
            rotX + component->rotation.x,
            rotY + component->rotation.y,
            rotZ + component->rotation.z,
            component->scale.x,
            component->scale.y,
            component->scale.z,
            opacity, pal, mtx
        );
        component->unk_4C = D_802DF540;
    }
}

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

void spr_component_update_commands(SpriteComponent* comp, SpriteAnimComponent* animComponent);
INCLUDE_ASM(s32, "sprite", spr_component_update_commands);

void spr_component_update_finish(SpriteComponent* comp, SpriteComponent** compList,
                                 SpriteRasterCacheEntry** rasterCacheEntry, s32 overridePalette)
{
    SpriteComponent* listComp;
    SpriteRasterCacheEntry* cache;

    if (comp->initialized) {
        comp->compPos.x = comp->posOffset.x;
        comp->compPos.y = comp->posOffset.y;
        comp->compPos.z = comp->posOffset.z;

        if ((comp->unk_04 & 0xF00) == 0x100) {
            listComp = compList[comp->unk_04 & 0xFF];
            comp->compPos.x += listComp->compPos.x;
            comp->compPos.y += listComp->compPos.y;
            comp->compPos.z += listComp->compPos.z;
        }

        if (comp->currentRaster != -1) {
            cache = rasterCacheEntry[comp->currentRaster];
            if (comp->currentPalette == -1) {
                comp->currentPalette = cache->palette;
                if (overridePalette != 0 && comp->currentPalette == 0) {
                    comp->currentPalette = overridePalette;
                }
            }
        }
    }
}

s32 spr_component_update(s32 arg0, SpriteComponent** compList, SpriteAnimComponent** arg2, SpriteRasterCacheEntry** rasterCache, s32 overridePalette) {
    SpriteComponent** compListIt;

    D_802DFEAC = arg0;

    compListIt = compList;
    while ((s32) *compListIt != -1) {
        spr_component_update_commands(*compListIt++, *arg2);
        if ((s32) *arg2 != -1) {
            arg2++;
        }
    }

    compListIt = compList;
    while ((s32) *compListIt != -1) {
        spr_component_update_finish(*compListIt++, compList, rasterCache, overridePalette);
    }

    return D_802DFEAC;
}

void spr_init_component_anim_state(SpriteComponent* comp, s16*** anim) {
    if (anim == (s16***)-1) {
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


// very questionable cast, spr_init_component_anim_state args are probably wrong
void spr_init_anim_state(SpriteComponent** compList, s16** cmdList) {
    SpriteComponent* component;
    SpriteComponent** compListIt = compList;
    s16** cmdListIt = cmdList;
    while (*compListIt != (SpriteComponent*)-1) {
        component = *compListIt++;
        spr_init_component_anim_state(component, (s16***)*cmdListIt);
        if (*cmdListIt != (s16*)-1) {
            cmdListIt++;
        }
    }
}

void spr_set_anim_timescale(f32 timescale) {
    spr_animUpdateTimeScale = timescale * 2.0f;
}

void spr_load_player_sprite(s32 spriteIndex) {
    s32 ind = spriteIndex - 1;
    SpriteAnimData* playerSprite = spr_load_sprite(ind, TRUE, FALSE);

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
    fold_init();

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
        PlayerCurrentAnimInfo* animInfo = &spr_playerCurrentAnimInfo[i];

        animInfo->componentList = NULL;
        animInfo->animID = -1;
    }

    for (i = 0; i < ARRAY_COUNT(spr_npcSprites); i++) {
        s32* npcSprites = (s32*)spr_npcSprites;
        u8* npcSpriteInstanceCount = spr_npcSpriteInstanceCount;

        npcSprites[i] = NULL;
        npcSpriteInstanceCount[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_802DFA48); i++) {
        SpriteInstance* sprite = &D_802DFA48[i];

        sprite->spriteIndex = 0;
        sprite->componentList = NULL;
        sprite->spriteData = 0;
        sprite->currentAnimID = -1;
        sprite->unk_10 = 0;
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
    return spr_playerCurrentAnimInfo[arg0].unk_08;
}

void func_802DDEE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    SpriteComponent* component;
    SpriteComponent** componentListIt;
    s32 i;

    if (spr_playerCurrentAnimInfo[arg0].componentList != NULL) {
        componentListIt = spr_playerCurrentAnimInfo[arg0].componentList;
        i = 0;

        while (*componentListIt != (SpriteComponent*)-1) {
            component = *componentListIt;
            if (arg1 == -1 || i == arg1) {
                fold_update(component->unk_4C & 0xFF, arg2, arg3, arg4, arg5, arg6, arg7);
                if (arg2 != 0) {
                    component->unk_4C |= 0x10000000;
                } else {
                    component->unk_4C &= ~0xF0000000;
                }
            }
            componentListIt++;
            i++;
        }
    }
}

void func_802DDFF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_802DDEE4(0, -1, arg1, arg2, arg3, arg4, arg5, arg6);
}

void spr_get_player_raster_info(SpriteRasterInfo* out, s32 playerSpriteID, s32 rasterIndex) {
    SpriteAnimData* sprite;
    SpriteRasterCacheEntry* cache;
    u16** paletteOffsetCopy;

    playerSpriteID--;
    sprite = spr_playerSprites[playerSpriteID];
    if (sprite != NULL) {
        paletteOffsetCopy = sprite->palettesOffset;
        cache = sprite->rastersOffset[rasterIndex];
        out->width = cache->width;
        out->height = cache->height;
        out->defaultPal = paletteOffsetCopy[cache->palette];
        out->raster = spr_get_player_raster(rasterIndex, playerSpriteID);
    }
}

u16** spr_get_player_palettes(s32 spriteIndex) {
    SpriteAnimData* sprites = spr_playerSprites[spriteIndex - 1];
    if (sprites == NULL) {
        return NULL;
    }

    return sprites->palettesOffset;
}

INCLUDE_ASM(s32, "sprite", spr_load_npc_sprite);

INCLUDE_ASM(s32, "sprite", spr_update_sprite, s32 arg0, s32 arg1, f32 arg2);

INCLUDE_ASM(void, "sprite", spr_draw_npc_sprite, s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f* arg4);

s32 func_802DE5C8(s32 arg0) {
    return D_802DFA48[arg0].unk_10;
}

s32 spr_free_sprite(s32 spriteInstanceID) {
    SpriteInstance* sprite = &D_802DFA48[spriteInstanceID];
    s32 spriteIndex = sprite->spriteIndex;
    SpriteHeader* spriteData;
    SpriteComponent** comps;

    if (spriteIndex == 0 || spriteIndex >= ARRAY_COUNT(spr_npcSprites)) {
        return spriteInstanceID;
    }

    spr_npcSpriteInstanceCount[spriteIndex]--;
    spriteData = sprite->spriteData;

    comps = sprite->componentList;
    while ((s32) *comps != -1) {
        func_8013A854((u8) (*comps)->unk_4C);
        comps++;
    }

    comps = D_802DFA48[spriteInstanceID].componentList;

    if (spr_npcSpriteInstanceCount[spriteIndex] == 0) {
        spr_npcSprites[spriteIndex] = NULL;
        _heap_free(&gSpriteHeapPtr, spriteData);
    }

    if (spr_allocateBtlComponentsOnWorldHeap) {
        _heap_free(&heap_generalHead, comps);
    } else {
        _heap_free(&gSpriteHeapPtr, comps);
    }

    D_802DFA48[spriteInstanceID].spriteIndex = 0;
    D_802DFA48[spriteInstanceID].componentList = NULL;
    D_802DFA48[spriteInstanceID].spriteData = NULL;
    D_802DFA48[spriteInstanceID].currentAnimID = -1;
    return 0;
}

s32 func_802DE748(s32 arg0, s32 arg1) {
    SpriteComponent** componentList = D_802DFA48[arg0].componentList;

    if (componentList == NULL) {
        return -1;
    }

    return componentList[arg1]->unk_4C & 0xFF;
}

INCLUDE_ASM(s32, "sprite", func_802DE780);

s32 func_802DE894(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_802DE780(arg0, -1, arg1, arg2, arg3, arg4, arg5, arg6);
}

INCLUDE_ASM(s32, "sprite", func_802DE8DC);

s32 spr_get_npc_raster_info(SpriteRasterInfo* out, s32 npcSpriteID, s32 rasterIndex) {
    SpriteAnimData* sprite = spr_npcSprites[npcSpriteID];
    SpriteRasterCacheEntry* cache;
    u16** paletteOffsetCopy;
    s32 newVar;

    if (sprite != NULL) {
        paletteOffsetCopy = sprite->palettesOffset;
        cache = sprite->rastersOffset[rasterIndex];
        out->raster = cache->image;
        out->width = cache->width;
        newVar = npcSpriteID;
        out->height = cache->height;
        out->defaultPal = paletteOffsetCopy[cache->palette];
        return TRUE;
    }
    return FALSE;
}

u16** spr_get_npc_palettes(s32 npcSpriteID) {
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

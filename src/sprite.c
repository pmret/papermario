#include "sprite.h"
#include "sprite/player.h"

extern HeapNode heap_generalHead;
extern HeapNode heap_spriteHead;

BSS s32 D_802DF520; // unused?
BSS s32 spr_allocateBtlComponentsOnWorldHeap;
BSS s32 D_802DF528[2]; // unused?
BSS s32 MaxLoadedSpriteInstanceID;
BSS s32 D_802DF534[3]; // unused?
BSS s32 D_802DF540;
BSS s32 D_802DF544; // unused?
BSS SpriteAnimData* spr_playerSprites[13];
BSS s32 D_802DF57C;
BSS s32 spr_playerMaxComponents;
BSS s32 D_802DF584; // unused?
BSS PlayerCurrentAnimInfo spr_playerCurrentAnimInfo[3];
BSS s32 D_802DF5AC; // unused?
BSS SpriteAnimData* NpcSpriteData[234];
BSS u8 NpcSpriteInstanceCount[234];
BSS s32 D_802DFA44; // unused?
BSS SpriteInstance SpriteInstances[51];
BSS Quad* D_802DFE44;
BSS s32 D_802DFE48[22];
BSS s32 D_802DFEA0[3];
BSS s32 SpriteUpdateNotifyValue;

SpriteComponent** spr_allocate_components(s32);
void spr_load_npc_extra_anims(SpriteAnimData*, u32*);
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
    gsDPSetCombineMode(PM_CC_02, PM_CC_02),
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

#define MARIO_SPRITE_COMMON_BITS \
      1 << SPR_Mario1 \
    | 1 << SPR_Mario1_Back \

#define MARIO_SPRITE_WORLD_BITS \
    MARIO_SPRITE_COMMON_BITS \
    | 1 << SPR_MarioW1 \
    | 1 << SPR_MarioW1_Back \
    | 1 << SPR_MarioW2 \
    | 1 << SPR_MarioW3

#define MARIO_SPRITE_BATTLE_BITS \
    MARIO_SPRITE_COMMON_BITS \
    | 1 << SPR_MarioB1 \
    | 1 << SPR_MarioB2 \
    | 1 << SPR_MarioB3

#define PEACH_SPRITE_BITS \
      1 << SPR_Peach1 \
    | 1 << SPR_Peach1_Back \
    | 1 << SPR_Peach2 \
    | 1 << SPR_Peach3 \

// TODO(player raster splat header generation):
// - macroify rasterSize based on the biggest raster
PlayerSpriteSet spr_playerSpriteSets[] = {
    [PLAYER_SPRITES_MARIO_WORLD]            {  6, 0x700, MARIO_SPRITE_WORLD_BITS },
    [PLAYER_SPRITES_MARIO_REFLECT_FLOOR]    { 18, 0x700, MARIO_SPRITE_WORLD_BITS },
    [PLAYER_SPRITES_COMBINED_EPILOGUE]      { 10, 0x900, MARIO_SPRITE_WORLD_BITS | PEACH_SPRITE_BITS },
    [PLAYER_SPRITES_MARIO_PARADE]           {  3, 0x700, MARIO_SPRITE_COMMON_BITS },
    [PLAYER_SPRITES_PEACH_WORLD]            {  6, 0x900, PEACH_SPRITE_BITS },
    [PLAYER_SPRITES_MARIO_BATTLE]           {  6, 0x700, MARIO_SPRITE_BATTLE_BITS },
    [PLAYER_SPRITES_PEACH_BATTLE]           {  6, 0x900, PEACH_SPRITE_BITS},
};

void spr_init_quad_cache(void) {
    s32 i;

    D_802DFE44 = _heap_malloc(&heap_spriteHead, ARRAY_COUNT(D_802DFE48) * sizeof(*D_802DFE44));

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
    s32 dimensions;
    s32 i;

    if ((width * height) / 2 <= 0x800) {
        dimensions = (width << 0x18) + (height << 0x10);
        qi = *quadIndex;
        if (qi != -1 && (dimensions == (D_802DFE48[qi] & 0xFFFF0000))) {
            return spr_get_cached_quad(qi);
        }

        for (i = 0; i < ARRAY_COUNT(D_802DFE48); i++) {
            if (dimensions == (D_802DFE48[i] & 0xFFFF0000)) {
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
            D_802DFE48[i] = dimensions;
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

void spr_appendGfx_component_flat(
    Quad* vertices,
    IMG_PTR raster, PAL_PTR palette,
    s32 width, s32 height,
    f32 arg5,
    Matrix4f mtx,
    s32 alpha
) {
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, palette);
    if (gSpriteShadingProfile->flags & 1) {
        gDPScrollMultiTile2_4b(gMainGfxPos++, raster, G_IM_FMT_CI, width, height,
                              0, 0, width - 1, height - 1, 0,
                              G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                              256, 256);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 63 << 2, 0);
        if (gSpriteShadingProfile->flags & 2) {
            Camera* camera = &gCameras[gCurrentCamID];
            if (gGameStatusPtr->isBattle == 2) {
                gSPViewport(gMainGfxPos++, &D_802DF3E0);
            } else {
                gSPViewport(gMainGfxPos++, &camera->vpAlt);
            }

            if (alpha == 255) {
                gDPSetRenderMode(gMainGfxPos++, AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                                 G_RM_PASS, AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                                 GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
            }

            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha);
            gDPSetCombineMode(gMainGfxPos++, PM_CC_0B, PM_CC_0C);
            gSPVertex(gMainGfxPos++, vertices, 4, 0);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 0, 3, 2, 0);
            gDPPipeSync(gMainGfxPos++);
        }
        create_shading_palette(mtx, 0, 0, width, height, alpha, alpha == 255 ? 0x111238 : 0x104B50); // TODO make macro for render mode
    } else {
        gDPScrollTextureBlock_4b(gMainGfxPos++, raster, G_IM_FMT_CI, width, height, 0,
                                 G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                 256, 256);
        if (gSpriteShadingProfile->flags & 2) {
            Camera* camera =  &gCameras[gCurrentCamID];
            if (gGameStatusPtr->isBattle == 2) {
                gSPViewport(gMainGfxPos++, &D_802DF3E0);
            } else {
                gSPViewport(gMainGfxPos++, &camera->vpAlt);
            }
            if (alpha == 255) {
                gDPSetRenderMode(gMainGfxPos++, AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            }

            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha);
            gDPSetCombineMode(gMainGfxPos++, PM_CC_0A, PM_CC_0A);
            gSPVertex(gMainGfxPos++, vertices, 4, 0);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 0, 3, 2, 0);
            gDPPipeSync(gMainGfxPos++);

            if (alpha == 255) {
                gDPSetRenderMode(gMainGfxPos++, AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                                 GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
                                 AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                                 GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            }

            gDPSetEnvColor(gMainGfxPos++, 100, 100, 100, 255);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
            gDPSetCombineLERP(gMainGfxPos++, SHADE, ENVIRONMENT, TEXEL0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, SHADE, ENVIRONMENT, TEXEL0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
            gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
        }
    }

    if (gSpriteShadingProfile->flags & 2) {
        Camera* camera =  &gCameras[gCurrentCamID];

        if (gGameStatusPtr->isBattle == 2) {
            gSPViewport(gMainGfxPos++, &D_802DF3D0);
            D_802DF3E0.vp.vtrans[0] = D_802DF3D0.vp.vtrans[0] + gGameStatusPtr->unk_82;
            D_802DF3E0.vp.vtrans[1] = D_802DF3D0.vp.vtrans[1] + gGameStatusPtr->unk_83;
        } else {
            gSPViewport(gMainGfxPos++, &camera->vp);
        }
    }

    gSPVertex(gMainGfxPos++, vertices, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 0, 3, 2, 0);
    gDPPipeSync(gMainGfxPos++);
}

void spr_appendGfx_component(
    SpriteRasterCacheEntry* cache,
    f32 dx, f32 dy, f32 dz,
    f32 rotX, f32 rotY, f32 rotZ,
    f32 scaleX, f32 scaleY, f32 scaleZ,
    s32 opacity, PAL_PTR palette, Matrix4f mtx)
{
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    ImgFXTexture ifxImg;
    s32 quadIndex;
    Quad* quad;
    s32 width;
    s32 height;

    guTranslateF(mtxTemp, dx, dy, dz);
    guMtxCatF(mtxTemp, mtx, mtxTransform);

    if (rotY != 0.0f) {
        guRotateF(mtxTemp, rotY, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    }
    if (rotZ != 0.0f) {
        guRotateF(mtxTemp, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    }
    if (rotX != 0.0f) {
        guRotateF(mtxTemp, rotX, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    }

    if (scaleX != 1.0f || scaleY != 1.0f || scaleZ != 1.0f) {
        guScaleF(mtxTemp, scaleX, scaleY, scaleZ);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    }

    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (gSpriteShadingProfile->flags & 1) {
        if ((u8) opacity == 255) {
            gSPDisplayList(gMainGfxPos++, D_802DF460);
        } else {
            gSPDisplayList(gMainGfxPos++, D_802DF490);
        }
    } else {
        if ((u8) opacity == 255) {
            gSPDisplayList(gMainGfxPos++, D_802DF3F0);
        } else {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, (u8) opacity);
            gSPDisplayList(gMainGfxPos++, D_802DF428);
        }
    }

    width = cache->width;
    height = cache->height;
    quadIndex = cache->quadCacheIndex;
    quad = NULL;
    if (!(D_802DF540 & SPR_IMGFX_FLAG_ALL)) {
        quad = spr_get_quad_for_size(&quadIndex, width, height);
        cache->quadCacheIndex = quadIndex;
    }

    if (quad != NULL) {
        spr_appendGfx_component_flat(quad, cache->image, palette, width, height, rotY, mtxTransform, (u8) opacity);
    } else {
        ifxImg.raster  = cache->image;
        ifxImg.palette = palette;
        ifxImg.width   = width;
        ifxImg.height  = height;
        ifxImg.xOffset = -(width / 2);
        ifxImg.yOffset = height;
        ifxImg.alpha = opacity;
        if (imgfx_appendGfx_component((u8) D_802DF540, &ifxImg, IMGFX_FLAG_80000, mtxTransform) == 1) {
            D_802DF540 &= ~SPR_IMGFX_FLAG_ALL;
        }
    }
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void spr_transform_point(s32 rotX, s32 rotY, s32 rotZ, f32 inX, f32 inY, f32 inZ, f32* outX, f32* outY, f32* outZ) {
    if (rotX == 0 && rotY == 0 && rotZ == 0) {
        *outX = inX;
        *outY = inY;
        *outZ = inZ;
    } else {
        Matrix4f mtxTransform, mtxTemp;
        f32 xx, yx, zx, xy, yy, zy, xz, yz, zz;

        guRotateF(mtxTransform, rotY, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxTemp, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guRotateF(mtxTemp, rotX, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

        xx = (mtxTransform[0][0] * inX);
        yx = (mtxTransform[1][0] * inY);
        zx = (mtxTransform[2][0] * inZ);
        xy = (mtxTransform[0][1] * inX);
        yy = (mtxTransform[1][1] * inY);
        zy = (mtxTransform[2][1] * inZ);
        xz = (mtxTransform[0][2] * inX);
        yz = (mtxTransform[1][2] * inY);
        zz = (mtxTransform[2][2] * inZ);

        *outX = xx + yx + zx;
        *outY = xy + yy + zy;
        *outZ = xz + yz + zz;
    }
}

void spr_draw_component(s32 drawOpts, SpriteComponent* component, SpriteAnimComponent* anim,
        SpriteRasterCacheEntry** cache, PAL_PTR* palettes, f32 zscale, Matrix4f mtx) {
    SpriteRasterCacheEntry* cacheEntry;
    s32 paletteIdx;
    PAL_PTR pal;
    f32 dx, dy, dz;
    f32 rotX, rotY, rotZ;
    f32 inX, inY, inZ;

    if (component->initialized && component->curRaster != -1) {
        rotX = D_802DFEA0[0];
        rotY = D_802DFEA0[1];
        rotZ = D_802DFEA0[2];
        inX = component->compPos.x + anim->compOffset.x;
        inY = component->compPos.y + anim->compOffset.y;
        inZ = component->compPos.z + anim->compOffset.z;

        spr_transform_point(rotX, rotY, rotZ, inX, inY, inZ * zscale, &dx, &dy, &dz);
        cacheEntry = cache[component->curRaster];
        paletteIdx = component->curPalette;
        if (drawOpts & DRAW_SPRITE_USE_PLAYER_RASTERS) {
            cacheEntry->image = spr_get_player_raster(component->curRaster & 0xFFF, D_802DF57C);
        }
        D_802DF540 = component->imgfxIdx;
        pal = palettes[paletteIdx];

        spr_appendGfx_component(
            cacheEntry,
            dx, dy, dz,
            rotX + component->rot.x,
            rotY + component->rot.y,
            rotZ + component->rot.z,
            component->scale.x,
            component->scale.y,
            component->scale.z,
            drawOpts, pal, mtx
        );
        component->imgfxIdx = D_802DF540;
    }
}

s32 spr_unpack_signed_12bit(u16 val) {
    s32 temp = val & 0xFFF;

    if (temp & 0x800) {
        return temp | ~0xFFF;
    } else {
        return temp;
    }
}

s32 spr_unpack_signed_16bit(u16 val) {
    s32 temp = val & 0xFFFF;

    if (temp & 0x8000) {
        return temp | ~0xFFFF;
    } else {
        return temp;
    }
}

void spr_component_update_commands(SpriteComponent* comp, SpriteAnimComponent* anim) {
    f32 posX, posY, posZ;
    f32 rotX, rotY, rotZ;
    f32 scaleX, scaleY, scaleZ;
    s32 changedFlags;

    u16* bufPos;
    u16* gotoPos;
    s32 cmdValue;

    if (comp->initialized) {
        scaleZ = 1.0f;
        scaleY = 1.0f;
        scaleX = 1.0f;
        changedFlags = 0;

        bufPos = comp->readPos;
        gotoPos = (u16*) -1;

        comp->waitTime -= spr_animUpdateTimeScale;

        while (comp->waitTime <= 0.0f) {
            // overflow check
            if (bufPos >= &anim->cmdList[anim->cmdListSize / 2]) {
                bufPos = anim->cmdList;
                break;
            }

            switch (*bufPos & 0xF000) {
                // 0VVV
                // Wait
                case 0x0000:
                    comp->waitTime = *bufPos++ & 0xFFF;
                    if (comp->waitTime == 0.0f) {
                        comp->waitTime = 4095.0f;
                    }
                    comp->posOffset.z = 0.0f;
                    comp->posOffset.y = 0.0f;
                    comp->posOffset.x = 0.0f;
                    comp->rot.z = 0;
                    comp->rot.y = 0;
                    comp->rot.x = 0;
                    comp->scale.z = 1.0f;
                    comp->scale.y = 1.0f;
                    comp->scale.x = 1.0f;
                    break;
                // 2VVV
                // Goto -- jump to another position in the list
                case 0x2000:
                    bufPos = &anim->cmdList[spr_unpack_signed_12bit(*bufPos)];
                    if (bufPos == gotoPos) {
                        bufPos = anim->cmdList;
                        comp->waitTime = 1.0f;
                    }
                    gotoPos = bufPos;
                    break;
                // 1VVV
                // SetImage -- FFF is valid value for "no image"
                case 0x1000:
                    cmdValue = *bufPos++ & 0xFFF;
                    if (cmdValue != 0xFFF) {
                        comp->curRaster = cmdValue;
                    } else {
                        comp->curRaster = -1;
                    }
                    comp->curPalette = -1;
                    break;
                // 6VVV
                // SetPalette -- FFF to clear
                case 0x6000:
                    cmdValue = *bufPos++ & 0xFFF;
                    if (cmdValue != 0xFFF) {
                        comp->curPalette = cmdValue;
                    } else {
                        comp->curPalette = -1;
                    }
                    break;
                // 8VUU
                // SetProperty
                // 81-XX parent to component XX
                // 82-YY set notify value to YY
                case 0x8000:
                    cmdValue = *bufPos++;
                    switch (cmdValue & 0xF00) {
                        case 0x100: // set parent
                            comp->properties = (comp->properties & 0xFFFF0000) | cmdValue;
                            break;
                        case 0x200: // set notify value
                            SpriteUpdateNotifyValue = cmdValue & 0xFF;
                            comp->properties = (comp->properties & 0xFF00FFFF) | (SpriteUpdateNotifyValue << 0x10);
                            break;
                    }
                    break;
                // 3VVV XXXX YYYY ZZZZ
                // SetPosition -- what does the flag do?
                case 0x3000:
                    switch (*bufPos++ & 0xF) {
                        case 0:
                        case 1:
                            posX = spr_unpack_signed_16bit(*bufPos++);
                            posY = spr_unpack_signed_16bit(*bufPos++);
                            posZ = spr_unpack_signed_16bit(*bufPos++);
                            changedFlags |= 1;
                            break;
                    }
                    break;
                // 4XXX YYYY ZZZZ
                // SetRotation (euler angles)
                case 0x4000:
                    rotX = spr_unpack_signed_12bit(*bufPos++);
                    rotY = spr_unpack_signed_16bit(*bufPos++);
                    rotZ = spr_unpack_signed_16bit(*bufPos++);
                    changedFlags |= 2;
                    break;
                // 5VVV UUUU
                // SetScale (%)
                case 0x5000:
                    switch (*bufPos++ & 0xF) {
                        case 0:
                            scaleZ = *bufPos++ / 100.0f;
                            scaleY = scaleZ;
                            scaleX = scaleZ;
                            break;
                        case 1:
                            scaleX = *bufPos++ / 100.0f;
                            break;
                        case 2:
                            scaleY = *bufPos++ / 100.0f;
                            break;
                        case 3:
                            scaleZ = *bufPos++ / 100.0f;
                            break;
                    }
                    changedFlags |= 4;
                    break;
                // 7VVV UUUU
                // Loop -- VV iterations jumping back to UUUU
                case 0x7000:
                    if (comp->loopCounter != 0) {
                        comp->loopCounter--;
                        if (comp->loopCounter == 0) {
                            bufPos += 2;
                            break;
                        }
                    } else {
                        comp->loopCounter = bufPos[1];
                    }
                    bufPos = &anim->cmdList[spr_unpack_signed_12bit(*bufPos)];
                    break;
                // invalid command
                default:
                    bufPos = anim->cmdList;
                    comp->waitTime = 1.0f;
                    break;
            }
        } // end loop

        comp->readPos = bufPos;
        if (changedFlags & 1) {
            comp->posOffset.x = posX;
            comp->posOffset.y = posY;
            comp->posOffset.z = posZ;
        }
        if (changedFlags & 2) {
            comp->rot.x = rotX;
            comp->rot.y = rotY;
            comp->rot.z = rotZ;
        }
        if (changedFlags & 4) {
            comp->scale.x = scaleX;
            comp->scale.y = scaleY;
            comp->scale.z = scaleZ;
        }
    }
}

void spr_component_update_finish(SpriteComponent* comp, SpriteComponent** compList,
                                 SpriteRasterCacheEntry** rasterCacheEntry, s32 overridePalette)
{
    SpriteComponent* listComp;
    SpriteRasterCacheEntry* cache;

    if (comp->initialized) {
        comp->compPos.x = comp->posOffset.x;
        comp->compPos.y = comp->posOffset.y;
        comp->compPos.z = comp->posOffset.z;

        if ((comp->properties & 0xF00) == 0x100) {
            listComp = compList[comp->properties & 0xFF];
            comp->compPos.x += listComp->compPos.x;
            comp->compPos.y += listComp->compPos.y;
            comp->compPos.z += listComp->compPos.z;
        }

        if (comp->curRaster != -1) {
            cache = rasterCacheEntry[comp->curRaster];
            if (comp->curPalette == -1) {
                comp->curPalette = cache->palette;
                if (overridePalette != 0 && comp->curPalette == 0) {
                    comp->curPalette = overridePalette;
                }
            }
        }
    }
}

s32 spr_component_update(s32 curNotifyValue, SpriteComponent** compList, SpriteAnimComponent** animList,
        SpriteRasterCacheEntry** rasterCache, s32 overridePalette) {
    SpriteComponent** compListIt;

    SpriteUpdateNotifyValue = curNotifyValue;

    compListIt = compList;
    while (*compListIt != PTR_LIST_END) {
        spr_component_update_commands(*compListIt++, *animList);
        if (*animList != PTR_LIST_END) {
            animList++;
        }
    }

    compListIt = compList;
    while (*compListIt != PTR_LIST_END) {
        spr_component_update_finish(*compListIt++, compList, rasterCache, overridePalette);
    }

    return SpriteUpdateNotifyValue;
}

void spr_init_component_anim_state(SpriteComponent* comp, SpriteAnimComponent* anim) {
    if (anim == PTR_LIST_END) {
        comp->initialized = FALSE;
        return;
    }

    comp->initialized = TRUE;
    comp->properties = 0;
    comp->readPos = anim->cmdList;
    comp->waitTime = 0;
    comp->loopCounter = 0;
    comp->curRaster = -1;
    comp->curPalette = -1;
    comp->posOffset.x = 0.0f;
    comp->posOffset.y = 0.0f;
    comp->posOffset.z = 0.0f;
    comp->compPos.x = 0.0f;
    comp->compPos.y = 0.0f;
    comp->compPos.z = 0.0f;
    comp->rot.x = 0.0f;
    comp->rot.y = 0.0f;
    comp->rot.z = 0.0f;
    comp->scale.x = 1.0f;
    comp->scale.y = 1.0f;
    comp->scale.z = 1.0f;
}

void spr_init_anim_state(SpriteComponent** compList, SpriteAnimComponent** animList) {
    while (*compList != PTR_LIST_END) {
        SpriteComponent* component = *compList++;
        spr_init_component_anim_state(component, *animList);
        if (*animList != PTR_LIST_END) {
            animList++;
        }
    }
}

void spr_set_anim_timescale(f32 timescale) {
    spr_animUpdateTimeScale = timescale * 2.0f;
}

void spr_load_player_sprite(s32 spriteIndex) {
    SpriteAnimData* playerSprite = spr_load_sprite(spriteIndex - 1, TRUE, FALSE);

    spr_playerSprites[spriteIndex - 1] = playerSprite;
    if (spr_playerMaxComponents < playerSprite->maxComponents) {
        spr_playerMaxComponents = playerSprite->maxComponents;
    }
}

void spr_init_sprites(s32 playerSpriteSet) {
    s32 loadedFlags;
    s32 i;

    spr_allocateBtlComponentsOnWorldHeap = FALSE;
    _heap_create(&heap_spriteHead, 0x40000);
    imgfx_init();

    for (i = 0; i < ARRAY_COUNT(spr_playerSprites); i++) {
        SpriteAnimData** playerSprites = spr_playerSprites;
        playerSprites[i] = 0;
    }

    spr_playerMaxComponents = 0;

    if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH) {
        playerSpriteSet = PLAYER_SPRITES_PEACH_WORLD;
    }

    loadedFlags = (&spr_playerSpriteSets[playerSpriteSet])->initiallyLoaded;
    spr_init_player_raster_cache((&spr_playerSpriteSets[playerSpriteSet])->cacheSize,
                  (&spr_playerSpriteSets[playerSpriteSet])->rasterSize);

    for (i = 1; i <= SPR_Peach3; i++) {
        if ((loadedFlags >> i) & 1) {
            spr_load_player_sprite(i);
        }
    }

    for (i = 0; i < ARRAY_COUNT(spr_playerCurrentAnimInfo); i++) {
        spr_playerCurrentAnimInfo[i].componentList = NULL;
        spr_playerCurrentAnimInfo[i].animID = -1;
    }

    for (i = 0; i < ARRAY_COUNT(NpcSpriteData); i++) {
        NpcSpriteData[i] = NULL;
        NpcSpriteInstanceCount[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(SpriteInstances); i++) {
        SpriteInstances[i].spriteIndex = 0;
        SpriteInstances[i].componentList = NULL;
        SpriteInstances[i].spriteData = NULL;
        SpriteInstances[i].curAnimID = -1;
        SpriteInstances[i].notifyValue = 0;
    }

    spr_init_quad_cache();
}

void spr_render_init(void) {
    spr_update_player_raster_cache();
    spr_clear_quad_cache();
}

s32 func_802DDA84(void) {
    return 0;
}

s32 spr_update_player_sprite(s32 spriteInstanceID, s32 animID, f32 timeScale) {
    u32* spriteData;
    SpriteComponent** compList;
    SpriteComponent* component;
    SpriteAnimComponent** animList;
    SpriteRasterCacheEntry** rasterList;
    s32 spriteId = ((animID >> 16) & 0xFF) - 1;
    s32 instanceIdx = spriteInstanceID & 0xFF;
    s32 animIndex = animID & 0xFF;
    D_802DF57C = spriteId;

    if (spr_playerCurrentAnimInfo[instanceIdx].componentList == NULL) {
        compList = spr_allocate_components(spr_playerMaxComponents);
        spr_playerCurrentAnimInfo[instanceIdx].componentList = compList;
        while (*compList != PTR_LIST_END) {
            component = *compList;
            component->imgfxIdx = imgfx_get_free_instances(1);
            compList++;
        }
    }

    spriteData = (u32*)spr_playerSprites[spriteId];
    compList = spr_playerCurrentAnimInfo[instanceIdx].componentList;

    if (spriteData == NULL) {
        return 0;
    }

    rasterList = (SpriteRasterCacheEntry**)*spriteData;
    spriteData += 4 + animIndex;
    animList = (SpriteAnimComponent**)*spriteData;

    spr_set_anim_timescale(timeScale);
    if ((spriteInstanceID & DRAW_SPRITE_OVERRIDE_ALPHA) ||
        (animID & ~SPRITE_ID_BACK_FACING) != (spr_playerCurrentAnimInfo[instanceIdx].animID & ~SPRITE_ID_BACK_FACING))
    {
        spr_init_anim_state(compList, animList);
        spr_playerCurrentAnimInfo[instanceIdx].notifyValue = 0;
    }

    spr_playerCurrentAnimInfo[instanceIdx].animID = animID;

    if (!(spriteInstanceID & DRAW_SPRITE_OVERRIDE_YAW)) {
        spr_playerCurrentAnimInfo[instanceIdx].notifyValue = spr_component_update(spr_playerCurrentAnimInfo[instanceIdx].notifyValue,
                compList, animList, rasterList, 0);
    }
    return spr_playerCurrentAnimInfo[instanceIdx].notifyValue;
}

s32 spr_draw_player_sprite(s32 spriteInstanceID, s32 yaw, s32 alphaIn, PAL_PTR* paletteList, Matrix4f mtx) {
    s32 instanceIdx = spriteInstanceID & 0xFF;
    s32 animID = spr_playerCurrentAnimInfo[instanceIdx].animID;
    SpriteRasterCacheEntry** rasters;
    PAL_PTR* palettes;
    SpriteAnimComponent** animComponents;
    SpriteComponent** components;
    f32 zscale;
    u32 alpha;
    u32* spriteData;
    s32 spriteId;
    s32 spriteIdBackFacing;

    if (animID == ANIM_LIST_END) {
        return FALSE;
    }

    D_802DF57C = spriteId = ((animID >> 0x10) & 0xFF) - 1;
    spriteData = (u32*)spr_playerSprites[spriteId];
    if (spriteData == NULL) {
        return FALSE;
    }

    // TODO: fake match or not?
    rasters = (SpriteRasterCacheEntry**)*spriteData++;
    palettes = (PAL_PTR*)*spriteData++;
    spriteData++;
    spriteData++;
    animComponents = (SpriteAnimComponent**)spriteData[animID & 0xFF];

    if (animID & SPRITE_ID_BACK_FACING) {
        switch (spriteId) {
            case 0:
            case 5:
            case 9:
                spriteIdBackFacing = spriteId + 1;
                // TODO find better match
                rasters = (SpriteRasterCacheEntry**)spr_playerSprites[spriteIdBackFacing];
                D_802DF57C = spriteIdBackFacing;
                rasters = (SpriteRasterCacheEntry**)*rasters;
                break;
        }
    }

    if (!(spriteInstanceID & DRAW_SPRITE_OVERRIDE_YAW)) {
        yaw += (s32)-gCameras[gCurrentCamID].curYaw;
        if (yaw > 360) {
            yaw -= 360;
        }
        if (yaw < -360) {
            yaw += 360;
        }
    }

    if (yaw > 90 && yaw <= 270 || yaw >= -270 && yaw < -90) {
        zscale = -1.5f;
    } else {
        zscale = 1.5f;
    }

    if (spriteInstanceID & DRAW_SPRITE_UPSIDE_DOWN) {
        zscale = 0.0f - zscale;
    }

    D_802DFEA0[0] = 0;
    D_802DFEA0[1] = yaw;
    D_802DFEA0[2] = 0;


    if (spriteInstanceID & DRAW_SPRITE_OVERRIDE_ALPHA) {
        alpha = alphaIn & 0xFF;
        if (alphaIn == 0) {
            return FALSE;
        }
    } else {
        alpha = 255;
    }

    components = spr_playerCurrentAnimInfo[instanceIdx].componentList;
    if (spriteInstanceID & DRAW_SPRITE_OVERRIDE_PALETTES) {
        palettes = paletteList;
    }

    while (*components != PTR_LIST_END) {
        spr_draw_component(alpha | DRAW_SPRITE_USE_PLAYER_RASTERS, *components++, *animComponents, rasters, palettes, zscale, mtx);
        if (*animComponents != PTR_LIST_END) {
            animComponents++;
        }
    }

    return TRUE;
}

s32 func_802DDEC4(s32 spriteIdx) {
    return spr_playerCurrentAnimInfo[spriteIdx].notifyValue;
}

void set_player_imgfx_comp(s32 spriteIdx, s32 compIdx, ImgFXType imgfx, s32 imgfxArg1, s32 imgfxArg2, s32 imgfxArg3, s32 imgfxArg4, s32 flags) {
    SpriteComponent* component;
    SpriteComponent** componentListIt;
    s32 i;

    if (spr_playerCurrentAnimInfo[spriteIdx].componentList != NULL) {
        componentListIt = spr_playerCurrentAnimInfo[spriteIdx].componentList;
        i = 0;

        while (*componentListIt != PTR_LIST_END) {
            component = *componentListIt;
            if (compIdx == -1 || i == compIdx) {
                imgfx_update(component->imgfxIdx & 0xFF, imgfx, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, flags);
                if (imgfx != IMGFX_CLEAR) {
                    component->imgfxIdx |= SPR_IMGFX_FLAG_10000000;
                } else {
                    component->imgfxIdx &= ~SPR_IMGFX_FLAG_ALL;
                }
            }
            componentListIt++;
            i++;
        }
    }
}

// applied to all components
void set_player_imgfx_all(s32 animID, ImgFXType imgfxType, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, imgfxType, arg2, arg3, arg4, arg5, arg6);
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

PAL_PTR* spr_get_player_palettes(s32 spriteIndex) {
    SpriteAnimData* sprites = spr_playerSprites[spriteIndex - 1];

    if (sprites == NULL) {
        return NULL;
    } else {
        return sprites->palettesOffset;
    }
}

s32 spr_load_npc_sprite(s32 animID, u32* extraAnimList) {
    SpriteAnimData* header;
    SpriteComponent** compList;
    s32 listIndex;
    s32 i;

    s32 spriteIndex = (animID >> 0x10) & 0x7FFF;
    s32 useTailAlloc = (u32)animID >> 0x1F;

    for (i = 0; i < ARRAY_COUNT(SpriteInstances); i++) {
        if (SpriteInstances[i].spriteIndex == 0) {
            break;
        }
    }
    if (MaxLoadedSpriteInstanceID < i) {
        MaxLoadedSpriteInstanceID = i;
    }
    if (i == ARRAY_COUNT(SpriteInstances)) {
        return -1;
    }
    listIndex = i;
    if (NpcSpriteData[spriteIndex] != NULL) {
        NpcSpriteInstanceCount[spriteIndex]++;
        header = NpcSpriteData[spriteIndex];
        SpriteInstances[listIndex].spriteData = header;
    } else {
        NpcSpriteInstanceCount[spriteIndex] = 1;
        header = spr_load_sprite(spriteIndex - 1, FALSE, useTailAlloc);
        SpriteInstances[listIndex].spriteData = header;
        NpcSpriteData[spriteIndex] = header;
        if (extraAnimList != NULL) {
            spr_load_npc_extra_anims(header, extraAnimList);
        }
    }
    compList = spr_allocate_components(header->maxComponents);
    SpriteInstances[listIndex].componentList = compList;
    while (*compList != PTR_LIST_END) {
        SpriteComponent* comp = *compList;
        comp->imgfxIdx = imgfx_get_free_instances(1);
        compList++;
    }
    SpriteInstances[listIndex].spriteIndex = spriteIndex;
    SpriteInstances[listIndex].curAnimID = -1;
    return listIndex;
}

s32 spr_update_sprite(s32 spriteInstanceID, s32 animID, f32 timeScale) {
    u32* spriteData;
    SpriteComponent** compList;
    SpriteAnimComponent** animList;
    SpriteRasterCacheEntry** rasterList;

    s32 palID;
    s32 i = spriteInstanceID & 0xFF;
    s32 animIndex = animID & 0xFF;

    compList = SpriteInstances[i].componentList;
    spriteData = (u32*)SpriteInstances[i].spriteData;

    rasterList = (SpriteRasterCacheEntry**)*spriteData;
    spriteData += 4 + animIndex;
    animList = (SpriteAnimComponent**)*spriteData;

    palID = (animID >> 8) & 0xFF;
    spr_set_anim_timescale(timeScale);
    if ((spriteInstanceID & DRAW_SPRITE_OVERRIDE_ALPHA) || ((SpriteInstances[i].curAnimID & 0xFF) != animIndex)) {
        spr_init_anim_state(compList, animList);
        SpriteInstances[i].curAnimID = (palID << 8) | animIndex;
        SpriteInstances[i].notifyValue = 0;
    }
    if (!(spriteInstanceID & DRAW_SPRITE_OVERRIDE_YAW)) {
        SpriteInstances[i].notifyValue = spr_component_update(SpriteInstances[i].notifyValue,
            compList, animList, rasterList, palID);
    }
    return SpriteInstances[i].notifyValue;
}

s32 spr_draw_npc_sprite(s32 spriteInstanceID, s32 yaw, s32 arg2, PAL_PTR* paletteList, Matrix4f mtx) {
    s32 i = spriteInstanceID & 0xFF;
    s32 animID = SpriteInstances[i].curAnimID;
    SpriteRasterCacheEntry** rasters;
    PAL_PTR* palettes;
    SpriteAnimComponent** animComponents;
    SpriteComponent** components;
    f32 zscale;
    u32 alpha;
    u32* spriteData;

    if (animID == ANIM_LIST_END) {
        return FALSE;
    }

    spriteData = (u32*)SpriteInstances[i].spriteData;

    // TODO: fake match or not?
    rasters = (SpriteRasterCacheEntry**)*spriteData++;
    palettes = (PAL_PTR*)*spriteData++;
    spriteData++;
    spriteData++;
    animComponents = (SpriteAnimComponent**)spriteData[animID & 0xFF];

    D_802DFEA0[0] = 0;
    D_802DFEA0[1] = yaw;
    D_802DFEA0[2] = 0;

    if (!(spriteInstanceID & DRAW_SPRITE_OVERRIDE_YAW)) {
        yaw += gCameras[gCurrentCamID].curYaw;
        if (yaw > 360) {
            yaw -= 360;
        }
        if (yaw < -360) {
            yaw += 360;
        }
    }

    if (yaw > 90 && yaw <= 270 || yaw >= -270 && yaw < -90) {
        zscale = -1.5f;
    } else {
        zscale = 1.5f;
    }

    if (spriteInstanceID & DRAW_SPRITE_OVERRIDE_ALPHA) {
        alpha = arg2 & 0xFF;
        if (arg2 == 0) {
            return FALSE;
        }
    } else {
        alpha = 255;
    }

    components = SpriteInstances[i].componentList;
    if (spriteInstanceID & DRAW_SPRITE_OVERRIDE_PALETTES) {
        palettes = paletteList;
    }

    while (*components != PTR_LIST_END) {
        spr_draw_component(alpha, *components++, *animComponents, rasters, palettes, zscale, mtx);
        if (*animComponents != PTR_LIST_END) {
            animComponents++;
        }
    }

    return TRUE;
}

s32 spr_get_notify_value(s32 spriteIndex) {
    return SpriteInstances[spriteIndex].notifyValue;
}

s32 spr_free_sprite(s32 spriteInstanceID) {
    SpriteInstance* sprite = &SpriteInstances[spriteInstanceID];
    SpriteAnimData* spriteData;
    SpriteComponent** compList;
    s32 spriteIndex = sprite->spriteIndex;

    if (spriteIndex == 0 || spriteIndex >= ARRAY_COUNT(NpcSpriteData)) {
        return spriteInstanceID;
    }

    NpcSpriteInstanceCount[spriteIndex]--;
    spriteData = sprite->spriteData;

    compList = sprite->componentList;
    while (*compList != PTR_LIST_END) {
        SpriteComponent* comp = *compList;
        imgfx_release_instance(comp->imgfxIdx & 0xFF);
        compList++;
    }

    compList = SpriteInstances[spriteInstanceID].componentList;

    if (NpcSpriteInstanceCount[spriteIndex] == 0) {
        NpcSpriteData[spriteIndex] = NULL;
        _heap_free(&heap_spriteHead, spriteData);
    }

    if (spr_allocateBtlComponentsOnWorldHeap) {
        _heap_free(&heap_generalHead, compList);
    } else {
        _heap_free(&heap_spriteHead, compList);
    }

    SpriteInstances[spriteInstanceID].spriteIndex = 0;
    SpriteInstances[spriteInstanceID].componentList = NULL;
    SpriteInstances[spriteInstanceID].spriteData = NULL;
    SpriteInstances[spriteInstanceID].curAnimID = -1;
    return 0;
}

s32 get_npc_comp_imgfx_idx(s32 spriteIdx, s32 compIdx) {
    SpriteComponent** componentList = SpriteInstances[spriteIdx].componentList;

    if (componentList == NULL) {
        return -1;
    } else {
        return componentList[compIdx]->imgfxIdx & 0xFF;
    }
}

void set_npc_imgfx_comp(s32 spriteIdx, s32 compIdx, ImgFXType imgfx, s32 imgfxArg1, s32 imgfxArg2, s32 imgfxArg3, s32 imgfxArg4, s32 imgfxArg5) {
    SpriteInstance* sprite = &SpriteInstances[spriteIdx];
    SpriteComponent** componentList;
    s32 i;

    if (sprite->componentList != NULL) {
        componentList = sprite->componentList;
        i = 0;

        while (*componentList != PTR_LIST_END) {
            SpriteComponent* comp = *componentList;

            if (compIdx == -1 || i == compIdx) {
                imgfx_update((u8)comp->imgfxIdx, imgfx, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, imgfxArg5);
                if (imgfx != IMGFX_CLEAR) {
                    comp->imgfxIdx |= SPR_IMGFX_FLAG_10000000;
                } else {
                    comp->imgfxIdx &= ~SPR_IMGFX_FLAG_ALL;
                }
            }
            componentList++;
            i++;
        }
    }
}

void set_npc_imgfx_all(s32 spriteIdx, ImgFXType imgfxType, s32 imgfxArg1, s32 imgfxArg2, s32 imgfxArg3, s32 imgfxArg4, s32 imgfxArg5) {
    set_npc_imgfx_comp(spriteIdx, -1, imgfxType, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, imgfxArg5);
}

s32 spr_get_comp_position(s32 spriteIdx, s32 compListIdx, s32* outX, s32* outY, s32* outZ) {
    SpriteInstance* sprite = &SpriteInstances[spriteIdx];
    SpriteAnimComponent** animCompList;
    SpriteAnimComponent* anim;
    SpriteComponent** compList;
    SpriteComponent* comp;
    u8 animID;
    s32 i;
    u32* spriteData;

    if (sprite->componentList == NULL) {
        return; // bug: does not return a value
    }

    animID = sprite->curAnimID;
    if (animID != 255) {
        // following 3 lines equivalent to:
        // animCompList = sprite->spriteData->animListStart[animID];
        spriteData = (u32*)sprite->spriteData;
        spriteData += 4 + animID;
        animCompList = (SpriteAnimComponent**)*spriteData;
        compList = sprite->componentList;
        i = 0;
        while (*compList != PTR_LIST_END) {
            if (i == compListIdx) {
                anim = *animCompList;
                comp = *compList;
                *outX = comp->compPos.x + anim->compOffset.x;
                *outY = comp->compPos.y + anim->compOffset.y;
                *outZ = comp->compPos.z + anim->compOffset.z;
                return 0;
            }
            i++;
            compList++;
            if (*animCompList != PTR_LIST_END) {
                animCompList++;
            }
        }
    } else {
        return; // bug: does not return a value
    }
    return -1;
}

s32 spr_get_npc_raster_info(SpriteRasterInfo* out, s32 npcSpriteID, s32 rasterIndex) {
    SpriteAnimData* sprite = NpcSpriteData[npcSpriteID];
    SpriteRasterCacheEntry* cache;
    PAL_PTR* paletteOffsetCopy;

    if (sprite != NULL) {
        paletteOffsetCopy = sprite->palettesOffset;
        cache = sprite->rastersOffset[rasterIndex];
        out->raster = cache->image;
        out->width = cache->width;
        out->height = cache->height;
        out->defaultPal = paletteOffsetCopy[cache->palette];
        return TRUE;
    }
    return FALSE;
}

PAL_PTR* spr_get_npc_palettes(s32 npcSpriteID) {
    SpriteAnimData* sprite = NpcSpriteData[npcSpriteID];

    if (sprite != NULL) {
        return sprite->palettesOffset;
    } else {
        return NULL;
    }
}

s32 spr_get_npc_color_variations(s32 npcSpriteID) {
    SpriteAnimData* sprite = NpcSpriteData[npcSpriteID];

    if (sprite != NULL) {
        return sprite->colorVariations;
    } else {
        return -1;
    }
}

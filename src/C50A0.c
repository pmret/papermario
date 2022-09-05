#include "common.h"
#include "effects.h"
#include "hud_element.h"
#include "pause/pause_common.h"
#include "world/partners.h"
#include "sparkle_script.h"
#include "item_entity.h"

#define MAX_ITEM_ENTITIES 256

extern SparkleScript SparkleScript_Coin;

extern Lights1 D_8014C6C8;

extern s32 ItemEntitiesCreated;
extern s32 D_80155D80;
extern s32 ItemEntityAlternatingSpawn;
extern s32 ItemEntityRenderGroup;
extern s16 D_80155D8C;
extern s16 D_80155D8E;
extern s16 D_80155D90;
extern ItemEntity* WorldItemEntities[MAX_ITEM_ENTITIES];
extern ItemEntity* BattleItemEntities[MAX_ITEM_ENTITIES];
extern ItemEntity** gCurrentItemEntities;
extern s16 isPickingUpItem;
extern s16 D_801565A6;
extern s16 D_801565A8;
extern PopupMenu D_801565B0;
extern s32 D_801568E0;
extern s32 D_801568E4;
extern s32 D_801568E8;
extern s32 D_801568EC;
extern EffectInstance* D_801568F0;
extern MessagePrintState* D_801568F4;
extern s32 D_801568F8;

void item_entity_load(ItemEntity*);
void item_entity_update(ItemEntity*);
void appendGfx_item_entity(void*);
void draw_item_entities(void);
void draw_item_entities_UI(void);
s32 test_item_player_collision(ItemEntity*);
void update_item_entity_collectable(ItemEntity*);
void func_8013559C(ItemEntity*);
void update_item_entity_static(ItemEntity*);
void func_801356C4(ItemEntity*);
void func_801356CC(ItemEntity*);
void func_801356D4(ItemEntity*);
void func_801363A0(ItemEntity*);
void update_item_entity_temp(ItemEntity*);
s32 draw_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, s16 posX, s16 posY, u16 clipULx,
                             u16 clipULy, u16 clipLRx, u16 clipRLy);
void func_8013673C(ItemEntity* itemEntity, s32 posX, s32 posY);
void func_801369D0(ItemEntity* itemEntity, s32 posX, s32 posY);
void func_80136A08(ItemEntity* itemEntity, s32 posX, s32 posY);

Vtx D_8014C5A0[4] = {
    {{{ -12,  0, 0 }, 0, { 0x2300, 0x2300 }, { 0, 0, 0, 255 }}},
    {{{  11,  0, 0 }, 0, { 0x2000, 0x2300 }, { 0, 0, 0, 255 }}},
    {{{  11, 23, 0 }, 0, { 0x2000, 0x2000 }, { 0, 0, 0, 255 }}},
    {{{ -12, 23, 0 }, 0, { 0x2300, 0x2000 }, { 0, 0, 0, 255 }}},
};

Vtx D_8014C5E0[4] = {
    {{{ -16,  0, 0 }, 0, { 0x2400, 0x2400 }, { 0, 0, 0, 255 }}},
    {{{  15,  0, 0 }, 0, { 0x2000, 0x2400 }, { 0, 0, 0, 255 }}},
    {{{  15, 31, 0 }, 0, { 0x2000, 0x2000 }, { 0, 0, 0, 255 }}},
    {{{ -16, 31, 0 }, 0, { 0x2400, 0x2000 }, { 0, 0, 0, 255 }}},
};

Gfx D_8014C620[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPEndDisplayList(),
};

Gfx D_8014C678[] = {
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_8014C5A0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8014C6A0[] = {
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_8014C5E0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Lights1 D_8014C6C8 = gdSPDefLights1(255, 255, 255, 0, 0, 0, 0, 0, 0);

s16 D_8014C6E0[] = { 32, 40 };
s16 D_8014C6E4[] = { 8, 4 };

s32 draw_ci_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, PAL_PTR palette, s16 posX,
                                s16 posY, u16 clipULx, u16 clipULy, u16 clipLRx, u16 clipRLy, u8 opacity) {
    s32 ret;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);

    if (opacity == 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else if (opacity == 0) {
        return 1;
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, opacity);
    }

    if (fmt == G_IM_FMT_CI) {
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
        if (bitDepth == G_IM_SIZ_4b) {
            gDPLoadTLUT_pal16(gMasterGfxPos++, 0, palette);
        } else {
            gDPLoadTLUT_pal256(gMasterGfxPos++, palette);
        }
    } else {
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    }
    ret = draw_image_with_clipping(raster, width, height, fmt, bitDepth, posX, posY, clipULx, clipULy, clipLRx, clipRLy);
    gDPPipeSync(gMasterGfxPos++);
    return ret;
}

INCLUDE_ASM(s32, "C50A0", draw_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_tiled_image);

s32 integer_log(s32 number, u32 base) {
    f32 fNumber = number;
    s32 ret = 1;

    while (TRUE) {
        fNumber /= base;
        if (fNumber <= 1.0) {
            return ret;
        }

        ret++;
    }
}

INCLUDE_ASM(s32, "C50A0", draw_adjustable_tiled_image);

void sparkle_script_init(ItemEntity* itemEntity, SparkleScript* script) {
    itemEntity->sparkleReadPos = (s32*)script;
    itemEntity->sparkleNextUpdate = 1;
    itemEntity->sparkleSavedPos = (s32*)script;
}

s32 sparkle_script_step(ItemEntity* itemEntity) {
    s32* readPos = itemEntity->sparkleReadPos;

    switch (*readPos++) {
        case SPARKLE_OP_SetGfx:
            itemEntity->sparkleNextUpdate = *readPos++;
            itemEntity->sparkleUnk44 = *readPos++;
            itemEntity->sparkleReadPos = readPos;
            break;
        case SPARKLE_OP_Restart:
            itemEntity->sparkleReadPos = itemEntity->sparkleSavedPos;
            return TRUE;
        case SPARKLE_OP_Jump:
            itemEntity->sparkleSavedPos = readPos;
            itemEntity->sparkleReadPos = readPos;
            return TRUE;
        case SPARKLE_OP_SetCI:
            itemEntity->sparkleNextUpdate = *readPos++;
            itemEntity->sparkleRaster  = (IMG_PTR)*readPos++;
            itemEntity->sparklePalette = (PAL_PTR)*readPos++;
            itemEntity->sparkleWidth = *readPos++;
            itemEntity->sparkleHeight = *readPos++;
            itemEntity->sparkleReadPos = readPos;
            break;
        case SPARKLE_OP_Break:
            readPos++; // ignore arg
            itemEntity->sparkleReadPos = readPos;
        case SPARKLE_OP_End:
            return TRUE;
    }
    return FALSE;
}

void sparkle_script_update(ItemEntity* itemEntity) {
    itemEntity->sparkleNextUpdate--;
    if (itemEntity->sparkleNextUpdate <= 0) {
        while (sparkle_script_step(itemEntity)) {}
    }
}

void draw_coin_sparkles(ItemEntity* itemEntity) {
    f32 x, y, z;
    f32 angle;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    FoldImageRecPart foldImage;

    x = D_80155D8C;
    y = D_80155D8E;
    z = D_80155D90;
    angle = clamp_angle(180.0f - gCameras[gCurrentCamID].currentYaw);

    guTranslateF(sp18, x, y, z);
    guTranslateF(sp58, itemEntity->position.x, itemEntity->position.y + 12.0f, itemEntity->position.z);
    guRotateF(sp98, angle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp18, sp98, sp98);
    guMtxCatF(sp98, sp58, spD8);
    guMtxF2L(spD8, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPSetLights1(gMasterGfxPos++, D_8014C6C8);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);

    foldImage.raster = itemEntity->sparkleRaster;
    foldImage.palette = itemEntity->sparklePalette;
    foldImage.width = itemEntity->sparkleWidth;
    foldImage.height = itemEntity->sparkleHeight;
    foldImage.xOffset = -itemEntity->sparkleWidth / 2;
    foldImage.yOffset = itemEntity->sparkleHeight / 2;
    foldImage.opacity = 255;
    fold_appendGfx_component(0, &foldImage, 0, spD8);

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return gCurrentItemEntities[itemEntityIndex];
}

void item_entity_disable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags |= ITEM_ENTITY_FLAGS_40;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags |= ENTITY_FLAGS_HIDDEN;
    }
}

void item_entity_enable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags &= ~ITEM_ENTITY_FLAGS_40;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags &= ~ENTITY_FLAGS_HIDDEN;
    }
}

void clear_item_entity_data(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        gCurrentItemEntities[i] = NULL;
    }

    ItemEntitiesCreated = 0;
    D_80155D8C = 0;
    D_80155D8E = 0;
    D_80155D90 = 0;
    ItemEntityAlternatingSpawn = 0;

    if (!gGameStatusPtr->isBattle) {
        ItemEntityRenderGroup = 0;
    }

    create_generic_entity_world(NULL, draw_item_entities);
    create_generic_entity_frontUI(NULL, draw_item_entities_UI);
    isPickingUpItem = FALSE;
    D_801565A8 = 0;
}

void init_item_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    isPickingUpItem = FALSE;
    D_801565A8 = 0;
    ItemEntitiesCreated = 0;
    ItemEntityAlternatingSpawn = 0;
}

INCLUDE_ASM(s32, "C50A0", item_entity_load);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign, s32 pickupVar) {
    s32 i;
    s32 id;
    ItemEntity* itemEntity;
    f32 hitDepth;
    Shadow* shadow;

    if (pickupVar <= -120000000) {
        pickupVar = pickupVar + 130000000;
    }

    if (pickupVar > 0) {
        switch (itemSpawnMode) {
            case ITEM_SPAWN_MODE_NOTHING:
            case ITEM_SPAWN_MODE_TOSS_NEVER_VANISH:
            case ITEM_SPAWN_MODE_TOSS:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE_NEVER_VANISH:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE:
            case ITEM_SPAWN_MODE_FALL_NEVER_VANISH:
            case ITEM_SPAWN_MODE_FALL:
            case ITEM_SPAWN_MODE_FALL_SPAWN_ONCE:
            case ITEM_SPAWN_MODE_FIXED_NEVER_VANISH:
            case ITEM_SPAWN_MODE_FIXED:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_COIN:
            case ITEM_SPAWN_MODE_TOSS_HIGHER_NEVER_VANISH:
                if (get_global_flag(pickupVar) != 0) {
                    return -1;
                }
                break;
        }
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        if (gCurrentItemEntities[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_ITEM_ENTITIES);

    id = i;
    gCurrentItemEntities[id] = itemEntity = heap_malloc(sizeof(*itemEntity));
    ItemEntitiesCreated++;
    ASSERT(itemEntity != NULL);

    itemEntity->renderGroup = ((u32)itemID >> 0x10) & 0xF;
    if (itemEntity->renderGroup == 5) {
        itemEntity->renderGroup = -1;
    }

    itemEntity->spawnType = itemSpawnMode;
    itemEntity->state = 0;
    itemEntity->position.x = x;
    itemEntity->position.y = y;
    itemEntity->position.z = z;

    itemID &= 0xFFFF;

    itemEntity->flags = ITEM_ENTITY_FLAGS_80 | ITEM_ENTITY_FLAGS_10 | ITEM_ENTITY_FLAGS_CAM2 | ITEM_ENTITY_FLAGS_CAM1 | ITEM_ENTITY_FLAGS_CAM0;
    itemEntity->pickupMsgFlags = 0;
    itemEntity->boundVar = pickupVar;
    itemEntity->itemID = itemID;
    itemEntity->physicsData = NULL;
    itemEntity->pickupDelay = pickupDelay;
    itemEntity->scale = 1.0f;
    itemEntity->wsFaceAngle = facingAngleSign;
    itemEntity->shadowIndex = -1;
    itemEntity->nextUpdate = 1;
    itemEntity->unk_34.x = -9999;
    itemEntity->unk_34.y = -9999;
    itemEntity->unk_34.z = -9999;
    D_801565A6 = 30;

    itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        itemEntity->flags |= ITEM_ENTITY_FLAGS_40000;
        itemEntity->flags &= ~ITEM_ENTITY_FLAGS_TINY;
    }

    if (ItemEntityAlternatingSpawn != 0) {
        itemEntity->flags |= ITEM_ENTITY_FLAGS_20000;
    }

    ItemEntityAlternatingSpawn = 1 - ItemEntityAlternatingSpawn;

    switch (itemEntity->spawnType) {
        case ITEM_SPAWN_MODE_NOTHING:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_80000000;
            break;
        case ITEM_SPAWN_MODE_DECORATION:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000;
            break;
        case ITEM_SPAWN_MODE_INVISIBLE:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_100000;
            break;
        case ITEM_SPAWN_MODE_BATTLE_REWARD:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_800;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_800 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_40000000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_40000000 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000;
            break;
        case ITEM_SPAWN_MODE_FALL_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL_SPAWN_ONCE:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_800;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_FIXED;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000000;
            break;
        case ITEM_SPAWN_MODE_FIXED_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_FIXED | ITEM_ENTITY_FLAGS_400 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_FIXED | ITEM_ENTITY_FLAGS_400;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_FIXED | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE1:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_1000;
            itemEntity->scale = 0.8f;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE2:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_1000;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_10000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_FADE1;
            itemEntity->scale = 0.8f;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE3:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_1000;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_400000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_FADE1;
            itemEntity->scale = 0.8f;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            itemEntity->scale = 0.8f;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
            break;
        case ITEM_SPAWN_MODE_UNKNOWN_1B:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_8000;
            itemEntity->spawnType = ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS;
            itemEntity->scale = 0.8f;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_TINY;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_8000 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_COIN:
            itemEntity->spawnType = ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_8000 | ITEM_ENTITY_FLAGS_400 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            break;
        case ITEM_SPAWN_MODE_TOSS_HIGHER_NEVER_VANISH:
            itemEntity->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_800000 | ITEM_ENTITY_FLAGS_400 | ITEM_ENTITY_FLAGS_NEVER_VANISH;
            itemEntity->flags |= ITEM_ENTITY_FLAGS_1000000;
            break;
    }

    switch (itemEntity->spawnType) {
        case ITEM_SPAWN_MODE_NOTHING:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            itemEntity->shadowIndex = create_shadow_type(0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
            shadow = get_shadow_by_index(itemEntity->shadowIndex);

            if (itemEntity->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
                shadow->flags |= ENTITY_FLAGS_HIDDEN;
            }

            x = itemEntity->position.x;
            y = itemEntity->position.y + 12.0f;
            z = itemEntity->position.z;
            hitDepth = 1000.0f;
            npc_raycast_down_sides(0x20000, &x, &y, &z, &hitDepth);
            shadow->position.x = x;
            shadow->position.y = y;
            shadow->position.z = z;
            shadow->rotation.x = gGameStatusPtr->playerGroundTraceAngles.x;
            shadow->rotation.y = 0.0f;
            shadow->rotation.z = gGameStatusPtr->playerGroundTraceAngles.z;
            set_standard_shadow_scale(shadow, hitDepth * 0.5f);
            break;
    }

    if (itemEntity->pickupDelay != 0) {
        item_entity_disable_shadow(itemEntity);
    }

    item_entity_load(itemEntity);

    if (itemEntity->itemID == ITEM_COIN) {
        sparkle_script_init(itemEntity, &SparkleScript_Coin);
        sparkle_script_update(itemEntity);
    }

    if (itemEntity->itemID == ITEM_STAR_PIECE) {
        itemEntity->flags &= ~ITEM_ENTITY_FLAGS_80;
    }

    return id;
}

s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, 0, -1, pickupVar);
}

s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, pickupDelay, -1, pickupVar);
}

s32 make_item_entity_at_player(s32 itemID, s32 arg1, s32 pickupMsgFlags) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    ItemEntity* item;
    Shadow* shadow;
    s32 i;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 depth;
    s32 id;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        if (gCurrentItemEntities[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ITEM_ENTITIES);
    id = i;

    gCurrentItemEntities[id] = item = heap_malloc(sizeof(*item));
    ItemEntitiesCreated++;
    ASSERT(item != NULL);

    itemID &= 0xFFFF;
    item->renderGroup = -1;
    item->flags = (ITEM_ENTITY_FLAGS_CAM0 | ITEM_ENTITY_FLAGS_CAM1 | ITEM_ENTITY_FLAGS_CAM2 | ITEM_ENTITY_FLAGS_10 | ITEM_ENTITY_FLAGS_2000000);
    if (arg1 != 0) {
        item->flags |= ITEM_ENTITY_FLAGS_4000000;
    }
    item->pickupMsgFlags = pickupMsgFlags;
    item->spawnType = ITEM_SPAWN_AT_PLAYER;
    item->state = 0;
    item->boundVar = 0;
    item->position.x = playerStatus->position.x;
    item->position.y = playerStatus->position.y;
    item->position.z = playerStatus->position.z;

    item->shadowIndex = -1;
    item->nextUpdate = 1;
    item->unk_34.x = -9999;
    item->unk_34.y = -9999;
    item->unk_34.z = -9999;
    item->scale = 1.0f;
    item->itemID = itemID;
    item->physicsData = NULL;
    item->pickupDelay = 0;
    item->wsFaceAngle = 0;
    item->flags |= ITEM_ENTITY_FLAGS_TINY;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags = (item->flags | ITEM_ENTITY_FLAGS_40000) & ~ITEM_ENTITY_FLAGS_TINY;
    }
    if (ItemEntityAlternatingSpawn != 0) {
        item->flags |= ITEM_ENTITY_FLAGS_20000;
    }
    ItemEntityAlternatingSpawn = 1 - ItemEntityAlternatingSpawn;

    item->shadowIndex = create_shadow_type(0, item->position.x, item->position.y, item->position.z);
    shadow = get_shadow_by_index(item->shadowIndex);
    shadow->flags |= ENTITY_FLAGS_HIDDEN;

    posX = item->position.x;
    posY = item->position.y + 12.0f;
    posZ = item->position.z;
    depth = 1000.0f;
    npc_raycast_down_sides(0x20000, &posX, &posY, &posZ, &depth);
    shadow->position.x = posX;
    shadow->position.y = posY;
    shadow->position.z = posZ;

    shadow->rotation.x = gGameStatusPtr->playerGroundTraceAngles.x;
    shadow->rotation.y = 0.0f;
    shadow->rotation.z = gGameStatusPtr->playerGroundTraceAngles.z;
    set_standard_shadow_scale(shadow, depth * 0.5f);

    item_entity_load(item);
    if (item->itemID == ITEM_COIN) {
        sparkle_script_init(item, &SparkleScript_Coin);
        sparkle_script_update(item);
    }
    return id;
}

void item_entity_update(ItemEntity* entity) {
    s32* args;
    s32 max, threshold;

    entity->nextUpdate--;
    if (entity->nextUpdate != 0) {
        return;
    }

    do {
        args = entity->readPos;
        switch(*args++) {
            case ITEM_SCRIPT_OP_End:
                entity->nextUpdate = 60;
                return;
            case ITEM_SCRIPT_OP_SetImage:
                entity->nextUpdate = *args++;
                *args++;
                *args++;
                if (!gGameStatusPtr->isBattle) {
                    entity->lookupRasterIndex  = *args++ & 0xFFFF;
                    entity->lookupPaletteIndex = *args++ & 0xFFFF;
                } else {
                    entity->lookupRasterIndex  = *args++ >> 16;
                    entity->lookupPaletteIndex = *args++ >> 16;
                }
                entity->readPos = args;
                return;
            case ITEM_SCRIPT_OP_Restart:
                entity->readPos = entity->savedReadPos;
                break;
            case ITEM_SCRIPT_OP_Loop:
                entity->savedReadPos = args;
                entity->readPos = args;
                break;
            case ITEM_SCRIPT_OP_RandomRestart:
                max = *args++;
                threshold = *args++;
                if (rand_int(max) < threshold) {
                    entity->readPos = entity->savedReadPos;
                } else {
                    entity->readPos = args;
                }
                break;
        }
    } while (TRUE);
}

void update_item_entities(void) {
    ItemEntity* entity;
    ItemEntity* entity2;
    f32 x, y, z, hitDepth;
    s32 coin;
    s32 i;

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800))) {
        for (i = 0; i < 0x100; i++) {
            entity = gCurrentItemEntities[i];

            if (entity != NULL && entity->flags != 0) {
                if (entity->itemID == ITEM_COIN) {
                    if (rand_int(100) > 90) {
                        sparkle_script_init(entity, &SparkleScript_Coin);
                        D_80155D8C = rand_int(16) - 8;
                        D_80155D8E = rand_int(16) - 8;
                        D_80155D90 = 5;
                    }
                    sparkle_script_update(entity);
                }

                item_entity_update(entity);

                switch (entity->spawnType) {
                    case ITEM_SPAWN_MODE_NOTHING:
                        update_item_entity_static(entity);
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        func_801356CC(entity);
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        update_item_entity_collectable(entity);
                        break;
                    case ITEM_SPAWN_AT_PLAYER:
                        update_item_entity_temp(entity);
                        break;
                }


                entity = gCurrentItemEntities[i];
                if (entity != NULL) {
                    s32 xs, ys, zs;

                    switch (entity->spawnType) {
                        case ITEM_SPAWN_MODE_NOTHING:
                        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                        case ITEM_SPAWN_AT_PLAYER:
                            xs = entity->position.x;
                            ys = entity->position.y;
                            zs = entity->position.z;

                            if (xs != entity->unk_34.x || ys != entity->unk_34.y || zs != entity->unk_34.z) {
                                Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

                                x = entity->position.x;
                                y = entity->position.y + 12.0f;
                                z = entity->position.z;
                                hitDepth = 1000.0f;
                                npc_raycast_down_sides(0x20000, &x, &y, &z, &hitDepth);

                                shadow->position.x = x;
                                shadow->position.y = y;
                                shadow->position.z = z;
                                shadow->rotation.x = gGameStatusPtr->playerGroundTraceAngles.x;
                                shadow->rotation.y = 0.0f;
                                shadow->rotation.z = gGameStatusPtr->playerGroundTraceAngles.z;
                                set_standard_shadow_scale(shadow, hitDepth * 0.5f);
                            }
                            break;
                    }
                    entity->unk_34.x = entity->position.x;
                    entity->unk_34.y = entity->position.y;
                    entity->unk_34.z = entity->position.z;
                }
            }
            do {} while (0); // required to match
        }
    }
}

INCLUDE_ASM(s32, "C50A0", appendGfx_item_entity);

void draw_item_entities(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    RenderTask* retTask;
    s32 i;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        ItemEntity* itemEntity = gCurrentItemEntities[i];

        if (itemEntity != NULL && itemEntity->flags != 0 && !(itemEntity->flags & ITEM_ENTITY_FLAGS_40) &&
            (itemEntity->flags & (1 << gCurrentCamID)) && !(itemEntity->flags & ITEM_ENTITY_FLAGS_100000) &&
            !(itemEntity->renderGroup != -1 && ItemEntityRenderGroup != itemEntity->renderGroup))
        {
            if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_TRANSPARENT)) {
                rtPtr->renderMode = RENDER_MODE_ALPHATEST;
            } else {
                rtPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            }

            rtPtr->appendGfxArg = itemEntity;
            rtPtr->appendGfx = appendGfx_item_entity;
            rtPtr->distance = 0;

            retTask = queue_render_task(rtPtr);
            retTask->renderMode |= RENDER_TASK_FLAG_2;
        }

        do {} while (0); // required to match
    }
}

void draw_item_entities_UI(void) {
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_4000 | GLOBAL_OVERRIDES_8000))) {
        s32 i;

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = gCurrentItemEntities[i];

            if (itemEntity != NULL && itemEntity->flags != 0) {
                switch (itemEntity->spawnType) {
                    case ITEM_SPAWN_MODE_NOTHING:
                        func_801356C4(itemEntity);
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        func_801356D4(itemEntity);
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        func_8013559C(itemEntity);
                        break;
                }
            }

            do {} while (0); // required to match
        }
    }
}

INCLUDE_ASM(s32, "C50A0", render_item_entities);

void remove_item_entity_by_reference(ItemEntity* entity) {
    s32 index;

    for (index = 0; index < MAX_ITEM_ENTITIES; index++) {
        if (gCurrentItemEntities[index] == entity) {
            break;
        }
    }

    if (index < MAX_ITEM_ENTITIES) {
        if (entity->physicsData != NULL) {
            heap_free(entity->physicsData);
        }

        switch (entity->spawnType) {
            case ITEM_SPAWN_MODE_NOTHING:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            case ITEM_SPAWN_AT_PLAYER:
                delete_shadow(entity->shadowIndex);
                break;
        }

        heap_free(gCurrentItemEntities[index]);
        isPickingUpItem = FALSE;
        gCurrentItemEntities[index] = NULL;
    }
}

void remove_item_entity_by_index(s32 index) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    switch (itemEntity->spawnType) {
        case ITEM_SPAWN_MODE_NOTHING:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
        case ITEM_SPAWN_AT_PLAYER:
            delete_shadow(itemEntity->shadowIndex);
            break;
    }

    heap_free(gCurrentItemEntities[index]);
    gCurrentItemEntities[index] = NULL;
    isPickingUpItem = FALSE;
}

void func_80133A94(s32 idx, s32 itemID) {
    ItemEntity* item = gCurrentItemEntities[idx];

    item->itemID = itemID;

    item->flags |= ITEM_ENTITY_FLAGS_TINY;
    item->flags &= ~ITEM_ENTITY_FLAGS_40000;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags |= ITEM_ENTITY_FLAGS_40000;
        item->flags &= ~ITEM_ENTITY_FLAGS_TINY;
    }

    item_entity_load(item);
}

// float/stack crap
#ifdef NON_EQUIVALENT
s32 test_item_player_collision(ItemEntity* item) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 actionState;
    f32 t;
    f32 itemX;
    f32 itemY;
    f32 itemZ;
    f32 playerX;
    f32 playerY;
    f32 playerZ;

    f32 sp10;
    f32 sp14;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 zDiff;
    f32 temp_f14;
    f32 xDiff;
    f32 angle;
    s32 cond;
    f32 f1;


    actionState = playerStatus->actionState;

    if (item->flags & ITEM_ENTITY_FLAGS_100) {
        item->flags &= ~ITEM_ENTITY_FLAGS_100;
        return TRUE;
    }

    if (gGameState != 2 && gGameState != 0) {
        return FALSE;
    }

    if (encounterStatus->hitType == 5) {
        return FALSE;
    }

    if (item->flags & ITEM_ENTITY_FLAGS_200000) {
        return FALSE;
    }

    if (isPickingUpItem) {
        return FALSE;
    }

    if (item->flags & ITEM_ENTITY_FLAGS_40) {
        return FALSE;
    }

    if (get_time_freeze_mode() != 0) {
        return FALSE;
    }

    if (partnerActionStatus->partnerActionState != 0 && partnerActionStatus->actingPartner == 9) {
        return FALSE;
    }

    if ((actionState == 0x1D || actionState == 0x1E || actionState == 0x1F) && item->itemID != ITEM_COIN) {
        return FALSE;
    }

    if (gOverrideFlags & 0x200000) {
        return FALSE;
    }

    cond = FALSE;
    sp1C = playerStatus->colliderHeight / 2;
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    sp20 = playerStatus->colliderDiameter / 4;
    if (playerStatus->spriteFacingAngle < 180.0f) {
        temp_f14 = clamp_angle(camera->currentYaw - 90.0f);
    } else {
        temp_f14 = clamp_angle(camera->currentYaw + 90.0f);
    }
    sp10 = playerX;
    sp24 = playerY;
    sp14 = playerZ;
    if (get_clamped_angle_diff(camera->currentYaw, temp_f14) < 0.0f) {
        angle = clamp_angle(camera->currentYaw - 90.0f);
        if (playerStatus->trueAnimation & 0x01000000) {
            angle = clamp_angle(angle + 30.0f);
        }
    } else {
        angle = clamp_angle(camera->currentYaw + 90.0f);
        if (playerStatus->trueAnimation & 0x01000000) {
            angle = clamp_angle(angle - 30.0f);
        }
    }
    add_vec2D_polar(&sp10, &sp14, 24.0f, angle);
    itemX = item->position.x;
    itemY = item->position.y;
    itemZ = item->position.z;
    t = 13.5f;
    xDiff = itemX - playerX;
    zDiff = itemZ - playerZ;
    f1 = sqrtf(SQ(xDiff) + SQ(zDiff));
    if (!(sp20 + t <= f1) &&
        !(itemY + 27.0f < playerY) &&
        !(playerY + sp1C < itemY))
    {
        cond = TRUE;
    }

    if (playerStatus->actionState == 0x12 && (playerStatus->flags & 0x01000000)) {
        xDiff = itemX - sp10;
        zDiff = itemZ - sp14;
        f1 = sqrtf(SQ(xDiff) + SQ(zDiff));
        if (!(14.0f + t <= f1) &&
            !(itemY + 27.0f < sp24) &&
            !(sp24 + 18.0f < itemY))
        {
            cond = TRUE;
        }
    }

    if (cond) {
        if (item->flags & ITEM_ENTITY_FLAGS_80) {
            if (D_801565A6 != 0) {
                D_801565A6--;
                return FALSE;
            } else {
                item->flags &= ~ITEM_ENTITY_FLAGS_80;
            }
        }
        return TRUE;
    }

    if (item->flags & ITEM_ENTITY_FLAGS_80) {
        item->flags &= ~ITEM_ENTITY_FLAGS_80;
    }
    return FALSE;
}
#else
INCLUDE_ASM(s32, "C50A0", test_item_player_collision);
#endif

s32 test_item_entity_position(f32 x, f32 y, f32 z, f32 dist) {
    ItemEntity* item;
    f32 dx, dy, dz;
    s32 i;

    if (is_starting_conversation() || isPickingUpItem || get_time_freeze_mode() != 0 ||
        gOverrideFlags & GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    {
        return -1;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++){
        item = gCurrentItemEntities[i];

        if (item == NULL) {
            continue;
        }

        if (item->flags == 0) {
            continue;
        }

        if (item->spawnType == ITEM_SPAWN_MODE_DECORATION) {
            continue;
        }

        if (item->spawnType == ITEM_SPAWN_MODE_INVISIBLE) {
            continue;
        }

        if (item->flags & ITEM_ENTITY_FLAGS_40) {
            continue;
        }

        if (item->flags & ITEM_ENTITY_FLAGS_200000) {
            continue;
        }

        dx = item->position.x - x;
        dz = item->position.y - y;
        dy = item->position.z - z;
        if (sqrtf(SQ(dx) + SQ(dz) + SQ(dy)) < dist) {
            return i;
        }
    }
    return -1;
}

void set_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    itemEntity->flags |= flags;
    if (itemEntity->flags & ITEM_ENTITY_FLAGS_200000) {
        D_801565A8 = 1;
    }
}

void clear_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    itemEntity->flags &= ~flags;
}

void func_801341B0(s32 index) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    itemEntity->flags |= ITEM_ENTITY_FLAGS_100;
}

/// @returns TRUE when "you got X" popup is on-screen
s32 is_picking_up_item(void) {
    s32 ret = D_801565A8 != 0;

    if (isPickingUpItem) {
        ret = TRUE;
    }
    return ret;
}

void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z) {
    ItemEntity* itemEntity = gCurrentItemEntities[itemEntityIndex];

    itemEntity->position.x = x;
    itemEntity->position.y = y;
    itemEntity->position.z = z;
}

void set_current_item_entity_render_group(s32 group) {
    ItemEntityRenderGroup = group;
}

s32 get_current_item_entity_render_group(void) {
    return ItemEntityRenderGroup;
}

void update_item_entity_collectable(ItemEntity* item) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    ItemEntityPhysicsData* physData;
    s32 camID;
    s32 hit;
    f32 outX, outY, outZ, outDepth;
    f32 theta, sinAngle, cosAngle;
    f32 temp;

    if (!isPickingUpItem) {
        if (item->pickupDelay != 0) {
            item->pickupDelay--;
            return;
        }

        if (item->spawnType == ITEM_SPAWN_MODE_TOSS_FADE1) {
            camID = CAM_BATTLE;
        } else {
            camID = CAM_DEFAULT;
        }

        switch (item->state) {
            case 0:
                item_entity_enable_shadow(item);
                physData = heap_malloc(sizeof(*physData));
                item->physicsData = physData;
                ASSERT(physData != NULL);

                if (item->flags & ITEM_ENTITY_FLAGS_1000000) {
                    physData->verticalVelocity = 16.0f;
                    physData->gravity = 2.0f;
                } else if (!(item->flags & ITEM_ENTITY_FLAGS_10000)) {
                    physData->verticalVelocity = 12.0f;
                    physData->gravity = 2.0f;
                } else {
                    physData->verticalVelocity = 14.0f;
                    physData->gravity = 2.0f;
                }

                physData->unk_08 = 24.0f;
                physData->constVelocity = 24.0f;
                if (item->wsFaceAngle < 0) {
                    if (IS_ID_ITEM(item->itemID)) {
                        if (rand_int(10000) < 5000) {
                            physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 105.0f + rand_int(30) - 15.0f);
                        } else {
                            physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 105.0f + rand_int(30) - 15.0f);
                        }
                        physData->verticalVelocity += 4.0f;
                    } else {
                        switch (item->itemID) {
                            case ITEM_HEART:
                                physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(120) - 60.0f);
                                break;
                            case ITEM_FLOWER_POINT:
                                physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(120) + 60.0f);
                                break;
                            case ITEM_COIN:
                                if (rand_int(10000) < 5000) {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(120) - 60.0f);
                                } else {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(120) - 60.0f);
                                }
                                break;
                            case ITEM_KOOPA_FORTRESS_KEY:
                                if (rand_int(10000) >= 5000) {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(120) - 60.0f);
                                } else {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(120) - 60.0f);
                                }
                                break;
                            case ITEM_STAR_POINT:
                                if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(120) - 60.0f);
                                    break;
                                }
                                if (rand_int(10000) < 5000) {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(60) - 30.0f);
                                } else {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(60) - 30.0f);
                                }
                                break;
                            case ITEM_HEART_POINT:
                                physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(120) - 60.0f);
                                break;
                            case ITEM_STAR_PIECE:
                                if (rand_int(10000) < 5000) {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(60) - 30.0f);
                                } else {
                                    physData->moveAngle = clamp_angle(gCameras[camID].currentYaw - 90.0f + rand_int(60) - 30.0f);
                                }
                                break;
                            case ITEM_HEART_PIECE:
                                physData->moveAngle = clamp_angle(gCameras[camID].currentYaw + 90.0f + rand_int(120) - 60.0f);
                                break;
                            default:
                                physData->moveAngle = 0.0f;
                                break;
                        }
                    }

                    if (!(item->flags & ITEM_ENTITY_FLAGS_1000000)) {
                        temp = rand_int(2000);
                        temp = (temp / 1000.0f) + 1.5;
                        theta = (physData->moveAngle * TAU) / 360.0f;
                        sinAngle = sin_rad(theta);
                        cosAngle = cos_rad(theta);
                        physData->velx = temp * sinAngle;
                        physData->velz = -temp * cosAngle;
                    } else {
                        temp = rand_int(2000);
                        temp = (temp / 1000.0f) + 2.0;
                        theta = (physData->moveAngle * TAU) / 360.0f;
                        sinAngle = sin_rad(theta);
                        cosAngle = cos_rad(theta);
                        physData->velx = temp * sinAngle;
                        physData->velz = -temp * cosAngle;
                    }
                } else {
                    physData->moveAngle = clamp_angle(item->wsFaceAngle);
                    if (!(item->flags & ITEM_ENTITY_FLAGS_40000000)) {
                        temp = ((item->wsFaceAngle / 360) * 0.6) + 1.5;
                    } else {
                        temp = 2.1f;
                    }
                    theta = physData->moveAngle * TAU / 360.0f;
                    sinAngle = sin_rad(theta);
                    cosAngle = cos_rad(theta);
                    physData->velx = temp * sinAngle;
                    physData->velz = -temp * cosAngle;
                }

                if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                    physData->unk_1C = 180;
                    physData->unk_20 = 0;
                } else {
                    if (!(item->flags & ITEM_ENTITY_FLAGS_400000)) {
                        physData->unk_1C = 0x11;
                    } else {
                        physData->unk_1C = 0x14;
                    }
                    physData->unk_20 = 0;
                    physData->verticalVelocity = 15.0f;
                    physData->gravity = 1.6f;
                }

                if (item->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
                    physData->unk_1C = 60;
                    physData->unk_20 = 0;
                    physData->velx = 0.0f;
                    physData->velz = 0.0f;
                }

                if (item->spawnType == ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS) {
                    physData->verticalVelocity = 0.0f;
                    physData->velx = 0.0f;
                    physData->velz = 0.0f;
                    physData->unk_20 = 1;
                }

                if (item->spawnType == ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS) {
                    physData->verticalVelocity = 0.0f;
                    physData->velx = 0.0f;
                    physData->velz = 0.0f;
                    physData->unk_20 = 1;
                }

                if (item->flags & ITEM_ENTITY_FLAGS_800) {
                    set_global_flag(item->boundVar);
                }
                item->state = 1;
                break;
            case 1:
                physData = item->physicsData;
                if (item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS &&
                    item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1 &&
                    physData->unk_20 != 0 &&
                    test_item_player_collision(item))
                {
                    item->state = 3;
                    break;
                }

                if (!(item->flags & ITEM_ENTITY_FLAGS_NEVER_VANISH)) {
                    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES))) {
                        if (!(item->flags & ITEM_ENTITY_FLAGS_200000)) {
                            physData->unk_1C--;
                            if (physData->unk_1C < 0) {
                                item->state = 2;
                                break;
                            }
                        }
                    }
                }

                if (!(item->flags & ITEM_ENTITY_FLAGS_FIXED)) {
                    if (!(item->flags & ITEM_ENTITY_FLAGS_200000)) {
                        physData->verticalVelocity -= physData->gravity;
                        if (physData->verticalVelocity < -16.0) {
                            physData->verticalVelocity = -16.0f;
                        }
                        item->position.y += physData->verticalVelocity;
                        item->position.x += physData->velx;
                        item->position.z += physData->velz;
                    }
                }

                if (item->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS &&
                    physData->verticalVelocity <= 0.0f)
                {
                    item->state = 3;
                    break;
                }

                if (!(item->flags & (ITEM_ENTITY_FLAGS_20000000 | ITEM_ENTITY_FLAGS_10000000)) &&
                    item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS &&
                    item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1 &&
                    physData->verticalVelocity > 0.0f)
                {
                    temp = physData->constVelocity;
                    outX = item->position.x;
                    outY = item->position.y;
                    outZ = item->position.z;
                    outDepth = temp + physData->verticalVelocity;

                    if (physData->unk_20 == 0) {
                        hit = npc_raycast_up(0x20000, &outX, &outY, &outZ, &outDepth);
                    } else {
                        hit = npc_raycast_up(0x20000, &outX, &outY, &outZ, &outDepth);
                    }

                    if (hit && outDepth < temp) {
                        item->position.y = outY - temp;
                        physData->verticalVelocity = 0.0f;
                    }
                }

                if (!(item->flags & (ITEM_ENTITY_FLAGS_20000000 | ITEM_ENTITY_FLAGS_10000000)) &&
                    item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS &&
                    item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1 &&
                    (physData->velx != 0.0f || physData->velz != 0.0f))
                {
                    outX = item->position.x;
                    outY = item->position.y;
                    outZ = item->position.z;

                    if (physData->unk_20 == 0) {
                        hit = npc_test_move_complex_with_slipping(0x20000, &outX, &outY, &outZ, 0.0f, physData->moveAngle, physData->constVelocity, physData->unk_08);
                    } else {
                        hit = npc_test_move_simple_with_slipping(0x20000, &outX, &outY, &outZ, 0.0f, physData->moveAngle, physData->constVelocity, physData->unk_08);
                    }

                    if (hit) {
                        item->position.x = outX;
                        item->position.y = outY;
                        item->position.z = outZ;
                        physData->moveAngle = clamp_angle(physData->moveAngle + 180.0f);
                        theta = physData->moveAngle * TAU / 360.0f;
                        sinAngle = sin_rad(theta);
                        cosAngle = cos_rad(theta);
                        physData->velx = sinAngle * 2.0;
                        physData->velz = cosAngle * -2.0;
                    }
                }

                if (!(item->flags & ITEM_ENTITY_FLAGS_10000000) &&
                    item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS &&
                    physData->verticalVelocity <= 0.0)
                {
                    physData->unk_20 = 1;
                    if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                        outX = item->position.x;
                        outY = (item->position.y - physData->verticalVelocity) + 12.0f;
                        outZ = item->position.z;
                        outDepth = -physData->verticalVelocity + 12.0f;
                        if (physData->unk_20 == 0) {
                            hit = npc_raycast_down_sides(0x20000, &outX, &outY, &outZ, &outDepth);
                        } else {
                            hit = npc_raycast_down_around(0x20000, &outX, &outY, &outZ, &outDepth, 180.0f, 20.0f);
                        }
                    } else {
                        outX = item->position.x;
                        outY = (item->position.y - physData->verticalVelocity) + 12.0f;
                        outZ = item->position.z;
                        outDepth = -physData->verticalVelocity + 12.0f;
                        if (outY < outDepth + 0.0f) {
                            outY = 0.0f;
                            hit = TRUE;
                        } else {
                            hit = FALSE;
                        }
                    }

                    if (hit) {
                        item->position.y = outY;
                        physData->verticalVelocity = (-physData->verticalVelocity / 1.25);
                        if (physData->verticalVelocity < 3.0) {
                            physData->verticalVelocity = 0.0f;
                            physData->velx = 0.0f;
                            physData->velz = 0.0f;
                            item->flags |= ITEM_ENTITY_FLAGS_20000000;
                        } else {
                            if (IS_ID_BADGE(item->itemID)) {
                                sfx_play_sound_at_position(SOUND_21B, 0, item->position.x, item->position.y, item->position.z);
                            } else if (IS_ID_ITEM(item->itemID)) {
                                sfx_play_sound_at_position(SOUND_21A, 0, item->position.x, item->position.y, item->position.z);
                            } else {
                                switch (item->itemID) {
                                    case ITEM_HEART:
                                        sfx_play_sound_at_position(SOUND_214, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_COIN:
                                        sfx_play_sound_at_position(SOUND_212, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_KOOPA_FORTRESS_KEY:
                                        sfx_play_sound_at_position(SOUND_212, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_HEART_PIECE:
                                        sfx_play_sound_at_position(SOUND_214, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_STAR_POINT:
                                        sfx_play_sound_at_position(SOUND_212, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_HEART_POINT:
                                        sfx_play_sound_at_position(SOUND_214, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_STAR_PIECE:
                                        sfx_play_sound_at_position(SOUND_219, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                    case ITEM_FLOWER_POINT:
                                        sfx_play_sound_at_position(SOUND_218, 0, item->position.x, item->position.y, item->position.z);
                                        break;
                                }
                            }
                        }
                    }
                }

                if (item->position.y < -2000.0f) {
                    item->state = 2;
                }
                break;
        }

        if (item->state == 2) {
            remove_item_entity_by_reference(item);
        }

        if (item->state == 3) {
            if (item->flags & ITEM_ENTITY_FLAGS_400) {
                set_global_flag(item->boundVar);
            }

            fx_small_gold_sparkle(0, item->position.x, item->position.y + 16.0f, item->position.z, 1.0f, 0);

            if (IS_ID_ITEM(item->itemID)) {
                item->state = 0xA;
            } else if (IS_ID_BADGE(item->itemID)) {
                item->state = 0xA;
            } else if (item->itemID == ITEM_STAR_PIECE) {
                playerData->starPiecesCollected++;
                item->state = 0xA;
            } else {
                if (item->spawnType == ITEM_SPAWN_MODE_TOSS_FADE1) {
                    item->itemID = -1;
                }

                switch (item->itemID) {
                    case ITEM_HEART:
                        if (playerData->curHP < playerData->curMaxHP) {
                            fx_recover(0, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z, 1);
                            sfx_play_sound_at_position(SOUND_2056, 0, item->position.x, item->position.y, item->position.z);
                        }
                        playerData->curHP++;
                        if (playerData->curHP > playerData->curMaxHP) {
                            playerData->curHP = playerData->curMaxHP;
                        }
                        sfx_play_sound_at_position(SOUND_213, 0, item->position.x, item->position.y, item->position.z);
                        fx_sparkles(4, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z, 30.0f);
                        break;
                    case ITEM_FLOWER_POINT:
                        if (playerData->curFP < playerData->curMaxFP) {
                            fx_recover(1, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z, 1);
                            sfx_play_sound_at_position(SOUND_2056, 0, item->position.x, item->position.y, item->position.z);
                        }
                        playerData->curFP++;
                        if (playerData->curFP > playerData->curMaxFP) {
                            playerData->curFP = playerData->curMaxFP;
                        }
                        sfx_play_sound_at_position(SOUND_217, 0, item->position.x, item->position.y, item->position.z);
                        fx_sparkles(4, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z, 30.0f);
                        break;
                    case ITEM_COIN:
                        playerData->coins++;
                        if (playerData->coins > 999) {
                            playerData->coins = 999;
                        }
                        sfx_play_sound_at_position(SOUND_211, 0, item->position.x, item->position.y, item->position.z);
                        playerData->totalCoinsEarned++;
                        if (playerData->totalCoinsEarned > 99999) {
                            playerData->totalCoinsEarned = 99999;
                        }
                        break;
                    case ITEM_KOOPA_FORTRESS_KEY:
                        playerData->fortressKeyCount = playerData->fortressKeyCount + 1;
                        sfx_play_sound_at_position(SOUND_211, 0, item->position.x, item->position.y, item->position.z);
                        break;
                    case ITEM_STAR_POINT:
                        playerData->starPoints++;
                        if (playerData->starPoints > 100) {
                            playerData->starPoints = 100;
                        }
                        sfx_play_sound_at_position(SOUND_211, 0, item->position.x, item->position.y, item->position.z);
                        break;
                    case ITEM_HEART_POINT:
                        playerData->curHP = playerData->curMaxHP;
                        playerData->curFP = playerData->curMaxFP;
                        sfx_play_sound_at_position(SOUND_213, 0, item->position.x, item->position.y, item->position.z);
                        break;
                }
                D_801565A8 = 0;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                remove_item_entity_by_reference(item);
            }
        }

        if (item->state == 4) {
            if (!does_script_exist(D_80155D80)) {
                D_801565A8 = 0;
                remove_item_entity_by_reference(item);
                resume_all_group(2);
            }
        }

        if (item->state == 0xA) {
            isPickingUpItem = TRUE;
            item->spawnType = ITEM_SPAWN_AT_PLAYER;
            item->state = 0;
            D_801565A8 = 0;
            gOverrideFlags |= GLOBAL_OVERRIDES_40;
        }
    }
}

void func_8013559C(ItemEntity* itemEntity) {
    if (itemEntity->state == 1) {
        ItemEntityPhysicsData* physicsData = itemEntity->physicsData;
        s32 flag = (itemEntity->flags & ITEM_ENTITY_FLAGS_20000) > 0;

        if (itemEntity->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
            if (itemEntity->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                if (physicsData->unk_1C < 60) {
                    if ((itemEntity->flags & ITEM_ENTITY_FLAGS_200000) || ((gGameStatusPtr->frameCounter + flag) & 1)) {
                        itemEntity->flags &= ~ITEM_ENTITY_FLAGS_40;
                    } else {
                        itemEntity->flags |= ITEM_ENTITY_FLAGS_40;
                    }
                }
            } else {
                if (physicsData->unk_1C < 10) {
                    itemEntity->alpha = physicsData->unk_1C * 28;
                    itemEntity->flags |= ITEM_ENTITY_FLAGS_TRANSPARENT;
                }
            }
        }
    }
}

void update_item_entity_static(ItemEntity* itemEntity) {
    if (itemEntity->state == 0 && test_item_player_collision(itemEntity)) {
        isPickingUpItem = TRUE;
        itemEntity->spawnType = ITEM_SPAWN_AT_PLAYER;
        itemEntity->state = 0;
        D_801565A8 = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }
}

void func_801356C4(ItemEntity* itemEntity) {
}

void func_801356CC(ItemEntity* itemEntity) {
}

void func_801356D4(ItemEntity* itemEntity) {
}

INCLUDE_ASM(s32, "C50A0", update_item_entity_temp);

/*void update_item_entity_temp(ItemEntity* itemEntity) {
    PlayerData* playerData = &gPlayerData;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PopupMenu* menu = &D_801565B0;
    s32 i;

    ItemData* temp_a1;
    ItemData* temp_a1_2;
    PlayerData* var_a2;
    PlayerData* var_v1;
    PlayerData* var_v1_2;
    PlayerData* var_v1_3;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s16 temp_a0_4;
    s16 temp_v0_6;
    s16 temp_v0_8;
    s16 temp_v1_6;
    s16 temp_v1_7;
    s32 (**temp_v0_9)[0];
    s32 (**var_v1_4)[0];
    s32 temp_v0_2;
    s32 temp_v0_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s8 temp_v0;
    s8 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u8 temp_v0_3;

    if (itemEntity->state == 0) {
        isPickingUpItem = 1;
        if (!(itemEntity->flags & 0x02000000)) {
            disable_player_input();
            partner_disable_input();
            gOverrideFlags |= 0x40;
            set_time_freeze_mode(2);
        }
        item_entity_disable_shadow(itemEntity);
        itemEntity->state = (s8) 1;
    }
    temp_v0 = (u8) itemEntity->state - 1;
    switch (temp_v0) {
        case 0:
            if ((itemEntity->flags & 0x02000000) || (temp_v1 = playerStatus->actionState, ((playerStatus->animFlags & 0x10000000) != 0)) || (((playerStatus->timeInAir != 0) || (temp_v1 == 3) || (temp_v1 == 8)) && (playerStatus->enableCollisionOverlapsCheck != 0) && (playerStatus->inputEnabledCounter != 0)) || (temp_v1 == 6) || (temp_v1 == 0x21) || (temp_v1 == 0) || ((temp_v1 == 0x1D) && (playerStatus->fallState == 1))) {
                if (!((u16) itemEntity->pickupMsgFlags & 1)) {
                    temp_a0 = itemEntity->itemID;
                    temp_v1_2 = *(&gItemTable->typeFlags + (temp_a0 << 5));
                    if (temp_v1_2 & 0x40) {
                        var_a0 = 0xD3;
                        goto block_25;
                    }
                    if (temp_v1_2 & 8) {
                        var_a0 = 0xD2;
                        goto block_25;
                    }
                    var_a0 = 0xD1;
                    if (temp_a0 == 0x157) {
                        sfx_play_sound_at_position(0x211, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
                    } else {
block_25:
                        sfx_play_sound(var_a0);
                    }
                }
                temp_v0_2 = hud_element_create(gItemHudScripts[*(&gItemTable->hudElemID + (itemEntity->itemID << 5))].enabled);
                D_801568E0 = temp_v0_2;
                hud_element_set_flags(temp_v0_2, 0x80);
                hud_element_set_render_pos(D_801568E0, -0x64, -0x64);
                itemEntity->state = 2;
                if (!(itemEntity->flags & 0x02000000)) {
                    var_a0_2 = 0;
                    if ((u16) gItemTable[itemEntity->itemID].typeFlags & 4) {
                        var_v1 = &gPlayerData;
loop_29:
                        var_v0 = var_a0_2 < 0xA;
                        if (var_v1->invItems[0] != 0) {
                            var_a0_2 += 1;
                            var_v1 += 2;
                            if (var_a0_2 >= 0xA) {
                                var_v0 = var_a0_2 < 0xA;
                            } else {
                                goto loop_29;
                            }
                        }
                        if (var_v0 != 0) {
                            playerData->invItems[var_a0_2] = (s16) (u16) itemEntity->itemID;
                            goto block_34;
                        }
                        goto block_47;
                    }
block_34:
                    var_a0_3 = 0;
                    if (*(&gItemTable->typeFlags + (itemEntity->itemID << 5)) & 8) {
                        var_v1_2 = &gPlayerData;
loop_36:
                        var_v0_2 = var_a0_3 < 0x20;
                        if (var_v1_2->keyItems[0] != 0) {
                            var_a0_3 += 1;
                            var_v1_2 += 2;
                            if (var_a0_3 >= 0x20) {
                                var_v0_2 = var_a0_3 < 0x20;
                            } else {
                                goto loop_36;
                            }
                        }
                        if (var_v0_2 != 0) {
                            playerData->keyItems[var_a0_3] = (s16) (u16) itemEntity->itemID;
                            goto block_41;
                        }
                        goto block_47;
                    }
block_41:
                    var_a0_4 = 0;
                    if (*(&gItemTable->typeFlags + (itemEntity->itemID << 5)) & 0x40) {
                        var_v1_3 = &gPlayerData;
loop_43:
                        var_v0_3 = var_a0_4 < 0x80;
                        if (var_v1_3->badges[0] != 0) {
                            var_a0_4 += 1;
                            var_v1_3 += 2;
                            if (var_a0_4 >= 0x80) {
                                var_v0_3 = var_a0_4 < 0x80;
                            } else {
                                goto loop_43;
                            }
                        }
                        if (var_v0_3 == 0) {
block_47:
                            itemEntity->state = 0xA;
                        } else {
                            playerData->badges[var_a0_4] = (s16) (u16) itemEntity->itemID;
                            goto block_49;
                        }
                    } else {
block_49:
                        if (itemEntity->itemID == 0x15C) {
                            temp_v0_3 = playerData->starPieces + 1;
                            playerData->starPieces = temp_v0_3;
                            if ((u32) (temp_v0_3 & 0xFF) >= 0xDFU) {
                                playerData->starPieces = 0xDE;
                            }
                        }
                        if (itemEntity->itemID == 7) {
                            playerData->hasActionCommands = 1;
                        }
                        if ((u32) ((u16) itemEntity->itemID - 4) < 3U) {
                            playerData->hammerLevel = itemEntity->itemID - 4;
                        }
                        if ((u32) ((u16) itemEntity->itemID - 1) < 3U) {
                            playerData->bootsLevel = itemEntity->itemID - 1;
                        }
                    }
                }
                if (itemEntity->flags < 0) {
                    set_global_flag(itemEntity->boundVar);
                }
                if (itemEntity->state == (s8) 0xA) {
                    func_801363A0(itemEntity);
                    set_window_update(0xC, basic_window_update);
                    set_window_update(0x11, basic_window_update);
                    set_window_update(0x13, basic_window_update);
                }
                increment_status_menu_disabled();
                D_801568E4 = 0xA;
                return;
            }
        case 1:
            if (D_801568E4 == 9) {
                temp_a0_2 = itemEntity->itemID;
                temp_v1_3 = *(&gItemTable->typeFlags + (temp_a0_2 << 5));
                if ((temp_v1_3 & 0x40) || (temp_v1_3 & 8) || (temp_a0_2 == 0x15C) || (temp_v1_3 & 0x20) || (itemEntity->flags & 0x04000000) || ((u16) itemEntity->pickupMsgFlags & 2)) {
                    itemEntity->position.x = playerStatus->position.x;
                    itemEntity->position.y = playerStatus->position.y + (f32) playerStatus->colliderHeight;
                    itemEntity->position.z = playerStatus->position.z;
                    suggest_player_anim_setUnkFlag(0x6000C);
                }
                if (*(&gItemTable->typeFlags + (itemEntity->itemID << 5)) & 0x20) {
                    fx_got_item_outline(1, itemEntity->position.x, itemEntity->position.y + 8.0f, itemEntity->position.z, 1.0f, &D_801568F0);
                }
            }
            if ((D_801568E4 < 9) && ((temp_a0_3 = itemEntity->itemID, temp_v1_4 = *(&gItemTable->typeFlags + (temp_a0_3 << 5)), ((temp_v1_4 & 0x40) != 0)) || (temp_v1_4 & 8) || (temp_a0_3 == 0x15C) || (temp_v1_4 & 0x20) || (itemEntity->flags & 0x04000000) || ((u16) itemEntity->pickupMsgFlags & 2))) {
                suggest_player_anim_setUnkFlag(0x6000C);
            }
            if (D_801568E4 == 7) {
                temp_a0_4 = itemEntity->itemID;
                temp_v1_5 = *(&gItemTable->typeFlags + (temp_a0_4 << 5));
                if ((temp_v1_5 & 0x40) || (temp_v1_5 & 8) || (temp_a0_4 == 0x15C) || (temp_v1_5 & 0x20) || (itemEntity->flags & 0x04000000) || ((u16) itemEntity->pickupMsgFlags & 2)) {
                    itemEntity->flags &= ~0x40;
                }
            }
            if (D_801568E4 == 6) {
                func_801363A0(itemEntity);
                set_window_update(0xC, basic_window_update);
                temp_v1_6 = itemEntity->itemID;
                if ((temp_v1_6 != 0x15C) && (temp_v1_6 != 0x157)) {
                    set_window_update(0x13, basic_window_update);
                }
            }
            if (D_801568E4 != 0) {
                D_801568E4--;
                return;
            }
            if (gGameStatusPtr->pressedButtons[0] & 0xFC000) {
                item_entity_disable_shadow(itemEntity);
                if ((func_800DFCF4() != 0) && (playerStatus->actionState != 0x1D) && !(playerStatus->animFlags & 0x10000000)) {
                    set_action_state(0);
                }
                if (*(&gItemTable->typeFlags + (itemEntity->itemID << 5)) & 0x20) {
                    D_801568F0->data.gotItemOutline->unk_14 = 0xA;
                }
                set_window_update(0xC, basic_hidden_window_update);
                set_window_update(0x13, basic_hidden_window_update);
                itemEntity->state = 3;
            }
            break;
        case 2:
            if (!(gWindows[12].flags & 8) && !(gWindows[19].flags & 8)) {
                itemEntity->state = 4;
            }
            break;
        case 3:
            if ((*(&gItemTable->typeFlags + (itemEntity->itemID << 5)) & 4) && (evt_get_variable(NULL, -0x07BFA41F) == 0)) {
                evt_set_variable(NULL, -0x07BFA41F, 1);
                itemEntity->state = 5;
                break;
            }
            if ((itemEntity->itemID == 0x15C) && (evt_get_variable(NULL, -0x07BFA41B) == 0)) {
                evt_set_variable(NULL, -0x07BFA41B, 1);
                itemEntity->state = 5;
                break;
            }
            itemEntity->state = 9;
            break;
        case 4:
            temp_v1_7 = itemEntity->itemID;
            var_a0_5 = 0;
            if (*(&gItemTable->typeFlags + (temp_v1_7 << 5)) & 4) {
                var_a0_5 = 0x1D0002;
            }
            if (temp_v1_7 == 0x15C) {
                var_a0_5 = 0x1D0003;
            }
            D_801568F4 = msg_get_printer_for_msg(var_a0_5, &D_801568F8);
            msg_printer_set_origin_pos(D_801568F4, 0, 0);
            itemEntity->state = 6;
            break;
        case 5:
            if (D_801568F8 == 1) {
                isPickingUpItem = FALSE;
            } else {
                break;
            }
        case 8:
            if (!(itemEntity->flags & 0x02000000)) {
                set_time_freeze_mode(0);
                enable_player_input();
                partner_enable_input();
                gOverrideFlags &= ~0x40;
            }
            hud_element_free(D_801568E0);
            remove_item_entity_by_reference(itemEntity);
            sort_items();
            decrement_status_menu_disabled();
            isPickingUpItem = FALSE;
            break;
        case 9:
            var_a3 = 1;
            if (gGameStatusPtr->pressedButtons[0] & 0x8000) {
                i = 0;
                temp_a1 = &gItemTable[itemEntity->itemID];
                menu->ptrIcon[0] = gItemHudScripts[temp_a1->hudElemID].enabled;
                menu->enabled[0] = 1;
                menu->userIndex[0] = itemEntity->itemID;
                var_a2 = &gPlayerData;
                menu->nameMsg[0] = temp_a1->nameMsg;
                var_v1_4 = &menu->ptrIcon[1];
                menu->descMsg[0] = temp_a1->shortDescMsg;
                do {
                    temp_v0_6 = var_a2->invItems[0];
                    i += 1;
                    if (temp_v0_6 != 0) {
                        temp_a1_2 = &gItemTable[temp_v0_6];
                        // var_v1_4->unk0 = gItemHudScripts[temp_a1_2->hudElemID].enabled;
                        // var_v1_4->unk18C = 1;
                        // var_v1_4->unk108 = var_a2->invItems[0];
                        // var_v1_4->unk84 = temp_a1_2->nameMsg;
                        // var_a3 += 1;
                        // var_v1_4->unk294 = temp_a1_2->shortDescMsg;
                        // var_v1_4 += 4;
                    }
                    var_a2 += 2;
                } while (i < 0xA);
                menu->popupType = 2;
                menu->numEntries = var_a3;
                menu->initialPos = 0;
                create_popup_menu(&menu);
                set_window_update(0xC, basic_hidden_window_update);
                set_window_update(0x11, basic_hidden_window_update);
                D_801568E4 = 0;
                itemEntity->state = 0xB;
            }
            break;
        case 10:
            if (!(gWindows[12].flags & 8) && !(gWindows[17].flags & 8) && !(gWindows[19].flags & 8)) {
                itemEntity->state = 0xC;
            }
            break;
        case 11:
            temp_v0_7 = D_801568E4;
            var_v0_4 = temp_v0_7 + 1;
            if (temp_v0_7 == 0) {
                temp_v0_8 = menu->result;
                D_801568E8 = temp_v0_8;
                if (temp_v0_8 != 0) {
                    hide_popup_menu();
                    var_v0_4 = D_801568E4 + 1;
                    goto block_139;
                }
            } else {
block_139:
                D_801568E4 = var_v0_4;
                if (var_v0_4 >= 0xF) {
                    destroy_popup_menu();
                    if (D_801568E8 == 0xFF) {
                        D_801568E8 = 1;
                    }
                    // temp_v0_9 = &menu->.ptrIcon[D_801568E8 - 1];
                    // D_801568EC = temp_v0_9->unk108;
                    // hud_element_set_script(D_801568E0, temp_v0_9->unk0);
                    get_item_entity(make_item_entity_delayed(D_801568EC, playerStatus->position.x, playerStatus->position.y + (f32) playerStatus->colliderHeight, playerStatus->position.z, 3, 0, 0))->renderGroup = -1;
                    temp_v1_8 = D_801568E8;
                    if (temp_v1_8 >= 2) {
                        playerData->invItems[temp_v1_8 - 2] = 0;
                        sort_items();
                        add_item(itemEntity->itemID);
                    }
                    suggest_player_anim_setUnkFlag(0x6000C);
                    func_801363A0(itemEntity);
                    set_window_update(0xC, basic_window_update);
                    D_801568E4 = 0x32;
                    itemEntity->state = 0xD;
                }
            }
            break;
        case 12:
            if (gGameStatusPtr->pressedButtons[0] & 0x8000) {
                set_window_update(0xC, basic_hidden_window_update);
                itemEntity->state = 0xE;
            }
            break;
        case 13:
            if (!(gWindows[12].flags & 8) && !(gWindows[17].flags & 8) && !(gWindows[19].flags & 8)) {
                itemEntity->state = 0xF;
            }
            break;
        case 14:
            suggest_player_anim_setUnkFlag(0x10002);
            set_time_freeze_mode(0);
            enable_player_input();
            partner_enable_input();
            gOverrideFlags &= ~0x40;
            hud_element_free(D_801568E0);
            remove_item_entity_by_reference(itemEntity);
            sort_items();
            decrement_status_menu_disabled();
            isPickingUpItem = FALSE;
            break;
    }
}
*/

#ifdef NON_EQUIVALENT
void func_801363A0(ItemEntity* itemEntity) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 itemMsg;
    s32 offsetY;
    s32 s1;
    s32 temp;
    s32 s3;
    s32 temp2;
    s32 v1;

    switch (itemEntity->state) {
        case 2:
        case 10:
            if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BADGE)) {
                if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_4000000) || (itemEntity->pickupMsgFlags & 0x4)) {
                    itemMsg = MESSAGE_ID(0x1D, 0x058);
                } else {
                    itemMsg = MESSAGE_ID(0x1D, 0x05A);
                }

                if (itemEntity->pickupMsgFlags & 0x10) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05D);
                }
                if (itemEntity->pickupMsgFlags & 0x20) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05E);
                }
                if (itemEntity->pickupMsgFlags & 0x40) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05C);
                }

                set_message_msg(itemData->nameMsg, 0);

                if (!(gItemTable[itemEntity->itemID].typeFlags & ITEM_TYPE_FLAG_KEY) &&
                    itemEntity->itemID != ITEM_STAR_PIECE &&
                    !(gItemTable[itemEntity->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR) &&
                    !(itemEntity->pickupMsgFlags & 0x30)) {
                    offsetY = get_msg_width(itemMsg, 0) + 54;
                } else {
                    offsetY = get_msg_width(itemMsg, 0) + 30;
                }
                s1 = 160 - offsetY / 2;
                s3 = 0x4C;
            } else {
                if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_4000000) || (itemEntity->pickupMsgFlags & 0x4)) {
                    itemMsg = MESSAGE_ID(0x1D, 0x059);
                } else {
                    itemMsg = MESSAGE_ID(0x1D, 0x05B);
                }

                if (itemEntity->pickupMsgFlags & 0x10) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05D);
                }
                if (itemEntity->pickupMsgFlags & 0x20) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05E);
                }
                if (itemEntity->pickupMsgFlags & 0x40) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05C);
                }

                set_message_msg(itemData->nameMsg, 0);
                offsetY = get_msg_width(itemMsg, 0) + 30;
                s1 = 160 - offsetY / 2;
                s3 = 0x4C;
            }
            temp2 = D_8014C6E0[get_msg_lines(itemMsg) - 1];
            if (itemEntity->state != 2) {
                temp = 0x1C;
            } else {
                temp = 0;
            }
            if (gItemTable[itemEntity->itemID].typeFlags) {
                set_window_properties(WINDOW_ID_12, s1, s3 - 0x18 + temp, offsetY,
                                    temp2, 0, func_8013673C, itemEntity, -1);
            } else {
                set_window_properties(WINDOW_ID_12, s1, s3 - 0x18 + temp, offsetY,
                                    temp2, 0, func_8013673C, itemEntity, -1);
            }
            if (itemEntity->itemID != ITEM_STAR_PIECE && itemEntity->itemID != ITEM_COIN) {
                set_window_properties(WINDOW_ID_19, 0x14, 0xBA, 0x118, 0x20, NULL, func_80136A08, itemEntity, -1);
            }
            if (itemEntity->state != 2) {
                offsetY = get_msg_width(MESSAGE_ID(0x1D, 0x060), 0) + 0x18;
                set_window_properties(WINDOW_ID_17, 160 - offsetY / 2, 0x24, offsetY, 40, NULL, func_801369D0, itemEntity, -1);
            }
            break;
        case 12:
            set_message_msg(itemData->nameMsg, 0);
            offsetY = get_msg_width(MESSAGE_ID(0x1D, 0x05F), 0) + 0x36;
            set_window_properties(WINDOW_ID_12, 160 - offsetY / 2, 0x4C, offsetY, 40, NULL, func_8013673C, itemEntity, -1);
            break;
    }
}
#else
INCLUDE_ASM(s32, "C50A0", func_801363A0);
#endif

void func_8013673C(ItemEntity* itemEntity, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 itemMsg;
    s32 offsetY;

    switch (itemEntity->state) {
        case 2:
        case 3:
        case 10:
        case 11:
            if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BADGE)) {
                if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_4000000) || (itemEntity->pickupMsgFlags & 0x4)) {
                    itemMsg = MESSAGE_ID(0x1D, 0x058);
                } else {
                    itemMsg = MESSAGE_ID(0x1D, 0x05A);
                }
                set_message_msg(itemData->nameMsg, 0);

                if (itemEntity->pickupMsgFlags & 0x10) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05D);
                }
                if (itemEntity->pickupMsgFlags & 0x20) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05E);
                }
                if (itemEntity->pickupMsgFlags & 0x40) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05C);
                }
            } else {
                if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_4000000) || (itemEntity->pickupMsgFlags & 0x4)) {
                    itemMsg = MESSAGE_ID(0x1D, 0x059);
                } else {
                    itemMsg = MESSAGE_ID(0x1D, 0x05B);
                }

                if (itemEntity->pickupMsgFlags & 0x10) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05D);
                }
                if (itemEntity->pickupMsgFlags & 0x20) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05E);
                }
                if (itemEntity->pickupMsgFlags & 0x40) {
                    itemMsg = MESSAGE_ID(0x1D, 0x05C);
                }

                set_message_msg(itemData->nameMsg, 0);
            }

            offsetY = D_8014C6E4[get_msg_lines(itemMsg) - 1];

            if ((gItemTable[itemEntity->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE) ||
                (gItemTable[itemEntity->itemID].typeFlags & ITEM_TYPE_FLAG_KEY) ||
                itemEntity->itemID == ITEM_STAR_PIECE ||
                (gItemTable[itemEntity->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR) ||
                (itemEntity->pickupMsgFlags & 0x30)) {

                draw_msg(itemMsg, posX + 15, posY + offsetY, 255, 47, 0);
            } else {
                draw_msg(itemMsg, posX + 40, posY + offsetY, 255, 47, 0);
                if (!(itemEntity->pickupMsgFlags & 0x30)) {
                    hud_element_set_render_pos(D_801568E0, posX + 20, posY + 20);
                    hud_element_draw_next(D_801568E0);
                }
            }
            break;
        case 13:
        case 14:
            set_message_msg(gItemTable[D_801568EC].nameMsg, 0);
            draw_msg(MESSAGE_ID(0x1D, 0x05F), posX + 40, posY + 4, 255, 47, 0);
            hud_element_set_render_pos(D_801568E0, posX + 20, posY + 20);
            hud_element_draw_next(D_801568E0);
            break;
    }
}

void func_801369D0(ItemEntity* itemEntity, s32 x, s32 y) {
    draw_msg(MESSAGE_ID(0x1D,0x060), x + 12, y + 4, 255, 52, 0);
}

void func_80136A08(ItemEntity* itemEntity, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 itemMsg;

    switch (itemEntity->state) {
        case 2:
        case 3:
        case 10:
        case 11:
            itemMsg = itemData->shortDescMsg;
            draw_msg(itemMsg, posX + 8, posY, 255, 10, 0);
            break;
    }
}

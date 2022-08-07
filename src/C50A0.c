#include "common.h"
#include "effects.h"
#include "hud_element.h"
#include "pause/pause_common.h"
#include "world/partners.h"
#include "sparkle_script.h"

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
void update_item_entity_temp(ItemEntity*);
s32 draw_image_with_clipping(s32* raster, s32 width, s32 height, s32 fmt, s32 bitDepth, s16 posX, s16 posY, u16 clipULx,
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

s32 draw_ci_image_with_clipping(s32* raster, s32 width, s32 height, s32 fmt, s32 bitDepth, s32* palette, s16 posX,
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
            itemEntity->sparkleRaster = (s8*)*readPos++;
            itemEntity->sparklePalette = (s8*)*readPos++;
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

//TODO remove this
static const f32 rodata_padding_2 = 0.0f;

INCLUDE_ASM(s32, "C50A0", item_entity_update);

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

    if (item->flags & 0x100) {
        item->flags &= ~0x100;
        return TRUE;
    }

    if (gGameState != 2 && gGameState != 0) {
        return FALSE;
    }

    if (encounterStatus->hitType == 5) {
        return FALSE;
    }

    if (item->flags & 0x200000) {
        return FALSE;
    }

    if (isPickingUpItem) {
        return FALSE;
    }

    if (item->flags & 0x40) {
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
        if (item->flags & 0x80) {
            if (D_801565A6 != 0) {
                D_801565A6--;
                return FALSE;
            } else {
                item->flags &= ~0x80;
            }
        }
        return TRUE;
    }

    if (item->flags & 0x80) {
        item->flags &= ~0x80;
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

        if (!item->flags) {
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

INCLUDE_ASM(s32, "C50A0", update_item_entity_collectable);

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

// TODO remove this
static const f32 rodata_padding[] = { 0.0f, 0.0f };

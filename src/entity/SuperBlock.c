#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "entity.h"

extern EntityBlueprint Entity_SuperBlockContent;

extern Gfx Entity_SuperBlock_Render[];
extern Gfx Entity_UltraBlock_Render[];
extern Gfx Entity_SuperBlockContent_Render[];
extern Gfx Entity_SuperBlockContent_Render2[];
extern Gfx Entity_UltraBlockContent_Render[];
extern Gfx Entity_UltraBlockContent_Render2[];
extern unsigned char D_0A000200_E4A8A0[];
extern unsigned char D_0A000220_E4A8C0[];
extern unsigned char D_0A000240_E4A8E0[];
extern unsigned char D_0A000260_E4A900[];

f32 entity_SuperBlockContent_get_previous_yaw(SuperBlockContentData* data, s32 lagTime) {
    s32 bufIdx = data->yawBufferPos - lagTime;

    if (bufIdx < 0) {
        bufIdx += ARRAY_COUNT(data->yawBuffer);
    }
    return data->yawBuffer[bufIdx];
}

void entity_upgrade_block_hide_content(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    BlockData* data = entity->dataBuf.block;

    if (data->childEntityIndex >= 0) {
        Entity* childEntity = get_entity_by_index(data->childEntityIndex);
        SuperBlockContentData* childEntityData = childEntity->dataBuf.superBlockContent;
        childEntityData->isHidden = TRUE;
    }
}

s32 entity_upgrade_block_idle(Entity* entity) {
    return entity_base_block_idle(entity);
}

void entity_upgrade_block_check_if_inactive(Entity* entity) {
    BlockData* parentData = entity->dataBuf.block;

    if (parentData->gameFlagIndex != 0xFFFF && !get_global_flag(parentData->gameFlagIndex)) {
        Entity* childEntity;
        SuperBlockContentData* childData;

        parentData->childEntityIndex = create_entity(&Entity_SuperBlockContent, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, 0, MAKE_ENTITY_END);
        childEntity = get_entity_by_index(parentData->childEntityIndex);
        childData = childEntity->dataBuf.superBlockContent;
        childData->parentEntityIndex = entity->listIndex;
    }
}

void entity_upgrade_block_init(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    entity_base_block_init(entity);
    entity->rot.y += 180.0f;
    data->gameFlagIndex = 0xFFFF;
    data->childEntityIndex = -1;
}

void entity_SuperBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_UltraBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_SuperBlockContent_attach_to_parent(Entity* entity) {
    SuperBlockContentData* data = entity->dataBuf.superBlockContent;
    Entity* parentEntity = get_entity_by_index(data->parentEntityIndex);

    entity->pos.x = parentEntity->pos.x;
    entity->pos.y = parentEntity->pos.y + 14.0f;
    entity->pos.z = parentEntity->pos.z;
}

EntityScript Entity_SuperBlock_Script = {
    es_Call(entity_upgrade_block_check_if_inactive)
    es_Label(1)
        es_SetCallback(entity_upgrade_block_idle, 0)
        es_PlaySound(SOUND_HIT_BLOCK)
        es_Call(entity_block_hit_init_scale)
        es_SetCallback(entity_block_hit_animate_scale, 6)
        es_Call(entity_start_script)
    es_Goto(1)
    es_End
    es_End
};

unsigned char* Entity_SuperBlock_Palettes[] = {
    D_0A000200_E4A8A0,
    D_0A000220_E4A8C0,
    D_0A000240_E4A8E0,
    D_0A000260_E4A900
};

s8 Entity_SuperBlock_PalData[] = {
    20, 0,
    2,  1,
    2,  2,
    20, 3,
    2,  2,
    1,  2,
    -1, -1,
};

void entity_SuperBlockContent_setupGfx(s32 entityIndex) {
    Gfx* gfxPos = gMainGfxPos;
    Gfx* dlist;
    u8* palette;
    Entity* entity = get_entity_by_index(entityIndex);
    SuperBlockContentData* data = entity->dataBuf.superBlockContent;
    s32 alpha;
    Matrix4f sp18;

    if (data->paletteTimer == 0) {
        s32 temp = data->paletteArrOffset;
        temp += 2;
        if (Entity_SuperBlock_PalData[temp] > 0) {
            data->paletteTimer = Entity_SuperBlock_PalData[temp];
            data->paletteArrOffset = temp;
        } else {
            data->paletteTimer = Entity_SuperBlock_PalData[0];
            data->paletteArrOffset = 0;
        }
    } else {
        data->paletteTimer--;
    }

    palette = ENTITY_ADDR(entity, u8*, Entity_SuperBlock_Palettes[Entity_SuperBlock_PalData[data->paletteArrOffset + 1]]);
    dlist = data->gfx2;

    gDPPipeSync(gfxPos++);
    guRotateF(sp18, entity_SuperBlockContent_get_previous_yaw(data, 1), 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp18, &data->unk_10);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_10;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetCombineMode(gfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPLoadTLUT_pal16(gfxPos++, 0, palette);
    gSPDisplayList(gfxPos++, dlist);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    alpha = 120;
    if (entity->alpha < alpha) {
        alpha = entity->alpha;
    }

    gDPPipeSync(gfxPos++);
    guRotateF(sp18, entity_SuperBlockContent_get_previous_yaw(data, 6), 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp18, &data->unk_50);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_50;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPDisplayList(gfxPos++, dlist);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    alpha = 80;
    if (entity->alpha < alpha) {
        alpha = entity->alpha;
    }

    gDPPipeSync(gfxPos++);
    guRotateF(sp18, entity_SuperBlockContent_get_previous_yaw(data, 10), 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp18, &data->unk_90);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_90;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPDisplayList(gfxPos++, dlist);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    gMainGfxPos = gfxPos;
}

void entity_SuperBlockContent_idle(Entity* entity) {
    SuperBlockContentData* data = entity->dataBuf.superBlockContent;

    entity_SuperBlockContent_attach_to_parent(entity);
    if (data->isHidden) {
        entity->renderSetupFunc = NULL;
    }

    entity->rot.y = clamp_angle(entity->rot.y + 3.0);
    data->yawBuffer[data->yawBufferPos] = entity->rot.y;

    data->yawBufferPos++;
    if (data->yawBufferPos > ARRAY_COUNT(data->yawBuffer)) {
        data->yawBufferPos = 0;
    }

    if (!data->isHidden && gOverrideFlags == 0) {
        if (--data->effectTimer <= 0) {
            data->effectTimer = 50;
            fx_stars_shimmer(3, entity->pos.x, entity->pos.y, entity->pos.z, 22.0f, 8.0f, 4, 20);
        }
    }
}

void entity_init_SuperBlockContent(Entity* entity) {
    SuperBlockContentData* data = entity->dataBuf.superBlockContent;

    data->gfx1 = Entity_SuperBlockContent_Render;
    data->gfx2 = Entity_SuperBlockContent_Render2;
    entity->renderSetupFunc = entity_SuperBlockContent_setupGfx;
}

void entity_init_UltraBlockContent(Entity* entity) {
    SuperBlockContentData* data = entity->dataBuf.superBlockContent;

    data->gfx1 = Entity_UltraBlockContent_Render;
    data->gfx2 = Entity_UltraBlockContent_Render2;
    entity->renderSetupFunc = entity_SuperBlockContent_setupGfx;
}

extern Gfx Entity_RenderNone[];

EntityScript Entity_SuperBlockContent_Script = {
    es_SetCallback(entity_SuperBlockContent_idle, 0)
    es_End
};
EntityScript Entity_UltraBlockContent_Script = {
    es_SetCallback(entity_SuperBlockContent_idle, 0)
    es_End
};

EntityModelScript Entity_SuperBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_SuperBlock_Render, RENDER_MODE_ALPHATEST);
EntityModelScript Entity_SuperBlockContent_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER2);
EntityModelScript Entity_UltraBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_UltraBlock_Render, RENDER_MODE_ALPHATEST);
EntityModelScript Entity_UltraBlockContent_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER2);

EntityBlueprint Entity_SuperBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_SuperBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_SuperBlock_init,
    .updateEntityScript = Entity_SuperBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(SuperBlock) },
    .entityType = ENTITY_TYPE_SUPER_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_SuperBlockContent = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .typeDataSize = sizeof(SuperBlockContentData),
    .renderCommandList = Entity_SuperBlockContent_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_SuperBlockContent,
    .updateEntityScript = Entity_SuperBlockContent_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(SuperBlockContent) },
    .entityType = ENTITY_TYPE_SUPER_BLOCK_HIT_EFFECT,
    .aabbSize = { 18, 6, 18 }
};

EntityBlueprint Entity_UltraBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_UltraBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_UltraBlock_init,
    .updateEntityScript = Entity_SuperBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(UltraBlock) },
    .entityType = ENTITY_TYPE_ULTRA_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_UltraBlockContent = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .typeDataSize = sizeof(SuperBlockContentData),
    .renderCommandList = Entity_UltraBlockContent_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_UltraBlockContent,
    .updateEntityScript = Entity_UltraBlockContent_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(UltraBlockContent) },
    .entityType = ENTITY_TYPE_ULTRA_BLOCK_HIT_EFFECT,
    .aabbSize = { 18, 6, 18 }
};

#include "common.h"
#include "ld_addrs.h"
#include "entity.h"

#if VERSION_JP // TODO remove once segments are split
extern Addr entity_model_ShatteringBrickBlock_ROM_END;
extern Addr entity_model_ShatteringBrickBlock_ROM_START;
extern Addr entity_model_ShatteringHammer1Block_ROM_END;
extern Addr entity_model_ShatteringHammer1Block_ROM_START;
extern Addr entity_model_ShatteringHammer2Block_ROM_END;
extern Addr entity_model_ShatteringHammer2Block_ROM_START;
extern Addr entity_model_ShatteringHammer3Block_ROM_END;
extern Addr entity_model_ShatteringHammer3Block_ROM_START;
#endif

extern Mtx Entity_ShatteringHammer1Block_FragmentsMatrices[];
extern Gfx* Entity_ShatteringHammer1Block_FragmentsRender[];
extern Mtx Entity_ShatteringHammer2Block_FragmentsMatrices[];
extern Gfx* Entity_ShatteringHammer2Block_FragmentsRender[];
extern Mtx Entity_ShatteringHammer3Block_FragmentsMatrices[];
extern Gfx* Entity_ShatteringHammer3Block_FragmentsRender[];
extern Mtx Entity_ShatteringBrickBlock_FragmentsMatrices[];
extern Gfx* Entity_ShatteringBrickBlock_FragmentsRender[];

extern Gfx Entity_RenderNone[];
extern EntityScript Entity_ShatteringBlock_Script;

void entity_shattering_init_pieces(Entity* entity, Gfx** dlists, Mtx* matrices);
void entity_shattering_block_init(Entity* entity);

EntityModelScript Entity_ShatteringBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityBlueprint Entity_ShatteringHammer1Block = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK,
    .aabbSize = {16, 16, 16}
};

EntityBlueprint Entity_ShatteringHammer2Block = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK,
    .aabbSize = {16, 16, 16}
};

EntityBlueprint Entity_ShatteringHammer3Block = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK,
    .aabbSize = {16, 16, 16}
};

EntityBlueprint Entity_ShatteringHammer1BlockTiny = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK_TINY,
    .aabbSize = {8, 8, 8}
};

EntityBlueprint Entity_ShatteringHammer2BlockTiny = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK_TINY,
    .aabbSize = {8, 8, 8}
};

EntityBlueprint Entity_ShatteringHammer3BlockTiny = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringHammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK_TINY,
    .aabbSize = {8, 8, 8}
};

EntityBlueprint Entity_ShatteringBrickBlock = {
    .flags = 0,
    .typeDataSize = sizeof(ShatteringBlockData),
    .renderCommandList = Entity_ShatteringBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_shattering_block_init,
    .updateEntityScript = Entity_ShatteringBlock_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(ShatteringBrickBlock) },
    .entityType = ENTITY_TYPE_BRICK_BLOCK,
    .aabbSize = {8, 8, 8}
};

void entity_shattering_block_init(Entity* entity) {
    u32 type;
    Mtx* fragmentMatrices = NULL;
    Gfx** fragmentDisplayLists = NULL;

    entity->dataBuf.shatteringBlock->originalPosY = entity->pos.y;
    type = get_entity_type(entity->listIndex);

    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY ||
        type == ENTITY_TYPE_HAMMER2_BLOCK_TINY ||
        type == ENTITY_TYPE_HAMMER3_BLOCK_TINY)
    {
        entity->scale.x = 0.5f;
        entity->scale.y = 0.5f;
        entity->scale.z = 0.5f;
    }

    switch (type) {
        case ENTITY_TYPE_HAMMER1_BLOCK:
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            fragmentDisplayLists = Entity_ShatteringHammer1Block_FragmentsRender;
            fragmentMatrices = Entity_ShatteringHammer1Block_FragmentsMatrices;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            fragmentDisplayLists = Entity_ShatteringHammer2Block_FragmentsRender;
            fragmentMatrices = Entity_ShatteringHammer2Block_FragmentsMatrices;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            fragmentDisplayLists = Entity_ShatteringHammer3Block_FragmentsRender;
            fragmentMatrices = Entity_ShatteringHammer3Block_FragmentsMatrices;
            break;
        case ENTITY_TYPE_BRICK_BLOCK:
            sfx_play_sound_at_position(SOUND_BLOCK_SHATTER, SOUND_SPACE_DEFAULT, entity->pos.x, entity->pos.y, entity->pos.z);
            fragmentDisplayLists = Entity_ShatteringBrickBlock_FragmentsRender;
            fragmentMatrices = Entity_ShatteringBrickBlock_FragmentsMatrices;
            break;
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    if (fragmentMatrices == NULL) {
        return;
    }

    entity_shattering_init_pieces(entity, fragmentDisplayLists, fragmentMatrices);
}

void entity_breakable_block_create_shattering_entity(Entity* entity) {
    EntityBlueprint* bp = NULL;

    switch (get_entity_type(entity->listIndex)) {
        case ENTITY_TYPE_HAMMER1_BLOCK:
            bp = &Entity_ShatteringHammer1Block;
            break;
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            bp = &Entity_ShatteringHammer1BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
            bp = &Entity_ShatteringHammer2Block;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            bp = &Entity_ShatteringHammer2BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
            bp = &Entity_ShatteringHammer3Block;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            bp = &Entity_ShatteringHammer3BlockTiny;
            break;
        case ENTITY_TYPE_BRICK_BLOCK:
            bp = &Entity_ShatteringBrickBlock;
            break;
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    if (bp == NULL) {
        return;
    }

    create_entity(bp, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, 0, MAKE_ENTITY_END);
}

#include "kzn_06.h"
#include "effects.h"
#include "entity.h"

f32 N(PushBlockFallCurve)[] = {
    0.02, 0.02, 0.04, 0.08, 0.11, 0.20, 0.30, 0.31, 
    0.42, 0.46, 0.50, 0.53, 0.56, 0.59, 0.62, 0.65, 
    0.68, 0.71, 0.74, 0.77, 0.80, 0.83, 0.86, 0.89, 
    0.92, 0.95, 0.98, 1.00, 
};

s32 N(push_block_handle_fall)(Entity* block, Evt* source) {
    
    block->position.y = source->varTable[0] - (N(PushBlockFallCurve)[source->functionTemp[0]] * BLOCK_GRID_SIZE);
    if (source->functionTemp[0] == 0) {
        sfx_play_sound_at_position(SOUND_1DA, 0, block->position.x, block->position.y, block->position.z);
    }
    
    if ((source->functionTemp[0] > 4) && (source->functionTemp[0] & 1)) {
        fx_smoke_burst(1, block->position.x, block->position.y, block->position.z, 1.0f, 20);
    }

    do {
        source->functionTemp[0]++;
    } while(0); // required to match

    return source->functionTemp[0] == ARRAY_COUNT(N(PushBlockFallCurve));
}

EvtScript N(EVS_OnBreakBlock) = {
    EVT_SET(GF_KZN06_Hammer3Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 325, 205, -30, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN06_HiddenItem_LifeShroom)
    EVT_IF_EQ(GF_KZN06_Hammer3Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block_TallHitbox), 385, 5, 180, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock)))
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        EVT_CALL(CreatePushBlockGrid, 0, 12, 1, -330, 145, -90, 0)
        EVT_CALL(SetPushBlockFallEffect, 0, EVT_PTR(N(push_block_handle_fall)))
        EVT_CALL(SetPushBlock, 0, 4, 0, PUSH_GRID_BLOCK)
        EVT_CALL(SetPushBlock, 0, 6, 0, PUSH_GRID_BLOCK)
        EVT_CALL(SetPushBlock, 0, 8, 0, PUSH_GRID_BLOCK)
    EVT_ELSE
        EVT_CALL(CreatePushBlockGrid, 0, 12, 1, -330, 120, -90, 0)
        EVT_CALL(SetPushBlock, 0,  9, 0, PUSH_GRID_BLOCK)
        EVT_CALL(SetPushBlock, 0, 10, 0, PUSH_GRID_BLOCK)
        EVT_CALL(SetPushBlock, 0, 11, 0, PUSH_GRID_BLOCK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "kzn_06.h"
#include "effects.h"
#include "entity.h"

#include "world/common/atomic/PushBlockGravity.inc.c"

EvtScript N(EVS_OnBreakBlock) = {
    EVT_SET(GF_KZN06_Hammer3Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 325, 205, -30, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN06_HiddenItem_LifeShroom)
    EVT_IF_EQ(GF_KZN06_Hammer3Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block_WideZ), 385, 5, 180, 0, MAKE_ENTITY_END)
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

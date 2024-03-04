#include "kzn_06.h"
#include "effects.h"
#include "entity.h"

#include "world/common/atomic/PushBlockGravity.inc.c"

EvtScript N(EVS_OnBreakBlock) = {
    Set(GF_KZN06_Hammer3Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 325, 205, -30, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN06_HiddenItem_LifeShroom)
    IfEq(GF_KZN06_Hammer3Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3BlockWideZ), 385, 5, 180, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlock)))
    EndIf
    IfLt(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        Call(CreatePushBlockGrid, 0, 12, 1, -330, 145, -90, 0)
        Call(SetPushBlockFallEffect, 0, Ref(N(push_block_handle_fall)))
        Call(SetPushBlock, 0, 4, 0, PUSH_GRID_BLOCK)
        Call(SetPushBlock, 0, 6, 0, PUSH_GRID_BLOCK)
        Call(SetPushBlock, 0, 8, 0, PUSH_GRID_BLOCK)
    Else
        Call(CreatePushBlockGrid, 0, 12, 1, -330, 120, -90, 0)
        Call(SetPushBlock, 0,  9, 0, PUSH_GRID_BLOCK)
        Call(SetPushBlock, 0, 10, 0, PUSH_GRID_BLOCK)
        Call(SetPushBlock, 0, 11, 0, PUSH_GRID_BLOCK)
    EndIf
    Return
    End
};

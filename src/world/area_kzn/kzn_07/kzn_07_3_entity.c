#include "kzn_07.h"
#include "effects.h"
#include "entity.h"

#include "world/common/atomic/PushBlockGravity.inc.c"

API_CALLABLE(func_802407F4_C6EB24) {
    get_entity_by_index(script->varTable[0])->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorChestStatus) = {
    EVT_IF_EQ(GF_KZN07_GiantChest, FALSE)
        EVT_LABEL(10)
        EVT_IF_EQ(GF_KZN07_GiantChest, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(60)
        EVT_EXEC(N(EVS_PlayUpgradeFanfare))
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0186, 160, 40)
        EVT_CALL(func_802407F4_C6EB24)
        EVT_SET(GB_StoryProgress, STORY_CH5_GOT_ULTRA_HAMMER)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlock) = {
    EVT_SET(GF_KZN07_Hammer3Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GiantChest), 0, 45, -290, 0, ITEM_ULTRA_HAMMER, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KZN07_GiantChest)
    EVT_EXEC(N(EVS_MonitorChestStatus))
    EVT_IF_EQ(GF_KZN07_Hammer3Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block_WideZ), 175, 35, -185, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock)))
    EVT_END_IF
    EVT_CALL(CreatePushBlockGrid, 0, 15, 5, -62, 0, 35, 0)
    EVT_CALL(SetPushBlockFallEffect, 0, EVT_PTR(N(push_block_handle_fall)))
    EVT_CALL(SetPushBlock, 0, 8, 1, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 11, 4, PUSH_GRID_BLOCK)
    EVT_RETURN
    EVT_END
};

#include "kzn_07.h"
#include "effects.h"
#include "entity.h"

#include "world/common/atomic/PushBlockGravity.inc.c"

API_CALLABLE(func_802407F4_C6EB24) {
    get_entity_by_index(script->varTable[0])->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorChestStatus) = {
    IfEq(GF_KZN07_GiantChest, FALSE)
        Label(10)
        IfEq(GF_KZN07_GiantChest, FALSE)
            Wait(1)
            Goto(10)
        EndIf
        Wait(60)
        Exec(N(EVS_PlayUpgradeFanfare))
        Call(ShowMessageAtScreenPos, MSG_Menus_0186, 160, 40)
        Call(func_802407F4_C6EB24)
        Set(GB_StoryProgress, STORY_CH5_GOT_ULTRA_HAMMER)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnBreakBlock) = {
    Set(GF_KZN07_Hammer3Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_GiantChest), 0, 45, -290, 0, ITEM_ULTRA_HAMMER, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_KZN07_GiantChest)
    Exec(N(EVS_MonitorChestStatus))
    IfEq(GF_KZN07_Hammer3Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3BlockWideZ), 175, 35, -185, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlock)))
    EndIf
    Call(CreatePushBlockGrid, 0, 15, 5, -62, 0, 35, 0)
    Call(SetPushBlockFallEffect, 0, Ref(N(push_block_handle_fall)))
    Call(SetPushBlock, 0, 8, 1, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 11, 4, PUSH_GRID_BLOCK)
    Return
    End
};

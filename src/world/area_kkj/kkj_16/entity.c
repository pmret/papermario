#include "kkj_16.h"
#include "entity.h"

// immediately remove the item from Peach's inventory, keeping only the flag
EvtScript N(EVS_AutoRemovePowerRush) = {
    Loop(0)
        IfEq(GF_KKJ16_Item_PowerRush, TRUE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(10)
    Call(RemoveBadge, ITEM_POWER_RUSH)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_LIFE_SHROOM, -840, 110, 10, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KKJ16_Item_LifeShroom)
    Call(MakeItemEntity, ITEM_POWER_RUSH, -550, 0, -120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KKJ16_Item_PowerRush)
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        IfEq(GF_KKJ16_Item_PowerRush, FALSE)
            Exec(N(EVS_AutoRemovePowerRush))
        EndIf
    EndIf
    Return
    End
};

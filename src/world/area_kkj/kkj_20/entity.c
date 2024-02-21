#include "kkj_20.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_LastStand) = {
    Set(LVarA, ITEM_LAST_STAND)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, LVarA)
    ExecWait(N(EVS_Chest_ShowGotItem))
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(AddBadge, LVarA, LVar0)
    EndIf
    Set(GF_KKJ20_Chest_LastStand, TRUE)
    Wait(15)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 95, 0, 0, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_KKJ20_Chest_LastStand)
    Call(AssignScript, Ref(N(EVS_OpenChest_LastStand)))
    Return
    End
};

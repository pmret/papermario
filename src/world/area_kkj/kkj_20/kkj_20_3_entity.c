#include "kkj_20.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_LastStand) = {
    EVT_SET(LVarA, ITEM_LAST_STAND)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_EXEC_WAIT(N(EVS_Chest_ShowGotItem))
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_CALL(AddBadge, LVarA, LVar0)
    EVT_END_IF
    EVT_SET(GF_KKJ20_Chest_LastStand, TRUE)
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 95, 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KKJ20_Chest_LastStand)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_LastStand)))
    EVT_RETURN
    EVT_END
};

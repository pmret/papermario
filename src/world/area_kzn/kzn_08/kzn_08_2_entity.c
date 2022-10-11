#include "kzn_08.h"
#include "entity.h"

s32** N(varStash) = NULL;

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

EvtScript N(D_80244BB4_C76034) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244C1C_C7609C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_IF_NE(LVarA, 0)
        EVT_EXEC_WAIT(N(D_80244BB4_C76034))
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_EQ(ITEM_TYPE_CONSUMABLE)
            EVT_CALL(AddItem, LVarA, LVar0)
        EVT_CASE_EQ(ITEM_TYPE_KEY)
            EVT_CALL(AddKeyItem, LVarA)
        EVT_CASE_EQ(ITEM_TYPE_BADGE)
            EVT_CALL(AddBadge, LVarA, LVar0)
    EVT_END_SWITCH
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest) = {
    EVT_SET(LVarA, ITEM_DIZZY_STOMP)
    EVT_SET(LVarB, ITEM_TYPE_BADGE)
    EVT_SET(GF_KZN08_Chest_DizzyStomp, TRUE)
    EVT_EXEC_WAIT(N(D_80244C1C_C7609C))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 120, 100, -55, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KZN08_Chest_DizzyStomp)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest)))
    EVT_RETURN
    EVT_END
};

#include "common.h"

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = NULL;

EvtScript N(EVS_Chest_ShowGotItem) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Chest_GetItem) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_IF_NE(LVarA, ITEM_NONE)
        EVT_EXEC_WAIT(N(EVS_Chest_ShowGotItem))
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

#define EVT_OPEN_CHEST_CONSUMABLE(item, flag) \
    { \
        EVT_SET(LVarA, item) \
        EVT_SET(LVarB, ITEM_TYPE_CONSUMABLE) \
        EVT_SET(flag, TRUE) \
        EVT_EXEC_WAIT(N(EVS_Chest_GetItem)) \
        EVT_RETURN \
        EVT_END \
    }


#define EVT_OPEN_CHEST_KEY(item, flag) \
    { \
        EVT_SET(LVarA, item) \
        EVT_SET(LVarB, ITEM_TYPE_KEY) \
        EVT_SET(flag, TRUE) \
        EVT_EXEC_WAIT(N(EVS_Chest_GetItem)) \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_OPEN_CHEST_BADGE(item, flag) \
    { \
        EVT_SET(LVarA, item) \
        EVT_SET(LVarB, ITEM_TYPE_BADGE) \
        EVT_SET(flag, TRUE) \
        EVT_EXEC_WAIT(N(EVS_Chest_GetItem)) \
        EVT_RETURN \
        EVT_END \
    }

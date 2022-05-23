#include "common.h"

// see dgb_12

//#define CHEST_ITEM  19
//#define CHEST_FLAG  1048

// temporarily copied from StashVars to allow static varStash
ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    static s32** varStash = NULL;
    s32 i;

    if (varStash == NULL) {
        varStash = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            varStash[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) varStash[i];
        }

        heap_free(varStash);
        varStash = NULL;
    }

    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

EvtScript N(EVS_Chest_ShowGotItem) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 2)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ShowGotItem, EVT_VAR(0), 0, 0)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Chest_GetItem) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_EXEC_WAIT(N(EVS_Chest_ShowGotItem))
    EVT_END_IF
    EVT_SWITCH(EVT_VAR(11))
        EVT_CASE_EQ(0)
            EVT_CALL(AddItem, EVT_VAR(10), EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_CALL(AddKeyItem, EVT_VAR(10))
        EVT_CASE_EQ(2)
            EVT_CALL(AddBadge, EVT_VAR(10), EVT_VAR(0))
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Chest_Interact) = {
    EVT_SET(EVT_VAR(10), CHEST_ITEM)
    EVT_SET(EVT_VAR(11), 1)
    EVT_SET(EVT_SAVE_FLAG(CHEST_FLAG), 1)
    EVT_EXEC_WAIT(N(EVS_Chest_GetItem))
    EVT_RETURN
    EVT_END
};

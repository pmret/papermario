#ifndef _COMMON_GIVE_REWARD_H_
#define _COMMON_GIVE_REWARD_H_

#include "common.h"

static s32** N(varStash) = NULL;

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"

EvtScript N(GiveKeyReward) = {
    EVT_CALL(ShowGotItem, LVar0, ITEM_TYPE_KEY, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(GiveCoinReward) = {
    EVT_CALL(ShowGotItem, LVar0, ITEM_TYPE_KEY, ITEM_PICKUP_FLAG_1_COIN)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

#define EVT_GIVE_KEY_REWARD(itemID) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_KEY) \
    EVT_EXEC_WAIT(N(GiveKeyReward)) \
    EVT_CALL(AddKeyItem, itemID)

#define EVT_GIVE_CONSUMABLE_REWARD(itemID) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_CONSUMABLE) \
    EVT_EXEC_WAIT(N(GiveKeyReward)) \
    EVT_CALL(AddItem, LVar0, LVar1)

#endif

#ifndef _COMMON_GIVE_REWARD_H_
#define _COMMON_GIVE_REWARD_H_

#include "common.h"

static s32** N(varStash) = NULL;

// TODO extracted from world/common/todo/StashVars to reduce warnings (for now)
API_CALLABLE(N(StashVars)) {
    //static s32** varTable = NULL;
    s32 i;

    if (N(varStash) == NULL) {
        N(varStash) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(varStash)[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) N(varStash)[i];
        }

        heap_free(N(varStash));
        N(varStash) = NULL;
    }

    return ApiStatus_DONE2;
}

#include "world/common/todo/GetItemName.inc.c"

EvtScript N(GiveItemReward) = {
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
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddKeyItem, itemID)

#define EVT_GIVE_BADGE_REWARD(itemID) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_BADGE) \
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddBadge, itemID, LVar0)

#define EVT_GIVE_BADGE_REWARD_ALT(itemID, outIdx) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_BADGE) \
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddBadge, LVar0, outIdx)

#define EVT_GIVE_CONSUMABLE_REWARD(itemID) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_CONSUMABLE) \
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddItem, LVar0, LVar1)

#define EVT_GIVE_CONSUMABLE_REWARD_ALT(itemID) \
    EVT_SET(LVar0, itemID) \
    EVT_SET(LVar1, ITEM_TYPE_CONSUMABLE) \
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddItem, itemID, LVar0)

#define EVT_GIVE_STAR_PIECE() \
    EVT_SET(LVar0, ITEM_STAR_PIECE) \
    EVT_SET(LVar1, ITEM_TYPE_STAR_PIECE) \
    EVT_EXEC_WAIT(N(GiveItemReward)) \
    EVT_CALL(AddStarPieces, 1)


#define EVT_GIVE_COIN() \
    EVT_SET(LVar0, ITEM_COIN) \
    EVT_SET(LVar1, 0) \
    EVT_EXEC_WAIT(N(GiveCoinReward)) \
    EVT_CALL(AddCoin, 1)

#endif

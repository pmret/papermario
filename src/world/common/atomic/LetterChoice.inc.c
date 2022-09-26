#include "common.h"

s32** N(varStash) = NULL;

EvtScript N(D_80244A14_C5F154) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244A44) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0x10)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

static s32 N(KeyItemChoiceList)[ITEM_NUM_KEYS + 2];

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

s32 N(HasLetterChoiceResult) = FALSE;
s32 N(LetterChoiceResult) = ITEM_NONE;

ApiStatus N(AwaitLetterChoiceResult)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(HasLetterChoiceResult) = FALSE;
    }

    if (N(HasLetterChoiceResult)) {
        N(HasLetterChoiceResult) = FALSE;
        evt_set_variable(script, *args++, N(LetterChoiceResult));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(SetLetterChoiceResult)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(LetterChoiceResult) = evt_get_variable(script, *args++);
    N(HasLetterChoiceResult) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != ITEM_NONE; i++) {
            N(KeyItemChoiceList)[i] = allowedItemList[i];
        }
        N(KeyItemChoiceList)[i] = ITEM_NONE;
    } else {
        for (i = 0; i < ITEM_NUM_KEYS; i++) {
            N(KeyItemChoiceList)[i] = ITEM_FIRST_KEY + i;
            N(KeyItemChoiceList)[ITEM_NUM_KEYS] = ITEM_NONE; // vanilla oddity -- should be after the loop!
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/LetterDelivery.inc.c"

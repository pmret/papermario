#include "stop_watch.h"

#include "ItemRefund.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A12D4_7270A4)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 254);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000092)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlayEffect, 0x62, 0, 0, 0, 0, EVT_FIXED(1.0), 200, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_246)
    EVT_WAIT_FRAMES(200)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_STOP_WATCH, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(MakeStatusField, EVT_VAR(0), 2097152, 100, EVT_VAR(0))
    EVT_CALL(func_80252B3C, EVT_VAR(0), 1342177280, EVT_VAR(0), 0, 32)
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(func_802A12D4_7270A4))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

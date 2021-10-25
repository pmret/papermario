#include "fright_jar.h"

#include "ItemRefund.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A12D4_72BBE4)(Evt* script, s32 isInitialCall) {
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
    EVT_SET_CONST(EVT_VAR(10), 0x00000098)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_CROUCH)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_367)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), -40)
    EVT_ADD(EVT_VAR(1), 5)
    EVT_SETF(EVT_VAR(3), EVT_FIXED(0.7))
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x61, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 25, 0, 0, 0, 0, 0, 0, 0)
        EVT_ADD(EVT_VAR(0), 5)
        EVT_ADDF(EVT_VAR(3), EVT_FIXED(0.15))
        EVT_WAIT_FRAMES(7)
    EVT_END_LOOP
    EVT_CALL(PlayEffect, 0x61, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(1.5), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(20)
    EVT_LOOP(4)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(MoveBattleCamOver, 2)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(AddBattleCamZoom, 100)
        EVT_CALL(MoveBattleCamOver, 2)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_80269EAC, 21)
    EVT_CALL(ItemAfflictEnemy, EVT_VAR(0), 1879052288, 0, 100, 0, 32)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_WALKING)
    EVT_CALL(N(func_802A12D4_72BBE4))
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

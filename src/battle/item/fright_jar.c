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

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000098)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_CROUCH)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_367)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), -40)
    EVT_ADD(LocalVar(1), 5)
    EVT_SETF(LocalVar(3), EVT_FLOAT(0.7))
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x61, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), 25, 0, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LocalVar(0), 5)
        EVT_ADDF(LocalVar(3), EVT_FLOAT(0.15))
        EVT_WAIT(7)
    EVT_END_LOOP
    EVT_CALL(PlayEffect, 0x61, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.5), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_LOOP(4)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(MoveBattleCamOver, 2)
        EVT_WAIT(2)
        EVT_CALL(AddBattleCamZoom, 100)
        EVT_CALL(MoveBattleCamOver, 2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LocalVar(0), 268435456, 0, LocalVar(0), 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_80269EAC, 21)
    EVT_CALL(ItemAfflictEnemy, LocalVar(0), 1879052288, 0, 100, 0, 32)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_WALKING)
    EVT_CALL(N(func_802A12D4_72BBE4))
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

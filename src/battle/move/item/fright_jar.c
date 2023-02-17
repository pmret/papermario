#include "fright_jar.h"
#include "model.h"

#include "ItemRefund.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

API_CALLABLE(N(func_802A12D4_72BBE4)) {
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
    EVT_SET_CONST(LVarA, 0x00000098)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Crouch)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_367)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -40)
    EVT_ADD(LVar1, 5)
    EVT_SETF(LVar3, EVT_FLOAT(0.7))
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x61, 0, LVar0, LVar1, LVar2, LVar3, 25, 0, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LVar0, 5)
        EVT_ADDF(LVar3, EVT_FLOAT(0.15))
        EVT_WAIT(7)
    EVT_END_LOOP
    EVT_CALL(PlayEffect, 0x61, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 60, 0, 0, 0, 0, 0, 0, 0)
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
    EVT_CALL(ItemCheckHit, LVar0, 268435456, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_80269EAC, 21)
    EVT_CALL(ItemSpookEnemy, LVar0, 1879052288, 0, 100, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Walking)
    EVT_CALL(N(func_802A12D4_72BBE4))
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

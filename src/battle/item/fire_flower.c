#include "fire_flower.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_716E9C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_3F(0, a, b, c, 0);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A1378_716FD8)(Evt* script, s32 isInitialCall) {
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
    EVT_SET_CONST(EVT_VAR(10), 0x00000080)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySound, SOUND_UNKNOWN_377)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PLANT)
    EVT_THREAD
        EVT_WAIT_FRAMES(50)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(35)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_SET(EVT_VAR(0), 40)
    EVT_CALL(MultiplyByActorScale, EVT_VAR(0))
    EVT_ADD(EVT_VAR(3), EVT_VAR(0))
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SUB(EVT_VAR(0), 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FIXED(2.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802A123C_716E9C), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_WAIT_FRAMES(25)
        EVT_LOOP(12)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(PlaySound, SOUND_UNKNOWN_202C)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(PlaySound, SOUND_UNKNOWN_202D)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(80)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetItemPower, ITEM_FIRE_FLOWER, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 939524098, 0, EVT_VAR(0), 32)
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(func_802A1378_716FD8))
    EVT_WAIT_FRAMES(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

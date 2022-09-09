#include "fire_flower.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_716E9C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_fire_flower(0, a, b, c, 0);

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

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000080)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySound, SOUND_377)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PLANT)
    EVT_THREAD
        EVT_WAIT(50)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_WAIT(35)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_SET(LocalVar(0), 40)
    EVT_CALL(MultiplyByActorScale, LocalVar(0))
    EVT_ADD(LocalVar(3), LocalVar(0))
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_SUB(LocalVar(0), 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(2.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802A123C_716E9C), LocalVar(3), LocalVar(4), LocalVar(5))
        EVT_WAIT(25)
        EVT_LOOP(12)
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_202C)
            EVT_WAIT(2)
            EVT_CALL(PlaySound, SOUND_202D)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(80)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LocalVar(0), 268435456, 0, LocalVar(0), 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetItemPower, ITEM_FIRE_FLOWER, LocalVar(0), LocalVar(1))
    EVT_CALL(ItemDamageEnemy, LocalVar(0), 939524098, 0, LocalVar(0), 32)
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(func_802A1378_716FD8))
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

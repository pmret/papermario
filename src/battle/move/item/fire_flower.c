#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"

#define NAMESPACE battle_item_fire_flower

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_716E9C)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_fire_flower(0, a, b, c, 0);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

API_CALLABLE(N(func_802A1378_716FD8)) {
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

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_FIRE_FLOWER)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySound, SOUND_377)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_PlantFireFlower)
    EVT_THREAD
        EVT_WAIT(50)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_WAIT(35)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SET(LVar0, 40)
    EVT_CALL(MultiplyByActorScale, LVar0)
    EVT_ADD(LVar3, LVar0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(2.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802A123C_716E9C), LVar3, LVar4, LVar5)
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
    EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetItemPower, ITEM_FIRE_FLOWER, LVar0, LVar1)
    EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(func_802A1378_716FD8))
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

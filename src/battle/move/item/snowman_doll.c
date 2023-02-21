#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"

#define NAMESPACE battle_item_snowman_doll

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_71C06C)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_2, a, b, c, 30.0f);
    fx_sparkles(FX_SPARKLES_2, a, b, c, 30.0f);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

API_CALLABLE(N(func_802A13B8_71C1E8)) {
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
    EVT_SET_CONST(LVarA, ITEM_SNOWMAN_DOLL)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_363)
    EVT_THREAD
        EVT_LOOP(45)
            EVT_CALL(RandInt, 300, LVar0)
            EVT_SUB(LVar0, 150)
            EVT_SET(LVar1, 170)
            EVT_CALL(RandInt, 50, LVar2)
            EVT_SUB(LVar2, 25)
            EVT_PLAY_EFFECT(EFFECT_SNOWFLAKE, LVar0, LVar1, LVar2, 60, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(50)
    EVT_PLAY_EFFECT(EFFECT_SNOWMAN_DOLL, 0, 0, 0, 20, EVT_FLOAT(1.0), 160, 0)
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(46)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(StartRumble, 10)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(110)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_802A123C_71C06C), LVar0, LVar1, LVar2)
    EVT_CALL(GetItemPower, ITEM_SNOWMAN_DOLL, LVar0, LVar1)
    EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(5)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(30)
    EVT_CALL(N(func_802A13B8_71C1E8))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

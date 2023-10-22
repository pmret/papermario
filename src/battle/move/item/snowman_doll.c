#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_snowman_doll

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_71C06C)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_2, x, y, z, 30.0f);
    fx_sparkles(FX_SPARKLES_2, x, y, z, 30.0f);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_SNOWMAN_DOLL)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_WINTERY_JINGLE)
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(50)
    EVT_PLAY_EFFECT(EFFECT_SNOWMAN_DOLL, 0, 0, 0, 20, EVT_FLOAT(1.0), 160, 0)
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(46)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(110)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(func_802A123C_71C06C), LVar0, LVar1, LVar2)
        EVT_CALL(GetItemPower, ITEM_SNOWMAN_DOLL, LVar0, LVar1)
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_WAIT(5)
        EVT_LABEL(1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(30)
    EVT_CALL(N(FadeBackgroundLighten))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

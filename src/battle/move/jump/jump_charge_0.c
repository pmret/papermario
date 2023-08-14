#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_jump_charge_0

#include "battle/common/move/JumpSupport.inc.c"

#include "world/common/todo/IsJumpMaxCharged.inc.c"

API_CALLABLE(N(func_802A1108_74D678)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_stat_change(0, var1, var2, var3, 1.0f, 60);

    battleStatus->jumpCharge++;
    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_JUMP_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A120C_74D77C)) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var0 + 10, var1 + 18, var2, var3, 45);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UseMove1) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove0) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    EVT_WAIT(10)
    EVT_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        EVT_WAIT(8)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FightingStance)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_802A120C_74D77C), LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(N(func_802A120C_74D77C), LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(N(IsJumpMaxCharged))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(N(func_802A1108_74D678), LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_JUMP)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_CHARGE_JUMP, 60, 1)
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

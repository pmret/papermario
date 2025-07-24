#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_jump_charge_1

#include "battle/common/move/JumpSupport.inc.c"

#include "world/common/todo/IsJumpMaxCharged.inc.c"

BSS bool N(HasCharged);

API_CALLABLE(N(func_802A1108_74D678)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_stat_change(1, var1, var2, var3, 1.0f, 60);

    N(HasCharged) = false;
    if (battleStatus->jumpCharge > 0) {
        N(HasCharged) = true;
    }

    battleStatus->jumpCharge += 2;

    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_JUMP_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;

    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMoveFunc2.inc.c"

API_CALLABLE(N(GetChargeMessage)) {
    if (!N(HasCharged)) {
        script->varTable[0] = BTL_MSG_CHARGE_JUMP;
    } else {
        script->varTable[0] = BTL_MSG_CHARGE_JUMP_MORE;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UseMove_Unimplemented) = {
    Return
    End
};

EvtScript N(EVS_UseMove) = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    Wait(10)
    ChildThread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
    EndChildThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FightingStance)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsJumpMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Add(LVar1, 25)
        Add(LVar2, 5)
        Call(N(func_802A1108_74D678), LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerHopToGoal, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, true)
        Call(N(GetChargeMessage))
        Call(ShowVariableMessageBox, LVar0, 60, 2)
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, true)
        Goto(0)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, false)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

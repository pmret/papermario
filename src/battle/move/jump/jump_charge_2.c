#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_jump_charge_2

#include "battle/common/move/JumpSupport.inc.c"

#include "world/common/todo/IsJumpMaxCharged.inc.c"

BSS s32 D_802A2C20;

API_CALLABLE(N(func_802A1108_74D678)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32* var4;

    fx_stat_change(2, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A2C20;
    *var4 = 0;
    if (battleStatus->jumpCharge > 0) {
        *var4 = 1;
    }

    battleStatus->jumpCharge += 3;

    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_JUMP_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;

    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMoveFunc3.inc.c"

API_CALLABLE(N(func_802A133C_761C5C)) {
    if (D_802A2C20 == 0) {
        script->varTable[0] = 6;
    } else {
        script->varTable[0] = 7;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UseMove1) = {
    Return
    End
};

EvtScript N(EVS_UseMove0) = {
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
    Call(N(UnkMoveFunc3), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(UnkMoveFunc3), LVar0, LVar1, LVar2, Float(0.8))
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
        Call(N(func_802A133C_761C5C))
        Call(ShowVariableMessageBox, LVar0, 60, 3)
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, TRUE)
        Goto(0)
    EndIf
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};


#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_charge_1

#include "battle/common/move/HammerSupport.inc.c"

#include "world/common/todo/IsHammerMaxCharged.inc.c"

BSS s32 D_802A43D0;

API_CALLABLE(func_802A10C8_759678) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32* var4;

    fx_stat_change(1, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A43D0;
    *var4 = 0;
    if (battleStatus->hammerCharge > 0) {
        *var4 = 1;
    }

    battleStatus->hammerCharge += 2;

    if (battleStatus->hammerCharge > 99) {
        battleStatus->hammerCharge = 99;
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_HAMMER_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_JUMP_CHARGED;

    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMoveFunc2.inc.c"

API_CALLABLE(func_802A12FC_7598AC) {
    if (D_802A43D0 == 0) {
        script->varTable[0] = 4;
    } else {
        script->varTable[0] = 5;
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove1_Impl);

EvtScript N(EVS_UseMove1) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 65)
            Set(LVarE, 1)
            Set(LVarF, 2)
            ExecWait(N(EVS_UseMove1_Impl))
        CaseEq(1)
            Set(LVarD, 65)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(EVS_UseMove1_Impl))
        CaseEq(2)
            Set(LVarD, 65)
            Set(LVarE, 4)
            Set(LVarF, 6)
            ExecWait(N(EVS_UseMove1_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove1_Impl) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseBasicHammer))
        CaseEq(1)
            ExecWait(N(EVS_UseSuperHammer))
        CaseEq(2)
            ExecWait(N(EVS_UseBasicHammer))
    EndSwitch
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.9))
                    EndThread
            EndSwitch
        CaseDefault
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.9))
                    EndThread
            EndSwitch
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_Hammer_ReturnHome_C))
        Return
    EndIf
    Set(LFlag0, FALSE)
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                CaseEq(1)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                CaseEq(2)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EndSwitch
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
            Set(LFlag0, TRUE)
        CaseDefault
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                CaseEq(1)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                CaseEq(2)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EndSwitch
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_TRIGGER_EVENTS)
            Set(LFlag0, FALSE)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(EVS_Hammer_ReturnHome_A))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_Hammer_ReturnHome_C))
        EndCaseGroup
    EndSwitch
    Return
    End
};

extern EvtScript N(EVS_802A39C8);
extern EvtScript N(EVS_802A3D1C);
extern EvtScript N(EVS_802A4070);

EvtScript N(EVS_UseMove0) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_802A39C8))
        CaseEq(1)
            ExecWait(N(EVS_802A3D1C))
        CaseEq(2)
            ExecWait(N(EVS_802A4070))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A39C8) = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    Wait(10)
    Thread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer1_Charging)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_759678, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(func_80273444, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(func_802A12FC_7598AC)
        Call(ShowVariableMessageBox, LVar0, 60, 2)
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, TRUE)
        Goto(0)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Return
    End
};

EvtScript N(EVS_802A3D1C) = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    Wait(10)
    Thread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer2_Charging)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_759678, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(func_80273444, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(func_802A12FC_7598AC)
        Call(ShowVariableMessageBox, LVar0, 60, 2)
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, TRUE)
        Goto(0)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Return
    End
};

EvtScript N(EVS_802A4070) = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    Wait(10)
    Thread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_CHARGE)
        Wait(8)
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer3_Charging)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(UnkMoveFunc2), LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_759678, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(func_80273444, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(func_802A12FC_7598AC)
        Call(ShowVariableMessageBox, LVar0, 60, 2)
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, TRUE)
        Goto(0)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Return
    End
};

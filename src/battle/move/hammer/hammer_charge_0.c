#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_charge_0

#include "battle/common/move/HammerSupport.inc.c"

#include "world/common/todo/IsHammerMaxCharged.inc.c"

API_CALLABLE(func_802A10C8_74F1F8) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_stat_change(0, var1, var2, var3, 1.0f, 60);

    battleStatus->hammerCharge++;
    if (battleStatus->hammerCharge > 99) {
        battleStatus->hammerCharge = 99;
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_HAMMER_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_JUMP_CHARGED;

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A11CC_74F2FC) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var0 + 10, var1 + 18, var2, var3, 45);

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove1_Impl);

EvtScript N(EVS_UseMove1) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 65) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove1_Impl))
        CaseEq(1)
            Set(LVarD, 65) // duration
            Set(LVarE, SUPER_HAMMER_DMG_BAD)
            Set(LVarF, SUPER_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove1_Impl))
        CaseEq(2)
            Set(LVarD, 65) // duration
            Set(LVarE, ULTRA_HAMMER_DMG_BAD + 1)
            Set(LVarF, ULTRA_HAMMER_DMG_GOOD)
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
    Call(GetPlayerActionQuality, LVar0)
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
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Set(LFlag0, FALSE)
    Call(GetPlayerActionQuality, LVar0)
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
            ExecWait(N(EVS_HammerSupport_ReturnHome_SmashSuccess))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        EndCaseGroup
    EndSwitch
    Return
    End
};

extern EvtScript N(EVS_802A3948);
extern EvtScript N(EVS_802A3C90);
extern EvtScript N(EVS_802A3FD8);

EvtScript N(EVS_UseMove0) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_802A3948))
        CaseEq(1)
            ExecWait(N(EVS_802A3C90))
        CaseEq(2)
            ExecWait(N(EVS_802A3FD8))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3948) = {
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
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerHopToGoal, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
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

EvtScript N(EVS_802A3C90) = {
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
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerHopToGoal, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
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

EvtScript N(EVS_802A3FD8) = {
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
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, Float(0.8))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Call(N(IsHammerMaxCharged))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Call(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_CHARGE_UP)
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerHopToGoal, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
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

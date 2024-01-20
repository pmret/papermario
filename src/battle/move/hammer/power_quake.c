#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_power_quake

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_802A3168);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 80)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(EVS_802A3168))
        CaseEq(1)
            Set(LVarD, 80)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(EVS_802A3168))
        CaseEq(2)
            Set(LVarD, 80)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(EVS_802A3168))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3168) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_Hammer_UseBasicQuake))
        CaseEq(1)
            ExecWait(N(EVS_Hammer_UseSuperQuake))
        CaseEq(2)
            ExecWait(N(EVS_Hammer_UseUltraQuake))
    EndSwitch
    Thread
        Wait(8)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 24)
        Add(LVar1, 10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 0, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 33, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 66, 30, 0, 0, 0, 0, 0)
    EndThread
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.24))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.2))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(2.4))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.2))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.84))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.48))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.12))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.06))
            EndThread
            Thread
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Add(LVar0, 24)
                Add(LVar1, 10)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 48, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 72, 30, 0, 0, 0, 0, 0)
            EndThread
        CaseDefault
            Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.7))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.4))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.1))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.05))
            EndThread
            Thread
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Add(LVar0, 24)
                Add(LVar1, 10)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                Wait(6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 96, 8, 48, 30, 0, 0, 0, 0, 0)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 96, 8, 72, 30, 0, 0, 0, 0, 0)
            EndThread
    EndSwitch
    Call(GetPlayerActionSuccess, LVar0)
    IfGt(LVar0, FALSE)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_46)
        Call(MoveBattleCamOver, 5)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PRESET_46)
        Call(MoveBattleCamOver, 50)
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_3)
    EndSwitch
    Wait(10)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_3)
    EndSwitch
    Set(LVar9, 0)
    Call(InitTargetIterator)
    Label(10)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE_HAMMER, 29, 0, 0, 16)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(11)
        EndIf
        Call(GetPlayerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(FALSE)
                Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
            CaseDefault
                Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
        EndSwitch
        Label(11)
        Call(ChooseNextTarget, ITER_NEXT, LVar1)
        Add(LVar9, 1)
        Call(GetTargetListLength, LVar1)
        IfLt(LVar9, LVar1)
            Goto(10)
        EndIf
    Thread
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Wait(10)
    ExecWait(N(EVS_Hammer_ReturnHome_B))
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

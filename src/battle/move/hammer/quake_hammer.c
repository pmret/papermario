#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_quake_hammer

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 80) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 80) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 80) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_Impl) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_Hammer_UseBasicQuake))
        CaseEq(1)
            ExecWait(N(EVS_Hammer_UseSuperQuake))
        CaseEq(2)
            ExecWait(N(EVS_Hammer_UseUltraQuake))
    EndSwitch
    ChildThread
        Wait(8)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 24)
        Add(LVar1, 10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 0, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 33, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 66, 30, 0, 0, 0, 0, 0)
    EndChildThread
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
            ChildThread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.7))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.4))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.1))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.05))
            EndChildThread
            ChildThread
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Add(LVar0, 24)
                Add(LVar1, 10)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
            EndChildThread
        CaseDefault
            Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
            ChildThread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.1))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.35))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.2))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.05))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.025390625))
            EndChildThread
    EndSwitch
    Call(GetPlayerActionQuality, LVar0)
    IfGt(LVar0, FALSE)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_QUAKE)
        Call(MoveBattleCamOver, 5)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_QUAKE)
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
        Call(GetPlayerActionQuality, LVar0)
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
    ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

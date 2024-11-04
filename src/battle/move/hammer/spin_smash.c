#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_spin_smash

API_CALLABLE(func_802A1000_737890) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->curPos.x + 20.0f;
    f32 yPos = playerActor->curPos.y + 15.0f;
    f32 zPos = playerActor->curPos.z + 5.0f;

    fx_stars_spread(0, xPos, yPos, zPos, 6, 20);

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A1074_737904) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->curPos.x + 20.0f;
    f32 yPos = playerActor->curPos.y + 15.0f;
    f32 zPos = playerActor->curPos.z + 5.0f;

    fx_steam_burst(0, xPos, yPos, zPos, 1.0f, 20);

    return ApiStatus_DONE2;
}

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove1_Impl);
extern EvtScript N(EVS_UseMove2_Impl);
extern EvtScript N(EVS_UseMove3_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(SetDamageSource, DMG_SRC_SPIN_SMASH)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 60) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove1_Impl))
        CaseEq(1)
            Set(LVarD, 60) // duration
            Set(LVarE, SUPER_HAMMER_DMG_BAD)
            Set(LVarF, SUPER_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove2_Impl))
        CaseEq(2)
            Set(LVarD, 60) // duration
            Set(LVarE, ULTRA_HAMMER_DMG_BAD)
            Set(LVarF, ULTRA_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove3_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove1_Impl) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(InitTargetIterator)
    ExecWait(N(EVS_HammerSupport_SmashApproach))
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Raise)
    Wait(8)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Hold1)
    Call(N(ShouldMovesAutoSucceed))
    IfEq(LVar0, HIT_RESULT_HIT)
        Loop(45)
            Wait(1)
            Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            IfNe(LVar0, FALSE)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(action_command_hammer_start, 0, LVarD, AC_DIFFICULTY_3)
    Call(SetActionProgress, 0)
    Set(LVar1, 0)
    Loop(30)
        Wait(1)
        Call(GetActionProgress, LVar0)
        IfNe(LVar0, 0)
            IfNe(LVar1, 1)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Hold2)
                Set(LVar1, 1)
            EndIf
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Label(0)
    Wait(1)
    Call(GetSmashActionQuality, LVar0)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_PreSwing)
    Wait(3)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Swing)
    Wait(3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_QUAKE)
    Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_1)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Wait(25)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(func_802A1000_737890)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(func_802A1074_737904)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(10)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 18)
            Call(SetActorYaw, ACTOR_PLAYER, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
    Return
    End
};

EvtScript N(EVS_UseMove2_Impl) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(InitTargetIterator)
    ExecWait(N(EVS_HammerSupport_SmashApproach))
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Raise)
    Wait(8)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Hold1)
    Call(N(ShouldMovesAutoSucceed))
    IfEq(LVar0, FALSE)
        Loop(45)
            Wait(1)
            Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            IfNe(LVar0, FALSE)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(action_command_hammer_start, 0, LVarD, AC_DIFFICULTY_3)
    Call(SetActionProgress, 0)
    Set(LVar1, 0)
    Loop(30)
        Wait(1)
        Call(GetActionProgress, LVar0)
        IfNe(LVar0, 0)
            IfNe(LVar1, 1)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Hold2)
                Set(LVar1, 1)
            EndIf
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Label(0)
    Wait(1)
    Call(GetSmashActionQuality, LVar0)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_PreSwing)
    Wait(3)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Swing)
    Wait(3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_QUAKE)
    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_2)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Wait(25)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(func_802A1000_737890)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(func_802A1074_737904)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(10)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 18)
            Call(SetActorYaw, ACTOR_PLAYER, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
    Return
    End
};

EvtScript N(EVS_UseMove3_Impl) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(InitTargetIterator)
    ExecWait(N(EVS_HammerSupport_SmashApproach))
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Call(InitTargetIterator)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Raise)
    Wait(8)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Hold1)
    Call(N(ShouldMovesAutoSucceed))
    IfEq(LVar0, FALSE)
        Loop(45)
            Wait(1)
            Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            IfNe(LVar0, FALSE)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(action_command_hammer_start, 0, LVarD, AC_DIFFICULTY_3)
    Call(SetActionProgress, 0)
    Set(LVar1, 0)
    Loop(30)
        Wait(1)
        Call(GetActionProgress, LVar0)
        IfNe(LVar0, 0)
            IfNe(LVar1, 1)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Hold2)
                Set(LVar1, 1)
            EndIf
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Label(0)
        Wait(1)
        Call(GetSmashActionQuality, LVar0)
        IfEq(LVar0, 0)
            Goto(0)
        EndIf
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_PreSwing)
    Wait(3)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Swing)
    Wait(3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_QUAKE)
    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_3)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Wait(25)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(func_802A1000_737890)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(func_802A1074_737904)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(10)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 18)
            Call(SetActorYaw, ACTOR_PLAYER, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    ExecWait(N(EVS_HammerSupport_ReturnHome_Quake))
    Return
    End
};

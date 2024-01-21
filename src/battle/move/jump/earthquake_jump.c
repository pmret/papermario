#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_earthquake_jump

#include "battle/common/move/JumpSupport.inc.c"

API_CALLABLE(N(func_802A10E4_785C04)) {
    script->varTable[0] = 3;
    return ApiStatus_DONE2;
}

MATCHING_BSS(0x3CC0);

s32 N(DifficultyTable)[] = {
    11, 10, 9, 8, 7, 6, 5, 4
};

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    Set(LFlagA, FALSE)
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseMove_ImplA))
        CaseEq(1)
            ExecWait(N(EVS_UseMove_ImplB))
        CaseEq(2)
            ExecWait(N(EVS_UseMove_ImplC))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_ImplA) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(SetGoalToFirstTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, Float(70.0))
    IfLt(LVar0, LVar3)
        Sub(LVar0, 20)
        Set(LVar3, LVar0)
    EndIf
    Call(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(CancelablePlayerRunToGoal, 0, LVar0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    ExecWait(N(EVS_JumpSupport_B))
    Set(LVarB, LVarA)
    Add(LVarB, 2)
    Call(action_command_jump_start, LVarB, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_34)
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    Call(func_80274A18, LVarA, 0)
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
    Wait(10)
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(1)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(2)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Label(2)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(1)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(GetActionResult, LVarE)
    Set(LVarF, 0)
    Set(LFlag0, FALSE)
    Label(10)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(CloseActionCommandInfo)
    Call(SetActionDifficultyTable, Ref(N(DifficultyTable)))
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Set(LVarA, 26)
    Switch(LVarF)
        CaseEq(0)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(1)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(2)
            Call(action_command_jump_start, LVarA, 4)
        CaseEq(3)
            Call(action_command_jump_start, LVarA, 4)
        CaseDefault
            Call(action_command_jump_start, LVarA, 5)
    EndSwitch
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    IfEq(LVarF, 0)
        Call(func_80274A18, 24, 3)
    Else
        Call(func_80274A18, 24, 4)
    EndIf
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
    Wait(10)
    Call(GetCommandAutoSuccess, LVar1)
    IfEq(LVar1, 1)
        IfGt(LVarF, 3)
            Set(LFlag0, TRUE)
        EndIf
    EndIf
    Set(LVar0, 3)
    Call(N(func_802A10E4_785C04))
    IfGt(LVarF, LVar0)
        Set(LFlag0, TRUE)
    EndIf
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(11)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(12)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            IfEq(LFlag0, FALSE)
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            Else
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EndIf
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVarF)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        CaseEq(3)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EndSwitch
    Call(SetActionResult, LVarE)
    Label(12)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(11)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Add(LVarF, 1)
    Goto(10)
    Return
    End
};

EvtScript N(EVS_UseMove_ImplB) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(SetGoalToFirstTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, Float(70.0))
    IfLt(LVar0, LVar3)
        Sub(LVar0, 20)
        Set(LVar3, LVar0)
    EndIf
    Call(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(CancelablePlayerRunToGoal, 0, LVar0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    ExecWait(N(EVS_CheckForAPress))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    ExecWait(N(EVS_JumpSupport_B))
    Set(LVarB, LVarA)
    Add(LVarB, 2)
    Call(action_command_jump_start, LVarB, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_34)
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    Call(func_80274A18, LVarA, 0)
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
    Wait(10)
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(1)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(2)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Label(2)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(1)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(GetActionResult, LVarE)
    Set(LVarF, 0)
    Set(LFlag0, FALSE)
    Label(10)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(CloseActionCommandInfo)
    Call(SetActionDifficultyTable, Ref(N(DifficultyTable)))
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Set(LVarA, 39)
    Switch(LVarF)
        CaseEq(0)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(1)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(2)
            Call(action_command_jump_start, LVarA, 4)
        CaseEq(3)
            Call(action_command_jump_start, LVarA, 4)
        CaseDefault
            Call(action_command_jump_start, LVarA, 5)
    EndSwitch
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    IfEq(LVarF, 0)
        Call(func_802752AC, 20, 3)
        Wait(7)
        Call(func_802752AC, 3, 6)
    Else
        Call(func_802752AC, 20, 4)
        Wait(7)
        Call(func_802752AC, 3, 5)
    EndIf
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
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
    Wait(10)
    Call(GetCommandAutoSuccess, LVar1)
    IfEq(LVar1, 1)
        IfGt(LVarF, 4)
            Set(LFlag0, TRUE)
        EndIf
    EndIf
    Set(LVar0, 4)
    Call(N(func_802A10E4_785C04))
    IfGt(LVarF, LVar0)
        Set(LFlag0, TRUE)
    EndIf
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(11)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(12)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            IfEq(LFlag0, FALSE)
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            Else
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EndIf
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVarF)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        CaseEq(3)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EndSwitch
    Call(SetActionResult, LVarE)
    Label(12)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(1)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Add(LVarF, 1)
    Goto(10)
    Return
    End
};

EvtScript N(EVS_UseMove_ImplC) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(SetGoalToFirstTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, Float(70.0))
    IfLt(LVar0, LVar3)
        Sub(LVar0, 20)
        Set(LVar3, LVar0)
    EndIf
    Call(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(CancelablePlayerRunToGoal, 0, LVar0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    ExecWait(N(EVS_CheckForAPress))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    ExecWait(N(EVS_JumpSupport_B))
    Set(LVarB, LVarA)
    Add(LVarB, 2)
    Call(action_command_jump_start, LVarB, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_34)
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    Call(func_80274A18, LVarA, 0)
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
    Wait(10)
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(1)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(2)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Label(2)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(1)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(GetActionResult, LVarE)
    Set(LVarF, 0)
    Set(LFlag0, FALSE)
    Label(10)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_28)
        Wait(5)
        Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(CloseActionCommandInfo)
    Call(SetActionDifficultyTable, Ref(N(DifficultyTable)))
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Set(LVarA, 27)
    Switch(LVarF)
        CaseEq(0)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(1)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(2)
            Call(action_command_jump_start, LVarA, 4)
        CaseEq(3)
            Call(action_command_jump_start, LVarA, 4)
        CaseDefault
            Call(action_command_jump_start, LVarA, 5)
    EndSwitch
    Call(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    IfEq(LVarF, 0)
        Call(func_80275F00, 25, 2)
    Else
        Call(func_80275F00, 25, 4)
    EndIf
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
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
    Wait(10)
    Call(GetCommandAutoSuccess, LVar1)
    IfEq(LVar1, 1)
        IfGt(LVarF, 5)
            Set(LFlag0, TRUE)
        EndIf
    EndIf
    Set(LVar0, 5)
    Call(N(func_802A10E4_785C04))
    IfGt(LVarF, LVar0)
        Set(LFlag0, TRUE)
    EndIf
    Call(InitTargetIterator)
    Call(GetPlayerActionSuccess, LVarB)
    Set(LVar9, 0)
    Label(11)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(12)
    EndIf
    Switch(LVarB)
        CaseGt(FALSE)
            IfEq(LFlag0, FALSE)
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            Else
                Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
                Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EndIf
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVarF)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        CaseEq(3)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EndSwitch
    Call(SetActionResult, LVarE)
    Label(12)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    Add(LVar9, 1)
    Call(GetTargetListLength, LVar0)
    IfLt(LVar9, LVar0)
        Goto(1)
    EndIf
    Switch(LVarC)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(EVS_JumpSupport_E))
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Add(LVarF, 1)
    Goto(10)
    Return
    End
};

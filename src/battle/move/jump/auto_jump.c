#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_auto_jump

#include "battle/common/move/JumpSupport.inc.c"

extern EvtScript N(EVS_UseMove_Basic);
extern EvtScript N(EVS_UseMove_Super);
extern EvtScript N(EVS_UseMove_Ultra);

EvtScript N(EVS_UseMove) = {
    Call(SetBattleFlagBits, BS_FLAGS1_AUTO_SUCCEED_ACTION, TRUE)
    Call(ShowActionHud, FALSE)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseMove_Basic))
        CaseEq(1)
            ExecWait(N(EVS_UseMove_Super))
        CaseEq(2)
            ExecWait(N(EVS_UseMove_Ultra))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_Basic) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(GetActionCommandMode, LVar0)
    IfEq(LVar0, AC_MODE_TUTORIAL)
        Call(SetActionCommandMode, AC_MODE_TUTORIAL_WAIT_INPUT)
        Loop(0)
            Call(GetActionCommandMode, LVar0)
            IfLt(LVar0, AC_MODE_TUTORIAL)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndIf
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
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
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_PRE_JUMP_FINISH)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_JUMP_FINISH)
    EndChildThread
    Call(GetJumpActionQuality, LVarF)
    Call(InterruptActionCommand)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 24, AC_DIFFICULTY_3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    Call(PlayerBasicJumpToGoal, 24, PLAYER_BASIC_JUMP_3)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_UseMove_Super) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Call(GetJumpActionQuality, LVarF)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_PRE_JUMP_FINISH)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_JUMP_FINISH)
    EndChildThread
    Call(InterruptActionCommand)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 37, AC_DIFFICULTY_3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(PlayerSuperJumpToGoal, 20, PLAYER_SUPER_JUMP_4)
    Wait(7)
    Call(PlayerSuperJumpToGoal, 3, PLAYER_SUPER_JUMP_5)
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_UseMove_Ultra) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Call(GetJumpActionQuality, LVarF)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_PRE_ULTRA_JUMP_FINISH)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_JUMP_FINISH)
    EndChildThread
    Call(InterruptActionCommand)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 25, AC_DIFFICULTY_3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    Call(PlayerUltraJumpToGoal, 25, PLAYER_ULTRA_JUMP_4)
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_jump_attack

#include "battle/common/move/JumpSupport.inc.c"

API_CALLABLE(N(GetJumpDamage)) {
    script->varTable[15] = 1;

    switch (gPlayerData.bootsLevel) {
        case 0:
            script->varTable[15] = 1;
            break;
        case 1:
            script->varTable[15] = 2;
            break;
        case 2:
            script->varTable[15] = 3;
            break;
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove_Basic);
extern EvtScript N(EVS_UseMove_Super);
extern EvtScript N(EVS_UseMove_Ultra);
extern EvtScript N(EVS_UseMove_Tutorial);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetBattleFlags2, LVar0)
    IfFlag(LVar0, BS_FLAGS2_DOING_JUMP_TUTORIAL)
        ExecWait(N(EVS_UseMove_Tutorial))
        Return
    EndIf
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
    Call(GetActionCommandMode, LVar0)
    IfGt(LVar0, AC_MODE_NOT_LEARNED)
        Wait(1)
    EndIf
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
            // missed action command, end the script here
            ExecWait(N(EVS_JumpSupport_G))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            // successful action command, continue with script
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
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
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
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

extern EvtScript N(EVS_FirstStrike_Normal);
extern EvtScript N(EVS_FirstStrike_Super);
extern EvtScript N(EVS_FirstStrike_Ultra);

EvtScript N(EVS_FirstStrike) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_FirstStrike_Normal))
        CaseEq(1)
            ExecWait(N(EVS_FirstStrike_Super))
        CaseEq(2)
            ExecWait(N(EVS_FirstStrike_Ultra))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_FirstStrike_Normal) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 40)
    Call(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(UseBattleCamPresetImmediately, BTL_CAM_PLAYER_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar0, LVar3)
    Sub(LVar0, 20)
    DivF(LVar0, Float(10.588))
    AddF(LVar0, 15)
    Set(LVarA, LVar0)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    Call(PlayerBasicJumpToGoal, LVarA, PLAYER_BASIC_JUMP_0)
    Call(N(GetJumpDamage))
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_FirstStrike_Super) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 40)
    Call(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    ExecWait(N(EVS_JumpSupport_CalcJumpTime_Alt1))
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_SUPER_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(PlayerSuperJumpToGoal, LVarA, PLAYER_SUPER_JUMP_0)
    Wait(7)
    Call(PlayerSuperJumpToGoal, 3, PLAYER_SUPER_JUMP_1)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(UseBattleCamPresetImmediately, BTL_CAM_PLAYER_JUMP_MIDAIR)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_FirstStrike_Ultra) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 40)
    Call(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    ExecWait(N(EVS_JumpSupport_CalcJumpTime_Alt2))
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ULTRA_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp)
    Call(PlayerUltraJumpToGoal, LVarA, PLAYER_ULTRA_JUMP_0)
    Set(LVarA, 4)
    Call(PlayerUltraJumpToGoal, LVarA, PLAYER_ULTRA_JUMP_1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

extern EvtScript N(EVS_UseBerserker_Normal);
extern EvtScript N(EVS_UseBerserker_Super);
extern EvtScript N(EVS_UseBerserker_Ultra);

EvtScript N(EVS_UseBerserker) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseBerserker_Normal))
        CaseEq(1)
            ExecWait(N(EVS_UseBerserker_Super))
        CaseEq(2)
            ExecWait(N(EVS_UseBerserker_Ultra))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseBerserker_Normal) = {
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

EvtScript N(EVS_UseBerserker_Super) = {
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
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_UseBerserker_Ultra) = {
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
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
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

EvtScript N(EVS_UseMove_Tutorial) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    ExecWait(N(EVS_JumpSupport_CalcJumpTime))
    Call(action_command_jump_start, LVarA, AC_DIFFICULTY_3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, -5, 10, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    Call(PlayerBasicJumpToGoal, LVarA, PLAYER_BASIC_JUMP_0)
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
    Call(GetActionCommandMode, LVar0)
    IfGt(LVar0, AC_MODE_NOT_LEARNED)
        Wait(1)
    EndIf
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

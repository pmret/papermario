#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_d_down_jump

#include "battle/common/move/JumpSupport.inc.c"

API_CALLABLE(N(SpawnImpactFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, x, y, z, 0.0f);
    } else {
        fx_green_impact(FALSE, x, y, z, 0.0f);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove_Basic);
extern EvtScript N(EVS_UseMove_Super);
extern EvtScript N(EVS_UseMove_Ultra);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(SetDamageSource, DMG_SRC_D_DOWN_JUMP)
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
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Call(GetPlayerActionQuality, LVarA)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_ACTOR_JUMPED_1)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
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
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
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
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpawnImpactFX), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_Rebound))
    Return
    End
};

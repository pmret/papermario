#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_d_down_jump

#include "battle/common/move/JumpSupport.inc.c"

API_CALLABLE(N(func_802A10E4_781A04)) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, var0, var1, var2, 0.0f);
    } else {
        fx_green_impact(FALSE, var0, var1, var2, 0.0f);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(SetDamageSource, DMG_SRC_D_DOWN_JUMP)
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
    ExecWait(N(EVS_JumpSupport_InitCommand))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Call(GetPlayerActionSuccess, LVarA)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
    Wait(1)
    Call(GetPlayerActionSuccess, LVar0)
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
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(GetActionResult, LVarF)
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 24, 3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    Call(func_80274A18, 24, 3)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_E))
    Return
    End
};

EvtScript N(EVS_UseMove_ImplB) = {
    ExecWait(N(EVS_JumpSupport_InitCommand))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
    Wait(1)
    Call(GetPlayerActionSuccess, LVar0)
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
    Call(GetActionResult, LVarF)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_27)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 37, 3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(func_802752AC, 20, 4)
    Wait(7)
    Call(func_802752AC, 3, 5)
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_E))
    Return
    End
};

EvtScript N(EVS_UseMove_ImplC) = {
    ExecWait(N(EVS_JumpSupport_InitCommand))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    Wait(1)
    Call(GetPlayerActionSuccess, LVar0)
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
    Call(GetActionResult, LVarF)
    ChildThread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_28)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EndChildThread
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 25, 3)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    Call(func_80275F00, 25, 4)
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(func_802A10E4_781A04), LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    Wait(1)
    Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    Call(SetActionResult, LVarF)
    ExecWait(N(EVS_JumpSupport_E))
    Return
    End
};

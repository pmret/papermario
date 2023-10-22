#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_auto_jump

#include "battle/common/move/JumpSupport.inc.c"

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_AUTO_SUCCEED_ACTION, TRUE)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplA))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplB))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplC))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplA) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(SetActionCommandMode, 3)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LVar0)
            EVT_IF_LT(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActionResult, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 24, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    EVT_CALL(func_80274A18, 24, 3)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplB) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActionResult, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 37, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(func_802752AC, 20, 4)
    EVT_WAIT(7)
    EVT_CALL(func_802752AC, 3, 5)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplC) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActionResult, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_28)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 25, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    EVT_CALL(func_80275F00, 25, 4)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

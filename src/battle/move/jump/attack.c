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

extern EvtScript N(EVS_UseMove_Normal);
extern EvtScript N(EVS_UseMove_Super);
extern EvtScript N(EVS_UseMove_Ultra);
extern EvtScript N(EVS_UseMove_Tutorial);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetBattleFlags2, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS2_DOING_JUMP_TUTORIAL)
        EVT_EXEC_WAIT(N(EVS_UseMove_Tutorial))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseMove_Normal))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseMove_Super))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseMove_Ultra))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_Normal) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_EQ(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
        EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_WAIT_INPUT)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LVar0)
            EVT_IF_LT(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
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
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, ACTION_COMMAND_MODE_NOT_LEARNED)
        EVT_WAIT(1)
    EVT_END_IF
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
            // missed action command, end the script here
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            // successful action command, continue with script
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

EvtScript N(EVS_UseMove_Super) = {
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_Ultra) = {
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

extern EvtScript N(EVS_FirstStrike_Normal);
extern EvtScript N(EVS_FirstStrike_Super);
extern EvtScript N(EVS_FirstStrike_Ultra);

EvtScript N(EVS_FirstStrike) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_FirstStrike_Normal))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_FirstStrike_Super))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_FirstStrike_Ultra))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FirstStrike_Normal) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 40)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar0, LVar3)
    EVT_SUB(LVar0, 20)
    EVT_DIVF(LVar0, EVT_FLOAT(10.588))
    EVT_ADDF(LVar0, 15)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CALL(N(GetJumpDamage))
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FirstStrike_Super) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 40)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_C))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_37)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(func_802752AC, LVarA, 0)
    EVT_WAIT(7)
    EVT_CALL(func_802752AC, 3, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_34)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FirstStrike_Ultra) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 40)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_D))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_38)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80275F00, LVarA, 0)
    EVT_SET(LVarA, 4)
    EVT_CALL(func_80275F00, LVarA, 1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

extern EvtScript N(EVS_UseBerserker_Normal);
extern EvtScript N(EVS_UseBerserker_Super);
extern EvtScript N(EVS_UseBerserker_Ultra);

EvtScript N(EVS_UseBerserker) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Normal))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Super))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Ultra))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBerserker_Normal) = {
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

EvtScript N(EVS_UseBerserker_Super) = {
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBerserker_Ultra) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
    EVT_CALL(SetActionResult, LVarF)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_Tutorial) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_Approach))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -5, 10, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
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
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(1)
    EVT_END_IF
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

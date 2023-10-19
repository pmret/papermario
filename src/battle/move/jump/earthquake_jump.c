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
    EVT_SET(LFlagA, FALSE)
    EVT_CALL(ShowActionHud, TRUE)
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
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SUB(LVar0, 20)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LVar0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, 2)
    EVT_CALL(action_command_jump_start, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_LABEL(2)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SWITCH(LVarC)
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
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActionResult, LVarE)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 26)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_80274A18, 24, 3)
    EVT_ELSE
        EVT_CALL(func_80274A18, 24, 4)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GT(LVarF, 3)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 3)
    EVT_CALL(N(func_802A10E4_785C04))
    EVT_IF_GT(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(11)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EVT_END_SWITCH
    EVT_CALL(SetActionResult, LVarE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_SWITCH(LVarC)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplB) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SUB(LVar0, 20)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LVar0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_EXEC_WAIT(N(EVS_CheckForAPress))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, 2)
    EVT_CALL(action_command_jump_start, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_LABEL(2)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SWITCH(LVarC)
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
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActionResult, LVarE)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 39)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_802752AC, 20, 3)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 6)
    EVT_ELSE
        EVT_CALL(func_802752AC, 20, 4)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 5)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GT(LVarF, 4)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 4)
    EVT_CALL(N(func_802A10E4_785C04))
    EVT_IF_GT(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(11)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EVT_END_SWITCH
    EVT_CALL(SetActionResult, LVarE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SWITCH(LVarC)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplC) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SUB(LVar0, 20)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LVar0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_EXEC_WAIT(N(EVS_CheckForAPress))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, 2)
    EVT_CALL(action_command_jump_start, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioB1_Stomp, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_LABEL(2)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SWITCH(LVarC)
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
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActionResult, LVarE)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_28)
        EVT_WAIT(5)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 27)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, 30, 0, 0)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_80275F00, 25, 2)
    EVT_ELSE
        EVT_CALL(func_80275F00, 25, 4)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(10)
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GT(LVarF, 5)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 5)
    EVT_CALL(N(func_802A10E4_785C04))
    EVT_IF_GT(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetPlayerActionSuccess, LVarB)
    EVT_SET(LVar9, 0)
    EVT_LABEL(11)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_NICE_HIT)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT | BS_FLAGS1_NO_RATING)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVarC, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_3)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_JUMP_COMBO_4)
    EVT_END_SWITCH
    EVT_CALL(SetActionResult, LVarE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_LT(LVar9, LVar0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SWITCH(LVarC)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

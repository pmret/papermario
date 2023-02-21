#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"

s32 N(D_802A10F0)[] = {
    9, 3, 9, 3, 9, 3, 8, 3,
    7, 3, 6, 2, 5, 2, 4, 2,
};

#include "world/common/todo/UnkMoveFunc1.inc.c"

EvtScript N(EVS_CheckForAPress) = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    EVT_LOOP(5)
        EVT_CALL(CheckButtonPress, BUTTON_A, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_A) = {
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LVar0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(EVS_CheckForAPress))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_B) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    EVT_IF_GT(LVar6, LVar7)
        EVT_SUB(LVar6, LVar7)
    EVT_ELSE
        EVT_SUB(LVar7, LVar6)
        EVT_SET(LVar6, LVar7)
    EVT_END_IF
    EVT_SUB(LVar6, 20)
    EVT_DIVF(LVar6, EVT_FLOAT(10.588))
    EVT_ADDF(LVar6, 15)
    EVT_SET(LVarA, LVar6)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_C) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    EVT_IF_GT(LVar6, LVar7)
        EVT_SUB(LVar6, LVar7)
    EVT_ELSE
        EVT_SUB(LVar7, LVar6)
        EVT_SET(LVar6, LVar7)
    EVT_END_IF
    EVT_SUB(LVar6, 20)
    EVT_DIVF(LVar6, EVT_FLOAT(22.5))
    EVT_ADDF(LVar6, 15)
    EVT_SET(LVarA, LVar6)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_D) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    EVT_IF_GT(LVar6, LVar7)
        EVT_SUB(LVar6, LVar7)
    EVT_ELSE
        EVT_SUB(LVar7, LVar6)
        EVT_SET(LVar6, LVar7)
    EVT_END_IF
    EVT_SUB(LVar6, 20)
    EVT_DIVF(LVar6, EVT_FLOAT(18.0))
    EVT_ADDF(LVar6, 22)
    EVT_SET(LVarA, LVar6)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_E) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.3))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(5)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_F) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_G) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_H) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_I) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Hurt, ANIM_Mario1_Hurt, ANIM_Mario1_Land)
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 8, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(func_80273444, 4, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_J) = {
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, 0, 0, ANIM_Mario1_SpinFall)
    EVT_CALL(PlayerLandJump)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_SpinFall)
    EVT_WAIT(2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
    EVT_WAIT(20)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_K) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_L) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_C))
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, 14)
    EVT_ADD(LVarB, -3)
    EVT_CALL(action_command_jump_start, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_37)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(func_802752AC, LVarA, 0)
    EVT_WAIT(7)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(func_802752AC, 3, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802752AC, 5, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpSupport_M) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_D))
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(D_802A10F0)))
    EVT_SET(LVarB, LVarA)
    EVT_SUB(LVarB, 4)
    EVT_ADD(LVarB, -3)
    EVT_CALL(action_command_jump_start, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_38)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioW2_Carried, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80275F00, LVarA, 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_SET(LVar9, 0)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SET(LVar9, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Stomp)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
        EVT_CALL(action_command_jump_init)
        EVT_CALL(action_command_jump_start, 13, 3)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_39)
        EVT_CALL(func_80275F00, 15, 2)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
        EVT_CALL(action_command_jump_init)
        EVT_CALL(action_command_jump_start, 2, 3)
        EVT_CALL(func_80275F00, 4, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

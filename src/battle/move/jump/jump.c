#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"

#define NAMESPACE battle_move_jump

extern EvtScript D_802A4018_740878;
extern EvtScript D_802A2720_73EF80;
extern EvtScript D_802A2ABC_73F31C;
extern EvtScript D_802A2DE8_73F648;
extern EvtScript D_802A3188_73F9E8;
extern EvtScript D_802A3378_73FBD8;
extern EvtScript D_802A34EC_73FD4C;
extern EvtScript D_802A36D8_73FF38;
extern EvtScript D_802A39C4_740224;
extern EvtScript D_802A3CF0_740550;

s32 D_802A1140_73D9A0[] = {
    9, 3, 9, 3,
    9, 3, 8, 3,
    7, 3, 6, 2,
    5, 2, 4, 2,
};

#include "world/common/UnkMoveFunc1.inc.c"

EvtScript N(CheckForAPress) = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_BEFORE_JUMP)
    EVT_LOOP(5)
        EVT_CALL(CheckButtonPress, A_BUTTON, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(MoveToJump) = {
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LVar0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(CheckForAPress))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_BEFORE_JUMP)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1370_73DBD0 = {
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
    EVT_DIVF(LVar6, EVT_FLOAT(10.5888671875))
    EVT_ADDF(LVar6, 15)
    EVT_SET(LVarA, LVar6)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1458_73DCB8 = {
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

EvtScript D_802A1540_73DDA0 = {
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

EvtScript D_802A1628_73DE88 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.3))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(5)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1814_73E074 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1A00_73E260 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1BEC_73E44C = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1DD8_73E638 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_FALL_BACK, ANIM_Mario_FALL_BACK, ANIM_Mario_10009)
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LVar0, 0, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 8, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(func_80273444, 4, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A203C_73E89C = {
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, 0, 0, ANIM_Mario_1000C)
    EVT_CALL(PlayerLandJump)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_1000C)
    EVT_WAIT(2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GET_UP)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_DUST_OFF)
    EVT_WAIT(20)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A21D4_73EA34 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(MoveToJump))
    EVT_EXEC_WAIT(D_802A1370_73DBD0)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_30000)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2280 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(MoveToJump))
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(D_802A1458_73DCB8)
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, 14)
    EVT_ADD(LVarB, -3)
    EVT_CALL(func_802A9120_421B10, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_37)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_Mario_1000A, ANIM_Mario_1000B)
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

EvtScript D_802A23D4_73EC34 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(MoveToJump))
    EVT_EXEC_WAIT(D_802A1540_73DDA0)
    EVT_CALL(func_8026919C, EVT_PTR(D_802A1140_73D9A0))
    EVT_SET(LVarB, LVarA)
    EVT_SUB(LVarB, 4)
    EVT_ADD(LVarB, -3)
    EVT_CALL(func_802A9120_421B10, LVarB, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_38)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, 524288, ANIM_Mario_30000)
    EVT_CALL(func_80275F00, LVarA, 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_SET(LVar9, 0)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SET(LVar9, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30000)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
        EVT_CALL(action_command_jump_CreateHudElements)
        EVT_CALL(func_802A9120_421B10, 13, 3)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_39)
        EVT_CALL(func_80275F00, 15, 2)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
        EVT_CALL(action_command_jump_CreateHudElements)
        EVT_CALL(func_802A9120_421B10, 2, 3)
        EVT_CALL(func_80275F00, 4, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2650_73EEB0 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetBattleFlags2, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS2_200)
        EVT_EXEC_WAIT(D_802A4018_740878)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_802A2720_73EF80)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A2ABC_73F31C)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A2DE8_73F648)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2720_73EF80 = {
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
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
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_1000C)
    EVT_CALL(func_80274A18, 24, 3)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2ABC_73F31C = {
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 37, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_Mario_1000A, ANIM_Mario_1000B)
    EVT_CALL(func_802752AC, 20, 4)
    EVT_WAIT(7)
    EVT_CALL(func_802752AC, 3, 5)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2DE8_73F648 = {
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_28)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 25, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR_STILL, ANIM_Mario_1000C)
    EVT_CALL(func_80275F00, 25, 4)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A30F4_73F954 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_802A3188_73F9E8)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A3378_73FBD8)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A34EC_73FD4C)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ApiStatus N(GetJumpDamage)(Evt* script, s32 isInitialCall) {
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

EvtScript D_802A3188_73F9E8 = {
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
    EVT_DIVF(LVar0, EVT_FLOAT(10.5888671875))
    EVT_ADDF(LVar0, 15)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_30000)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CALL(N(GetJumpDamage))
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, LVarF, 48)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3378_73FBD8 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 40)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(D_802A1458_73DCB8)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_37)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_Mario_1000A, ANIM_Mario_1000B)
    EVT_CALL(func_802752AC, LVarA, 0)
    EVT_WAIT(7)
    EVT_CALL(func_802752AC, 3, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_34)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 4, 48)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A34EC_73FD4C = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 40)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(D_802A1540_73DDA0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_38)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR_STILL, ANIM_Mario_30000)
    EVT_CALL(func_80275F00, LVarA, 0)
    EVT_SET(LVarA, 4)
    EVT_CALL(func_80275F00, LVarA, 1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 6, 48)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3644_73FEA4 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_802A36D8_73FF38)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A39C4_740224)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A3CF0_740550)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_802A36D8_73FF38 = {
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_1000C)
    EVT_CALL(func_80274A18, 24, 3)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A39C4_740224 = {
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 37, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_Mario_1000A, ANIM_Mario_1000B)
    EVT_CALL(func_802752AC, 20, 4)
    EVT_WAIT(7)
    EVT_CALL(func_802752AC, 3, 5)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 2, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3CF0_740550 = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(D_802A21D4_73EA34)
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_28)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 25, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR_STILL, ANIM_Mario_1000C)
    EVT_CALL(func_80275F00, 25, 4)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 3, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A4018_740878 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(MoveToJump))
    EVT_EXEC_WAIT(D_802A1370_73DBD0)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -5, 10, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_30000)
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
    EVT_CALL(PlayerTestEnemy, LVar0, 128, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_EXEC_WAIT(D_802A203C_73E89C)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A00_73E260)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_Mario_1000C)
    EVT_CALL(func_80274A18, 24, 3)
    EVT_WAIT(1)
    EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
    EVT_CALL(PlayerDamageEnemy, LVar0, 128, 0, 0, 1, 224)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(D_802A1628_73DE88)
    EVT_RETURN
    EVT_END
};

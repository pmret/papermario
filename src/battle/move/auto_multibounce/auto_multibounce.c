#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"

#define NAMESPACE battle_move_auto_multibounce

extern EvtScript N(D_802A26A8);
extern EvtScript N(D_802A2EC0);
extern EvtScript N(D_802A372C);

s32 N(D_802A10F0)[] = {
    9, 3, 9, 3, 9, 3, 8, 3,
    7, 3, 6, 2, 5, 2, 4, 2,
};

#include "world/common/UnkMoveFunc1.inc.c"

EvtScript N(CheckForAPress) = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_BEFORE_JUMP)
    EVT_LOOP(5)
        EVT_CALL(CheckButtonPress, A_BUTTON, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A11AC) = {
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_SUB(LocalVar(3), EVT_FLOAT(70.0))
    EVT_IF_LT(LocalVar(0), LocalVar(3))
        EVT_SET(LocalVar(3), LocalVar(0))
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(CancelablePlayerRunToGoal, 0, LocalVar(0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(CheckForAPress))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_BEFORE_JUMP)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A1320) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(6), LocalVar(7), LocalVar(8))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_IF_GT(LocalVar(6), LocalVar(7))
        EVT_SUB(LocalVar(6), LocalVar(7))
    EVT_ELSE
        EVT_SUB(LocalVar(7), LocalVar(6))
        EVT_SET(LocalVar(6), LocalVar(7))
    EVT_END_IF
    EVT_SUB(LocalVar(6), 20)
    EVT_DIVF(LocalVar(6), EVT_FLOAT(10.5888671875))
    EVT_ADDF(LocalVar(6), 15)
    EVT_SET(LocalVar(10), LocalVar(6))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A1408) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(6), LocalVar(7), LocalVar(8))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_IF_GT(LocalVar(6), LocalVar(7))
        EVT_SUB(LocalVar(6), LocalVar(7))
    EVT_ELSE
        EVT_SUB(LocalVar(7), LocalVar(6))
        EVT_SET(LocalVar(6), LocalVar(7))
    EVT_END_IF
    EVT_SUB(LocalVar(6), 20)
    EVT_DIVF(LocalVar(6), EVT_FLOAT(22.5))
    EVT_ADDF(LocalVar(6), 15)
    EVT_SET(LocalVar(10), LocalVar(6))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A14F0) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(6), LocalVar(7), LocalVar(8))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_IF_GT(LocalVar(6), LocalVar(7))
        EVT_SUB(LocalVar(6), LocalVar(7))
    EVT_ELSE
        EVT_SUB(LocalVar(7), LocalVar(6))
        EVT_SET(LocalVar(6), LocalVar(7))
    EVT_END_IF
    EVT_SUB(LocalVar(6), 20)
    EVT_DIVF(LocalVar(6), EVT_FLOAT(18.0))
    EVT_ADDF(LocalVar(6), 22)
    EVT_SET(LocalVar(10), LocalVar(6))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A15D8) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 40)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.3))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LocalVar(0), 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(5)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A17C4) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 50)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LocalVar(0), 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A19B0) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 40)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LocalVar(0), 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A1B9C) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.8))
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LocalVar(0), 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT(2)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A1D88) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 60)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_FALL_BACK, ANIM_FALL_BACK, ANIM_10009)
    EVT_CALL(N(UnkMoveFunc1))
    EVT_CALL(func_80273444, LocalVar(0), 0, 0)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    EVT_CALL(func_80273444, 8, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(func_80273444, 6, 0, 2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(func_80273444, 4, 0, 2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A1FEC) = {
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, 0, 0, ANIM_1000C)
    EVT_CALL(PlayerLandJump)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1000C)
    EVT_WAIT(2)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GET_UP)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_DUST_OFF)
    EVT_WAIT(20)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(func_802693F0)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(func_80276EFC)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A2184) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(D_802A11AC))
    EVT_EXEC_WAIT(N(D_802A1320))
    EVT_CALL(func_802A9120_421B10, LocalVar(10), 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_30000 )
    EVT_CALL(func_80274A18, LocalVar(10), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A2230) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(D_802A11AC))
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(N(D_802A1408))
    EVT_SET(LocalVar(11), LocalVar(10))
    EVT_ADD(LocalVar(11), 14)
    EVT_ADD(LocalVar(11), -3)
    EVT_CALL(func_802A9120_421B10, LocalVar(11), 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_37)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_1000A, ANIM_1000B)
    EVT_CALL(func_802752AC, LocalVar(10), 0)
    EVT_WAIT(7)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(func_802752AC, 3, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802752AC, 5, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A2384) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(D_802A11AC))
    EVT_EXEC_WAIT(N(D_802A14F0))
    EVT_CALL(func_8026919C, EVT_ADDR(N(D_802A10F0)))
    EVT_SET(LocalVar(11), LocalVar(10))
    EVT_SUB(LocalVar(11), 4)
    EVT_ADD(LocalVar(11), -3)
    EVT_CALL(func_802A9120_421B10, LocalVar(11), 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_38)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, 524288, 196608)
    EVT_CALL(func_80275F00, LocalVar(10), 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_SET(LocalVar(9), 0)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_IF_GT(LocalVar(0), 0)
        EVT_SET(LocalVar(9), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030000)
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

EvtScript N(D_802A2600) = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_1000, 1)
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(D_802A26A8))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(D_802A2EC0))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(D_802A372C))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A26A8) = {
    EVT_EXEC_WAIT(N(D_802A2184))
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LocalVar(14))
    EVT_ADD(LocalVar(15), 1)
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_SUB(LocalVar(0), 1)
    EVT_IF_EQ(LocalVar(15), LocalVar(0))
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(func_802694A4, 0)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(D_802A1320))
    EVT_ADD(LocalVar(10), 5)
    EVT_CALL(func_802A9120_421B10, LocalVar(10), 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_1000C)
    EVT_IF_EQ(LocalVar(15), 1)
        EVT_CALL(func_80274A18, LocalVar(10), 3)
    EVT_ELSE
        EVT_CALL(func_80274A18, LocalVar(10), 4)
    EVT_END_IF
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 346, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 1, 240)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(15))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LocalVar(14))
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LocalVar(15), 1)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_GE(LocalVar(15), LocalVar(0))
        EVT_EXEC_WAIT(N(D_802A17C4))
        EVT_RETURN
    EVT_END_IF
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A2EC0) = {
    EVT_EXEC_WAIT(N(D_802A2184))
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LocalVar(14))
    EVT_SET(LocalFlag(0), 0)
    EVT_SET(LocalVar(15), 0)
    EVT_ADD(LocalVar(15), 1)
    EVT_LABEL(10)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_SUB(LocalVar(0), 1)
    EVT_IF_EQ(LocalVar(15), LocalVar(0))
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(func_802694A4, 0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(func_802A9120_421B10, 37, 3)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_1000A, ANIM_1000B)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_IF_EQ(LocalVar(15), 1)
        EVT_CALL(func_802752AC, 20, 3)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 6)
    EVT_ELSE
        EVT_CALL(func_802752AC, 20, 4)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 5)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, 0)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 347, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 2, 240)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(15))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LocalVar(14))
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LocalVar(15), 1)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_GE(LocalVar(15), LocalVar(0))
        EVT_EXEC_WAIT(N(D_802A19B0))
        EVT_RETURN
    EVT_END_IF
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802A372C) = {
    EVT_EXEC_WAIT(N(D_802A2184))
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LocalVar(14))
    EVT_SET(LocalFlag(0), 0)
    EVT_SET(LocalVar(15), 0)
    EVT_ADD(LocalVar(15), 1)
    EVT_LABEL(20)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_SUB(LocalVar(0), 1)
    EVT_IF_EQ(LocalVar(15), LocalVar(0))
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(func_802694A4, 0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(func_802A9120_421B10, 25, 3)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR_STILL, ANIM_1000C)
    EVT_IF_EQ(LocalVar(15), 1)
        EVT_CALL(func_80275F00, 25, 2)
    EVT_ELSE
        EVT_CALL(func_80275F00, 25, 4)
    EVT_END_IF
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 128, 0, 0, 1, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_EXEC_WAIT(N(D_802A1FEC))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, 3, 348, 0)
                EVT_CALL(PlayerDamageEnemy, LocalVar(0), 553648256, 0, 0, 3, 240)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(15))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LocalVar(14))
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(D_802A19B0))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(D_802A15D8))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LocalVar(15), 1)
    EVT_CALL(GetTargetListLength, LocalVar(0))
    EVT_IF_GE(LocalVar(15), LocalVar(0))
        EVT_EXEC_WAIT(N(D_802A19B0))
        EVT_RETURN
    EVT_END_IF
    EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

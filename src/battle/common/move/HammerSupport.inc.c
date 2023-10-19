#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/hammer.h"
#include "sprite/player.h"

#include "world/common/todo/IsBerserkerEquipped.inc.c"
#include "world/common/todo/ShouldMovesAutoSucceed.inc.c"

EvtScript N(EVS_HammerSupport_A) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 32)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSupport_B) = {
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, -33, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSupport_C) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSupport_D) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSupport_E) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSupport_F) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PullBack)
    EVT_WAIT(4)
    EVT_CALL(action_command_hammer_start, 0, 36, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold1)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold2)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Swing)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_ReturnHome_A) = {
    EVT_CALL(PlayerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_ReturnHome_B) = {
    EVT_CALL(PlayerYieldTurn)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_ReturnHome_C) = {
    EVT_CALL(PlayerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_RESET)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBasicHammer) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_C))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PullBack)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_NE(LVar0, HIT_RESULT_HIT)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold1)
        EVT_CALL(GetActionCommandMode, LVar0)
        EVT_IF_LT(LVar0, 2)
            EVT_CALL(N(ShouldMovesAutoSucceed))
            EVT_IF_EQ(LVar0, 0)
                EVT_LOOP(45)
                    EVT_WAIT(1)
                    EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
                    EVT_IF_NE(LVar0, FALSE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVarD, 6)
        EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionQuality, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold2)
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
            EVT_CALL(GetActionCommandMode, LVar0)
            EVT_IF_LT(LVar0, 2)
                EVT_WAIT(1)
                EVT_CALL(GetActionSuccess, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_IF
    EVT_ELSE
        EVT_CALL(action_command_hammer_start, 0, LVar1, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold1)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold2)
        EVT_WAIT(5)
    EVT_END_IF
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PreSwing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSuperHammer) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_D))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_PullBack)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Hold1)
        EVT_CALL(N(ShouldMovesAutoSucceed))
        EVT_IF_EQ(LVar0, HIT_RESULT_HIT)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
                EVT_IF_NE(LVar0, FALSE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LVarD, 6)
        EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionQuality, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Hold2)
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
            EVT_WAIT(1)
            EVT_CALL(GetActionSuccess, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_ELSE
        EVT_CALL(action_command_hammer_start, 0, LVar1, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Hold1)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Hold2)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_PreSwing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseUltraHammer) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_E))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_PullBack)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Hold1)
        EVT_CALL(N(ShouldMovesAutoSucceed))
        EVT_IF_EQ(LVar0, HIT_RESULT_HIT)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
                EVT_IF_NE(LVar0, FALSE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LVarD, 6)
        EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionQuality, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Hold2)
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
            EVT_WAIT(1)
            EVT_CALL(GetActionSuccess, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_ELSE
        EVT_CALL(action_command_hammer_start, 0, LVar1, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Hold1)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Hold2)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_PreSwing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_UseBasicQuake) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_B))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_C))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PullBack)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold1)
    EVT_CALL(N(ShouldMovesAutoSucceed))
    EVT_IF_EQ(LVar0, 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LVarD, 6)
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Hold2)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActionSuccess, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash1_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_UseSuperQuake) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_B))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_D))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_PullBack)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Hold1)
    EVT_CALL(N(ShouldMovesAutoSucceed))
    EVT_IF_EQ(LVar0, 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LVarD, 6)
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActionSuccess, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash2_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hammer_UseUltraQuake) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_B))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_E))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_PullBack)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Hold1)
    EVT_CALL(N(ShouldMovesAutoSucceed))
    EVT_IF_EQ(LVar0, 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LVarD, 6)
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActionSuccess, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Smash3_Swing)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_3)
    EVT_RETURN
    EVT_END
};

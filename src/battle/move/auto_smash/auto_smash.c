#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/hammer.h"

#define NAMESPACE battle_move_auto_smash

#include "world/common/todo/IsBerserkerEquipped.inc.c"
#include "world/common/todo/ShouldMovesAutoSucceed.inc.c"

EvtScript N(EVS_802A10B0) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 32)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, 26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A118C) = {
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, -33, 0, 0)
    EVT_CALL(UseBattleCamPreset, 26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A1204) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000D)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000D)
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

EvtScript N(EVS_802A1388) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30014)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30014)
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

EvtScript N(EVS_802A150C) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001B)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001B)
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

EvtScript N(EVS_802A1690) = {
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000E)
    EVT_WAIT(4)
    EVT_CALL(action_command_hammer_start, 0, 36, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000F)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30010)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30012)
    EVT_CALL(UseBattleCamPreset, 44)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A18AC) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, 4)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A1998) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A1A64) = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, 29)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A1B40) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A10B0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A1204))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000E)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_NE(LVar0, HIT_RESULT_HIT)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000F)
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
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30010)
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
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000F)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30010)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30011)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2115)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2118)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A2000) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A10B0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A1388))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, BS_FLAGS1_10)
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30015)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LVar0, HIT_RESULT_1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30016)
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
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30017)
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
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30016)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30017)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30018)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2116)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2119)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A23E8) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A10B0))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A150C))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 0, 0, 0, BS_FLAGS1_10)
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001C)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LVar0, HIT_RESULT_1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001D)
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
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001E)
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
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001D)
        EVT_SUB(LVar1, 10)
        EVT_WAIT(LVar1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001E)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001F)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2117)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_211A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A27D0) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A118C))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A1204))
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000E)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000F)
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
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30010)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2115)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2118)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A2AFC) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A118C))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A1388))
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30015)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30016)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2116)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30018)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2119)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A2DA0) = {
    EVT_CALL(ChooseNextTarget, ITER_LAST, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(EVS_802A118C))
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_802A150C))
    EVT_CALL(UseBattleCamPreset, 43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001C)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001D)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2117)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3001F)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_211A)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(UseMove_Impl);

EvtScript N(UseMove) = {
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_AUTO_SUCCEED_ACTION, TRUE)
    EVT_CALL(ShowActionHud, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(UseMove_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(UseMove_Impl) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_802A1B40))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_802A2000))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_802A23E8))
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, BS_FLAGS1_10)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 7)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 7)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_WAIT(1)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_802A1A64))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVarF, 112)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVarE, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(EVS_802A18AC))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(EVS_802A1A64))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

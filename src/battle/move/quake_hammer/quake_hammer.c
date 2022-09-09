#include "common.h"
#include "effects.h"
#include "script_api/battle.h"
#include "battle/action_cmd/hammer.h"

#define NAMESPACE battle_move_quake_hammer

extern EvtScript D_802A3168_0073D038;

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

EvtScript D_802A10B0_73AF80 = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 32)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A118C_0073B05C = {
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, -33, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1204_0073B0D4 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000D)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000D)
    EVT_SWITCH(LocalVar(1))
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

EvtScript D_802A1388_0073B258 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030014)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030014)
    EVT_SWITCH(LocalVar(1))
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

EvtScript D_802A150C_0073B3DC = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001B)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001B)
    EVT_SWITCH(LocalVar(1))
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

EvtScript D_802A1690_0073B560 = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000E)
    EVT_WAIT(4)
    EVT_CALL(func_802A9258_422258, 0, 36, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000F)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030010)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030012)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A18AC_0073B77C = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1998_0073B868 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1A64_0073B934 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_WAIT(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A1B40 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_73AF80)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1204_0073B0D4)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000E)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000F)
        EVT_CALL(GetActionCommandMode, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 2)
            EVT_CALL(N(IsRightOnEquipped))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_LOOP(45)
                    EVT_WAIT(1)
                    EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
                    EVT_IF_NE(LocalVar(0), 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LocalVar(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LocalVar(1), 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_IF_NE(LocalVar(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030010)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_CALL(GetActionCommandMode, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 2)
            EVT_WAIT(1)
            EVT_CALL(GetActionSuccess, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LocalVar(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000F)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030010)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(GetActionCommandMode, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 2)
        EVT_CALL(SetActionCommandMode, 3)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030011)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2000_0073BED0 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_73AF80)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1388_0073B258)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030015)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030016)
        EVT_CALL(N(IsRightOnEquipped))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
                EVT_IF_NE(LocalVar(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LocalVar(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LocalVar(1), 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_IF_NE(LocalVar(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030017)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActionSuccess, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LocalVar(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030016)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030017)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030018)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A23E8 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_73AF80)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A150C_0073B3DC)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001C)
    EVT_WAIT(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001D)
        EVT_CALL(N(IsRightOnEquipped))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
                EVT_IF_NE(LocalVar(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LocalVar(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LocalVar(1), 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionResult, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_IF_NE(LocalVar(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001E)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActionSuccess, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LocalVar(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001D)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001E)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001F)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A27D0 = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073B05C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1204_0073B0D4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000E)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000F)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LocalVar(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030010)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2AFC_0073C9CC = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073B05C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1388_0073B258)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030015)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030016)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LocalVar(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030018)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2DA0_0073CC70 = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073B05C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A150C_0073B3DC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001C)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001D)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LocalVar(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 262144, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03001F)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x030020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3044_0073CF14 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_SET(LocalVar(13), 80)
            EVT_SET(LocalVar(14), 1)
            EVT_SET(LocalVar(15), 2)
            EVT_EXEC_WAIT(D_802A3168_0073D038)
        EVT_CASE_EQ(1)
            EVT_SET(LocalVar(13), 80)
            EVT_SET(LocalVar(14), 1)
            EVT_SET(LocalVar(15), 2)
            EVT_EXEC_WAIT(D_802A3168_0073D038)
        EVT_CASE_EQ(2)
            EVT_SET(LocalVar(13), 80)
            EVT_SET(LocalVar(14), 1)
            EVT_SET(LocalVar(15), 2)
            EVT_EXEC_WAIT(D_802A3168_0073D038)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3168_0073D038 = {
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_802A27D0)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A2AFC_0073C9CC)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A2DA0_0073CC70)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_WAIT(8)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 24)
        EVT_ADD(LocalVar(1), 10)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LocalVar(0), LocalVar(1), LocalVar(2), 60, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LocalVar(0), LocalVar(1), LocalVar(2), 60, 8, 33, 30, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LocalVar(0), LocalVar(1), LocalVar(2), 60, 8, 66, 30, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(StartRumble, 9)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.7))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.4))
                EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.1))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.05))
            EVT_END_CHILD_THREAD
            EVT_CHILD_THREAD
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_ADD(LocalVar(0), 24)
                EVT_ADD(LocalVar(1), 10)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LocalVar(0), LocalVar(1), LocalVar(2), 72, 8, 0, 30, 0, 0, 0, 0, 0)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LocalVar(0), LocalVar(1), LocalVar(2), 72, 8, 24, 30, 0, 0, 0, 0, 0)
            EVT_END_CHILD_THREAD
        EVT_CASE_DEFAULT
            EVT_CALL(StartRumble, 9)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.1))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.35))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.2))
                EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.05))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.025390625))
            EVT_END_CHILD_THREAD
    EVT_END_SWITCH
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_IF_GT(LocalVar(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211B)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211C)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211D)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_END_SWITCH
    EVT_SET(LocalVar(9), 0)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 2097152, 29, 0, 0, 16)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 941623296, 25, 0, LocalVar(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 941623296, 25, 0, LocalVar(14), 48)
    EVT_END_SWITCH
    EVT_LABEL(11)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(1))
    EVT_ADD(LocalVar(9), 1)
    EVT_CALL(GetTargetListLength, LocalVar(1))
    EVT_IF_LT(LocalVar(9), LocalVar(1))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_EXEC_WAIT(D_802A1998_0073B868)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_RETURN
    EVT_END
};

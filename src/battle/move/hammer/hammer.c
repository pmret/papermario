#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/world_bombette.h"
#include "battle/action_cmd/hammer.h"

#define NAMESPACE battle_move_hammer

extern EvtSource D_802A3168_00736708;
extern EvtSource D_802A3C4C_007371EC;

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

EvtSource D_802A10B0_734650 = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 32)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A118C_0073472C = {
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, -33, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A1204_007347A4 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000D)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000D)
    EVT_SWITCH(LW(1))
        EVT_CASE_LT(3)
            EVT_WAIT_FRAMES(4)
        EVT_CASE_LT(5)
            EVT_WAIT_FRAMES(3)
        EVT_CASE_LT(7)
            EVT_WAIT_FRAMES(2)
        EVT_CASE_LT(9)
            EVT_WAIT_FRAMES(1)
        EVT_CASE_LT(11)
            EVT_WAIT_FRAMES(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A1388_00734928 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30014)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30014)
    EVT_SWITCH(LW(1))
        EVT_CASE_LT(3)
            EVT_WAIT_FRAMES(4)
        EVT_CASE_LT(5)
            EVT_WAIT_FRAMES(3)
        EVT_CASE_LT(7)
            EVT_WAIT_FRAMES(2)
        EVT_CASE_LT(9)
            EVT_WAIT_FRAMES(1)
        EVT_CASE_LT(11)
            EVT_WAIT_FRAMES(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A150C_00734AAC = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001B)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001B)
    EVT_SWITCH(LW(1))
        EVT_CASE_LT(3)
            EVT_WAIT_FRAMES(4)
        EVT_CASE_LT(5)
            EVT_WAIT_FRAMES(3)
        EVT_CASE_LT(7)
            EVT_WAIT_FRAMES(2)
        EVT_CASE_LT(9)
            EVT_WAIT_FRAMES(1)
        EVT_CASE_LT(11)
            EVT_WAIT_FRAMES(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A1690_00734C30 = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(func_802A9258_422258, 0, 36, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
    EVT_SET(LW(1), 0)
    EVT_LOOP(30)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_IF_NE(LW(1), 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                EVT_SET(LW(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(CheckButtonDown, 0x40000, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A18AC_00734E4C = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(func_802693F0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A1998_00734F38 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(func_802693F0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A1A64_00735004 = {
    EVT_CALL(func_80276EFC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_29)
    EVT_CALL(func_802693F0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(EnablePlayerBlur, -1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtSource N(D_802A1B40) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_734650)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1204_007347A4)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
        EVT_CALL(GetActionCommandMode, LW(0))
        EVT_IF_LT(LW(0), 2)
            EVT_CALL(N(IsRightOnEquipped))
            EVT_IF_EQ(LW(0), 0)
                EVT_LOOP(45)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(CheckButtonDown, 0x40000, LW(0))
                    EVT_IF_NE(LW(0), 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LW(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LW(1), 0)
        EVT_LOOP(30)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetActionResult, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_IF_NE(LW(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                    EVT_SET(LW(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_CALL(GetActionCommandMode, LW(0))
        EVT_IF_LT(LW(0), 2)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetActionSuccess, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LW(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
        EVT_SUB(LW(1), 10)
        EVT_WAIT_FRAMES(LW(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
        EVT_WAIT_FRAMES(5)
    EVT_END_IF
    EVT_CALL(GetActionCommandMode, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_CALL(SetActionCommandMode, 3)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LW(0))
            EVT_IF_LT(LW(0), 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A2000_007355A0 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_734650)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1388_00734928)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30015)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
        EVT_CALL(N(IsRightOnEquipped))
        EVT_IF_EQ(LW(0), 0)
            EVT_LOOP(45)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(CheckButtonDown, 0x40000, LW(0))
                EVT_IF_NE(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LW(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LW(1), 0)
        EVT_LOOP(30)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetActionResult, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_IF_NE(LW(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30017)
                    EVT_SET(LW(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetActionSuccess, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LW(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
        EVT_SUB(LW(1), 10)
        EVT_WAIT_FRAMES(LW(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30017)
        EVT_WAIT_FRAMES(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30018)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A23E8_735988 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A10B0_734650)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A150C_00734AAC)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001C)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(N(IsBerserkerEquipped))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
        EVT_CALL(N(IsRightOnEquipped))
        EVT_IF_EQ(LW(0), 0)
            EVT_LOOP(45)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(CheckButtonDown, 0x40000, LW(0))
                EVT_IF_NE(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LW(13), 6)
        EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_SET(LW(1), 0)
        EVT_LOOP(30)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetActionResult, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_IF_NE(LW(1), 1)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001E)
                    EVT_SET(LW(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LABEL(0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetActionSuccess, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(func_802A9258_422258, 0, LW(1), 3)
        EVT_CALL(SetActionResult, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
        EVT_SUB(LW(1), 10)
        EVT_WAIT_FRAMES(LW(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001E)
        EVT_WAIT_FRAMES(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001F)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtSource N(D_802A27D0) = {
    EVT_CALL(ChooseNextTarget, 10, LW(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073472C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1204_007347A4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LW(0), 0)
        EVT_LOOP(45)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LW(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(30)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_IF_NE(LW(1), 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                EVT_SET(LW(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionSuccess, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A2AFC_0073609C = {
    EVT_CALL(ChooseNextTarget, 10, LW(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073472C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1388_00734928)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30015)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LW(0), 0)
        EVT_LOOP(45)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LW(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
    EVT_LOOP(60)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionSuccess, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30018)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A2DA0_00736340 = {
    EVT_CALL(ChooseNextTarget, 10, LW(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A118C_0073472C)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A150C_00734AAC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001C)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
    EVT_CALL(N(IsRightOnEquipped))
    EVT_IF_EQ(LW(0), 0)
        EVT_LOOP(45)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(CheckButtonDown, 0x40000, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LW(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LW(13), 3)
    EVT_LOOP(60)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(CheckButtonDown, 0x40000, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionSuccess, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001F)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A3044_007365E4 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_SET(LW(13), 45)
            EVT_SET(LW(14), 1)
            EVT_SET(LW(15), 2)
            EVT_EXEC_WAIT(D_802A3168_00736708)
        EVT_CASE_EQ(1)
            EVT_SET(LW(13), 45)
            EVT_SET(LW(14), 2)
            EVT_SET(LW(15), 4)
            EVT_EXEC_WAIT(D_802A3168_00736708)
        EVT_CASE_EQ(2)
            EVT_SET(LW(13), 45)
            EVT_SET(LW(14), 3)
            EVT_SET(LW(15), 6)
            EVT_EXEC_WAIT(D_802A3168_00736708)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A3168_00736708 = {
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(D_802A1B40))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A2000_007355A0)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A23E8_735988)
    EVT_END_SWITCH
    EVT_CALL(GetActionSuccessCopy, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 7)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 7)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LW(0), 64, 25, 0, LW(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LW(0), 64, 25, 0, LW(14), 48)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(D_802A18AC_00734E4C)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A369C_00736C3C = {
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_SET(LW(9), 1)
            EVT_SET_CONST(LW(10), NPC_ANIM_world_bombette_normal_celebrate)
            EVT_SET_CONST(LW(11), NPC_ANIM_world_bombette_normal_anim_11)
            EVT_SET_CONST(LW(12), ANIM_30012)
        EVT_CASE_EQ(1)
            EVT_SET(LW(9), 2)
            EVT_SET_CONST(LW(10), ANIM_30016)
            EVT_SET_CONST(LW(11), ANIM_30017)
            EVT_SET_CONST(LW(12), ANIM_30019)
        EVT_CASE_EQ(2)
            EVT_SET(LW(9), 3)
            EVT_SET_CONST(LW(10), ANIM_3001D)
            EVT_SET_CONST(LW(11), ANIM_3001E)
            EVT_SET_CONST(LW(12), ANIM_30020)
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 32)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(func_8024E664, 43)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(10))
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(11))
    EVT_WAIT_FRAMES(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(12))
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
            EVT_CALL(StartRumble, 7)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.3))
            EVT_END_THREAD
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
            EVT_CALL(StartRumble, 8)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.6))
            EVT_END_THREAD
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
            EVT_CALL(StartRumble, 9)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.9))
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
    EVT_END_SWITCH
    EVT_CALL(PlayerDamageEnemy, LW(0), 64, 25, 0, LW(9), 48)
    EVT_EXEC_WAIT(D_802A18AC_00734E4C)
    EVT_RETURN
    EVT_END
};

EvtSource D_802A3B28_007370C8 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_SET(LW(13), 75)
            EVT_SET(LW(14), 1)
            EVT_SET(LW(15), 2)
            EVT_EXEC_WAIT(D_802A3C4C_007371EC)
        EVT_CASE_EQ(1)
            EVT_SET(LW(13), 66)
            EVT_SET(LW(14), 2)
            EVT_SET(LW(15), 4)
            EVT_EXEC_WAIT(D_802A3C4C_007371EC)
        EVT_CASE_EQ(2)
            EVT_SET(LW(13), 57)
            EVT_SET(LW(14), 3)
            EVT_SET(LW(15), 6)
            EVT_EXEC_WAIT(D_802A3C4C_007371EC)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource D_802A3C4C_007371EC = {
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(D_802A1B40))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(D_802A2000_007355A0)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(D_802A23E8_735988)
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 25, 0, LW(9), 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
        EVT_SWITCH(LW(1))
            EVT_CASE_EQ(0)
                EVT_CALL(StartRumble, 8)
                EVT_THREAD
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.3))
                EVT_END_THREAD
            EVT_CASE_EQ(1)
                EVT_CALL(StartRumble, 9)
                EVT_THREAD
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                EVT_END_THREAD
            EVT_CASE_EQ(2)
                EVT_CALL(StartRumble, 10)
                EVT_THREAD
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.9))
                EVT_END_THREAD
        EVT_END_SWITCH
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
        EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActionSuccessCopy, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 10)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, 8)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, 9)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, 10)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlayerTestEnemy, LW(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LW(0), 64, 25, 0, LW(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10E)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LW(0), 64, 25, 0, LW(14), 48)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(D_802A18AC_00734E4C)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(D_802A1A64_00735004)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "effects.h"
#include "script_api/battle.h"
#include "battle/action_cmd/hammer.h"

#define NAMESPACE battle_move_spin_smash

extern EvtScript D_802A3258_739AE8;
extern EvtScript D_802A3920_73A1B0;
extern EvtScript D_802A3FC4_73A854;

ApiStatus func_802A1000_737890(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->currentPos.x + 20.0f;
    f32 yPos = playerActor->currentPos.y + 15.0f;
    f32 zPos = playerActor->currentPos.z + 5.0f;

    fx_stars_spread(0, xPos, yPos, zPos, 6, 20);

    return ApiStatus_DONE2;
}

ApiStatus func_802A1074_737904(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->currentPos.x + 20.0f;
    f32 yPos = playerActor->currentPos.y + 15.0f;
    f32 zPos = playerActor->currentPos.z + 5.0f;

    fx_steam_burst(0, xPos, yPos, zPos, 1.0f, 20);

    return ApiStatus_DONE2;
}

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

EvtScript D_802A1190_737A20 = {
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

EvtScript D_802A126C_737AFC = {
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, -33, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_26)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A12E4_737B74 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000D)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000D)
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

EvtScript D_802A1468_737CF8 = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30014)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30014)
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

EvtScript D_802A15EC_737E7C = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001B)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001B)
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

EvtScript D_802A1770_738000 = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT(4)
    EVT_CALL(func_802A9258_422258, 0, 36, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), TRUE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_44)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A198C_73821C = {
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

EvtScript D_802A1A78_738308 = {
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

EvtScript D_802A1B44_7383D4 = {
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

EvtScript D_802A1C20_7384B0 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A12E4_737B74)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT(4)
    EVT_CALL(battle_move_spin_smash_IsBerserkerEquipped)
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
        EVT_CALL(GetActionCommandMode, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 2)
            EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_LOOP(45)
                    EVT_WAIT(1)
                    EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
                    EVT_IF_NE(LocalVar(0), FALSE)
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
                EVT_IF_NE(LocalVar(1), TRUE)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), FALSE)
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
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2115)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A20E0_738970 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1468_737CF8)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30015)
    EVT_WAIT(4)
    EVT_CALL(battle_move_spin_smash_IsBerserkerEquipped)
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
        EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
                EVT_IF_NE(LocalVar(0), FALSE)
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
                EVT_IF_NE(LocalVar(1), TRUE)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30017)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), FALSE)
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
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30017)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30018)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2116)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A24C8_738D58 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A15EC_737E7C)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 0, 0, 0, 16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001C)
    EVT_WAIT(4)
    EVT_CALL(battle_move_spin_smash_IsBerserkerEquipped)
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
        EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
                EVT_IF_NE(LocalVar(0), FALSE)
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
                EVT_IF_NE(LocalVar(1), TRUE)
                    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001E)
                    EVT_SET(LocalVar(1), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), FALSE)
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
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
        EVT_SUB(LocalVar(1), 10)
        EVT_WAIT(LocalVar(1))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001E)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001F)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2117)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A28B0_739140 = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A126C_737AFC)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A12E4_737B74)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000E)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3000F)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
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
            EVT_IF_NE(LocalVar(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30010)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30011)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30012)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2118)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2BDC_73946C = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A126C_737AFC)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A1468_737CF8)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30015)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30016)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LocalVar(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30018)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30019)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2119)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A2E80_739710 = {
    EVT_CALL(ChooseNextTarget, 10, LocalVar(0))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_EXEC_WAIT(D_802A126C_737AFC)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_EXEC_WAIT(D_802A15EC_737E7C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(AddBattleCamZoom, 80)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001C)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001D)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_ADD(LocalVar(13), 6)
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_3001F)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30020)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211A)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3124_7399B4 = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(func_80269EAC, 2)
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_SET(LocalVar(13), 60)
            EVT_SET(LocalVar(14), 1)
            EVT_SET(LocalVar(15), 2)
            EVT_EXEC_WAIT(D_802A3258_739AE8)
        EVT_CASE_EQ(1)
            EVT_SET(LocalVar(13), 60)
            EVT_SET(LocalVar(14), 2)
            EVT_SET(LocalVar(15), 4)
            EVT_EXEC_WAIT(D_802A3920_73A1B0)
        EVT_CASE_EQ(2)
            EVT_SET(LocalVar(13), 60)
            EVT_SET(LocalVar(14), 3)
            EVT_SET(LocalVar(15), 6)
            EVT_EXEC_WAIT(D_802A3FC4_73A854)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3258_739AE8 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040000)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040000)
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
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 25, 0, LocalVar(9), 16)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040001)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040002)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040003)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040004)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040005)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, 7)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211E)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(D_802A1B44_7383D4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(14), 48)
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_EXEC_WAIT(D_802A1A78_738308)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LocalVar(0), 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_EXEC_WAIT(D_802A1A78_738308)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3920_73A1B0 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040006)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040006)
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
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040007)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040008)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), FALSE)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040009)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000A)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000B)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x211F)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(D_802A1B44_7383D4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(14), 48)
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_EXEC_WAIT(D_802A1A78_738308)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LocalVar(0), 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_EXEC_WAIT(D_802A1A78_738308)
    EVT_RETURN
    EVT_END
};

EvtScript D_802A3FC4_73A854 = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(D_802A1190_737A20)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000C)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000C)
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
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_43)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x10B)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000D)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000E)
    EVT_CALL(battle_move_spin_smash_IsRightOnEquipped)
    EVT_IF_EQ(LocalVar(0), FALSE)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
            EVT_IF_NE(LocalVar(0), FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(func_802A9258_422258, 0, LocalVar(13), 3)
    EVT_CALL(SetActionResult, 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_IF_NE(LocalVar(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x04000F)
                EVT_SET(LocalVar(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetActionSuccess, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040010)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x040011)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, 9)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x2120)
    EVT_CALL(PlayerTestEnemy, LocalVar(0), 64, 25, 0, 0, 16)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(D_802A1B44_7383D4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DidActionSucceed, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_GT(0)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LocalVar(0), 603979840, 25, 0, LocalVar(14), 48)
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_EXEC_WAIT(D_802A1A78_738308)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LocalVar(0), 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_EXEC_WAIT(D_802A1A78_738308)
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_spin_smash

API_CALLABLE(func_802A1000_737890) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->curPos.x + 20.0f;
    f32 yPos = playerActor->curPos.y + 15.0f;
    f32 zPos = playerActor->curPos.z + 5.0f;

    fx_stars_spread(0, xPos, yPos, zPos, 6, 20);

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A1074_737904) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->curPos.x + 20.0f;
    f32 yPos = playerActor->curPos.y + 15.0f;
    f32 zPos = playerActor->curPos.z + 5.0f;

    fx_steam_burst(0, xPos, yPos, zPos, 1.0f, 20);

    return ApiStatus_DONE2;
}

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove1_Impl);
extern EvtScript N(EVS_UseMove2_Impl);
extern EvtScript N(EVS_UseMove3_Impl);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetDamageSource, DMG_SRC_SPIN_SMASH)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(EVS_UseMove1_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_UseMove2_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(EVS_UseMove3_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove1_Impl) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Begin)
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
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Raise)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Hold1)
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
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Hold2)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash1_Swing)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_1)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove2_Impl) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Begin)
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
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Raise)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Hold1)
    EVT_CALL(N(ShouldMovesAutoSucceed))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Hold2)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash2_Swing)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_2)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove3_Impl) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(InitTargetIterator)
    EVT_EXEC_WAIT(N(EVS_HammerSupport_A))
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Begin)
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
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Raise)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Hold1)
    EVT_CALL(N(ShouldMovesAutoSucceed))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_LOOP(45)
            EVT_WAIT(1)
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, 1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Hold2)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_PreSwing)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_SpinSmash3_Swing)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SPIN_SMASH_3)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_WAIT(25)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(func_802A1000_737890)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A1074_737904)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SPIN_SMASH | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 18)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_power_quake

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_802A3168);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 80)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_802A3168))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 80)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_802A3168))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 80)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_802A3168))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3168) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_Hammer_UseBasicQuake))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_Hammer_UseSuperQuake))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_Hammer_UseUltraQuake))
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 24)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 0, 30, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 33, 30, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 66, 30, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.24))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.2))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.4))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.2))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.84))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.48))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.12))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.06))
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 24)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 48, 30, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 72, 30, 0, 0, 0, 0, 0)
            EVT_END_THREAD
        EVT_CASE_DEFAULT
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.7))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.4))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.1))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.05))
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 24)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                EVT_WAIT(6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 96, 8, 48, 30, 0, 0, 0, 0, 0)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 96, 8, 72, 30, 0, 0, 0, 0, 0)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_IF_GT(LVar0, FALSE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_46)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_3)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_3)
    EVT_END_SWITCH
    EVT_SET(LVar9, 0)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE_HAMMER, 29, 0, 0, 16)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(GetPlayerActionSuccess, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(FALSE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
            EVT_CASE_DEFAULT
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
        EVT_END_SWITCH
        EVT_LABEL(11)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar1)
        EVT_ADD(LVar9, 1)
        EVT_CALL(GetTargetListLength, LVar1)
        EVT_IF_LT(LVar9, LVar1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_B))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/WorldBombette.h"
#include "battle/action_cmd/hammer.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_attack

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 45)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_Impl) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseSuperHammer))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseUltraHammer))
    EVT_END_SWITCH
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_WAIT(1)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_A))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FirstStrike) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVar9, 1)
            EVT_SET_CONST(LVarA, ANIM_MarioB1_Smash1_Hold1)
            EVT_SET_CONST(LVarB, ANIM_MarioB1_Smash1_PreSwing)
            EVT_SET_CONST(LVarC, ANIM_MarioB1_Smash1_Swing)
        EVT_CASE_EQ(1)
            EVT_SET(LVar9, 2)
            EVT_SET_CONST(LVarA, ANIM_MarioB1_Smash2_Hold1)
            EVT_SET_CONST(LVarB, ANIM_MarioB1_Smash2_Hold2)
            EVT_SET_CONST(LVarC, ANIM_MarioB1_Smash2_Swing)
        EVT_CASE_EQ(2)
            EVT_SET(LVar9, 3)
            EVT_SET_CONST(LVarA, ANIM_MarioB1_Smash3_Hold1)
            EVT_SET_CONST(LVarB, ANIM_MarioB1_Smash3_Hold2)
            EVT_SET_CONST(LVarC, ANIM_MarioB1_Smash3_Swing)
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 32)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PLAYER_AIM_HAMMER)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVarA)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVarB)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVarC)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.3))
            EVT_END_THREAD
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.6))
            EVT_END_THREAD
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.9))
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_WAIT(1)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
    EVT_END_SWITCH
    EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVar9, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_A))
    EVT_RETURN
    EVT_END
};

extern EvtScript N(EVS_UseBerserker_Impl);

EvtScript N(EVS_UseBerserker) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 75)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 66)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 57)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(EVS_UseBerserker_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBerserker_Impl) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseSuperHammer))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseUltraHammer))
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar1)
            EVT_CASE_EQ(0)
                EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                EVT_THREAD
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.3))
                EVT_END_THREAD
            EVT_CASE_EQ(1)
                EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                EVT_THREAD
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                EVT_END_THREAD
            EVT_CASE_EQ(2)
                EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
                EVT_THREAD
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.9))
                EVT_END_THREAD
        EVT_END_SWITCH
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_WAIT(1)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_A))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

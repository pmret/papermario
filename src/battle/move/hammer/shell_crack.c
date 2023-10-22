#include "common.h"
#include "script_api/battle.h"
#include "effects.h"

#define NAMESPACE battle_move_shell_crack

#include "battle/common/move/HammerSupport.inc.c"

API_CALLABLE(func_802A10A4_77F2E4) {
    ActorState* playerActorState = &gBattleStatus.playerActor->state;
    s32 i;

    for (i = 0; i < 20; i++) {
        fx_floating_cloud_puff(0,
            (playerActorState->goalPos.x + (f32) rand_int(30)) - 15.0f,
            (playerActorState->goalPos.y + (f32) rand_int(20)) - 15.0f,
             playerActorState->goalPos.z + 5.0f, 1.0f, 25);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 60)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(UseMove_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3248) = {
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(UseMove_Impl) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseSuperHammer))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseUltraHammer))
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_EXEC_WAIT(N(EVS_802A3248))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(func_802A10A4_77F2E4)
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
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SHELL_CRACK, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
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
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SHELL_CRACK, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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

#include "common.h"
#include "script_api/battle.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_pound

#include "battle/common/move/HammerSupport.inc.c"

API_CALLABLE(func_802A10A4_74AE34) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, var0 + 30, var1 + 25, var2, 45.0f);
    } else {
        fx_green_impact(FALSE, var0 + 30, var1 + 25, var2, 45.0f);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetDamageSource, DMG_SRC_D_DOWN_POUND)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 50)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 50)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(UseMove_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 50)
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
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseSuperHammer))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseUltraHammer))
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, 25, 0, LVar9, 16)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
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
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_IF_GT(LVar0, FALSE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionSuccess, LVarA)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_802A10A4_74AE34, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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

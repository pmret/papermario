#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"

#define NAMESPACE battle_move_power_jump

#include "battle/common/move/JumpSupport.inc.c"

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplA))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplB))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplC))
    EVT_END_SWITCH
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A26B4) = {
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_CHILD_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplA) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_802A26B4))
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(HIT_RESULT_HIT)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_JumpSupport_F))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplB) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_802A26B4))
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(HIT_RESULT_HIT)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_JumpSupport_F))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplC) = {
    EVT_EXEC_WAIT(N(EVS_JumpSupport_InitCommand))
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_802A26B4))
    EVT_WAIT(1)
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 8, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 5, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(HIT_RESULT_HIT)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_JumpSupport_F))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

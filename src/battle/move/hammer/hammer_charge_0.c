#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_charge_0

#include "battle/common/move/HammerSupport.inc.c"

#include "world/common/todo/IsHammerMaxCharged.inc.c"

API_CALLABLE(func_802A10C8_74F1F8) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_stat_change(0, var1, var2, var3, 1.0f, 60);

    battleStatus->hammerCharge++;
    if (battleStatus->hammerCharge > 99) {
        battleStatus->hammerCharge = 99;
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_HAMMER_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_JUMP_CHARGED;

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A11CC_74F2FC) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var0 + 10, var1 + 18, var2, var3, 45);

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_802A3348);

EvtScript N(EVS_UseMove1) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 65)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(EVS_802A3348))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 65)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_802A3348))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 65)
            EVT_SET(LVarE, 4)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(EVS_802A3348))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3348) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseSuperHammer))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseBasicHammer))
    EVT_END_SWITCH
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LFlag0, FALSE)
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
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVarF, 48)
            EVT_SET(LFlag0, TRUE)
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
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVarE, 32)
            EVT_SET(LFlag0, FALSE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
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

extern EvtScript N(EVS_802A3948);
extern EvtScript N(EVS_802A3C90);
extern EvtScript N(EVS_802A3FD8);

EvtScript N(EVS_UseMove0) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_802A3948))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_802A3C90))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_802A3FD8))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3948) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer1_Charging)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(N(IsHammerMaxCharged))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 35)
        EVT_CALL(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208F)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged, ANIM_MarioB3_Hammer1_Charged)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3C90) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer2_Charging)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(N(IsHammerMaxCharged))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 35)
        EVT_CALL(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208F)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged, ANIM_MarioB3_Hammer2_Charged)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3FD8) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_CHARGE_UP)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_156)
        EVT_WAIT(8)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer3_Charging)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(func_802A11CC_74F2FC, LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(N(IsHammerMaxCharged))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 35)
        EVT_CALL(func_802A10C8_74F1F8, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208F)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged, ANIM_MarioB3_Hammer3_Charged)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_CHARGE_HAMMER, 60, 1)
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_RETURN
    EVT_END
};



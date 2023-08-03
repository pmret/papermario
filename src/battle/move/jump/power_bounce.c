#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "battle/battle.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_power_bounce

#include "battle/common/move/JumpSupport.inc.c"

s32 N(DifficultyTable)[] = {
    7, 6, 5, 4, 3, 2, 1, 0
};

s32 N(BaseHitChance) = 200;

API_CALLABLE(N(GetHitChance)) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);
    s32 powerBounceChance;

    script->varTable[0] = 99;
    powerBounceChance = targetActor->actorBlueprint->powerBounceChance;
    if (is_ability_active(ABILITY_DODGE_MASTER)) {
        powerBounceChance += 7;
    }
    N(BaseHitChance) = N(BaseHitChance) * powerBounceChance / 100;

    if (N(BaseHitChance) < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

BSS s32 N(HitCounter);

API_CALLABLE(N(InitializeHitCounter)) {
    N(HitCounter) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IncrementHitCounter)) {
    N(HitCounter) += 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StoreHitCountRecord)) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->powerBounces < N(HitCounter)) {
        playerData->powerBounces = N(HitCounter);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    EVT_SET(LFlagA, FALSE)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(N(InitializeHitCounter))
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarC, 1)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplA))
        EVT_CASE_EQ(1)
            EVT_SET(LVarC, 2)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplB))
        EVT_CASE_EQ(2)
            EVT_SET(LVarC, 3)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplC))
    EVT_END_SWITCH
    EVT_CALL(N(StoreHitCountRecord))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplA) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_CALL(action_command_jump_start, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(func_80269524, LVarE)
    EVT_CALL(N(IncrementHitCounter))
    EVT_SET(LVarD, 0)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 24)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_SUB(LVarD, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_80274A18, 24, 3)
    EVT_ELSE
        EVT_CALL(func_80274A18, 24, 4)
    EVT_END_IF
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GE(LVarF, 3)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(GetHitChance))
    EVT_IF_GE(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 64)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 224)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
            EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(N(IncrementHitCounter))
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplB) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_CALL(action_command_jump_start, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarE)
    EVT_CALL(N(IncrementHitCounter))
    EVT_SET(LVarD, 0)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_27)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 37)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_SUB(LVarD, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(EnablePlayerBlur, BLUR_DISABLE)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_802752AC, 20, 3)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 6)
    EVT_ELSE
        EVT_CALL(func_802752AC, 20, 4)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 5)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, BLUR_ENABLE)
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GT(LVarF, 3)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(GetHitChance))
    EVT_IF_GT(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 64)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 224)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
            EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(N(IncrementHitCounter))
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_ImplC) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_A))
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_CALL(action_command_jump_start, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_34)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    EVT_CALL(func_80274A18, LVarA, 0)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_80269524, LVarE)
    EVT_CALL(N(IncrementHitCounter))
    EVT_SET(LVarD, 0)
    EVT_SET(LVarF, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_28)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_35)
    EVT_END_CHILD_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(DifficultyTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 25)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_SUB(LVarD, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(EnablePlayerBlur, BLUR_DISABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    EVT_IF_EQ(LVarF, 0)
        EVT_CALL(func_80275F00, 25, 2)
    EVT_ELSE
        EVT_CALL(func_80275F00, 25, 4)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, BLUR_ENABLE)
    EVT_CALL(GetCommandAutoSuccess, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_IF_GT(LVarF, 3)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(GetHitChance))
    EVT_IF_GT(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 64)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 224)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
            EVT_CALL(PlayerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVarC, LVarD, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_236)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_237)
        EVT_CASE_EQ(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_238)
    EVT_END_SWITCH
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(N(IncrementHitCounter))
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

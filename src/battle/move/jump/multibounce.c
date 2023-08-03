#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_multibounce

#include "battle/common/move/JumpSupport.inc.c"

s32 N(DifficultyTable)[] = {
    7, 6, 5, 4, 3, 2, 1, 0
};

extern EvtScript N(EVS_UseMove_ImplA);
extern EvtScript N(EVS_UseMove_ImplB);
extern EvtScript N(EVS_UseMove_ImplC);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplA))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplB))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_UseMove_ImplC))
    EVT_END_SWITCH
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
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
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
    EVT_CALL(func_80269524, LVarE)
    EVT_ADD(LVarF, 1)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_EQ(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(ShowActionHud, FALSE)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_EXEC_WAIT(N(EVS_JumpSupport_B))
    EVT_ADD(LVarA, 5)
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_SpinFall)
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(func_80274A18, LVarA, 3)
    EVT_ELSE
        EVT_CALL(func_80274A18, LVarA, 4)
    EVT_END_IF
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15A, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 1, 240)
            EVT_END_IF
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
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(FALSE)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(TRUE)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_GE(LVarF, LVar0)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_F))
        EVT_RETURN
    EVT_END_IF
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
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
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
    EVT_CALL(func_80269524, LVarE)
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LVarF, 0)
    EVT_ADD(LVarF, 1)
    EVT_LABEL(10)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_EQ(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(ShowActionHud, FALSE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(action_command_jump_start, 37, 3)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    EVT_CALL(EnablePlayerBlur, BLUR_DISABLE)
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(func_802752AC, 20, 3)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 6)
    EVT_ELSE
        EVT_CALL(func_802752AC, 20, 4)
        EVT_WAIT(7)
        EVT_CALL(func_802752AC, 3, 5)
    EVT_END_IF
    EVT_CALL(EnablePlayerBlur, BLUR_ENABLE)
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15B, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 2, 240)
            EVT_END_IF
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
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(FALSE)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(TRUE)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_GE(LVarF, LVar0)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
        EVT_RETURN
    EVT_END_IF
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
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_235)
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
    EVT_CALL(func_80269524, LVarE)
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LVarF, 0)
    EVT_ADD(LVarF, 1)
    EVT_LABEL(20)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_EQ(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(ShowActionHud, FALSE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_40)
    EVT_CALL(action_command_jump_start, 25, 3)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_SpinFall)
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(func_80275F00, 25, 2)
    EVT_ELSE
        EVT_CALL(func_80275F00, 25, 4)
    EVT_END_IF
    EVT_CALL(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_Miss))
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 112)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 240)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 48)
            EVT_ELSE
                EVT_CALL(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_15C, SOUND_NONE)
                EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_MULTI_BOUNCE | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, 3, 240)
            EVT_END_IF
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
    EVT_CALL(DidActionSucceed, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(FALSE)
        EVT_CASE_OR_EQ(2)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(TRUE)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_EXEC_WAIT(N(EVS_JumpSupport_E))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_CALL(GetTargetListLength, LVar0)
    EVT_IF_GE(LVarF, LVar0)
        EVT_EXEC_WAIT(N(EVS_JumpSupport_G))
        EVT_RETURN
    EVT_END_IF
    EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

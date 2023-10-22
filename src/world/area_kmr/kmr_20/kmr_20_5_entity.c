#include "kmr_20.h"
#include "entity.h"

API_CALLABLE(N(SetAmbienceVolumeHalf_Entity)){
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

#include "world/common/EnableCameraFollowPlayerY.inc.c"

EvtScript N(EVS_SecretPanel_FlipBack) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_FLIP_PANEL, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(SetAmbienceVolumeHalf_Entity))
    EVT_CALL(MakeLerp, 0, -2160, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g61, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_CLOSE_PANEL, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherCamToPlayer) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring_Basement) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_IF_EQ(AF_KMR_0B, FALSE)
        EVT_CALL(PlayerJump, -110, -80, -35, 20)
        EVT_SET(AF_KMR_0B, TRUE)
    EVT_ELSE
        EVT_CALL(N(EnableCameraFollowPlayerY))
        EVT_EXEC(N(EVS_SecretPanel_FlipBack))
        EVT_CALL(PlayerJump, -150, 30, -90, 30)
        EVT_CALL(InterpPlayerYaw, 180, 0)
        EVT_SET(AF_KMR_0B, FALSE)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Luigi_JumpFromBlock) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_Luigi_1, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi_1, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Luigi_1, 1)
    EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Luigi_1, LVar0, 0, LVar2, 25)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Luigi_1, 0, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Luigi_JumpFromHighBlock) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_Luigi_1, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi_1, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Luigi_1, 1)
    EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(NpcJump0, NPC_Luigi_1, LVar0, 0, LVar2, 25)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Luigi_1, 0, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastRock) = {
    EVT_CALL(SetNpcAux, NPC_Luigi_1, 0)
    EVT_EXEC(N(EVS_Luigi_JumpFromBlock))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SmashBlock) = {
    EVT_CALL(SetNpcAux, NPC_Luigi_1, 0)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_Luigi_JumpFromBlock))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_Brick) = {
    EVT_CALL(SetNpcAux, NPC_Luigi_1, 0)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_Luigi_JumpFromHighBlock))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -150, -80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring_Basement)))
    EVT_CALL(SetEntityCullMode, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), 300, 0, 150, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_BlastRock)))
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), 300, 0, 150, 55, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_SmashBlock)))
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 300, 90, 150, 55, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_Brick)))
        EVT_CASE_LT(STORY_EPILOGUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

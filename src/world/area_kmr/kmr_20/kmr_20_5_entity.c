#include "kmr_20.h"
#include "entity.h"

API_CALLABLE(N(func_80240DD0_8ECBF0)){
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

EvtScript N(D_802456E0_8F1500) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_20AB, 0)
    EVT_CALL(N(func_80240DD0_8ECBF0))
    EVT_CALL(MakeLerp, 0, -2160, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g61, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_20AC, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802457E4_8F1604) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245848_8F1668) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(D_802457E4_8F1604), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_IF_EQ(AF_KMR_0B, FALSE)
        EVT_CALL(PlayerJump, -110, -80, -35, 20)
        EVT_SET(AF_KMR_0B, TRUE)
    EVT_ELSE
        EVT_CALL(N(UnsetCamera0MoveFlag1))
        EVT_EXEC(N(D_802456E0_8F1500))
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

EvtScript N(D_802459A0_8F17C0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_Luigi, ENEMY_FLAGS_100, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Luigi, 1)
    EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Luigi, LVar0, 0, LVar2, 25)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Luigi, 0, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245AA8_8F18C8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_Luigi, ENEMY_FLAGS_100, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Luigi, 1)
    EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(NpcJump0, NPC_Luigi, LVar0, 0, LVar2, 25)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Luigi, 0, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BC0_8F19E0) = {
    EVT_CALL(SetNpcAux, NPC_Luigi, 0)
    EVT_EXEC(N(D_802459A0_8F17C0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BF0_8F1A10) = {
    EVT_CALL(SetNpcAux, NPC_Luigi, 0)
    EVT_THREAD
        EVT_EXEC_WAIT(N(D_802459A0_8F17C0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245C30_8F1A50) = {
    EVT_CALL(SetNpcAux, NPC_Luigi, 0)
    EVT_THREAD
        EVT_EXEC_WAIT(N(D_80245AA8_8F18C8))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -150, -80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_80245848_8F1668)))
    EVT_CALL(SetEntityCullMode, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), 300, 0, 150, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(D_80245BC0_8F19E0)))
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), 300, 0, 150, 55, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(D_80245BF0_8F1A10)))
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 300, 90, 150, 55, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(D_80245C30_8F1A50)))
        EVT_CASE_LT(STORY_EPILOGUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "kmr_20.h"
#include "entity.h"

API_CALLABLE(N(SetAmbienceVolumeHalf_Entity)){
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

#include "world/common/EnableCameraFollowPlayerY.inc.c"

EvtScript N(EVS_SecretPanel_FlipBack) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_o252, SOUND_FLIP_PANEL, SOUND_SPACE_DEFAULT)
    Call(N(SetAmbienceVolumeHalf_Entity))
    Call(MakeLerp, 0, -2160, 60, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g61, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_o252, SOUND_CLOSE_PANEL, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_TetherCamToPlayer) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UseSpring_Basement) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    IfEq(AF_KMR_0B, FALSE)
        Call(PlayerJump, -110, -80, -35, 20)
        Set(AF_KMR_0B, TRUE)
    Else
        Call(N(EnableCameraFollowPlayerY))
        Exec(N(EVS_SecretPanel_FlipBack))
        Call(PlayerJump, -150, 30, -90, 30)
        Call(InterpPlayerYaw, 180, 0)
        Set(AF_KMR_0B, FALSE)
    EndIf
    Wait(30)
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_Luigi_JumpFromBlock) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetEnemyFlagBits, NPC_Luigi_1, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 0)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcVar, NPC_Luigi_1, 0, 1)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    Call(SetNpcJumpscale, NPC_Luigi_1, 1)
    Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Luigi_1, LVar0, 0, LVar2, 25)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Call(SetNpcVar, NPC_Luigi_1, 0, 2)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Luigi_JumpFromHighBlock) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetEnemyFlagBits, NPC_Luigi_1, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 0)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcVar, NPC_Luigi_1, 0, 1)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    Call(SetNpcJumpscale, NPC_Luigi_1, 1)
    Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(NpcJump0, NPC_Luigi_1, LVar0, 0, LVar2, 25)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Call(SetNpcVar, NPC_Luigi_1, 0, 2)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BlastRock) = {
    Call(SetNpcAux, NPC_Luigi_1, 0)
    Exec(N(EVS_Luigi_JumpFromBlock))
    Return
    End
};

EvtScript N(EVS_SmashBlock) = {
    Call(SetNpcAux, NPC_Luigi_1, 0)
    Thread
        ExecWait(N(EVS_Luigi_JumpFromBlock))
    EndThread
    Return
    End
};

EvtScript N(EVS_BreakBlock_Brick) = {
    Call(SetNpcAux, NPC_Luigi_1, 0)
    Thread
        ExecWait(N(EVS_Luigi_JumpFromHighBlock))
    EndThread
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_ScriptSpring), -150, -80, -50, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring_Basement)))
    Call(SetEntityCullMode, 1)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(MakeEntity, Ref(Entity_BombableRock), 300, 0, 150, 0, MAKE_ENTITY_END)
            Call(AssignScript, Ref(N(EVS_BlastRock)))
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(MakeEntity, Ref(Entity_Hammer3Block), 300, 0, 150, 55, MAKE_ENTITY_END)
            Call(AssignScript, Ref(N(EVS_SmashBlock)))
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(MakeEntity, Ref(Entity_BrickBlock), 300, 90, 150, 55, MAKE_ENTITY_END)
            Call(AssignScript, Ref(N(EVS_BreakBlock_Brick)))
        CaseLt(STORY_EPILOGUE)
    EndSwitch
    Return
    End
};

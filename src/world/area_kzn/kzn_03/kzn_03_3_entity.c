#include "kzn_03.h"
#include "entity.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

API_CALLABLE(N(IsPlayerOnFirstCliff)) {
    s32 result = -1;

    if (gPlayerStatus.lastGoodPos.y > 800.0) {
        result = 0;
    }
    if (gPlayerStatus.lastGoodPos.y < 680.0) {
        result = 1;
    }
    if (result >= 0) {
        evt_set_variable(script, MV_PlayerCliffState, result);
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_TetherCameraToPlayer) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UseSpringA) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Wait(1)
    Call(N(EnableCameraFollowPlayerY))
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, 335, 290, 360, 40)
    Call(SetPlayerFlagBits, PS_FLAG_FLYING, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_FALLING)
    Call(DisablePlayerPhysics, FALSE)
    KillThread(LVarA)
    Call(N(DisableCameraFollowPlayerY))
    Return
    End
};

EvtScript N(EVS_UseSpringB) = {
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    Call(N(EnableCameraFollowPlayerY))
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, 350, 470, 210, 40)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    KillThread(LVarA)
    Call(N(DisableCameraFollowPlayerY))
    Return
    End
};

EvtScript N(EVS_UseSpringC) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    Call(N(EnableCameraFollowPlayerY))
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    IfEq(MV_PlayerCliffState, 0)
        Call(SetPlayerJumpscale, Float(1.4))
        Call(PlayerJump, -470, 670, 71, 18)
    Else
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, -384, 870, -22, 40)
    EndIf
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    KillThread(LVarA)
    Call(N(DisableCameraFollowPlayerY))
    Return
    End
};

EvtScript N(EVS_OnBreakBlock) = {
    Set(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 365, 530, 135, 0, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_FIRE_SHIELD, 75, 290, 235, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KZN03_Item_FireShield)
    Call(MakeEntity, Ref(Entity_BrickBlock), 215, 745, -105, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 85, 770, -105, 0, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_POW_BLOCK, 85, 795, -105, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_KZN03_Item_POWBlock)
    Call(MakeEntity, Ref(Entity_YellowBlock), 35, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN03_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), -15, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN03_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_YellowBlock), -65, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN03_ItemBlock_CoinC)
    Call(MakeEntity, Ref(Entity_YellowBlock), -115, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN03_ItemBlock_CoinD)
    IfLt(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
        Call(MakeEntity, Ref(Entity_Hammer3Block), 490, 470, 210, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlock)))
        Thread
            Loop(0)
                IfGe(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_on_off, COLLIDER_FLAGS_UPPER_MASK)
        EndThread
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_on_off, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeEntity, Ref(Entity_ScriptSpring), 160, 30, 350, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpringA)))
    Call(MakeEntity, Ref(Entity_ScriptSpring), 335, 265, 360, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpringB)))
    Thread
        Call(N(IsPlayerOnFirstCliff))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), -410, 645, 120, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpringC)))
    Return
    End
};

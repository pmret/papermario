#include "omo_04.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_StoreroomKey) = {
    Set(LVarA, ITEM_STOREROOM_KEY)
    Set(LVarB, ITEM_TYPE_KEY)
    Set(GF_OMO04_Chest_StoreroomKey, TRUE)
    ExecWait(N(EVS_Chest_GetItem))
    Set(GF_MAC04_StoreroomKeyStolen, TRUE)
    Set(GB_StoryProgress, STORY_CH4_GOT_STOREROOM_KEY)
    Return
    End
};

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

EvtScript N(EVS_TetherCamToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

Vec3i N(StarBoxLaunchTargets)[] = {
    { -852,   0, -125 },
    { -887,   0,   98 },
    { -682,  80,  -77 },
    { -542,  80,   62 },
    { -647,  80,  132 },
    { -507,  80,  132 },
    {  672, 105,  132 },
    {  927,  80,  -87 },
};

EvtScript N(EVS_StarBoxLaunch_Impl) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    UseBuf(Ref(N(StarBoxLaunchTargets)))
    Loop(LVar0)
        BufRead3(LVar7, LVar8, LVar9)
    EndLoop
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Wait(1)
    Call(N(EnableCameraFollowPlayerY))
    ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, LVar7, LVar8, LVar9, 40)
    KillThread(LVarA)
    Call(N(DisableCameraFollowPlayerY))
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch1) = {
    Set(LVar0, 1) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch2) = {
    Set(LVar0, 2) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch3) = {
    Set(LVar0, 3) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch4) = {
    Set(LVar0, 4) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch5) = {
    Set(LVar0, 5) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch6) = {
    Set(LVar0, 6) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch7) = {
    Set(LVar0, 7) // entityID
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

API_CALLABLE(N(func_802402F4_DAD6F4)) {
    f32 playerVx = gPlayerStatus.curSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 playerVz = gPlayerStatus.curSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);
    script->varTable[0] = (gPlayerStatus.pos.x + playerVx);
    script->varTable[1] = (gPlayerStatus.pos.z + playerVz);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 1150, 0, 0, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO04_Chest_StoreroomKey)
    Call(AssignScript, Ref(N(EVS_OpenChest_StoreroomKey)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -892, 0, -125, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch1)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -847, 0, 98, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch2)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -722, 0, -72, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch3)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -647, 80, 62, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch4)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -607, 0, 133, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch5)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -467, 0, 133, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch6)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), 712, 0, 133, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch7)))
    Call(MakeEntity, Ref(Entity_YellowBlock), 575, 60, 60, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO04_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), 761, 60, -85, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO04_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_YellowBlock), 885, 140, -110, 0, ITEM_THUNDER_BOLT, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO04_ItemBlock_ThunderBolt)
    Call(MakeItemEntity, ITEM_COIN, -892, 110, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, -892, 130, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinB)
    Call(MakeItemEntity, ITEM_COIN, -892, 150, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinC)
    Call(MakeItemEntity, ITEM_COIN, -637, 190, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinD)
    Call(MakeItemEntity, ITEM_COIN, -614, 210, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinE)
    Call(MakeItemEntity, ITEM_COIN, -594, 220, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinF)
    Call(MakeItemEntity, ITEM_COIN, -574, 210, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinG)
    Call(MakeItemEntity, ITEM_COIN, -554, 190, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinH)
    Call(MakeItemEntity, ITEM_STAR_PIECE, 120, 180, -80, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_StarPieceA)
    Call(MakeItemEntity, ITEM_STAR_PIECE, -90, 0, -125, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_StarPieceB)
    Return
    End
};

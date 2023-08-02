#include "omo_04.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_StoreroomKey) = {
    EVT_SET(LVarA, ITEM_STOREROOM_KEY)
    EVT_SET(LVarB, ITEM_TYPE_KEY)
    EVT_SET(GF_OMO04_Chest_StoreroomKey, TRUE)
    EVT_EXEC_WAIT(N(EVS_Chest_GetItem))
    EVT_SET(GF_MAC04_StoreroomKeyStolen, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH4_GOT_STOREROOM_KEY)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"
#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

EvtScript N(EVS_TetherCamToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_USE_BUF(EVT_PTR(N(StarBoxLaunchTargets)))
    EVT_LOOP(LVar0)
        EVT_BUF_READ3(LVar7, LVar8, LVar9)
    EVT_END_LOOP
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, LVar7, LVar8, LVar9, 40)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(N(SetCamera0MoveFlag1))
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch1) = {
    EVT_SET(LVar0, 1) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch2) = {
    EVT_SET(LVar0, 2) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch3) = {
    EVT_SET(LVar0, 3) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch4) = {
    EVT_SET(LVar0, 4) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch5) = {
    EVT_SET(LVar0, 5) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch6) = {
    EVT_SET(LVar0, 6) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch7) = {
    EVT_SET(LVar0, 7) // entityID
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_802402F4_DAD6F4)) {
    f32 playerVx = gPlayerStatus.curSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 playerVz = gPlayerStatus.curSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);
    script->varTable[0] = (gPlayerStatus.pos.x + playerVx);
    script->varTable[1] = (gPlayerStatus.pos.z + playerVz);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 1150, 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO04_Chest_StoreroomKey)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_StoreroomKey)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -892, 0, -125, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch1)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -847, 0, 98, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch2)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -722, 0, -72, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch3)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -647, 80, 62, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch4)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -607, 0, 133, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch5)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -467, 0, 133, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch6)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), 712, 0, 133, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch7)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 575, 60, 60, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO04_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 761, 60, -85, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO04_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 885, 140, -110, 0, ITEM_THUNDER_BOLT, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO04_ItemBlock_ThunderBolt)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -892, 110, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -892, 130, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -892, 150, -124, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -637, 190, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -614, 210, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinE)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -594, 220, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinF)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -574, 210, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinG)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -554, 190, 62, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_CoinH)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 120, 180, -80, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_StarPieceA)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -90, 0, -125, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_StarPieceB)
    EVT_RETURN
    EVT_END
};

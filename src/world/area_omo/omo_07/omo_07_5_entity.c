#include "omo_07.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_FryingPan) = {
    EVT_SET(LVarA, ITEM_FRYING_PAN)
    EVT_SET(LVarB, ITEM_TYPE_KEY)
    EVT_SET(GF_OMO07_Chest_FryingPan, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH4_GOT_FRYING_PAN)
    EVT_EXEC_WAIT(N(EVS_Chest_GetItem))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest_DefendPlus) = EVT_OPEN_CHEST_BADGE(ITEM_DEFEND_PLUS_A, GF_OMO07_Chest_DefendPlusA);

EvtScript N(EVS_OpenChest_IcePower) = EVT_OPEN_CHEST_BADGE(ITEM_ICE_POWER, GF_OMO07_Chest_IcePower);

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

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
    { -337,  80,  -55 },
    { -472,   0,  127 },
    { -192,   0,  127 },
};

EvtScript N(EVS_StarBoxLaunch_Impl) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_USE_BUF(EVT_PTR(N(StarBoxLaunchTargets)))
    EVT_LOOP(LVar0)
        EVT_BUF_READ3(LVar7, LVar8, LVar9)
    EVT_END_LOOP
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 10)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(EnableCameraFollowPlayerY))
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, LVar7, LVar8, LVar9, 40)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(3)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(N(DisableCameraFollowPlayerY))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch1) = {
    EVT_SET(LVar0, 1)
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch2) = {
    EVT_SET(LVar0, 2)
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarBoxLaunch3) = {
    EVT_SET(LVar0, 3)
    EVT_EXEC_WAIT(N(EVS_StarBoxLaunch_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 1130, 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO07_Chest_FryingPan)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_FryingPan)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -910, 80, -100, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO07_Chest_DefendPlusA)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_DefendPlus)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 750, 0, -100, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO07_Chest_IcePower)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_IcePower)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 650, 60, -30, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO07_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -330, 0, 127, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch1)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -260, 0, 127, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch2)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -192, 80, -132, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch3)))
    EVT_RETURN
    EVT_END
};

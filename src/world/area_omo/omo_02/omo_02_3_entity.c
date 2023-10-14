#include "omo_02.h"
#include "entity.h"

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

EvtScript N(EVS_StarBoxLaunch_Impl) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
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
    EVT_CALL(PlayerJump, -290, 85, -78, 40)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(N(DisableCameraFollowPlayerY))
    EVT_WAIT(3)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(N(DisableCameraFollowPlayerY))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 300, 60, -100, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO02_ItemBlock_SleepySheep)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -200, 60, -78, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO02_HiddenItem_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -80, 89, -78, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_SHOOTING_STAR, -80, 114, -78, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_OMO02_Item_ShootingStar)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_StarBoxLauncher), -358, 0, -82, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_StarBoxLaunch_Impl)))
    EVT_RETURN
    EVT_END
};

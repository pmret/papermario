#include "omo_02.h"
#include "entity.h"

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

EvtScript N(EVS_StarBoxLaunch_Impl) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Loop(4)
        Add(LVar1, 10)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(N(EnableCameraFollowPlayerY))
    ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, -290, 85, -78, 40)
    KillThread(LVarA)
    Call(N(DisableCameraFollowPlayerY))
    Wait(3)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(N(DisableCameraFollowPlayerY))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 300, 60, -100, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO02_ItemBlock_SleepySheep)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -200, 60, -78, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO02_HiddenItem_Coin)
    Call(MakeEntity, Ref(Entity_BrickBlock), -80, 89, -78, 0, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_SHOOTING_STAR, -80, 114, -78, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_OMO02_Item_ShootingStar)
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -358, 0, -82, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch_Impl)))
    Return
    End
};

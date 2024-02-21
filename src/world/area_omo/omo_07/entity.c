#include "omo_07.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_FryingPan) = {
    Set(LVarA, ITEM_FRYING_PAN)
    Set(LVarB, ITEM_TYPE_KEY)
    Set(GF_OMO07_Chest_FryingPan, TRUE)
    Set(GB_StoryProgress, STORY_CH4_GOT_FRYING_PAN)
    ExecWait(N(EVS_Chest_GetItem))
    Return
    End
};

EvtScript N(EVS_OpenChest_DefendPlus) = EVT_OPEN_CHEST_BADGE(ITEM_DEFEND_PLUS_A, GF_OMO07_Chest_DefendPlusA);

EvtScript N(EVS_OpenChest_IcePower) = EVT_OPEN_CHEST_BADGE(ITEM_ICE_POWER, GF_OMO07_Chest_IcePower);

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
    { -337,  80,  -55 },
    { -472,   0,  127 },
    { -192,   0,  127 },
};

EvtScript N(EVS_StarBoxLaunch_Impl) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    UseBuf(Ref(N(StarBoxLaunchTargets)))
    Loop(LVar0)
        BufRead3(LVar7, LVar8, LVar9)
    EndLoop
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
    Call(PlayerJump, LVar7, LVar8, LVar9, 40)
    KillThread(LVarA)
    Wait(3)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(N(DisableCameraFollowPlayerY))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch1) = {
    Set(LVar0, 1)
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch2) = {
    Set(LVar0, 2)
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_StarBoxLaunch3) = {
    Set(LVar0, 3)
    ExecWait(N(EVS_StarBoxLaunch_Impl))
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 1130, 0, 0, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO07_Chest_FryingPan)
    Call(AssignScript, Ref(N(EVS_OpenChest_FryingPan)))
    Call(MakeEntity, Ref(Entity_Chest), -910, 80, -100, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO07_Chest_DefendPlusA)
    Call(AssignScript, Ref(N(EVS_OpenChest_DefendPlus)))
    Call(MakeEntity, Ref(Entity_Chest), 750, 0, -100, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO07_Chest_IcePower)
    Call(AssignScript, Ref(N(EVS_OpenChest_IcePower)))
    Call(MakeEntity, Ref(Entity_YellowBlock), 650, 60, -30, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO07_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -330, 0, 127, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch1)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -260, 0, 127, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch2)))
    Call(MakeEntity, Ref(Entity_StarBoxLauncher), -192, 80, -132, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_StarBoxLaunch3)))
    Return
    End
};

#include "omo_03.h"
#include "entity.h"

#define NAME_SUFFIX _Spring
#include "world/common/EnableCameraFollowPlayerY.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_TetherCamToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseSpring_Exit) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
    IfEq(AF_OMO_04, FALSE)
        Call(N(EnableCameraFollowPlayerY_Spring))
        Thread
            Wait(6)
            Call(GotoMap, Ref("mac_04"), mac_04_ENTRY_2)
            Wait(100)
        EndThread
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, -245, 270, 250, 20)
    Else
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump, -95, 0, 250, 25)
        Set(AF_OMO_04, FALSE)
    EndIf
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_Scene_EnterSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 100)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Wait(1)
    ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
    Thread
        Call(GetCurrentPartnerID, LVar0)
        Switch(LVar0)
            CaseEq(PARTNER_PARAKARRY)
            CaseEq(PARTNER_LAKILESTER)
            CaseEq(PARTNER_BOW)
            CaseEq(PARTNER_WATT)
            CaseDefault
                Call(SetNpcJumpscale, NPC_PARTNER, Float(0.7))
                Call(NpcJump0, NPC_PARTNER, -150, 25, 250, 37)
                Call(NpcJump0, NPC_PARTNER, -110, 0, 190, 20)
        EndSwitch
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        Call(EnablePartnerAI)
    EndThread
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, -150, 25, 250, 25)
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -250, 60, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ScriptSpring), -150, 0, 250, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring_Exit)))
    Call(MakeEntity, Ref(Entity_HiddenPanel), 203, 0, 200, 0, MODEL_o930, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OMO03_HiddenPanel)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 400, 60, -50, 0, ITEM_STONE_CAP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO03_HiddenItem_StoneCap)
    Return
    End
};

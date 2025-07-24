#include "pra_22.h"
#include "entity.h"

API_CALLABLE(N(GetTargetPosXForSpring)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 425;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 325;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MonitorPlayerFloor)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPos.y == 0) {
        evt_set_variable(script, MV_PlayerFloor, 0);
    }
    if (playerStatus->lastGoodPos.y == -200) {
        evt_set_variable(script, MV_PlayerFloor, 1);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_TetherCamToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar1, LVar3)
            Set(LVar1, LVar3)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Call(GetPlayerPos, LVar7, LVar8, LVar9)
    IfEq(MV_PlayerFloor, 0)
        Set(LVar3, -175)
        ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
        Call(N(GetTargetPosXForSpring))
        Set(LVar1, -200)
        Set(LVar2, 15)
        Call(SetPlayerJumpscale, Float(2.0))
    Else
        Set(LVar3, 0)
        ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
        IfEq(GB_PRA_TwinStatueState, 2)
            Set(LVar0, 340)
        Else
            Set(LVar0, 410)
        EndIf
        Set(LVar1, 0)
        Set(LVar2, 35)
        Call(SetPlayerJumpscale, Float(0.7))
    EndIf
    Call(PlayerJump, LVar0, LVar1, LVar9, LVar2)
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(2)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Thread
        Call(N(MonitorPlayerFloor))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), 366, -200, 80, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 55, 80, 75, 0, ITEM_JAMMIN_JELLY, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_PRA22_HiddenItem_JamminJelly)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 50, 0, 75, 0, MODEL_o1088, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_PRA22_HiddenPanel)
    Return
    End
};

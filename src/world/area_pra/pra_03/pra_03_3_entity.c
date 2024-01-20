#include "pra_03.h"
#include "entity.h"

API_CALLABLE(N(GetTargetPosXForSpring_Floor1)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 150;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 95;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTargetPosXForSpring_Floor0)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 165;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 70;
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

EvtScript N(EVS_TetherCamToPlayerWithCeiling) = {
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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Call(GetPlayerPos, LVar7, LVar8, LVar9)
    IfEq(MV_PlayerFloor, 0)
        Set(LVar3, -175)
        ExecGetTID(N(EVS_TetherCamToPlayerWithCeiling), LVarA)
        Call(N(GetTargetPosXForSpring_Floor0))
        Call(SetPlayerJumpscale, Float(2.0))
        Set(LVar1, -200)
        Set(LVar2, 15)
    Else
        Set(LVar3, 0)
        ExecGetTID(N(EVS_TetherCamToPlayerWithCeiling), LVarA)
        Call(N(GetTargetPosXForSpring_Floor1))
        Call(SetPlayerJumpscale, Float(0.7))
        Set(LVar1, 0)
        Set(LVar2, 35)
    EndIf
    Call(PlayerJump, LVar0, LVar1, LVar9, LVar2)
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(2)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Thread
        Call(N(MonitorPlayerFloor))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), 124, -200, -75, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(MakeEntity, Ref(Entity_SavePoint), -200, 60, -75, 0, MAKE_ENTITY_END)
    Return
    End
};

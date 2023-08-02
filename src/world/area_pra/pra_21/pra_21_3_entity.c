#include "pra_21.h"
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
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar1, LVar3)
            EVT_SET(LVar1, LVar3)
        EVT_END_IF
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_CALL(GetPlayerPos, LVar7, LVar8, LVar9)
    EVT_IF_EQ(MV_PlayerFloor, 0)
        EVT_SET(LVar3, -175)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
        EVT_CALL(N(GetTargetPosXForSpring))
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 15)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
        EVT_IF_EQ(GB_PRA_TwinStatueState, 2)
            EVT_SET(LVar0, 340)
        EVT_ELSE
            EVT_SET(LVar0, 410)
        EVT_END_IF
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 35)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_END_IF
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar9, LVar2)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(2)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerFloor))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 366, -200, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 55, 80, -75, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_PRA21_ItemBlock_MapleSyrup)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 50, 0, -75, 0, MODEL_o961, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_PRA21_HiddenPanel)
    EVT_RETURN
    EVT_END
};

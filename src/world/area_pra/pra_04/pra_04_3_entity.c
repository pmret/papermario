#include "pra_04.h"
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
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayerWithCeiling), LVarA)
        EVT_CALL(N(GetTargetPosXForSpring_Floor0))
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 15)
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayerWithCeiling), LVarA)
        EVT_CALL(N(GetTargetPosXForSpring_Floor1))
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 35)
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

EvtScript N(EVS_BreakFloor) = {
    EVT_SET(GF_PRA04_BoardedFloor, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o994, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerFloor))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 124, -200, 80, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_IF_EQ(GF_PRA04_BoardedFloor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 124, 0, 80, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakFloor)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -200, 60, 75, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_PRA04_ItemBlock_SuperShroom)
    EVT_RETURN
    EVT_END
};

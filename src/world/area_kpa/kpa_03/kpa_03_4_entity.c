#include "kpa_03.h"
#include "entity.h"

API_CALLABLE(N(MonitorPlayerAltitude)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPos.y >= 0) {
        evt_set_variable(script, MV_PlayerHeightLevel, 0);
    }
    if (playerStatus->lastGoodPos.y <= -280) {
        evt_set_variable(script, MV_PlayerHeightLevel, 1);
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
    EVT_IF_EQ(MV_PlayerHeightLevel, 0)
        EVT_SET(LVar3, -275)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, -507, -288, -159, 20)
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.1))
        EVT_CALL(PlayerJump, -500, 0, -150, 40)
    EVT_END_IF
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(4)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerAltitude))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -400, -300, -150, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 620, -65, -200, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA03_ItemBlock_ShootingStar)
    EVT_RETURN
    EVT_END
};

#include "iwa_04.h"
#include "entity.h"

API_CALLABLE(N(MonitorPlayerAltitude)) {
    s32 status = -1;

    if (gPlayerStatus.lastGoodPos.y > -100.0) {
        status = 0;
    }
    if (gPlayerStatus.lastGoodPos.y < -240.0) {
        status = 1;
    }
    if (status >= 0) {
        evt_set_variable(script, MV_PlayerCliffLevel, status);
    }

    return ApiStatus_BLOCK;
}

EvtScript N(TetherCameraToPlayer) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(TetherCameraToPlayer), LVarA)
    EVT_IF_EQ(MV_PlayerCliffLevel, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.4))
        EVT_CALL(PlayerJump, -560, -250, 190, 15)
    EVT_ELSE
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, -560, 0, 90, 40)
    EVT_END_IF
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerAltitude))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -561, -250, 121, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), -513, 0, -97, 0, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 600, 0, 200, 0, 270, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 336, -140, 203, 0, 70, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 730, -250, -95, 0, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_CHAIN_GOOMPAPA_1, -275, -250, 150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA04_Item_Letter10)
    EVT_RETURN
    EVT_END
};

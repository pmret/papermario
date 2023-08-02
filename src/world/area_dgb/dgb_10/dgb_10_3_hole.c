#include "dgb_10.h"

// unused
#include "world/common/atomic/BetaFloorPanels.inc.c"

API_CALLABLE(N(AwaitFallInHole)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 entry;

    if (playerStatus->pos.y >= 0.0f) {
        return ApiStatus_BLOCK;
    }

    if (playerStatus->pos.x < 440.0f) {
        entry = dgb_11_ENTRY_3;
    } else if (playerStatus->pos.z < -170.0f) {
        entry = dgb_11_ENTRY_2;
    } else {
        entry = dgb_11_ENTRY_1;
    }
    script->varTable[0] = entry;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AwaitFallDownHole)) {
    if (gPlayerStatus.pos.y > -60.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupHoles) = {
    EVT_CALL(N(AwaitFallInHole))
    EVT_CALL(func_802CA988, CAM_DEFAULT, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(N(AwaitFallDownHole))
#if VERSION_PAL
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
#endif
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(GotoMap, EVT_PTR("dgb_11"), LVar0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

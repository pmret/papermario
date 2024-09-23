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
    Call(N(AwaitFallInHole))
    Call(GrabCamera, CAM_DEFAULT, LVar2, LVar3, LVar4, LVar5)
    Call(N(AwaitFallDownHole))
#if VERSION_PAL
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, TRUE)
#endif
    Call(InterruptUsePartner)
    Call(GotoMap, Ref("dgb_11"), LVar0)
    Wait(100)
    Return
    End
};

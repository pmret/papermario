#include "dgb_05.h"

API_CALLABLE(N(AwaitFallInHole)) {
    if (gPlayerStatus.position.y >= -210.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AwaitFallDownHole)) {
    if (gPlayerStatus.position.y > -270.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupHole) = {
    EVT_CALL(N(AwaitFallInHole))
    EVT_CALL(func_802CA988, 0, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(N(AwaitFallDownHole))
    EVT_SET(GF_DGB05_BoardedFloor, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("dgb_06"), dgb_06_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

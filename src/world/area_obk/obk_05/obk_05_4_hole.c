#include "obk_05.h"

API_CALLABLE(N(AwaitPlayerEnterHole)) {
    if (gPlayerStatus.pos.y < -50.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_ManageHole) = {
    EVT_CALL(N(AwaitPlayerEnterHole))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("obk_06"), obk_06_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

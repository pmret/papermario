#include "obk_04.h"

API_CALLABLE(N(AwaitPlayerEnterHole)) {
    if (gPlayerStatus.pos.y < -50.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_ManageHole) = {
    EVT_CALL(N(AwaitPlayerEnterHole))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("obk_03"), obk_03_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

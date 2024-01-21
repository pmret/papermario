#include "obk_05.h"

API_CALLABLE(N(AwaitPlayerEnterHole)) {
    if (gPlayerStatus.pos.y < -50.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_ManageHole) = {
    Call(N(AwaitPlayerEnterHole))
    Call(DisablePlayerPhysics, TRUE)
    Call(GotoMap, Ref("obk_06"), obk_06_ENTRY_0)
    Wait(100)
    Return
    End
};

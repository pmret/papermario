#include "obk_04.h"

API_CALLABLE(N(AwaitPlayerEnterHole)) {
    if (gPlayerStatus.pos.y < -50.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_ManageHole) = {
    Call(N(AwaitPlayerEnterHole))
    Call(DisablePlayerPhysics, true)
    Call(GotoMap, Ref("obk_03"), obk_03_ENTRY_2)
    Wait(100)
    Return
    End
};

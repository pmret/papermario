#include "dgb_05.h"

API_CALLABLE(N(AwaitFallInHole)) {
    if (gPlayerStatus.pos.y >= -210.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AwaitFallDownHole)) {
    if (gPlayerStatus.pos.y > -270.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupHole) = {
    Call(N(AwaitFallInHole))
    Call(GrabCamera, CAM_DEFAULT, LVar2, LVar3, LVar4, LVar5)
    Call(N(AwaitFallDownHole))
    Set(GF_DGB05_BoardedFloor, true)
    Call(GotoMap, Ref("dgb_06"), dgb_06_ENTRY_1)
    Wait(100)
    Return
    End
};

#include "end_01.h"

API_CALLABLE(N(WidenCameraFOV)) {
    gCameras[CAM_DEFAULT].vfov = 35.0f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamViewport, CAM_DEFAULT, 15, 28, 290, 128)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(N(WidenCameraFOV))
    Call(EnableWorldStatusBar, FALSE)
    Exec(N(EVS_ManageParade))
    Wait(1)
    Return
    End
};

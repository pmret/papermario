#include "end_00.h"

EvtScript N(EVS_Main) = {
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 35, 16, 4096)
    Call(SetCamViewport, CAM_DEFAULT, 15, 28, 290, 128)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(FadeOutMusic, 0, 500)
    Call(ClearAmbientSounds, 250)
    Call(EnableWorldStatusBar, FALSE)
    Wait(30)
    Exec(N(EVS_ManageParade))
    Return
    End
};

#include "end_00.h"

EvtScript N(EVS_Main) = {
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 35, 16, 4096)
    EVT_CALL(SetCamViewport, CAM_DEFAULT, 15, 28, 290, 128)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(EnableWorldStatusBar, FALSE)
    EVT_WAIT(30)
    EVT_EXEC(N(EVS_ManageParade))
    EVT_RETURN
    EVT_END
};

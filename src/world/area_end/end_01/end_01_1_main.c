#include "end_01.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ManageParade);

API_CALLABLE(N(WidenCameraFOV)) {
    gCameras[CAM_DEFAULT].vfov = 35.0f;
    return ApiStatus_DONE2;
}

EntryList N(Entrances) = {
    [end_01_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_Main) = {
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamViewport, CAM_DEFAULT, 15, 28, 290, 128)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(N(WidenCameraFOV))
    EVT_CALL(EnableStatusMenu, FALSE)
    EVT_EXEC(N(EVS_ManageParade))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

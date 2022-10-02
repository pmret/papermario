#include "end_01.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_802451F8);

API_CALLABLE(N(func_80240010_E05370));

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
    EVT_CALL(N(func_80240010_E05370))
    EVT_CALL(EnableStatusMenu, FALSE)
    EVT_EXEC(N(EVS_802451F8))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

#include "mgm_03.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [mgm_03_ENTRY_0]    {    0.0,  200.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_01 },
};

EvtScript N(EVS_Main) = {
    EVT_CALL(SetSpriteShading, SHADING_ARN_09)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_RETURN
    EVT_END
};

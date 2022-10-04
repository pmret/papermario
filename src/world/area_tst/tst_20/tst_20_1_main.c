#include "tst_20.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [tst_20_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_RETURN
    EVT_END
};


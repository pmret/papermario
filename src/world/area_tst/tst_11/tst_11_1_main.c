#include "tst_11.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupReflections);

EntryList N(Entrances) = {
    [tst_11_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TESTING)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Exec(N(EVS_SetupReflections))
    Return
    End
};

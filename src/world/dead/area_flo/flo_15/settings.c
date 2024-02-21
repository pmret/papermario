#include "flo_15.h"

EntryList N(Entrances) = {
    [flo_15_ENTRY_0]    {  320.0,    0.0,    0.0,  270.0 },
    [flo_15_ENTRY_1]    { -170.0,    0.0,   55.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_15 },
};

#include "flo_18.h"

EntryList N(Entrances) = {
    [flo_18_ENTRY_0]    { -320.0,    0.0,    0.0,   90.0 },
    [flo_18_ENTRY_1]    {   36.0,    0.0,   40.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_18 },
};

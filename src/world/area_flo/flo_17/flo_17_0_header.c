#include "flo_17.h"

EntryList N(Entrances) = {
    [flo_17_ENTRY_0]    { -730.0,    0.0,    0.0,   90.0 },
    [flo_17_ENTRY_1]    {  730.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_17 },
};

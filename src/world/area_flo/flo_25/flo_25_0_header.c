#include "flo_25.h"

EntryList N(Entrances) = {
    [flo_25_ENTRY_0]    {  620.0,    0.0,    0.0,  270.0 },
    [flo_25_ENTRY_1]    { -620.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_25 },
};

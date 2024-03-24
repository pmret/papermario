#include "flo_03.h"

EntryList N(Entrances) = {
    [flo_03_ENTRY_0]    { -325.0,    0.0,    0.0,   90.0 },
    [flo_03_ENTRY_1]    {  325.0,    0.0,    0.0,  270.0 },
    [flo_03_ENTRY_2]    { -325.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_03 },
};

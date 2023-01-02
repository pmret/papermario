#include "kpa_40.h"

EntryList N(Entrances) = {
    [kpa_40_ENTRY_0]    { -490.0,    0.0,  -80.0,   90.0 },
    [kpa_40_ENTRY_1]    {  490.0,    0.0,  -30.0,  270.0 },
    [kpa_40_ENTRY_2]    {  490.0,  120.0, -130.0,  270.0 },
    [kpa_40_ENTRY_3]    { -430.0,  133.0,  -80.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_40 },
};

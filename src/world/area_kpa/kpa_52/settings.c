#include "kpa_52.h"

EntryList N(Entrances) = {
    [kpa_52_ENTRY_0]    { -345.0,    0.0,  -80.0,   90.0 },
    [kpa_52_ENTRY_1]    {  330.0,    0.0,  -25.0,  270.0 },
    [kpa_52_ENTRY_2]    {  330.0,  119.0, -140.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_52 },
};

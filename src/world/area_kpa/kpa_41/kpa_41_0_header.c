#include "kpa_41.h"

EntryList N(Entrances) = {
    [kpa_41_ENTRY_0]    { -340.0,    0.0,  -70.0,   90.0 },
    [kpa_41_ENTRY_1]    {  340.0,    0.0,  -70.0,  270.0 },
    [kpa_41_ENTRY_2]    {  340.0,  119.0, -230.0,  270.0 },
    [kpa_41_ENTRY_3]    { -340.0,  119.0, -230.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_41 },
};

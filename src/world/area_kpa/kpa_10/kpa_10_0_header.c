#include "kpa_10.h"

EntryList N(Entrances) = {
    [kpa_10_ENTRY_0]    {   25.0,  100.0, -140.0,   90.0 },
    [kpa_10_ENTRY_1]    { 1402.0,   30.0, -1082.0,  180.0 },
    [kpa_10_ENTRY_2]    { 1378.0,   30.0, -724.0,   90.0 },
    [kpa_10_ENTRY_3]    {   15.0,  -20.0,  -20.0,   90.0 },
    [kpa_10_ENTRY_4]    { 1529.0,  -20.0, -1082.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_10 },
};

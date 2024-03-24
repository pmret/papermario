#include "kpa_03.h"

EntryList N(Entrances) = {
    [kpa_03_ENTRY_0]    { 1888.0, -410.0,  -93.0,  270.0 },
    [kpa_03_ENTRY_1]    { -1575.0, -105.0, -158.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_03 },
};

#include "kpa_17.h"

EntryList N(Entrances) = {
    [kpa_17_ENTRY_0]    { 1042.0,  250.0, -496.0,   90.0 },
    [kpa_17_ENTRY_1]    { 1168.0,   30.0, -560.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_17 },
};

#include "kpa_95.h"

EntryList N(Entrances) = {
    [kpa_95_ENTRY_0]    {  205.0,    0.0,  100.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_95 },
};

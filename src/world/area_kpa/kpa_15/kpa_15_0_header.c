#include "kpa_15.h"

EntryList N(Entrances) = {
    [kpa_15_ENTRY_0]    {   12.0,    0.0,  -97.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_15 },
};

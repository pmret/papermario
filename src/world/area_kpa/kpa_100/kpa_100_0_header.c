#include "kpa_100.h"

EntryList N(Entrances) = {
    [kpa_100_ENTRY_0]   { -208.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_100 },
};

#include "kpa_117.h"

EntryList N(Entrances) = {
    [kpa_117_ENTRY_0]   { -210.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_117 },
};

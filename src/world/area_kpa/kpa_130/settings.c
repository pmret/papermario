#include "kpa_130.h"

EntryList N(Entrances) = {
    [kpa_130_ENTRY_0]   { -975.0,    0.0,   -5.0,   90.0 },
    [kpa_130_ENTRY_1]   {  975.0,  720.0, -100.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_130 },
};

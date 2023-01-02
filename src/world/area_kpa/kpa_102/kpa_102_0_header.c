#include "kpa_102.h"

EntryList N(Entrances) = {
    [kpa_102_ENTRY_0]   { -480.0,    0.0, -215.0,   90.0 },
    [kpa_102_ENTRY_1]   {  764.0,    0.0, -215.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_102 },
};

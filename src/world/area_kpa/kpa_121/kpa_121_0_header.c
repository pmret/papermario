#include "kpa_121.h"

EntryList N(Entrances) = {
    [kpa_121_ENTRY_0]   { -373.0, -240.0,  100.0,   90.0 },
    [kpa_121_ENTRY_1]   {  465.0,    0.0,   95.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_121 },
};

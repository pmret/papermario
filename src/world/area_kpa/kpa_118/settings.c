#include "kpa_118.h"

EntryList N(Entrances) = {
    [kpa_118_ENTRY_0]   {  144.0,    0.0,  100.0,    0.0 },
    [kpa_118_ENTRY_1]   { -471.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_118 },
};

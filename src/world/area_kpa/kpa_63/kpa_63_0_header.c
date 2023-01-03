#include "kpa_63.h"

EntryList N(Entrances) = {
    [kpa_63_ENTRY_0]    {  160.0,    0.0,  240.0,    0.0 },
    [kpa_63_ENTRY_1]    {  -40.0,    0.0,  225.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_63 },
};

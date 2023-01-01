#include "kpa_94.h"

EntryList N(Entrances) = {
    [kpa_94_ENTRY_0]    { -270.0, -240.0,  100.0,   90.0 },
    [kpa_94_ENTRY_1]    {  470.0,    0.0,  100.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_94 },
};

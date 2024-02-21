#include "kpa_82.h"

EntryList N(Entrances) = {
    [kpa_82_ENTRY_0]    { -210.0,    0.0,  150.0,   90.0 },
    [kpa_82_ENTRY_1]    {  150.0,    0.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_82 },
};

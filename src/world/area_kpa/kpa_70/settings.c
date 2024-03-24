#include "kpa_70.h"

EntryList N(Entrances) = {
    [kpa_70_ENTRY_0]    {   13.0,    0.0,  134.0,   90.0 },
    [kpa_70_ENTRY_1]    { 1233.0,    0.0,  126.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_70 },
};

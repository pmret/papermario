#include "kpa_90.h"

EntryList N(Entrances) = {
    [kpa_90_ENTRY_0]    { -470.0,    0.0,  100.0,   90.0 },
    [kpa_90_ENTRY_1]    {  265.0, -240.0,  100.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_90 },
};

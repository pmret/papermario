#include "kpa_53.h"

EntryList N(Entrances) = {
    [kpa_53_ENTRY_0]    { -480.0,    0.0,  -28.0,   90.0 },
    [kpa_53_ENTRY_1]    {  768.0,    0.0,  -28.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_53 },
};

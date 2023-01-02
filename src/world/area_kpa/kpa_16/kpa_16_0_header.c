#include "kpa_16.h"

EntryList N(Entrances) = {
    [kpa_16_ENTRY_0]    {   25.0,    0.0,  -92.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_16 },
};

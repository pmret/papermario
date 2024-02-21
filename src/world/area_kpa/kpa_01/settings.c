#include "kpa_01.h"

EntryList N(Entrances) = {
    [kpa_01_ENTRY_0]    {  690.0, -378.0,  337.0,   90.0 },
    [kpa_01_ENTRY_1]    { -511.0,  149.0,   57.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_01 },
};

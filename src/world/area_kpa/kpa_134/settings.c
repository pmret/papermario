#include "kpa_134.h"

EntryList N(Entrances) = {
    [kpa_134_ENTRY_0]   { -370.0,    0.0,  115.0,   90.0 },
    [kpa_134_ENTRY_1]   {  730.0,    0.0,  115.0,  270.0 },
    [kpa_134_ENTRY_2]   { -370.0,  100.0,  128.0,   90.0 },
    [kpa_134_ENTRY_3]   { -365.0,  240.0,  -22.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_134 },
};

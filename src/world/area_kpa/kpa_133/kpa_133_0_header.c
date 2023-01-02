#include "kpa_133.h"

EntryList N(Entrances) = {
    [kpa_133_ENTRY_0]   { -387.0,    0.0,  115.0,   90.0 },
    [kpa_133_ENTRY_1]   {  370.0,    0.0,  120.0,  270.0 },
    [kpa_133_ENTRY_2]   {  370.0,  100.0,  120.0,  270.0 },
    [kpa_133_ENTRY_3]   {  365.0,  240.0,  -20.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_133 },
};

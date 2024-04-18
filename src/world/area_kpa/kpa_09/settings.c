#include "kpa_09.h"

EntryList N(Entrances) = {
    [kpa_09_ENTRY_0]    { -483.0,  100.0,  -17.0,   90.0 },
    [kpa_09_ENTRY_1]    {  202.0,    0.0,  -16.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = 11, //@bug -- should be 2
    .tattle = { MSG_MapTattle_kpa_09 },
};

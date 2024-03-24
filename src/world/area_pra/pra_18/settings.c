#include "pra_18.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_18_ENTRY_0]    {   13.0,    0.0,   70.0,   90.0 },
    [pra_18_ENTRY_1]    {  737.0,    0.0,  -70.0,  270.0 },
    [pra_18_ENTRY_2]    {   13.0,    0.0,  -70.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_18 },
};

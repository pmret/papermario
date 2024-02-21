#include "pra_33.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_33_ENTRY_0]    {  487.0,    0.0,   70.0,  270.0 },
    [pra_33_ENTRY_1]    {   13.0,    0.0,  -70.0,   90.0 },
    [pra_33_ENTRY_2]    {  487.0,    0.0,  -70.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_33 },
};

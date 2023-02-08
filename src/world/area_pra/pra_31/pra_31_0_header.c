#include "pra_31.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_31_ENTRY_0]    {   13.0,    0.0,   70.0,   90.0 },
    [pra_31_ENTRY_1]    {  487.0,   50.0,   13.0,  270.0 },
    [pra_31_ENTRY_2]    {   13.0,    0.0,  -70.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_31 },
};

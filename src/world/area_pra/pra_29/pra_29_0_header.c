#include "pra_29.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_29_ENTRY_0]    {   13.0,    0.0,   70.0,   90.0 },
    [pra_29_ENTRY_1]    {  487.0,    0.0,   70.0,  270.0 },
    [pra_29_ENTRY_2]    {  487.0,    0.0,  -70.0,  270.0 },
    [pra_29_ENTRY_3]    {   13.0,    0.0,  -70.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_29 },
};

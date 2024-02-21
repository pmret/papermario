#include "pra_35.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_35_ENTRY_0]    {   13.0,    0.0,   80.0,   90.0 },
    [pra_35_ENTRY_1]    {  487.0,    0.0,   80.0,  270.0 },
    [pra_35_ENTRY_2]    {   13.0,    0.0,  -80.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_35 },
};

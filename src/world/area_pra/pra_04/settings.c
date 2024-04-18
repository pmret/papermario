#include "pra_04.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_04_ENTRY_0]    { -128.0,    0.0,  157.0,    0.0 },
    [pra_04_ENTRY_1]    {  237.0,    0.0,   78.0,  270.0 },
    [pra_04_ENTRY_2]    {  237.0, -200.0,   78.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_04 },
};

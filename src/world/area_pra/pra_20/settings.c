#include "pra_20.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_20_ENTRY_0]    {   13.0,    0.0,   70.0,   90.0 },
    [pra_20_ENTRY_1]    {  126.0,    0.0,  137.0,    0.0 },
    [pra_20_ENTRY_2]    {  237.0,    0.0,   70.0,  270.0 },
    [pra_20_ENTRY_3]    {  237.0,    0.0,  -70.0,  270.0 },
    [pra_20_ENTRY_4]    {  126.0,    0.0, -137.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_20 },
};

#include "pra_02.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_02_ENTRY_0]    {   13.0,    0.0,   77.0,   90.0 },
    [pra_02_ENTRY_1]    {  500.0,    0.0,  212.0,    0.0 },
    [pra_02_ENTRY_2]    {  960.0,    0.0,   80.0,  270.0 },
    [pra_02_ENTRY_3]    {  960.0,    0.0,  -80.0,  270.0 },
    [pra_02_ENTRY_4]    {  500.0,    0.0, -212.0,  180.0 },
    [pra_02_ENTRY_5]    {   13.0,    0.0,  -77.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_02 },
};

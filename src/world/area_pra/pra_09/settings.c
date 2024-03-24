#include "pra_09.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_09_ENTRY_0]    {   13.0,    0.0,   73.0,   90.0 },
    [pra_09_ENTRY_1]    {  479.0,    0.0,   84.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_09 },
};

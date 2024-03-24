#include "pra_01.h"

#include "../common/MapInit_EnableFloorReflection.inc.c"

EntryList N(Entrances) = {
    [pra_01_ENTRY_0]    {  519.0,  -60.0,  105.0,   90.0 },
    [pra_01_ENTRY_1]    {  977.0,    0.0,   70.0,  270.0 },
    [pra_01_ENTRY_2]    {  977.0,    0.0,  -78.0,  270.0 },
    [pra_01_ENTRY_3]    {  519.0,  -60.0, -100.0,   90.0 },
    [pra_01_ENTRY_4]    {  774.0,  -30.0,   85.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_pra_01 },
};

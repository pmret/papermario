#include "hos_10.h"

#include "world/common/todo/SetPlayerSpriteSet2_MapInit.inc.c"

EntryList N(Entrances) = {
    [hos_10_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_10_ENTRY_1]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_10_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_10_ENTRY_3]    {    0.0, -1000.0,    0.0,   90.0 },
    [hos_10_ENTRY_4]    {    0.0, -1000.0,    0.0,   90.0 },
    [hos_10_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

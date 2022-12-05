#include "isk_07.h"

EntryList N(Entrances) = {
    [isk_07_ENTRY_0]    { -283.0, -390.0,  530.0,  110.0 },
    [isk_07_ENTRY_1]    {  560.0, -340.0,  217.0,  210.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_07 },
};

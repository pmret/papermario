#include "isk_18.h"

EntryList N(Entrances) = {
    [isk_18_ENTRY_0]    { -528.0, -780.0,  217.0,  150.0 },
    [isk_18_ENTRY_1]    {  431.0, -780.0,  388.0,  230.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_18 },
};

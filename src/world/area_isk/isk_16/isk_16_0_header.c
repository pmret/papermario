#include "isk_16.h"

EntryList N(Entrances) = {
    [isk_16_ENTRY_0]    {  307.0, -910.0,  492.0,   50.0 },
    [isk_16_ENTRY_1]    {  492.0, -910.0,  307.0,  220.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_16 },
};

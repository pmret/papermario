#include "isk_13.h"

EntryList N(Entrances) = {
    [isk_13_ENTRY_0]    {  568.0, -650.0, -120.0,  340.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_13 },
};

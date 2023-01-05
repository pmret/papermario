#include "dgb_14.h"

EntryList N(Entrances) = {
    [dgb_14_ENTRY_0]    {  575.0,    0.0,  180.0,  270.0 },
    [dgb_14_ENTRY_1]    {  575.0,  210.0,  180.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_14 },
};

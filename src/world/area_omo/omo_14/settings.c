#include "omo_14.h"

EntryList N(Entrances) = {
    [omo_14_ENTRY_0]    { -260.0,    0.0,   20.0,   90.0 },
    [omo_14_ENTRY_1]    {  230.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_omo_14 },
};

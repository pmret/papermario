#include "tik_15.h"

EntryList N(Entrances) = {
    [tik_15_ENTRY_0]    { -230.0,  -10.0,    0.0,   90.0 },
    [tik_15_ENTRY_1]    {   75.0,  -10.0,  -15.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_15 },
};

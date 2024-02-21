#include "tik_14.h"

EntryList N(Entrances) = {
    [tik_14_ENTRY_0]    { -173.0,    0.0,    0.0,   90.0 },
    [tik_14_ENTRY_1]    {   30.0,    0.0,   45.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_14 },
};

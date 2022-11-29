#include "tik_23.h"

EntryList N(Entrances) = {
    [tik_23_ENTRY_0]    { -270.0,  -20.0,  -20.0,   90.0 },
    [tik_23_ENTRY_1]    {  107.0,  -20.0, -115.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_23 },
};

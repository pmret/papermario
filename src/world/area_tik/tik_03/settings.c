#include "tik_03.h"

EntryList N(Entrances) = {
    [tik_03_ENTRY_0]    {  320.0,  -10.0,    0.0,  270.0 },
    [tik_03_ENTRY_1]    { -215.0,   60.0,    0.0,   90.0 },
    [tik_03_ENTRY_2]    {  260.0,  -10.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_03 },
};

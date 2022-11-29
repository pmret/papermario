#include "tik_18.h"

EntryList N(Entrances) = {
    [tik_18_ENTRY_0]    { -220.0,  -10.0,    0.0,   90.0 },
    [tik_18_ENTRY_1]    {  320.0,  -10.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_18 },
};

#include "tik_04.h"

EntryList N(Entrances) = {
    [tik_04_ENTRY_0]    { -220.0,  -10.0,    0.0,   90.0 },
    [tik_04_ENTRY_1]    {  320.0,  -10.0,    0.0,  270.0 },
    [tik_04_ENTRY_2]    { -110.0,  -10.0,  -80.0,  270.0 },
    [tik_04_ENTRY_3]    {  268.0, -105.0,   94.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_04 },
};

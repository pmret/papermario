#include "tik_22.h"

EntryList N(Entrances) = {
    [tik_22_ENTRY_0]    { -222.0,    0.0,    0.0,   90.0 },
    [tik_22_ENTRY_1]    {  -50.0,   50.0,   20.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_22 },
};

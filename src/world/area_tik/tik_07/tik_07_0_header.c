#include "tik_07.h"

EntryList N(Entrances) = {
    [tik_07_ENTRY_0]    { -270.0,  -10.0,    0.0,   90.0 },
    [tik_07_ENTRY_1]    { -275.0,   90.0, -110.0,  180.0 },
    [tik_07_ENTRY_2]    {  525.0,   25.0, -100.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_07 },
};

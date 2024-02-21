#include "tik_10.h"

EntryList N(Entrances) = {
    [tik_10_ENTRY_0]    {  330.0,   20.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_10 },
};

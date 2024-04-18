#include "tik_25.h"

EntryList N(Entrances) = {
    [tik_25_ENTRY_0]    {  325.0, -135.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_25 },
};

#include "tik_19.h"

EntryList N(Entrances) = {
    [tik_19_ENTRY_0]    { -170.0,  -10.0,  -90.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_19 },
};

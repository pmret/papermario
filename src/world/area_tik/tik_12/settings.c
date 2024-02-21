#include "tik_12.h"

EntryList N(Entrances) = {
    [tik_12_ENTRY_0]    { -173.0, -135.0, -100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_12 },
};

#include "obk_04.h"

EntryList N(Entrances) = {
    [obk_04_ENTRY_0]    { -235.0,    0.0,    5.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_obk_04 },
};

#include "kpa_91.h"

EntryList N(Entrances) = {
    [kpa_91_ENTRY_0]    { -200.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_91 },
};

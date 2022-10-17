#include "kzn_04.h"

EntryList N(Entrances) = {
    [kzn_04_ENTRY_0]    { -560.0,  500.0,    5.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_04 },
};

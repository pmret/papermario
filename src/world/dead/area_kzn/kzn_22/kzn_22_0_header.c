#include "kzn_22.h"

EntryList N(Entrances) = {
    [kzn_22_ENTRY_0]    { -390.0,    0.0,  210.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_22 },
};

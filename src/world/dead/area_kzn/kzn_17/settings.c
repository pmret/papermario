#include "kzn_17.h"

EntryList N(Entrances) = {
    [kzn_17_ENTRY_0]    { -670.0,    0.0,  160.0,   90.0 },
    [kzn_17_ENTRY_1]    {  620.0,    0.0,   30.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_17 },
};

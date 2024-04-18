#include "kzn_20.h"

EntryList N(Entrances) = {
    [kzn_20_ENTRY_0]    { -182.0,    0.0,   36.0,   90.0 },
    [kzn_20_ENTRY_1]    {  164.0,  150.0,   20.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_20 },
};

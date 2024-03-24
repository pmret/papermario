#include "kzn_11.h"

EntryList N(Entrances) = {
    [kzn_11_ENTRY_0]    { -810.0,   20.0,    0.0,   90.0 },
    [kzn_11_ENTRY_1]    {  810.0,   20.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_11 },
};

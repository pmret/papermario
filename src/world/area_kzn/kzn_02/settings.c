#include "kzn_02.h"

EntryList N(Entrances) = {
    [kzn_02_ENTRY_0]    { -810.0,   20.0,  -10.0,   90.0 },
    [kzn_02_ENTRY_1]    {  810.0,   20.0,  -10.0,  270.0 },
    [kzn_02_ENTRY_2]    { -810.0,   20.0,  -10.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_02 },
};

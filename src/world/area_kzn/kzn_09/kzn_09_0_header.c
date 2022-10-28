#include "kzn_09.h"

EntryList N(Entrances) = {
    [kzn_09_ENTRY_0]    { -445.0,  870.0,  -40.0,   90.0 },
    [kzn_09_ENTRY_1]    {  435.0,  719.0,   10.0,  270.0 },
    [kzn_09_ENTRY_2]    { -445.0,  400.0,   95.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_09 },
};

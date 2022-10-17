#include "kzn_01.h"

EntryList N(Entrances) = {
    [kzn_01_ENTRY_0]    { -445.0,    0.0,    0.0,   90.0 },
    [kzn_01_ENTRY_1]    {  425.0, -255.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_01 },
};

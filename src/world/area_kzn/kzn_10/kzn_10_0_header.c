#include "kzn_10.h"

EntryList N(Entrances) = {
    [kzn_10_ENTRY_0]    { -445.0,    0.0,    0.0,   90.0 },
    [kzn_10_ENTRY_1]    {  425.0, -259.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_10 },
};

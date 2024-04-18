#include "kzn_05.h"

EntryList N(Entrances) = {
    [kzn_05_ENTRY_0]    { -430.0, -259.0,   10.0,   90.0 },
    [kzn_05_ENTRY_1]    {  450.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_05 },
};

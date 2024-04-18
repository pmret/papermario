#include "obk_03.h"

EntryList N(Entrances) = {
    [obk_03_ENTRY_0]    {  -20.0,    0.0, -235.0,  180.0 },
    [obk_03_ENTRY_1]    {  240.0,    0.0,    0.0,  270.0 },
    [obk_03_ENTRY_2]    {  660.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_obk_03 },
};

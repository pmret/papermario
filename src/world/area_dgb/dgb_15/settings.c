#include "dgb_15.h"

EntryList N(Entrances) = {
    [dgb_15_ENTRY_0]    { -1290.0,    0.0,  180.0,   90.0 },
    [dgb_15_ENTRY_1]    {  125.0,    0.0,  180.0,  270.0 },
    [dgb_15_ENTRY_2]    {    0.0,    0.0,   88.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_15 },
};

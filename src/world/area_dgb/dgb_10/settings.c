#include "dgb_10.h"

EntryList N(Entrances) = {
    [dgb_10_ENTRY_0]    {  300.0,    0.0,  -50.0,    0.0 },
    [dgb_10_ENTRY_1]    {  375.0,    0.0, -240.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_10 },
};

#include "dgb_08.h"

EntryList N(Entrances) = {
    [dgb_08_ENTRY_0]    { -575.0,    0.0,  180.0,   90.0 },
    [dgb_08_ENTRY_1]    { -575.0,  210.0,  180.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_08 },
};

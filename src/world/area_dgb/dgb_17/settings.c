#include "dgb_17.h"

EntryList N(Entrances) = {
    [dgb_17_ENTRY_0]    { -570.0,    0.0,  180.0,   90.0 },
    [dgb_17_ENTRY_1]    { -180.0,    0.0,  180.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_17 },
};

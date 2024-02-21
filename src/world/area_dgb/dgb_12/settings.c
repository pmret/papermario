#include "dgb_12.h"

EntryList N(Entrances) = {
    [dgb_12_ENTRY_0]    { -500.0,    0.0,  -40.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_12 },
};

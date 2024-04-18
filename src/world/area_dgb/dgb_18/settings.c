#include "dgb_18.h"

EntryList N(Entrances) = {
    [dgb_18_ENTRY_0]    { -120.0,    0.0,  180.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_18 },
};

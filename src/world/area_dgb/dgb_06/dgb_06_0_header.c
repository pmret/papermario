#include "dgb_06.h"

EntryList N(Entrances) = {
    [dgb_06_ENTRY_0]    { -575.0,    0.0,  175.0,   90.0 },
    [dgb_06_ENTRY_1]    { -150.0,  100.0, -250.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_06 },
};

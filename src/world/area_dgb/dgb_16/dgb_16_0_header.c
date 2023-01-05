#include "dgb_16.h"

EntryList N(Entrances) = {
    [dgb_16_ENTRY_0]    {  450.0,    0.0,  -40.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_16 },
};

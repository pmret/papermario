#include "dgb_05.h"

EntryList N(Entrances) = {
    [dgb_05_ENTRY_0]    {  515.0,    0.0,  310.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_05 },
};

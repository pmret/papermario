#include "dgb_07.h"

EntryList N(Entrances) = {
    [dgb_07_ENTRY_0]    { -450.0,    0.0,  -40.0,    0.0 },
    [dgb_07_ENTRY_1]    {  250.0,  190.0, -250.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_07 },
};

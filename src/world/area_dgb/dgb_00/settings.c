#include "dgb_00.h"

EntryList N(Entrances) = {
    [dgb_00_ENTRY_0]    { -733.0,    0.0,   -8.0,   90.0 },
    [dgb_00_ENTRY_1]    {  250.0,   10.0, -100.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_dgb_00 },
};

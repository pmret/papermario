#include "isk_10.h"

EntryList N(Entrances) = {
    [isk_10_ENTRY_0]    { -594.0, -520.0,   84.0,    0.0 },
    [isk_10_ENTRY_1]    { -575.0, -780.0,  -81.0,  180.0 },
    [isk_10_ENTRY_2]    { -577.0, -780.0,   81.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_10 },
};

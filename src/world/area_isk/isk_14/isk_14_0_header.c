#include "isk_14.h"

EntryList N(Entrances) = {
    [isk_14_ENTRY_0]    { -538.0, -780.0, -217.0,   29.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_14 },
};

#include "isk_09.h"

EntryList N(Entrances) = {
    [isk_09_ENTRY_0]    { -575.0, -390.0,   81.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_09 },
};

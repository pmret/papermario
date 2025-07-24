#include "kmr_24.h"

// skip loading shape/hit/tex for this map
s32 N(map_init)(void) {
    return true;
}

EntryList N(Entrances) = {
    [kmr_24_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

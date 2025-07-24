#include "end_01.h"

s32 N(map_init)(void) {
    return false;
}

EntryList N(Entrances) = {
    [end_01_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

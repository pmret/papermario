#include "end_00.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = 3;
    return FALSE;
}

EntryList N(Entrances) = {
    [end_00_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

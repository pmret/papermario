#include "kkj_03.h"

#include "world/common/todo/SetPlayerSpriteSet2_MapInit.inc.c"

EntryList N(Entrances) = {
    [kkj_03_ENTRY_0]    {  -95.0,    0.0,    0.0,   90.0 },
    [kkj_03_ENTRY_1]    {  630.0,    0.0,    0.0,   90.0 },
    [kkj_03_ENTRY_2]    {  630.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

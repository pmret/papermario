#include "kkj_13.h"

#include "world/common/todo/SetPlayerSpriteSet2_MapInit.inc.c"

EntryList N(Entrances) = {
    [kkj_13_ENTRY_0]    {  -95.0,    0.0,    0.0,   90.0 },
    [kkj_13_ENTRY_1]    { 1295.0,    0.0,    0.0,  270.0 },
    [kkj_13_ENTRY_2]    {  630.0,    0.0,    0.0,   90.0 },
    [kkj_13_ENTRY_3]    {    0.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_13 },
};

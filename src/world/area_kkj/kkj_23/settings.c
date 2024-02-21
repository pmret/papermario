#include "kkj_23.h"

#include "world/common/todo/SetPlayerSpriteSet2_MapInit.inc.c"

EntryList N(Entrances) = {
    [kkj_23_ENTRY_0]    {  735.0,    0.0,  -60.0,  270.0 },
    [kkj_23_ENTRY_1]    {   10.0,    0.0,  -60.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_23 },
};

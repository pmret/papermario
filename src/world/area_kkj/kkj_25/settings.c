#include "kkj_25.h"

#include "world/common/todo/SetPlayerSpriteSet2_MapInit.inc.c"

EntryList N(Entrances) = {
    [kkj_25_ENTRY_0]    { -605.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_25 },
};

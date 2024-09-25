#include "omo_16.h"

EntryList N(Entrances) = {
    [omo_16_ENTRY_0]    { -1460.0,   50.0,    0.0,   90.0 },
    [omo_16_ENTRY_1]    { 1460.0,   50.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
#if VERSION_JP
    .tattle = { MSG_MapTattle_018D },
#endif
};

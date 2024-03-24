#include "omo_06.h"

EntryList N(Entrances) = {
    [omo_06_ENTRY_0]    { -475.0,    0.0,  140.0,   90.0 },
    [omo_06_ENTRY_1]    { -475.0,    0.0, -160.0,   90.0 },
    [omo_06_ENTRY_2]    { -466.0,   10.0,    5.0,   90.0 },
    [omo_06_ENTRY_3]    {  340.0,   10.0, -330.0,  225.0 },
    [omo_06_ENTRY_4]    {  337.0,    0.0,  337.0,  315.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_06 },
};

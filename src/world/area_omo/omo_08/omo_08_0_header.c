#include "omo_08.h"

EntryList N(Entrances) = {
    [omo_08_ENTRY_0]    {  333.0,    0.0,  333.0,  315.0 },
    [omo_08_ENTRY_1]    { -335.0,   10.0, -335.0,  135.0 },
    [omo_08_ENTRY_2]    {  340.0,   10.0, -340.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_08 },
};

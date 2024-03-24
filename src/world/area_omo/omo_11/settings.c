#include "omo_11.h"

EntryList N(Entrances) = {
    [omo_11_ENTRY_0]    { -640.0,    0.0,   20.0,   90.0 },
    [omo_11_ENTRY_1]    {  730.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_11 },
};

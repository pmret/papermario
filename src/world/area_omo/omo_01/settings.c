#include "omo_01.h"

EntryList N(Entrances) = {
    [omo_01_ENTRY_0]    {  350.0,    0.0, -330.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_01 },
};

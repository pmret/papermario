#include "hos_01.h"

EntryList N(Entrances) = {
    [hos_01_ENTRY_0]    { -400.0,    0.0,  410.0,   45.0 },
    [hos_01_ENTRY_1]    {   22.0,  285.0, -190.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_hos_01 },
};

#include "iwa_10.h"

EntryList N(Entrances) = {
    [iwa_10_ENTRY_0]    { -1250.0,   30.0,    0.0,   90.0 },
    [iwa_10_ENTRY_1]    { -445.0,  215.0, -500.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_10 },
};

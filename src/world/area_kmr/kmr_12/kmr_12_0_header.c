#include "kmr_12.h"

EntryList N(Entrances) = {
    [kmr_12_ENTRY_0]    { -126.0,    0.0,   12.0,   90.0 },
    [kmr_12_ENTRY_1]    {  471.0,    0.0,   12.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_12 },
};

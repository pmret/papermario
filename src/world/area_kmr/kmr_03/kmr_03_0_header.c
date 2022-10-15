#include "kmr_03.h"

EntryList N(Entrances) = {
    [kmr_03_ENTRY_0]    { -340.0,    0.0,  348.0,   48.0 },
    [kmr_03_ENTRY_1]    {  480.0,    0.0,    0.0,  270.0 },
    [kmr_03_ENTRY_2]    { -310.0,   20.0,  -80.0,  135.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_03 },
};

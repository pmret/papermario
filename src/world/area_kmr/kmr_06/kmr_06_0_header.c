#include "kmr_06.h"

EntryList N(Entrances) = {
    [kmr_06_ENTRY_0]    { -110.0,    0.0,   33.0,   90.0 },
    [kmr_06_ENTRY_1]    {  850.0,    0.0,   35.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_06 },
};

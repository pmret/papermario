#include "kmr_05.h"

EntryList N(Entrances) = {
    [kmr_05_ENTRY_0]    { -110.0,    0.0,  -19.0,   90.0 },
    [kmr_05_ENTRY_1]    { 1397.0,  200.0, -145.0,  220.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_05 },
};

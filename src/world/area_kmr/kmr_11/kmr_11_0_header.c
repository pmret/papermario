#include "kmr_11.h"

EntryList N(Entrances) = {
    [kmr_11_ENTRY_0]    { -925.0,    0.0,  -53.0,   90.0 },
    [kmr_11_ENTRY_1]    {  770.0,    0.0, -525.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_11 },
};

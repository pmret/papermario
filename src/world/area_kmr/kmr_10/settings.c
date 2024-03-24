#include "kmr_10.h"

EntryList N(Entrances) = {
    [kmr_10_ENTRY_0]    { -840.0,  245.0,  110.0,   90.0 },
    [kmr_10_ENTRY_1]    {  724.0,    0.0,  108.0,  270.0 },
    [kmr_10_ENTRY_2]    {  720.0,  148.0,  135.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_10 },
};

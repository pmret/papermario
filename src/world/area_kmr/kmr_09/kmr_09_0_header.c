#include "kmr_09.h"

EntryList N(Entrances) = {
    [kmr_09_ENTRY_0]    { -127.0,    0.0,   24.0,   90.0 },
    [kmr_09_ENTRY_1]    {  840.0,    0.0,   24.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_09 },
};

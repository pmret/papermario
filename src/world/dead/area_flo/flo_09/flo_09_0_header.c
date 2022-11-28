#include "flo_09.h"

EntryList N(Entrances) = {
    [flo_09_ENTRY_0]    { -520.0,    0.0,    0.0,   90.0 },
    [flo_09_ENTRY_1]    {  520.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_09 },
};

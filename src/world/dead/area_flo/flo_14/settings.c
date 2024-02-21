#include "flo_14.h"

EntryList N(Entrances) = {
    [flo_14_ENTRY_0]    {  720.0,    0.0,    0.0,  270.0 },
    [flo_14_ENTRY_1]    { -720.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_14 },
};

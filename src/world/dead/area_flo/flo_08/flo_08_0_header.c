#include "flo_08.h"

EntryList N(Entrances) = {
    [flo_08_ENTRY_0]    { -870.0,    0.0,    0.0,   90.0 },
    [flo_08_ENTRY_1]    {  570.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_08 },
};

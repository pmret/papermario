#include "flo_23.h"

EntryList N(Entrances) = {
    [flo_23_ENTRY_0]    {  470.0,    0.0,    0.0,  270.0 },
    [flo_23_ENTRY_1]    { -470.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_23 },
};

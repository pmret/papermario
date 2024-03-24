#include "sam_03.h"

EntryList N(Entrances) = {
    [sam_03_ENTRY_0]    { -730.0,    0.0,    0.0,   90.0 },
    [sam_03_ENTRY_1]    {  730.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_03 },
};

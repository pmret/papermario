#include "sam_05.h"

EntryList N(Entrances) = {
    [sam_05_ENTRY_0]    { -730.0,    0.0,  -45.0,   90.0 },
    [sam_05_ENTRY_1]    {  735.0,   95.0,  -50.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_05 },
};

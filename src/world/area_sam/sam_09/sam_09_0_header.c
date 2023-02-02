#include "sam_09.h"

EntryList N(Entrances) = {
    [sam_09_ENTRY_0]    { -565.0,    0.0,    0.0,   90.0 },
    [sam_09_ENTRY_1]    {  580.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_09 },
};

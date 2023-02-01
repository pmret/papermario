#include "sam_01.h"

EntryList N(Entrances) = {
    [sam_01_ENTRY_0]    {  480.0,    0.0,    0.0,  270.0 },
    [sam_01_ENTRY_1]    { -305.0,    0.0, -180.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_01 },
};

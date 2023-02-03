#include "sam_04.h"

EntryList N(Entrances) = {
    [sam_04_ENTRY_0]    { -330.0,    0.0,  340.0,   45.0 },
    [sam_04_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sam_04_ENTRY_2]    {    0.0,    0.0, -250.0,  180.0 },
    [sam_04_ENTRY_3]    { -360.0,   80.0,  -80.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_04 },
};

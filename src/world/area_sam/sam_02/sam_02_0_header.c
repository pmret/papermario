#include "sam_02.h"

EntryList N(Entrances) = {
    [sam_02_ENTRY_0]    { -485.0,    0.0,   50.0,   90.0 },
    [sam_02_ENTRY_1]    {  485.0,    0.0,   50.0,  270.0 },
    [sam_02_ENTRY_2]    {    0.0,   30.0,  270.0,  180.0 },
    [sam_02_ENTRY_3]    {  470.0,    0.0,   50.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_02 },
};

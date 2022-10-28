#include "iwa_00.h"

EntryList N(Entrances) = {
    [iwa_00_ENTRY_0]    {   55.0,   -5.0,  -25.0,   90.0 },
    [iwa_00_ENTRY_1]    { 1313.0,   90.0,  -40.0,  270.0 },
    [iwa_00_ENTRY_2]    {  625.0,  -30.0,  259.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_00 },
};

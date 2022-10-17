
#include "arn_05.h"

EntryList N(Entrances) = {
    [arn_05_ENTRY_0]    {  -77.0,  135.0,  150.0,   90.0 },
    [arn_05_ENTRY_1]    {  577.0,  200.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_arn_05 },
};

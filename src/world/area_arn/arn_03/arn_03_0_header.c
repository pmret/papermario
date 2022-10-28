#include "arn_03.h"

EntryList N(Entrances) = {
    [arn_03_ENTRY_0]    {  -76.0,  165.0,  150.0,   90.0 },
    [arn_03_ENTRY_1]    {  576.0,  225.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_arn_03 },
};

#include "arn_07.h"

EntryList N(Entrances) = {
    [arn_07_ENTRY_0]    {    0.0,   20.0, -147.0,  180.0 },
    [arn_07_ENTRY_1]    {  485.0,    0.0,    0.0,  270.0 },
    [arn_07_ENTRY_2]    { -488.0,    0.0,    0.0,   90.0 },
    [arn_07_ENTRY_3]    {  194.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_arn_07 },
};

#include "arn_08.h"

EntryList N(Entrances) = {
    [arn_08_ENTRY_0]    {  -80.0,    0.0,  108.0,   45.0 },
    [arn_08_ENTRY_1]    {    0.0,    0.0,    0.0,    0.0 },
    [arn_08_ENTRY_2]    {  -85.0,    0.0,   55.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_arn_08 },
};

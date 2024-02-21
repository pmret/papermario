#include "kkj_26.h"

EntryList N(Entrances) = {
    [kkj_26_ENTRY_0]    {  472.0,   30.0,  -26.0,   90.0 },
    [kkj_26_ENTRY_1]    {  540.0,   30.0,  -20.0,   90.0 },
    [kkj_26_ENTRY_2]    {  400.0,   30.0,  -20.0,   90.0 },
    [kkj_26_ENTRY_3]    {  483.0,   30.0,    8.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_26 },
};

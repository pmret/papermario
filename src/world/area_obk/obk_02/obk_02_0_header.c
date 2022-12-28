#include "obk_02.h"

EntryList N(Entrances) = {
    [obk_02_ENTRY_0]    {   67.0,    0.0,  235.0,    0.0 },
    [obk_02_ENTRY_1]    {    0.0, -210.0,  235.0,    0.0 },
    [obk_02_ENTRY_2]    {  220.0, -210.0,   65.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_obk_02 },
};

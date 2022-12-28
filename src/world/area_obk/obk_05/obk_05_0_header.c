#include "obk_05.h"

EntryList N(Entrances) = {
    [obk_05_ENTRY_0]    {  -68.0,    0.0,  235.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_obk_05 },
};

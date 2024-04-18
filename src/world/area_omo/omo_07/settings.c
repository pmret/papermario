#include "omo_07.h"

EntryList N(Entrances) = {
    [omo_07_ENTRY_0]    { -960.0,    0.0,   73.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_07 },
};

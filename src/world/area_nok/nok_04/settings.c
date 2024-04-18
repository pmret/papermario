#include "nok_04.h"

EntryList N(Entrances) = {
    [nok_04_ENTRY_0]    { -336.0,    0.0,  356.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_04 },
};

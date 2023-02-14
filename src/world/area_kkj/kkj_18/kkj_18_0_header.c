#include "kkj_18.h"

EntryList N(Entrances) = {
    [kkj_18_ENTRY_0]    { -187.0,    0.0,  -35.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_18 },
};

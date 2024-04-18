#include "sam_06.h"

EntryList N(Entrances) = {
    [sam_06_ENTRY_0]    { -340.0,    0.0,  340.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_06 },
};

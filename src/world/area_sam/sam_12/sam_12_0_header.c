#include "sam_12.h"

EntryList N(Entrances) = {
    [sam_12_ENTRY_0]    { -372.0,   15.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_sam_12 },
};

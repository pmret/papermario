#include "sam_08.h"

EntryList N(Entrances) = {
    [sam_08_ENTRY_0]    { -1527.0, -120.0,    0.0,   90.0 },
    [sam_08_ENTRY_1]    { -150.0,    0.0,  -80.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sam_08 },
};

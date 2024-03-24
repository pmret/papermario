#include "mim_10.h"

EntryList N(Entrances) = {
    [mim_10_ENTRY_0]    { -385.0,   20.0,   10.0,   90.0 },
    [mim_10_ENTRY_1]    {  385.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mim_10 },
};

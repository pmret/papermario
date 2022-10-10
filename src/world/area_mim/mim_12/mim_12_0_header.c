#include "mim_12.h"

EntryList N(Entrances) = {
    [mim_12_ENTRY_0]    { -380.0,    0.0,   10.0,   90.0 },
    [mim_12_ENTRY_1]    {  380.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mim_12 },
};

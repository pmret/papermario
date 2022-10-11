#include "mim_11.h"

EntryList N(Entrances) = {
    [mim_11_ENTRY_0]    { -635.0,    0.0,    5.0,   90.0 },
    [mim_11_ENTRY_1]    {  635.0,    0.0,    5.0,  270.0 },
    [mim_11_ENTRY_2]    {  117.0,   37.0, -201.0,  227.0 },
    [mim_11_ENTRY_3]    { -270.0,   35.0, -225.0,  180.0 },
    [mim_11_ENTRY_4]    {  -65.0,    0.0,  -22.0,  315.0 },
    [mim_11_ENTRY_5]    {  -56.0,    0.0,  -25.0,  227.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mim_11 },
};

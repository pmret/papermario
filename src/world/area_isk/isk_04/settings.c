#include "isk_04.h"

EntryList N(Entrances) = {
    [isk_04_ENTRY_0]    {  594.0,  -80.0,   84.0,    0.0 },
    [isk_04_ENTRY_1]    {  594.0, -340.0,   84.0,    0.0 },
    [isk_04_ENTRY_2]    {  524.0,   25.0, -169.0,  170.0 },
    [isk_04_ENTRY_3]    {  571.0,  -80.0, -186.0,  170.0 },
    [isk_04_ENTRY_4]    {  524.0, -210.0, -169.0,  170.0 },
    [isk_04_ENTRY_5]    {  543.0,   25.0,    5.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_isk_04 },
};

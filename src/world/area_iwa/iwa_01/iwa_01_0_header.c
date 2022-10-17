#include "iwa_01.h"

EntryList N(Entrances) = {
    [iwa_01_ENTRY_0]    { -786.0,   63.0,  323.0,   90.0 },
    [iwa_01_ENTRY_1]    { -770.0,  163.0,   45.0,   90.0 },
    [iwa_01_ENTRY_2]    {  958.0,  170.0,  173.0,  270.0 },
    [iwa_01_ENTRY_3]    {  989.0,  370.0,  235.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_01 },
};

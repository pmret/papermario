#include "dro_02.h"

EntryList N(Entrances) = {
    [dro_02_ENTRY_0]    { -473.0,    0.0,   12.0,   90.0 },
    [dro_02_ENTRY_1]    {  415.0,   35.0,  -15.0,  180.0 },
    [dro_02_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [dro_02_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_dro_02 },
};

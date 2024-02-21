#include "nok_02.h"

EntryList N(Entrances) = {
    [nok_02_ENTRY_0]    { -484.0,    0.0,    5.0,   90.0 },
    [nok_02_ENTRY_1]    {    2.0,    0.0, -479.0,  180.0 },
    [nok_02_ENTRY_2]    {  365.0,   35.0,   90.0,  180.0 },
    [nok_02_ENTRY_3]    {    0.0,    0.0,  -60.0,    0.0 },
    [nok_02_ENTRY_4]    { -360.0,    0.0,  -50.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_02 },
};

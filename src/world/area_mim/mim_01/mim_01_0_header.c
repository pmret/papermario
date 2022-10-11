#include "mim_01.h"

EntryList N(Entrances) = {
    [mim_01_ENTRY_0]    {    0.0,    0.0, -530.0,  180.0 },
    [mim_01_ENTRY_1]    { -530.0,    0.0,    0.0,   90.0 },
    [mim_01_ENTRY_2]    {    0.0,    0.0,  530.0,    0.0 },
    [mim_01_ENTRY_3]    {  530.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mim_01 },
};

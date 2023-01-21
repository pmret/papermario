#include "hos_02.h"

EntryList N(Entrances) = {
    [hos_02_ENTRY_0]    { -1005.0, -171.0,  225.0,   90.0 },
    [hos_02_ENTRY_1]    { 1160.0,  503.0,  350.0,  270.0 },
    [hos_02_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_02_ENTRY_A]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_hos_02 },
};

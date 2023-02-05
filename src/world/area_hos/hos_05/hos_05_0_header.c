#include "hos_05.h"

EntryList N(Entrances) = {
    [hos_05_ENTRY_0]    {    0.0,   85.0,  390.0,    0.0 },
    [hos_05_ENTRY_1]    {    0.0,  700.0,    0.0,  225.0 },
    [hos_05_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_3]    {    0.0,   85.0,  390.0,    0.0 },
    [hos_05_ENTRY_4]    {    0.0,   85.0,  390.0,    0.0 },
    [hos_05_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_05_ENTRY_A]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_hos_05 },
};

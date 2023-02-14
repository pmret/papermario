#include "kkj_10.h"

EntryList N(Entrances) = {
    [kkj_10_ENTRY_0]    {    0.0,    0.0,  480.0,    0.0 },
    [kkj_10_ENTRY_1]    {    0.0,  100.0, -365.0,  180.0 },
    [kkj_10_ENTRY_2]    { -420.0,   40.0, -260.0,  135.0 },
    [kkj_10_ENTRY_3]    {  230.0,    0.0, -210.0,  180.0 },
    [kkj_10_ENTRY_4]    {  420.0,   40.0, -260.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_10 },
};

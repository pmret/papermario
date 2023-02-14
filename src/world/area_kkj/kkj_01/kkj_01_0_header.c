#include "kkj_01.h"

EntryList N(Entrances) = {
    [kkj_01_ENTRY_0]    {    0.0,    0.0,  480.0,    0.0 },
    [kkj_01_ENTRY_1]    {    0.0,  100.0, -360.0,  180.0 },
    [kkj_01_ENTRY_2]    { -325.0,    0.0,  360.0,   45.0 },
    [kkj_01_ENTRY_3]    { -480.0,    0.0,   50.0,   90.0 },
    [kkj_01_ENTRY_4]    {    0.0,    0.0, -255.0,  180.0 },
    [kkj_01_ENTRY_5]    {  480.0,    0.0,   50.0,  270.0 },
    [kkj_01_ENTRY_6]    {  300.0,    0.0,  380.0,  315.0 },
    [kkj_01_ENTRY_7]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

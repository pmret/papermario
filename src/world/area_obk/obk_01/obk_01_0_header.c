#include "obk_01.h"

EntryList N(Entrances) = {
    [obk_01_ENTRY_0]    {  460.0, -420.0,  630.0,    0.0 },
    [obk_01_ENTRY_1]    {  250.0, -420.0,   15.0,  180.0 },
    [obk_01_ENTRY_2]    {  610.0, -420.0,   15.0,  180.0 },
    [obk_01_ENTRY_3]    {  250.0, -210.0,   15.0,  180.0 },
    [obk_01_ENTRY_4]    {  610.0, -210.0,   15.0,  180.0 },
    [obk_01_ENTRY_5]    {  270.0,    0.0,   15.0,  180.0 },
    [obk_01_ENTRY_6]    {  630.0,    0.0,   15.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_obk_01 },
};

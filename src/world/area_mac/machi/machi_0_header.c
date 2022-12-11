#include "machi.h"

EntryList N(Entrances) = {
    [machi_ENTRY_0]     {    0.0,    0.0, -485.0,    0.0 },
    [machi_ENTRY_1]     {  345.0,    0.0, -345.0,    0.0 },
    [machi_ENTRY_2]     {  485.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_3]     {    0.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_4]     {    0.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_5]     { -345.0,    0.0,  345.0,   45.0 },
    [machi_ENTRY_6]     { -485.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_7]     { -345.0,    0.0, -345.0,    0.0 },
    [machi_ENTRY_8]     {    0.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_9]     {    0.0,    0.0,    0.0,    0.0 },
    [machi_ENTRY_A]     {  354.0,    0.0,  294.0,  117.0 },
    [machi_ENTRY_B]     { -210.0,   35.0, -100.0,  180.0 },
    [machi_ENTRY_C]     { -150.0,   35.0, -100.0,  180.0 },
    [machi_ENTRY_D]     {  -90.0,   35.0, -100.0,  180.0 },
    [machi_ENTRY_E]     {  -90.0,   35.0, -200.0,  180.0 },
    [machi_ENTRY_F]     {  -30.0,   35.0, -200.0,  180.0 },
    [machi_ENTRY_10]    {   30.0,   35.0, -200.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

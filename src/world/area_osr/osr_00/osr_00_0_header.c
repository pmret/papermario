#include "osr_00.h"

EntryList N(Entrances) = {
    [osr_00_ENTRY_0]    {    0.0,    0.0,  604.0,    0.0 },
    [osr_00_ENTRY_1]    {  612.0,    0.0,  111.0,  270.0 },
    [osr_00_ENTRY_2]    {    0.0,    0.0, -260.0,  180.0 },
    [osr_00_ENTRY_3]    {  500.0,   20.0,  100.0,  270.0 },
    [osr_00_ENTRY_4]    {    0.0,    0.0,  300.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

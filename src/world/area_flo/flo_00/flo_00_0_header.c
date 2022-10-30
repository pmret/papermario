#include "flo_00.h"

EntryList N(Entrances) = {
    [flo_00_ENTRY_0]    {    0.0,    0.0, -310.0,  170.0 },
    [flo_00_ENTRY_1]    { -320.0,    0.0, -335.0,  135.0 },
    [flo_00_ENTRY_2]    { -470.0,    0.0,    0.0,   90.0 },
    [flo_00_ENTRY_3]    { -320.0,    0.0,  335.0,   45.0 },
    [flo_00_ENTRY_4]    {  320.0,    0.0, -335.0,  225.0 },
    [flo_00_ENTRY_5]    {  465.0,    0.0,    0.0,  270.0 },
    [flo_00_ENTRY_6]    {  320.0,    0.0,  335.0,  315.0 },
    [flo_00_ENTRY_7]    {  -30.0,    0.0,  120.0,  270.0 },
    [flo_00_ENTRY_8]    {  -30.0,    0.0,  120.0,  270.0 },
    [flo_00_ENTRY_9]    { -470.0,    0.0,    0.0,   90.0 },
    [flo_00_ENTRY_A]    {   40.0,    0.0,  -30.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_00 },
};

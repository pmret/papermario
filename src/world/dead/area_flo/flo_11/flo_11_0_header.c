#include "flo_11.h"

EntryList N(Entrances) = {
    [flo_11_ENTRY_0]    {  470.0,    0.0,  -15.0,  270.0 },
    [flo_11_ENTRY_1]    { -470.0,    0.0,  -15.0,   90.0 },
    [flo_11_ENTRY_2]    {  360.0,   50.0, -237.0,  270.0 },
    [flo_11_ENTRY_3]    {  118.0,   50.0, -420.0,  270.0 },
    [flo_11_ENTRY_4]    {    0.0,   50.0,    0.0,  270.0 },
    [flo_11_ENTRY_5]    { -120.0,   50.0,  357.0,   90.0 },
    [flo_11_ENTRY_6]    { -360.0,   50.0, -240.0,   90.0 },
    [flo_11_ENTRY_7]    { -360.0,   35.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_11 },
};

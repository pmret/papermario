#include "jan_06.h"

EntryList N(Entrances) = {
    [jan_06_ENTRY_0]    {    0.0,    0.0,  470.0,    0.0 },
    [jan_06_ENTRY_1]    {  470.0,    0.0,    0.0,  270.0 },
    [jan_06_ENTRY_2]    {    0.0,    0.0, -470.0,  180.0 },
    [jan_06_ENTRY_3]    { -470.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_06 },
};

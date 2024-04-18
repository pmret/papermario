#include "isk_11.h"

EntryList N(Entrances) = {
    [isk_11_ENTRY_0]    { -277.0, -520.0,  529.0,  105.0 },
    [isk_11_ENTRY_1]    {  338.0, -470.0,  434.0,  240.0 },
    [isk_11_ENTRY_2]    {  370.0, -600.0,  472.0,  240.0 },
    [isk_11_ENTRY_3]    {  180.0, -910.0,  552.0,  260.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_11 },
};

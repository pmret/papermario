#include "mac_04.h"

EntryList N(Entrances) = {
    [mac_04_ENTRY_0]    {  610.0,    0.0,    0.0,  280.0 },
    [mac_04_ENTRY_1]    { -420.0,    0.0,  430.0,   35.0 },
    [mac_04_ENTRY_2]    { -490.0,   20.0, -150.0,  180.0 },
    [mac_04_ENTRY_3]    { -420.0,   20.0,  -95.0,    0.0 },
    [mac_04_ENTRY_4]    {    0.0, -100.0,    0.0,    0.0 },
    [mac_04_ENTRY_5]    { -420.0,   20.0,  235.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mac_04 },
};

s32 N(map_init)(void) {
    if (gGameStatusPtr->entryID == mac_04_ENTRY_4) {
        sprintf(wMapBgName, "hos_bg");
    }
    return FALSE;
}

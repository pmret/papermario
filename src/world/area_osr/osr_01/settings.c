#include "osr_01.h"

s32 N(map_init)(void) {
    if (gGameStatusPtr->entryID == osr_01_ENTRY_3) {
        sprintf(wMapBgName, "hos_bg");
    }
    return FALSE;
}

EntryList N(Entrances) = {
    [osr_01_ENTRY_0]    {    0.0,    0.0,  604.0,    0.0 },
    [osr_01_ENTRY_1]    {  612.0,    0.0,  111.0,  270.0 },
    [osr_01_ENTRY_2]    {    0.0,    0.0, -290.0,  180.0 },
    [osr_01_ENTRY_3]    {    0.0, -1000.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_osr_01 },
};

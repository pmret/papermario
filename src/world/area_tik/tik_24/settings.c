#include "tik_24.h"

s32 N(map_init)(void) {
    sprintf((s8*) &wMapShapeName, "tik_18_shape");
    sprintf((s8*) &wMapHitName, "tik_18_hit");
    return false;
}

//TODO these shouldnt need to be declared outside of tik_24_2_main
//however, doing so creates extra rodata padding (not OK)
const char STR_TIK_25[] = "tik_25";
const char STR_TIK_23[] = "tik_23";

EntryList N(Entrances) = {
    [tik_24_ENTRY_0]    { -220.0,  -10.0,    0.0,   90.0 },
    [tik_24_ENTRY_1]    {  320.0,  -10.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_24 },
};

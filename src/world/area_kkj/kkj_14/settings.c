#include "kkj_14.h"

s32 N(map_init)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) == STORY_INTRO) {
        sprintf(wMapBgName, "nok_bg");
    }
    return FALSE;
}

EntryList N(Entrances) = {
    [kkj_14_ENTRY_0]    { -375.0,    0.0,  -30.0,   90.0 },
    [kkj_14_ENTRY_1]    {  435.0,   30.0,  -33.0,  270.0 },
    [kkj_14_ENTRY_2]    { -122.0,   10.0,  -82.0,  180.0 },
    [kkj_14_ENTRY_3]    {  -20.0,    0.0,   30.0,  270.0 },
    [kkj_14_ENTRY_4]    { -140.0,    0.0,    0.0,  270.0 },
    [kkj_14_ENTRY_5]    {   40.0,    0.0,   30.0,  180.0 },
    [kkj_14_ENTRY_6]    {  -20.0,    0.0,    0.0,  270.0 },
    [kkj_14_ENTRY_7]    {    0.0,    0.0,   30.0,  180.0 },
    [kkj_14_ENTRY_8]    { -130.0,    0.0,    0.0,  180.0 },
    [kkj_14_ENTRY_9]    {  -60.0,    0.0,    0.0,  270.0 },
    [kkj_14_ENTRY_A]    {  380.0,   30.0,   10.0,  270.0 },
    [kkj_14_ENTRY_B]    {  150.0,    0.0,  -30.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_14 },
};

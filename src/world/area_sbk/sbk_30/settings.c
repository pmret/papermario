#include "sbk_30.h"

s32 N(get_tattle)(void) {
    s32 tattle;
    if (evt_get_variable(nullptr, GB_StoryProgress) > STORY_CH2_STAR_SPRIT_DEPARTED) {
        tattle = MSG_MapTattle_sbk_30_after;
    } else {
        tattle = MSG_MapTattle_sbk_30_before;
    }
    return  tattle;
}

EntryList N(Entrances) = {
    [sbk_30_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_30_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_30_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_30_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_30_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [sbk_30_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};

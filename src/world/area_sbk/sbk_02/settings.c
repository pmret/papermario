#include "sbk_02.h"

s32 N(get_tattle)(void) {
    s32 tattle;
    if (evt_get_variable(nullptr, GB_StoryProgress) > STORY_CH2_GOT_PULSE_STONE) {
        tattle = MSG_MapTattle_sbk_02_after;
    } else {
        tattle = MSG_MapTattle_sbk_02_before;
    }
    return tattle;
}

EntryList N(Entrances) = {
    [sbk_02_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_02_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_02_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_02_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_02_ENTRY_4]    {    0.0,   80.0, -195.0,  180.0 },
    [sbk_02_ENTRY_5]    {   20.0,    0.0,  110.0,  270.0 },
    [sbk_02_ENTRY_6]    {  -80.0,    0.0,   80.0,  180.0 },
    [sbk_02_ENTRY_7]    {   80.0,    0.0,   80.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};

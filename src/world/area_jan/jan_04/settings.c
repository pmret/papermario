#include "jan_04.h"

s32 N(get_tattle)(void) {
    if (evt_get_variable(nullptr, GB_StoryProgress) < STORY_CH5_SUSHIE_JOINED_PARTY) {
        return MSG_MapTattle_jan_04_before;
    } else {
        return MSG_MapTattle_jan_04_after;
    }
}

EntryList N(Entrances) = {
    [jan_04_ENTRY_0]    { -483.0,    0.0,    0.0,   90.0 },
    [jan_04_ENTRY_1]    {    0.0, -100.0,    0.0,   90.0 },
    [jan_04_ENTRY_2]    {    0.0, -100.0,    0.0,   90.0 },
    [jan_04_ENTRY_3]    {    0.0, -100.0,    0.0,   90.0 },
    [jan_04_ENTRY_4]    { -110.0,  -15.0,  204.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};

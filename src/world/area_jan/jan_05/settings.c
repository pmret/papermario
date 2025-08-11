#include "jan_05.h"

s32 N(get_tattle)(void) {
    if (evt_get_variable(nullptr, GB_StoryProgress) < STORY_CH5_SUSHIE_JOINED_PARTY) {
        return MSG_MapTattle_jan_05_before;
    } else {
        return MSG_MapTattle_jan_05_after;
    }
}

EntryList N(Entrances) = {
    [jan_05_ENTRY_0]    {  330.0,    0.0,  330.0,  315.0 },
    [jan_05_ENTRY_1]    { -500.0,  -20.0,    0.0,   90.0 },
    [jan_05_ENTRY_2]    {  480.0,    0.0,    0.0,  270.0 },
    [jan_05_ENTRY_3]    {    0.0,    0.0, -450.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};

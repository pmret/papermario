#include "sam_11.h"

s32 N(get_tattle)(void) {
    if (evt_get_variable(nullptr, GB_StoryProgress) < STORY_CH7_SHATTERED_FROZEN_POND) {
        return MSG_MapTattle_sam_11_before;
    } else {
        return MSG_MapTattle_sam_11_after;
    }
}

EntryList N(Entrances) = {
    [sam_11_ENTRY_0]    { -480.0,    0.0,    0.0,   90.0 },
    [sam_11_ENTRY_1]    {  455.0,    0.0,    0.0,  270.0 },
    [sam_11_ENTRY_2]    {  325.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};

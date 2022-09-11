#include "jan_04.h"

static char* N(exit_str_0) = "kmr_24";
static char* N(exit_str_1) = "jan_05";

s32 N(get_tattle)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_CH5_SUSHIE_JOINED_PARTY) {
        return MSG_MapTattle_jan_04_before;
    } else {
        return MSG_MapTattle_jan_04_after;
    }
}

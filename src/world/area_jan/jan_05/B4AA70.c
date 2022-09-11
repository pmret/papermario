#include "jan_05.h"

static char* N(exit_str_0) = "jan_03";
static char* N(exit_str_1) = "jan_08";
static char* N(exit_str_2) = "jan_04";
static char* N(exit_str_3) = "jan_06";

s32 N(get_tattle)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_CH5_SUSHIE_JOINED_PARTY) {
        return MSG_MapTattle_jan_05_before;
    } else {
        return MSG_MapTattle_jan_05_after;
    }
}

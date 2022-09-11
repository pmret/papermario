#include "kzn_18.h"

static char* N(exit_str_0) = "kzn_17";
static char* N(exit_str_1) = "kzn_19";

s32 N(get_tattle)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_CH5_STAR_SPRIT_DEPARTED) {
        return MSG_MapTattle_kzn_18_before;
    } else {
        return MSG_MapTattle_kzn_18_after;
    }
}

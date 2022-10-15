#include "flo_10.h"
#include "message_ids.h"

s32 N(get_tattle)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_CH6_FILLED_SPRING_WITH_WATER) {
        return MSG_MapTattle_flo_10_before;
    } else {
        return MSG_MapTattle_flo_10_after;
    }
}

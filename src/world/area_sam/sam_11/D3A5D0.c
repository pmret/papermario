#include "sam_11.h"

static char* N(exit_str_0) = "sam_02";
static char* N(exit_str_1) = "sam_03";
static char* N(exit_str_2) = "kmr_20";
static char* N(exit_str_3) = "";

s32 N(get_tattle)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_CH7_SHATTERED_FROZEN_POND) {
        return MSG_MapTattle_sam_11_before;
    } else {
        return MSG_MapTattle_sam_11_after;
    }
}

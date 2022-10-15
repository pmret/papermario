#include "kzn_18.h"
#include "message_ids.h"

s32 func_80240000_EA6FD0(void) {
    s32 temp = evt_get_variable(NULL, GB_StoryProgress);

    if (temp <= 0x26) {
        return MSG_MapTattle_kzn_18_before;
    } else {
        return MSG_MapTattle_kzn_18_after;
    }
}

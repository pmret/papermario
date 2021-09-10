#include "dead.h"
#include "common.h"

s32 func_80240000_EA6FD0(void) {
    s32 temp = evt_get_variable(NULL, EVT_STORY_PROGRESS);

    if (temp <= 0x26) {
        return 0x19010F;
    } else {
        return 0x190110;
    }
}

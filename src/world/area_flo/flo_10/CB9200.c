#include "flo_10.h"

s32 N(func_80240000_CB9200)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) <= 0x30) {
        return MESSAGE_ID(0x19, 0x0119);
    }
    return MESSAGE_ID(0x19, 0x011A);
}

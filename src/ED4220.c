#include "dead.h"
#include "common.h"

// Copy of flo_10 (CBP200.c)

#define NAMESPACE ED4220

s32 func_80240000_ED4220(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) <= 0x30) {
        return MESSAGE_ID(0x19, 0x0119);
    }
    return MESSAGE_ID(0x19, 0x011A);
}

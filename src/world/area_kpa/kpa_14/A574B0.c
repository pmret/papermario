#include "kpa_14.h"

static char* N(exit_str_0) = "kpa_13";
static char* N(exit_str_1) = "kpa_01";
static char* N(exit_str_2) = "kpa_16";

s32 func_80240000_A574B0(void) {
    if (evt_get_variable(NULL, GameFlag(1556)) == 0) {
        return 0x190164;
    } else {
        return 0x190165;
    }
}

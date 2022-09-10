#include "kpa_13.h"

static char* N(exit_str_0) = "kpa_12";
static char* N(exit_str_1) = "kpa_15";
static char* N(exit_str_2) = "kpa_14";

s32 func_80240000_A55F20(void) {
    if (evt_get_variable(NULL, GSWF(1556)) == 0) {
        return 0x190162;
    } else {
        return 0x190163;
    }
}

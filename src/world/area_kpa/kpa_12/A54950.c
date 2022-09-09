#include "kpa_12.h"

static char* N(exit_str_0) = "kpa_10";
static char* N(exit_str_1) = "kpa_11";
static char* N(exit_str_2) = "kpa_13";

s32 func_80240000_A54950(void) {
    if (evt_get_variable(NULL, GF_KPA16_ShutOffLava) == 0) {
        return 0x190160;
    } else {
        return 0x190161;
    }
}

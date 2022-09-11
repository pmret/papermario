#include "kpa_13.h"

static char* N(exit_str_0) = "kpa_12";
static char* N(exit_str_1) = "kpa_15";
static char* N(exit_str_2) = "kpa_14";

s32 N(get_tattle)(void) {
    if (!evt_get_variable(NULL, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_13_before;
    } else {
        return MSG_MapTattle_kpa_13_after;
    }
}

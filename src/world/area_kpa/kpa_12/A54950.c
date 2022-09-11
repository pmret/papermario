#include "kpa_12.h"

static char* N(exit_str_0) = "kpa_10";
static char* N(exit_str_1) = "kpa_11";
static char* N(exit_str_2) = "kpa_13";

s32 N(get_tattle)(void) {
    if (!evt_get_variable(NULL, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_12_before;
    } else {
        return MSG_MapTattle_kpa_12_after;
    }
}

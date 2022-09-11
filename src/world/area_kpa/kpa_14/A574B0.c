#include "kpa_14.h"

static char* N(exit_str_0) = "kpa_13";
static char* N(exit_str_1) = "kpa_01";
static char* N(exit_str_2) = "kpa_16";

s32 N(get_tattle)(void) {
    if (!evt_get_variable(NULL, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_14_before;
    } else {
        return MSG_MapTattle_kpa_14_after;
    }
}

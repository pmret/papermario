#include "kpa_96.h"

static char* N(exit_str_0) = "kpa_32";
static char* N(exit_str_1) = "";

ApiStatus func_80240000_A927C0(Evt* script, s32 isInitialCall) {
    if (gPlayerData.coins > 0) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

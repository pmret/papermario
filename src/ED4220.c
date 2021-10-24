#include "dead.h"
#include "common.h"

ApiStatus func_80240000_ED4220(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(NULL, EVT_SAVE_VAR(0)) <= 0x30) {
        return 0x190119;
    } else {
        return 0x19011A;
    }
}

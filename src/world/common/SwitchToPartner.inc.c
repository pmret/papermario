#include "common.h"

ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall) {
    switch_to_partner(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "common.h"

API_CALLABLE(N(SwitchToPartner)) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

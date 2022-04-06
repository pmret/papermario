#include "common.h"

ApiStatus N(TempSuperBlockAlpha)(Evt* script, s32 isInitialCall) {
    entity_upgrade_block_hide_content(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

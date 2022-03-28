#include "mgm_02.h"

extern s32 D_802484C0_E1E240; /* TODO: assign proper type for this data */

ApiStatus func_802423D0_E18150(Evt* script, s32 isInitialCall) {
    set_message_images(&D_802484C0_E1E240);
    return ApiStatus_DONE2;
}

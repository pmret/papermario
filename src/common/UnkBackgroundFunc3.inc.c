#include "common.h"
#include "model.h"

API_CALLABLE(N(UnkBackgroundFunc3)) {
    mdl_set_all_tint_type(ENV_TINT_SHROUD);
    *gBackgroundTintModePtr = ENV_TINT_SHROUD;
    mdl_set_shroud_tint_params(0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "kzn_10.h"

#define UNK_FUNC_50_VAR1 -469.0
#define UNK_FUNC_50_VAR2 46.0

ApiStatus N(SpinyTrompHit)(Evt* script, s32 isInitialCall) {
    subtract_hp(1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kzn/kzn_10/C7E4B0", func_80240350_C7E4D0);

#include "world/common/UnkFunc46.inc.c"

#include "world/common/UnkFunc47.inc.c"

#include "world/common/UnkFunc48.inc.c"

#include "world/common/UnkFunc49.inc.c"

#include "world/common/UnkFunc50.inc.c"

#include "world/common/UnkFunc51.inc.c"

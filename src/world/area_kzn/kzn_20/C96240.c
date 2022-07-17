#include "kzn_20.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240654_C96584);

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802406A8_C965D8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802406E0_C96610);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

ApiStatus func_80240A68_C96998(Evt* script, s32 isInitialCall) {
    snd_ambient_80055618(0, 1);
    return ApiStatus_DONE2;
}


#include "world/common/GetFloorCollider.inc.c"

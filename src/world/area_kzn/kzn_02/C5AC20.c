#include "kzn_02.h"

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_02/C5AC20", func_80242310_C5CA50);

INCLUDE_ASM(s32, "world/area_kzn/kzn_02/C5AC20", func_80242364_C5CAA4);

INCLUDE_ASM(s32, "world/area_kzn/kzn_02/C5AC20", func_8024239C_C5CADC);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

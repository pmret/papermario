#include "obk_03.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_802404B4_BC4734);

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240508_BC4788);

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240540_BC47C0);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

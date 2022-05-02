#include "hos_06.h"

#include "world/common/StashVars.inc.c"

#define NAMESPACE dup2_hos_06
#include "world/common/GetItemName.inc.c"
#define NAMESPACE hos_06

#define NAMESPACE dup_hos_06
#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE hos_06

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240654_A39B34);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406A8_A39B88);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406E0_A39BC0);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240A68_A39F48);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240A94_A39F74);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240AD0_A39FB0);

#include "kzn_17.h"

#include "world/common/enemy/MeleeHitbox_30.inc.c"
#include "world/common/enemy/MeleeHitbox_31.inc.c"
#include "world/common/enemy/MeleeHitbox_32.inc.c"
#include "world/common/enemy/MeleeHitbox_33.inc.c"
#include "world/common/enemy/MeleeHitbox_CanSeePlayer.inc.c"
#include "world/common/enemy/MeleeHitbox_Control.inc.c"
#include "world/common/enemy/MeleeHitbox_Main.inc.c"

#include "world/common/enemy/PiranhaPlantAI_00.inc.c"
#include "world/common/enemy/PiranhaPlantAI_01.inc.c"

// Data migration (PiranhaPlantAI_10)
INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240D48_C867F8);

#include "world/common/enemy/PiranhaPlantAI_11.inc.c"
#include "world/common/enemy/PiranhaPlantAI_12.inc.c"
#include "world/common/enemy/PiranhaPlantAI_13.inc.c"
#include "world/common/enemy/PiranhaPlantAI_14.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241A64_C87514);

#include "world/common/enemy/LungeAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024296C_C8841C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242C84_C88734);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242CC8_C88778);

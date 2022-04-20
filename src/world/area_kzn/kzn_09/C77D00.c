#include "kzn_09.h"

#include "world/common/enemy/MeleeHitbox_30.inc.c"
#include "world/common/enemy/MeleeHitbox_31.inc.c"
#include "world/common/enemy/MeleeHitbox_32.inc.c"
#include "world/common/enemy/MeleeHitbox_33.inc.c"
#include "world/common/enemy/MeleeHitbox_CanSeePlayer.inc.c"
#include "world/common/enemy/MeleeHitbox_Control.inc.c"
#include "world/common/enemy/MeleeHitbox_Main.inc.c"

#include "world/common/enemy/PiranhaPlantAI_00.inc.c"
#include "world/common/enemy/PiranhaPlantAI_01.inc.c"

// matches PiranhaPlantAI_10, but requires data in kzn_03 to be migrated due to an invalid symbol
INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80241A58_C78738);

#include "world/common/enemy/PiranhaPlantAI_11.inc.c"
#include "world/common/enemy/PiranhaPlantAI_12.inc.c"
#include "world/common/enemy/PiranhaPlantAI_13.inc.c"
#include "world/common/enemy/PiranhaPlantAI_14.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242774_C79454);

#include "world/common/enemy/LungeAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802435F0_C7A2D0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243644_C7A324);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024367C_C7A35C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243994_C7A674);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802439D8_C7A6B8);

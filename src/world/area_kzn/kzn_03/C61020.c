#include "kzn_03.h"

// spike top
#include "world/common/atomic/enemy/UnkAI_5.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

// hitbox piranha plant
#include "world/common/AttackAheadHitboxAI_30.inc.c"
#include "world/common/AttackAheadHitboxAI_31.inc.c"
#include "world/common/AttackAheadHitboxAI_32.inc.c"
#include "world/common/AttackAheadHitboxAI_33.inc.c"
#include "world/common/AttackAheadHitbox_CanSeePlayer.inc.c"
#include "world/common/AttackAheadHitbox_Control.inc.c"
#include "world/common/AttackAheadHitbox_Main.inc.c" // unused?

// main piranha plant
#include "world/common/atomic/enemy/PiranhaPlant.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802428E0_C635F0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242934_C63644);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024296C_C6367C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242C84_C63994);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242CC8_C639D8);

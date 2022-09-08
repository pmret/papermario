#include "dead.h"
#include "common.h"
#include "effects.h"
#include "dead_structs.h"

// Copy of flo_08 (CAFAC0.c)

#define NAMESPACE ECAA80

extern s32 N(ItemChoiceList)[];
extern s32 N(FlowerGuard_ItemChoiceList)[91];

void ECAA80_UnkFloAI_Chase(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory);

#include "world/common/enemy/UnkFloAI.inc.c"

// following four functions can be folded into this combined include when the last two are done
// #include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// ECAA80_ItemChoice_WaitForSelection (needs data?)
INCLUDE_ASM(s32, "ECAA80", func_8024199C_ECB69C);

// ECAA80_ItemChoice_SaveSelected (needs data?)
INCLUDE_ASM(s32, "ECAA80", func_802419F0_ECB6F0);

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"

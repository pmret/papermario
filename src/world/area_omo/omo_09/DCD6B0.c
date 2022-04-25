#include "omo_09.h"

#include "world/common/enemy/ShyGuyAI.inc.c"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241DDC_DCEAAC);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241E4C_DCEB1C);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241F1C_DCEBEC);

#define NAMESPACE dup_omo_09
#include "world/common/UnkNpcDurationAnimationFunc.inc.c"
#define NAMESPACE omo_09

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80242014_DCECE4);

#include "world/common/enemy/ProjectileAI.inc.c"

#include "world/common/SetNpcB5_3.inc.c"

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

#define NAMESPACE dup_omo_09
#include "world/common/SetNpcB5_3.inc.c"
#define NAMESPACE omo_09

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

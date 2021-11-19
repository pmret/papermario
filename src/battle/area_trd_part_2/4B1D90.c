#include "common.h"

#define NAMESPACE b_area_trd_part_2

#include "common/StartRumbleWithParams.inc.c"

// Requires data migration to match
#ifdef NON_MATCHING
#include "common/UnkWhirlwindEffectFunc.inc.c"
#else
INCLUDE_ASM(s32, "battle/area_trd_part_2/4B1D90", func_80218BF8_4B1DE8);
#endif

#include "common/UnkEnemyFunc.inc.c"

INCLUDE_ASM(s32, "battle/area_trd_part_2/4B1D90", func_80218D70_4B1F60);

#include "common/GetLastActorEventType.inc.c"

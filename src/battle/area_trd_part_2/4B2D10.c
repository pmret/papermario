#include "common.h"

#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup_b_area_trd_part_2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_trd_part_2

// Requires data migration to match
#ifdef NON_MATCHING
#define NAMESPACE dup_b_area_trd_part_2
#include "common/UnkWhirlwindEffectFunc.inc.c"
#define NAMESPACE b_area_trd_part_2
#else
INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2D10", func_80219B78_4B2D68);
#endif

#define NAMESPACE dup_b_area_trd_part_2
#include "common/UnkEnemyFunc.inc.c"
#define NAMESPACE b_area_trd_part_2

INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2D10", func_80219CF0_4B2EE0);

#define NAMESPACE dup_b_area_trd_part_2
#include "common/GetLastActorEventType.inc.c"
#define NAMESPACE b_area_trd_part_2

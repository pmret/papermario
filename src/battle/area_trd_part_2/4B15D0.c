#include "common.h"

#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup3_b_area_trd_part_2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_trd_part_2

// Requires data migration to match
#ifdef NON_MATCHING
#define NAMESPACE dup3_b_area_trd_part_2
#include "common/UnkWhirlwindEffectFunc.inc.c"
#define NAMESPACE b_area_trd_part_2
#else
INCLUDE_ASM(s32, "battle/area_trd_part_2/4B15D0", func_80218438_4B1628);
#endif

#define NAMESPACE dup3_b_area_trd_part_2
#include "common/UnkEnemyFunc.inc.c"
#define NAMESPACE b_area_trd_part_2

INCLUDE_ASM(s32, "battle/area_trd_part_2/4B15D0", func_802185B0_4B17A0);

#define NAMESPACE dup3_b_area_trd_part_2
#include "common/GetLastActorEventType.inc.c"
#define NAMESPACE b_area_trd_part_2

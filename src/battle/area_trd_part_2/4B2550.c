#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup4_b_area_trd_part_2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_trd_part_2

// Requires data migration to match
#ifdef NON_MATCHING
#define NAMESPACE dup4_b_area_trd_part_2
#include "common/UnkWhirlwindEffectFunc.inc.c"
#define NAMESPACE b_area_trd_part_2
#else
INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2550", func_802193B8_4B25A8);
#endif

//INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2550", dup4_b_area_trd_part_2_UnkEnemyFunc);
#define NAMESPACE dup4_b_area_trd_part_2
#include "common/UnkEnemyFunc.inc.c"
#define NAMESPACE b_area_trd_part_2

INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2550", func_80219530_4B2720);

#define NAMESPACE dup4_b_area_trd_part_2
#include "common/GetLastActorEventType.inc.c"
#define NAMESPACE b_area_trd_part_2

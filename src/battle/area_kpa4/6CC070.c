#include "common.h"

#define NAMESPACE b_area_kpa4

INCLUDE_ASM(s32, "battle/area_kpa4/6CC070", func_80218000_6CC070);

INCLUDE_ASM(s32, "battle/area_kpa4/6CC070", func_80218020_6CC090);

#define NAMESPACE dup_p_area_kpa4
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_kpa4

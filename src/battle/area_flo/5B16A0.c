#include "common.h"

#define NAMESPACE b_area_flo

#include "common/UnkFloatFunc.inc.c"

#define NAMESPACE dup_b_area_flo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_flo

INCLUDE_ASM(s32, "battle/area_flo/5B16A0", func_8021844C_5B18FC);

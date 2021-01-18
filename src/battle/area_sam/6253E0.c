#include "common.h"

#define NAMESPACE b_area_sam

INCLUDE_ASM(s32, "battle/area_sam/6253E0", func_80219840_6253E0);

#include "common/GetSelectedMoveID.inc.c"

#define NAMESPACE dup2_b_area_sam
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_sam

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_sam/6253E0", func_80219AE8_625688);

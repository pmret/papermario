#include "common.h"

#define NAMESPACE b_area_flo

INCLUDE_ASM(s32, "battle/area_flo/5B1A10", func_80218560_5B1A10);

#define NAMESPACE dup_b_area_flo
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_flo

#define NAMESPACE dup2_b_area_flo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_flo

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_flo/5B1A10", func_80218808_5B1CB8);

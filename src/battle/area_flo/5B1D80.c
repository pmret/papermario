#include "common.h"

#define NAMESPACE b_area_flo

INCLUDE_ASM(s32, "battle/area_flo/5B1D80", func_802188D0_5B1D80);

#include "common/GetSelectedMoveID.inc.c"

#define NAMESPACE dup3_b_area_flo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_flo

#define NAMESPACE dup_b_area_flo
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_flo

INCLUDE_ASM(s32, "battle/area_flo/5B1D80", func_80218B78_5B2028);

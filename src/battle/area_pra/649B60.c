#include "common.h"

#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649B60", func_80218D50_649B60);

#include "common/GetSelectedMoveID.inc.c"

#define NAMESPACE dup4_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup3_b_area_pra
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649B60", func_80218FF8_649E08);

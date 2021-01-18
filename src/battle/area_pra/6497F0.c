#include "common.h"

#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/6497F0", func_802189E0_6497F0);

#define NAMESPACE dup2_b_area_pra
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup3_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup2_b_area_pra
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/6497F0", func_80218C88_649A98);

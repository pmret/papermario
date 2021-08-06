#include "common.h"

#define NAMESPACE b_area_pra

#define NAMESPACE dup_b_area_pra
#include "common/ShrinkActor.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup4_b_area_pra
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup2_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup_b_area_pra
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649480", func_80218918_649728);

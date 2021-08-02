#include "common.h"

#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649050", func_80218240_649050);

#include "common/ShrinkActor.inc.c"

#define NAMESPACE dup3_b_area_pra
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_pra/649050", func_802185A8_6493B8);

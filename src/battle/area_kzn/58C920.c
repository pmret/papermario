#include "common.h"

#define NAMESPACE b_area_kzn

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

#define NAMESPACE dup3_b_area_kzn
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kzn

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_kzn/58C920", func_802188D8_58CBC8);

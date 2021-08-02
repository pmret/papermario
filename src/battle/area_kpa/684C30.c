#include "common.h"

#define NAMESPACE b_area_kpa

#include "common/ShrinkActor.inc.c"

#include "common/UnkFloatFunc.inc.c"

#include "common/GetSelectedMoveID.inc.c"

#define NAMESPACE dup2_b_area_kpa
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kpa

#define NAMESPACE dup_b_area_kpa
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_kpa

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_80218638_685068);

#include "common.h"

#define NAMESPACE b_area_sam2

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

#include "common/UnkBattleFunc1.inc.c"

#define NAMESPACE dup2_b_area_sam2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_sam2

INCLUDE_ASM(s32, "battle/area_sam2/63D9F0", func_80218AB8_63DC98);

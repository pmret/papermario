#include "common.h"

#define NAMESPACE b_area_kzn

#define NAMESPACE dup_b_area_kzn
#include "common/ShrinkActor.inc.c"
#define NAMESPACE b_area_kzn

#define NAMESPACE dup_b_area_kzn
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_kzn

#define NAMESPACE dup4_b_area_kzn
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kzn

#define NAMESPACE dup_b_area_kzn
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_kzn

INCLUDE_ASM(s32, "battle/area_kzn/58CC90", func_80218C48_58CF38);

#include "common/GetBootsHammerLevel.inc.c"

#include "common/UnkBattleFunc5.inc.c"

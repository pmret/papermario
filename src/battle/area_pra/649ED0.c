#include "common.h"

#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649ED0", func_802190C0_649ED0);

#define NAMESPACE dup_b_area_pra
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup5_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup4_b_area_pra
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649ED0", func_80219368_64A178);

#include "common/UnkBattleFunc3.inc.c"

#include "common/UnkBattleFunc5.inc.c"

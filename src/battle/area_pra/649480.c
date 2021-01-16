#include "common.h"

#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649480", func_80218670_649480);

INCLUDE_ASM(s32, "battle/area_pra/649480", func_802187C8_6495D8);

#define NAMESPACE dup2_b_area_pra
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra

#define NAMESPACE dup_b_area_pra
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_pra

INCLUDE_ASM(s32, "battle/area_pra/649480", func_80218918_649728);

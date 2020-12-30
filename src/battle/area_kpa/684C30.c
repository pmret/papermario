#include "common.h"

#define NAMESPACE b_area_kpa

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_80218200_684C30);

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_80218358_684D88);

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_802184E8_684F18);

#define NAMESPACE dup2_b_area_kpa
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kpa

#define NAMESPACE dup_b_area_kpa
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_kpa

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_80218638_685068);

INCLUDE_ASM(s32, "battle/area_kpa/684C30", func_80218700_685130);

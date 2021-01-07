#include "common.h"

#define NAMESPACE b_area_omo

#define NAMESPACE dup6_b_area_omo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_omo

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_802185AC_512B7C);

#define NAMESPACE dup7_b_area_omo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_omo

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_8021878C_512D5C);

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_80218880_512E50);

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_80218A98_513068);

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_80218B38_513108);

INCLUDE_ASM(s32, "battle/area_omo/512AB0", func_80218CF4_5132C4);

#include "common/StartRumbleWithParams.inc.c"

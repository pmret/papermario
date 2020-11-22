#include "kmr_09.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240000_8D5E00);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_802401B0_8D5FB0);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240898_8D6698);

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240C54_8D6A54);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240CC0_8D6AC0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240DF4_8D6BF4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_80240E58_8D6C58);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_802411E8_8D6FE8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_09/8D5E00", func_8024130C_8D710C);

ApiStatus func_802414F8_8D72F8(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_enemy_safe(2);

    return ApiStatus_DONE2;
}

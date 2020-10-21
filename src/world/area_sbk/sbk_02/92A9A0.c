#include "common.h"

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802406F0_92A9A0);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024074C_92A9FC);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240970);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802409A8);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240A44);

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240B5C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240B98_92AE48);

ApiStatus func_80240BD4(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

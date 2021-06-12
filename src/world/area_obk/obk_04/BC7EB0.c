#include "obk_04.h"

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240050_BC7EB0);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802400D0_BC7F30);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240198_BC7FF8);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_8024022C_BC808C);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802402A0_BC8100);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802402F4_BC8154);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802405B4_BC8414);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240624_BC8484);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240910_BC8770);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240940_BC87A0);
/*
ApiStatus N(func_80240940_BC87A0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80243A10_BCB870) == NULL) {
        N(D_80243A10_BCB870) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80243A10_BCB870)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80243A10_BCB870)[i];
        }
        heap_free(N(D_80243A10_BCB870));
        N(D_80243A10_BCB870) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240A58_BC88B8);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240C10_BC8A70);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240CA0_BC8B00);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240D00_BC8B60);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240D14_BC8B74);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240E58_BC8CB8);

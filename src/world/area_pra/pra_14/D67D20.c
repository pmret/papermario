#include "pra_14.h"

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_802400EC_D67DEC);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240128_D67E28);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_802402F0_D67FF0);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_8024049C_D6819C);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240500_D68200);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_8024068C_D6838C);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240870_D68570);

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240D3C_D68A3C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240F20_D68C20);
/*
ApiStatus N(func_80240F20_D68C20)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

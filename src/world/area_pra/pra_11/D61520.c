#include "pra_11.h"

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_802400EC_D615EC);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240128_D61628);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_802402F0_D617F0);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_8024049C_D6199C);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240500_D61A00);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_8024068C_D61B8C);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240870_D61D70);

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240D3C_D6223C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240F20_D62420);
/*
ApiStatus N(func_80240F20_D62420)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &D_80241C68_BE09F8;
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
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
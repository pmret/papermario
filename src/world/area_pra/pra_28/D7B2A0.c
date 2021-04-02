#include "pra_28.h"

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240000_D7B2A0);

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_8024011C_D7B3BC);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240158_D7B3F8);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240320_D7B5C0);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_802404CC_D7B76C);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240530_D7B7D0);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_802406BC_D7B95C);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_802408A0_D7BB40);

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240D6C_D7C00C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240F50_D7C1F0);
/*
ApiStatus N(func_80240F50_D7C1F0)(ScriptInstance* script, s32 isInitialCall) {
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
    return 2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

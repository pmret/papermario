#include "pra_12.h"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240000_D62D10);

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_8024011C_D62E2C);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240158_D62E68);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240320_D63030);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_802404CC_D631DC);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240530_D63240);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_802406BC_D633CC);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_802408A0_D635B0);

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240D6C_D63A7C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240F50_D63C60);
/*
ApiStatus N(func_80240F50_D63C60)(ScriptInstance* script, s32 isInitialCall) {
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
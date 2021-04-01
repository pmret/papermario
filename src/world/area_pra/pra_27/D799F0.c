#include "pra_27.h"

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240000_D799F0);

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_8024011C_D79B0C);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240158_D79B48);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240320_D79D10);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_802404CC_D79EBC);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240530_D79F20);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_802406BC_D7A0AC);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_802408A0_D7A290);

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240D6C_D7A75C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240F50_D7A940);
/*
s32 N(func_80240F50_D7A940)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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
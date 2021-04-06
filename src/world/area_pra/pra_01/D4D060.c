#include "pra_01.h"

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802400EC_D4D12C);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80240128_D4D168);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802402F0_D4D330);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_8024049C_D4D4DC);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80240500_D4D540);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_8024068C_D4D6CC);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80240870_D4D8B0);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80240D3C_D4DD7C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80240F20_D4DF60);

ApiStatus func_80240F60_D4DFA0(ScriptInstance* script, s32 isInitialCall) {
    OVERRIDE_FLAG_UNSET(0x80);
    return ApiStatus_DONE2;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802411AC_D4E1EC);
/*
ApiStatus N(func_802411AC_D4E1EC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80241200_D4E240);
/*
ApiStatus N(func_80241200_D4E240)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80241238_D4E278);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802412D4_D4E314);

ApiStatus PostChapter7StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(7);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
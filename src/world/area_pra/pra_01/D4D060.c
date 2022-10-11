#include "pra_01.h"

#include "world/common/atomic/Reflection.inc.c"

#include "common/UnkFogFunc.inc.c"

ApiStatus func_80240F60_D4DFA0(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_80;
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802411AC_D4E1EC);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80241200_D4E240);

extern s32 D_80242FB0[];

ApiStatus func_80241238_D4E278(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80242FB0[i] = ptr[i];
        }
        D_80242FB0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80242FB0[i] = i + 16;
            D_80242FB0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 pra_01_80243178[];

ApiStatus func_802412D4_D4E314(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_01_80243178[i] = ptr[i];
        }
        pra_01_80243178[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            pra_01_80243178[i] = i + 128;
            pra_01_80243178[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus PostChapter7StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(7);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

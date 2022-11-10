#include "pra_31.h"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_8024024C_D7EFAC);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 D_80247CA0[];

ApiStatus func_802402D8_D7F038(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247CA0[i] = ptr[i];
        }
        D_80247CA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80247CA0[i] = i + 16;
            D_80247CA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_80247E68[];

ApiStatus func_80240374_D7F0D4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247E68[i] = ptr[i];
        }
        D_80247E68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80247E68[i] = i + 128;
            D_80247E68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240410_D7F170(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    script->varTable[0] = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatus.position.x, gPlayerStatus.position.z));
    return ApiStatus_DONE2;
}

ApiStatus func_80240468_D7F1C8(Evt* script, s32 isInitialCall) {
    script->varTable[6] = script->varTable[0] + 90;
    script->varTable[7] = script->varTable[5] + 90;
    script->varTable[8] = abs(script->varTable[6] - script->varTable[7]);

    if (script->varTable[8] == 270) {
        script->varTable[8] = 90;
        if (script->varTable[6] > script->varTable[7]) {
            script->varTable[6] -= 360;
        } else {
            script->varTable[7] -= 360;
        }
    }
    script->varTable[8] = (script->varTable[8] / 90) * 20;
    return ApiStatus_DONE2;
}

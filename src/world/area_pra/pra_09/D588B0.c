#include "pra_09.h"
#include "effects.h"

#include "../common/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
#include "world/common/todo/ItemChoice_WaitForSelection.inc.c"

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 pra_09_80246A20[114];
BSS s32 D_80246BE8[92];

ApiStatus func_802411D8_D59A68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_09_80246A20[i] = ptr[i];
        }
        pra_09_80246A20[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            pra_09_80246A20[i] = i + 16;
            pra_09_80246A20[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80241274_D59B04(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80246BE8[i] = ptr[i];
        }
        D_80246BE8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80246BE8[i] = i + 128;
            D_80246BE8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/PlayBigSmokePuff.inc.c"

ApiStatus func_802413A4_D59C34(Evt* script, s32 isInitialCall) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 var_s1 = evt_get_variable(script, *args++) == 0;
    Encounter* encounter;

    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }
    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }
    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }

    switch (var_s1) {
        case 1:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2101;
            break;
        case 2:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2102;
            break;
        case 3:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2103;
            break;
        case 4:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2104;
            break;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802414F4_D59D84(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, script->varTable[0]);

    if (isInitialCall) {
        npc->pos.x = script->varTable[1];
        npc->pos.y = script->varTable[2];
        npc->pos.z = script->varTable[3];
        npc->jumpVelocity = 0.0f;
        npc->currentAnim = 0x30011;
        npc->jumpScale = 0.8f;
    }
    npc->rotation.z -= 39.0f;
    npc->rotation.x -= 33.0f;
    npc->pos.y -= npc->jumpVelocity;
    npc->jumpVelocity += npc->jumpScale;
    if (npc->pos.y <= 0.0f) {
        npc->pos.y = 0.0f;
        npc->rotation.z = 0.0f;
        npc->rotation.x = 0.0f;
        npc->jumpVelocity = 0.0f;
        npc->jumpScale = 0.0f;
        npc->currentAnim = 0x30003;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802415F8_D59E88(Evt* script, s32 isInitialCall) {
    Npc* npc1 = resolve_npc(script, script->varTable[3]);
    Npc* npc2 = resolve_npc(script, script->varTable[4]);

    npc1->collisionRadius = npc2->collisionRadius;
    npc1->collisionHeight = npc2->collisionHeight;
    return ApiStatus_DONE2;
}

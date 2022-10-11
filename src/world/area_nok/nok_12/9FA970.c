#include "nok_12.h"

ApiStatus func_80240180_9FA970(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 tableIdx = evt_get_variable(script, *args++);
    s32 val = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = enemy->npcID;
    }

    enemy = get_enemy_safe(npcID);
    if (enemy != NULL) {
        enemy->varTable[tableIdx] = val;
    }

    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"

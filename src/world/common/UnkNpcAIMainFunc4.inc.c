#include "common.h"
#include "npc.h"

ApiStatus N(UnkNpcAIMainFunc4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->varTable[0] = npc->yaw;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;

        if (!(enemy->territory->wander.isFlying)) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 15;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc43)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc44)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc3)(script, aiSettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13_2)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkNpcAIFunc11)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcAIFunc10)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(UnkNpcAIFunc42)(script, aiSettings, territoryPtr);
        case 16:
            N(UnkNpcAIFunc45)(script, aiSettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}

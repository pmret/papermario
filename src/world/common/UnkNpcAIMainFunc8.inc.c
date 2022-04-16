#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(UnkNpcAIMainFunc8)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* settings = (NpcAISettings*) evt_get_variable(script, *args++);

    territoryPtr->unk_00 = 0;
    territoryPtr->shape = enemy->territory->patrol.detectShape;
    territoryPtr->pointX = enemy->territory->patrol.detect.x;
    territoryPtr->pointZ = enemy->territory->patrol.detect.z;
    territoryPtr->sizeX = enemy->territory->patrol.detectSizeX;
    territoryPtr->sizeZ = enemy->territory->patrol.detectSizeZ;
    territoryPtr->unk_18 = 100.0f;
    territoryPtr->unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->unk_B0 |= ENEMY_AI_FLAGS_8;
    }

    if (isInitialCall || (enemy->unk_B0 & ENEMY_AI_FLAGS_4)) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B5 = 0;
        enemy->varTable[8] = 0;

        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->unk_B0 & ENEMY_AI_FLAGS_4) {
            s32 emoteTemp;

            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 40, &emoteTemp);
            enemy->unk_B0 &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, settings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            /* fallthrough */
        case 1:
            N(UnkFunc13)(script, settings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, settings, territoryPtr);
            /* fallthrough */
        case 3:
            N(UnkFunc14)(script, settings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, settings, territoryPtr);
            break;
        case 12:
            N(set_script_owner_npc_anim)(script, settings, territoryPtr);
            /* fallthrough */
        case 13:
            N(UnkDistFunc)(script, settings, territoryPtr);
            break;
        case 14:
            N(UnkNpcAIFunc12)(script, settings, territoryPtr);
            break;
        case 15:
            N(set_script_owner_npc_col_height)(script, settings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}

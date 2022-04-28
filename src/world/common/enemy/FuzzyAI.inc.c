#include "world/common/enemy/state/HoppingAI_HopInit.inc.c"

#include "world/common/enemy/state/HoppingAI_Hop.inc.c"

void N(HoppingAI_LoiterInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->AI_TEMP_STATE = 3;
}

#include "world/common/enemy/state/HoppingAI_Loiter.inc.c"

#include "world/common/enemy/state/HoppingAI_ChaseInit.inc.c"

#include "world/common/enemy/state/HoppingAI_Chase.inc.c"

void N(HoppingAI_LosePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = 0;
    }
}

ApiStatus N(HoppingAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr;

    enemy->varTable[10] = evt_get_variable(script, *args++);
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 100.0f;
    territory.unk_1C = 0;
    territoryPtr = &territory;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_HOP_INIT;
        npc->duration = 0;
        script->functionTemp[1] = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;

        enemy->aiFlags |= (ENEMY_AI_FLAGS_8 | ENEMY_AI_FLAGS_10);
        if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->aiPaused != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_HOP_INIT:
            N(HoppingAI_HopInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_HOP:
            N(HoppingAI_Hop)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            N(HoppingAI_LoiterInit)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_LOITER) {
                break;
            }
            // fallthrough
        case AI_STATE_LOITER:
            N(HoppingAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            N(HoppingAI_ChaseInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_CHASE:
            N(HoppingAI_Chase)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            N(HoppingAI_LosePlayer)(script, aiSettings, territoryPtr);
            break;
    }
    return ApiStatus_BLOCK;
}

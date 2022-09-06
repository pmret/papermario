#include "world/common/enemy/HoppingAI.inc.c"

void N(StoneChompAI_HopInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    basic_ai_wander_init(script, aiSettings, territory);
    npc->jumpVelocity = rand_int(5) + 8.0;
    npc->jumpScale = 1.5f;
}

void N(StoneChompAI_ChaseInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    basic_ai_chase_init(script, aiSettings, territory);
    npc->jumpVelocity = rand_int(5) + 5.0;
    npc->jumpScale = 1.5f;
}

ApiStatus N(StoneChompAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        npc->duration = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        script->functionTemp[1] = 0;
        script->AI_TEMP_STATE = AI_STATE_HOP_INIT;
        if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_HOP_INIT:
            N(StoneChompAI_HopInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_HOP:
            N(HoppingAI_Hop)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            N(HoppingAI_LoiterInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            N(HoppingAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            N(StoneChompAI_ChaseInit)(script, aiSettings, territoryPtr);
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


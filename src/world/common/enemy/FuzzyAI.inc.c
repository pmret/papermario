#include "world/common/UnkNpcAIFunc36.inc.c"

#include "world/common/UnkNpcAIFunc37.inc.c"

// used in 38 files
//#include "world/common/enemy/state/PatrolAI_LoiterInit.inc.c"
void N(PatrolAI_LoiterInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = *enemy->animList;
    script->functionTemp[0] = 3;
}

#include "world/common/UnkNpcAIFunc38.inc.c"

#include "world/common/UnkNpcAIFunc15.inc.c"

#include "world/common/UnkNpcAIFunc39.inc.c"

// used in 11 files
// #include "world/common/UnkDurationCheck.inc.c"
void N(UnkDurationCheck)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 0;
    }
}

ApiStatus N(FuzzyAI_Main)(Evt* script, s32 isInitialCall) {
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
        script->functionTemp[0] = 0;
        npc->duration = 0;
        script->functionTemp[1] = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;

        enemy->aiFlags |= (ENEMY_AI_FLAGS_8 | ENEMY_AI_FLAGS_10);
        if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc36)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc37)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(PatrolAI_LoiterInit)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 3) {
                break;
            }
        case 3:
            N(UnkNpcAIFunc38)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc15)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkNpcAIFunc39)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkDurationCheck)(script, aiSettings, territoryPtr);
            break;
    }
    return ApiStatus_BLOCK;
}

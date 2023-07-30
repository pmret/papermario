#include "Boo.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

void N(BooPatrolAI_Move)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f20;
    f32 temp_f22;

    posX = npc->pos.x;
    posZ = npc->pos.z;
    temp_f22 = script->functionTemp[2][enemy->territory->patrol.points].x;
    temp_f20 = script->functionTemp[2][enemy->territory->patrol.points].z;

    npc->yaw = atan2(posX, posZ, temp_f22, temp_f20);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    posX = npc->pos.x;
    posY = npc->pos.y + script->functionTemp[2][enemy->territory->patrol.points].y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
    posY += script->functionTemp[2][enemy->territory->patrol.points].y;
    posW = posY - npc->pos.y;
    if (posW > 2.0) {
        npc->pos.y += 2.0;
    } else if (posW < -2.0) {
        npc->pos.y -= 2.0;
    } else {
        npc->pos.y = posY;
    }

    posW = dist2D(npc->pos.x, npc->pos.z, temp_f22, temp_f20);
    if (!(posW > npc->moveSpeed)) {
        script->functionTemp[0] = 2;
    }
}

void N(BooPatrolAI_Loiter)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration < 0) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] >= 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
        } else {
            script->functionTemp[0] = 4;
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        }
    }
}

API_CALLABLE(N(BooPatrolAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(PatrolAI_MoveInit)(script, aiSettings, territoryPtr);
        case 1:
            N(BooPatrolAI_Move)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(PatrolAI_LoiterInit)(script, aiSettings, territoryPtr);
        case 3:
            N(BooPatrolAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(PatrolAI_PostLoiter)(script, aiSettings, territoryPtr);
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

MobileAISettings N(AISettings_Boo_Patrol) = {
    .moveSpeed = 1.0f,
    .moveTime = 25,
    .waitTime = 30,
    .alertRadius = 50.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 10,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 80.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Boo_Patrol) = {
    EVT_CALL(N(BooPatrolAI_Main), EVT_PTR(N(AISettings_Boo_Patrol)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Boo_Patrol) = {
    .height = 24,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_Boo_Patrol),
};

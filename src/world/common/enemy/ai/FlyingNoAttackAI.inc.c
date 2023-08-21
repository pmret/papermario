#include "common.h"
#include "npc.h"
#include "effects.h"

// This AI is used by:
// - Lava Bubble
// - Ruff Puff
// - Ember

void N(FlyingNoAttackAI_12)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 tempAngle;
    f32 angleDiff;

    npc->duration = (aiSettings->chaseUpdateInterval / 2) + rand_int(aiSettings->chaseUpdateInterval / 2 + 1);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_CHASE];
    npc->moveSpeed = aiSettings->chaseSpeed;

    tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    angleDiff = get_clamped_angle_diff(npc->yaw, tempAngle);

    if (aiSettings->chaseTurnRate < fabsf(angleDiff)) {
        tempAngle = npc->yaw;

        if (angleDiff < 0.0f) {
            tempAngle += -aiSettings->chaseTurnRate;
        } else {
            tempAngle += aiSettings->chaseTurnRate;
        }
    }

    npc->yaw = clamp_angle(tempAngle);
    script->functionTemp[0] = 13;
}

void N(FlyingNoAttackAI_13)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    EffectInstance* var;
    s32 flag;
    f32 temp_f6;

    if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1) == 0) {
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = 30;
        script->functionTemp[0] = 20;
        enemy->varTable[9] = 30;
        return;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    flag = 0;
    if (!(npc->flags & NPC_FLAG_FLYING)) {
        x = npc->pos.x;
        y = npc->pos.y + npc->collisionHeight;
        z = npc->pos.z;
        w = npc->collisionHeight + 3.0;
        if ((npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w) != 0) && (w < npc->collisionHeight)) {
            flag = 1;
        }
    }

    if (flag) {
        npc->pos.y = y + 1.0;
    } else {
        temp_f6 = npc->pos.y - (gPlayerStatusPtr->pos.y + 6.0);
        if ((temp_f6 < 0.0) || (temp_f6 > 4.0)) {
            temp_f6 = -temp_f6;
            npc->pos.y += temp_f6 * 0.06;
        }
    }
    if (npc->duration > 0) {
        npc->duration--;
        return;
    }
    script->functionTemp[0] = 12;
}

void N(FlyingNoAttackAI_20)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->varTable[2] = 0;
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }
}

API_CALLABLE(N(FlyingNoAttackAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*) evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 120.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall) {
        #ifdef _DEAD_H_
        N(FlyingAI_Init)(npc, (Enemy*)enemy, script, aiSettings);
        #else
        N(FlyingAI_Init)(npc, enemy, script, aiSettings);
        #endif

        script->functionTemp[0] = 0;
    }
    npc->verticalRenderOffset = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(FlyingAI_WanderInit)(script, aiSettings, territoryPtr);
        case 1:
            N(FlyingAI_Wander)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
        case 3:
            N(FlyingAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(FlyingAI_JumpInit)(script, aiSettings, territoryPtr);
        case 11:
            N(FlyingAI_Jump)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(FlyingNoAttackAI_12)(script, aiSettings, territoryPtr);
        case 13:
            N(FlyingNoAttackAI_13)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(FlyingNoAttackAI_20)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}


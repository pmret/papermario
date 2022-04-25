#include "common.h"
#include "npc.h"
#include "effects.h"

// required include args
#ifndef AI_SENTINEL_FIRST_NPC
#error  AI_SENTINEL_FIRST_NPC must be defined for SentinelAI.inc.c
#define AI_SENTINEL_FIRST_NPC 0
#endif
#ifndef AI_SENTINEL_LAST_NPC
#error  AI_SENTINEL_LAST_NPC must be defined for SentinelAI.inc.c
#define AI_SENTINEL_LAST_NPC 0
#endif

// prerequisites
#include "world/common/enemy/FlyingAI.inc.c"

enum AiStateSentinel {
    AI_STATE_SENTINEL_WANDER_INIT       = 0,
    AI_STATE_SENTINEL_WANDER            = 1,
    AI_STATE_SENTINEL_LOITER_INIT       = 2,
    AI_STATE_SENTINEL_LOITER            = 3,
    AI_STATE_SENTINEL_CHASE_INIT        = 12,
    AI_STATE_SENTINEL_CHASE             = 13,
    AI_STATE_SENTINEL_DESCEND_INIT      = 14,
    AI_STATE_SENTINEL_DESCEND           = 15,
    AI_STATE_SENTINEL_LOSE_PLAYER_INIT  = 16,
    AI_STATE_SENTINEL_LOSE_PLAYER       = 17,
    AI_STATE_SENTINEL_POST_LOSE_PLAYER  = 18,
    AI_STATE_SENTINEL_GRAB_PLAYER       = 20,
    AI_STATE_SENTINEL_RETURN_HOME_INIT  = 30,
    AI_STATE_SENTINEL_RETURN_HOME       = 31,
    AI_STATE_SENTINEL_CAUGHT_PLAYER     = 100
};

#define SENTINEL_AI_FLAG_CHASING        0x100   // use to ensure only one sentinel can 'attack' at a time
#define SENTINEL_AI_FLAG_PLAYING_SOUND  0x1000  // use to force looping sound to stop

#define SENTINEL_AI_DESCEND_RATE        1.8

void N(SentinelAI_ChaseInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 deltaAngle;
    f32 angle;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= ~NPC_FLAG_200000;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
        npc->moveSpeed = aiSettings->chaseSpeed;
        angle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        deltaAngle = get_clamped_angle_diff(npc->yaw, angle);
        if (aiSettings->unk_1C.s < fabsf(deltaAngle)) {
            angle = npc->yaw;
            if (deltaAngle < 0.0f) {
                angle += -aiSettings->unk_1C.s;
            } else {
                angle += aiSettings->unk_1C.s;
            }
        }
        npc->yaw = clamp_angle(angle);
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_CHASE;
    }
}

void N(SentinelAI_Chase)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                   gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->AI_TEMP_STATE = AI_STATE_SENTINEL_DESCEND_INIT;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= NPC_FLAG_200000;
                script->AI_TEMP_STATE = AI_STATE_SENTINEL_CHASE_INIT;
            }
        }
    } else {
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOSE_PLAYER_INIT;
    }
}

void N(SentinelAI_DescendInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = AI_SENTINEL_FIRST_NPC; i < AI_SENTINEL_LAST_NPC; i++) {
        if (i != npc->npcID && (get_enemy(i)->varTable[0] & SENTINEL_AI_FLAG_CHASING)) {
            return;
        }
    }

    enemy->varTable[0] |= SENTINEL_AI_FLAG_CHASING;
    npc->pos.x = gPlayerStatusPtr->position.x;
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & SENTINEL_AI_FLAG_PLAYING_SOUND)) {
        enemy->varTable[0] |= SENTINEL_AI_FLAG_PLAYING_SOUND;
    }
    sfx_play_sound_at_position(SOUND_80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->AI_TEMP_STATE = AI_STATE_SENTINEL_DESCEND;
}

void N(SentinelAI_Descend)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, hitDepth;
    s32 color;

    sfx_adjust_env_sound_pos(SOUND_80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~SENTINEL_AI_FLAG_CHASING;
        npc->rotation.y = 0.0f;
        npc->flags &= ~NPC_FLAG_200000;
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOSE_PLAYER_INIT;
    } else {
        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        color = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, color, color, color, 255, 0);

        posX = gPlayerStatusPtr->position.x;
        posY = gPlayerStatusPtr->position.y;
        posZ = gPlayerStatusPtr->position.z;
        hitDepth = 1000.0f;
        npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= SENTINEL_AI_DESCEND_RATE;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= ~NPC_FLAG_200000;
            if (gPartnerActionStatus.actingPartner != PARTNER_BOW) {
                disable_player_input();
                partner_disable_input();
                npc->duration = 0;
                script->AI_TEMP_STATE = AI_STATE_SENTINEL_GRAB_PLAYER;
            } else {
                script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOSE_PLAYER_INIT;
            }
        }
    }
}

void N(SentinelAI_LosePlayerInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~SENTINEL_AI_FLAG_CHASING;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & SENTINEL_AI_FLAG_PLAYING_SOUND) {
        sfx_stop_sound(SOUND_80000011);
        enemy->varTable[0] &= ~SENTINEL_AI_FLAG_PLAYING_SOUND;
    }
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_HIT];
    npc->duration = 20;
    script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOSE_PLAYER;
}

void N(SentinelAI_LosePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 idleHeight = (f32)enemy->varTable[3] / 100.0;
    s32 emoteTemp;

    npc->pos.y += 2.5;
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < posY + idleHeight)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + idleHeight;
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &emoteTemp);
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_POST_LOSE_PLAYER;
    }
}

void N(SentinelAI_PostLosePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_RETURN_HOME_INIT;
    }
}

void N(SentinelAI_GrabPlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (gPartnerActionStatus.actingPartner != PARTNER_BOW) {
            npc->duration = 0;
            script->AI_TEMP_STATE = AI_STATE_SENTINEL_CAUGHT_PLAYER;
        } else {
            enable_player_input();
            partner_enable_input();
            script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOSE_PLAYER_INIT;
        }
    }
}

void N(SentinelAI_ReturnHomeInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~SENTINEL_AI_FLAG_CHASING;
    npc->flags &= ~NPC_FLAG_200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 30;
}

void N(SentinelAI_ReturnHome)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX = npc->pos.x;
    f32 posY = npc->pos.y;
    f32 posZ = npc->pos.z;
    f32 hitDepth = 1000.0f;
    f32 idleHeight = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f24 = idleHeight + (f32)((f32)enemy->varTable[7] / 100.0);
    f32 undulateAmplitude = (f32)enemy->varTable[1] / 100.0;
    f32 undulateAmount = sin_deg(enemy->varTable[2]);
    s32 emoteTemp;

    if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
        npc->pos.y = posY + idleHeight + (undulateAmount * undulateAmplitude);
    } else {
        npc->pos.y = temp_f24 + (undulateAmount * undulateAmplitude);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (basic_ai_try_detect_player(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
            ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->AI_TEMP_STATE = AI_STATE_SENTINEL_CHASE_INIT;
            return;
        }
    }

    script->functionTemp[1]--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        hitDepth = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (hitDepth <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            script->AI_TEMP_STATE = AI_STATE_SENTINEL_LOITER_INIT;
        }
    }
}

ApiStatus N(SentinelAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings =(NpcAISettings*) evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 125.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_SENTINEL_WANDER_INIT;
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_SENTINEL_WANDER_INIT:
            N(FlyingAI_WanderInit)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
            // fallthrough
        case AI_STATE_SENTINEL_WANDER:
            N(FlyingAI_Wander)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE == AI_STATE_SENTINEL_CHASE_INIT) {
                npc->duration = 6;
            }
            break;
        case AI_STATE_SENTINEL_LOITER_INIT:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_SENTINEL_LOITER:
            N(FlyingAI_Loiter)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE == AI_STATE_SENTINEL_CHASE_INIT) {
                npc->duration = 6;
            }
            break;
        case AI_STATE_SENTINEL_CHASE_INIT:
            N(SentinelAI_ChaseInit)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_SENTINEL_CHASE) {
                break;
            }
            // fallthrough
        case AI_STATE_SENTINEL_CHASE:
            N(SentinelAI_Chase)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SENTINEL_DESCEND_INIT:
            N(SentinelAI_DescendInit)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_SENTINEL_DESCEND) {
                break;
            }
            // fallthrough
        case AI_STATE_SENTINEL_DESCEND:
            N(SentinelAI_Descend)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SENTINEL_LOSE_PLAYER_INIT:
            N(SentinelAI_LosePlayerInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_SENTINEL_LOSE_PLAYER:
            N(SentinelAI_LosePlayer)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SENTINEL_POST_LOSE_PLAYER:
            N(SentinelAI_PostLosePlayer)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SENTINEL_GRAB_PLAYER:
            N(SentinelAI_GrabPlayer)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SENTINEL_RETURN_HOME_INIT:
            N(SentinelAI_ReturnHomeInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_SENTINEL_RETURN_HOME:
            N(SentinelAI_ReturnHome)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->AI_TEMP_STATE == AI_STATE_SENTINEL_CAUGHT_PLAYER) {
        return ApiStatus_DONE2; // when player is caught, relinquish control to the AI evt script
    } else {
        return ApiStatus_BLOCK;
    }
}

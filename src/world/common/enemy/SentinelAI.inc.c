#include "common.h"
#include "npc.h"
#include "effects.h"

#ifndef AI_SENTINEL_FIRST_NPC
#error  AI_SENTINEL_FIRST_NPC must be defined for SentinelAI.inc.c
#endif

#ifndef AI_SENTINEL_LAST_NPC
#error  AI_SENTINEL_LAST_NPC must be defined for SentinelAI.inc.c
#endif

#include "world/common/enemy/FlyingAI.inc.c"

void N(SentinelAI_12)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f0;
    f32 phi_f20;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= ~NPC_FLAG_200000;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim.w = enemy->animList[8];
        npc->moveSpeed = aiSettings->chaseSpeed;
        phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        temp_f0 = get_clamped_angle_diff(npc->yaw, phi_f20);
        if (aiSettings->unk_1C.s < fabsf(temp_f0)) {
            phi_f20 = npc->yaw;
            if (temp_f0 < 0.0f) {
                phi_f20 += -aiSettings->unk_1C.s;
            } else {
                phi_f20 += aiSettings->unk_1C.s;
            }
        }
        npc->yaw = clamp_angle(phi_f20);
        script->functionTemp[0] = 13;
    }
}

void N(SentinelAI_13)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                   gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->functionTemp[0] = 14;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= NPC_FLAG_200000;
                script->functionTemp[0] = 12;
            }
        }
    } else {
        script->functionTemp[0] = 16;
    }
}

void N(SentinelAI_14)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = AI_SENTINEL_FIRST_NPC; i < AI_SENTINEL_LAST_NPC; i++) {
        if (i != npc->npcID && (get_enemy(i)->varTable[0] & 0x100)) {
            return;
        }
    }

    enemy->varTable[0] |= 0x100;
    npc->pos.x = gPlayerStatusPtr->position.x;
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }
    sfx_play_sound_at_position(SOUND_80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0] = 15;
}

void N(SentinelAI_15)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    s32 temp_f8_2;

    sfx_adjust_env_sound_pos(SOUND_80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~0x100;
        npc->rotation.y = 0.0f;
        npc->flags &= ~NPC_FLAG_200000;
        script->functionTemp[0] = 16;
    } else {
        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        temp_f8_2 = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, temp_f8_2, temp_f8_2, temp_f8_2, 255, 0);

        posX = gPlayerStatusPtr->position.x;
        posY = gPlayerStatusPtr->position.y;
        posZ = gPlayerStatusPtr->position.z;
        posW = 1000.0f;
        npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= 1.8;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= ~NPC_FLAG_200000;
            if (gPartnerActionStatus.actingPartner  != 9) {
                disable_player_input();
                partner_disable_input();
                npc->duration = 0;
                script->functionTemp[0] = 20;
            } else {
                script->functionTemp[0] = 16;
            }
        }
    }
}

void N(SentinelAI_16)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & 0x1000) {
        sfx_stop_sound(SOUND_80000011);
        enemy->varTable[0] &= ~0x1000;
    }
    npc->currentAnim.w = enemy->animList[9];
    npc->duration = 20;
    script->functionTemp[0] = 17;
}

void N(SentinelAI_17)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 tmp = enemy->varTable[3];
    f32 temp_f20 = tmp / 100.0;
    s32 var;

    npc->pos.y += 2.5;
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < (posY + temp_f20))) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + temp_f20;
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &var);
        npc->duration = 10;
        script->functionTemp[0] = 18;
    }
}

void N(SentinelAI_18)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 30;
    }
}

void N(SentinelAI_20)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (gPartnerActionStatus.actingPartner  != 9) {
            npc->duration = 0;
            script->functionTemp[0] = 100;
        } else {
            enable_player_input();
            partner_enable_input();
            script->functionTemp[0] = 16;
        }
    }
}

void N(SentinelAI_30)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= ~NPC_FLAG_200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 0x1E;
}

void N(SentinelAI_31)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX = npc->pos.x;
    f32 posY = npc->pos.y;
    f32 posZ = npc->pos.z;
    f32 posW = 1000.0f;
    f32 temp_f26 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f24 = temp_f26 + (f32)((f32)enemy->varTable[7] / 100.0);
    f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
    f32 temp_f20 = sin_deg(enemy->varTable[2]);
    s32 var;
    s32 var2;

    if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW)) {
        npc->pos.y = posY + temp_f26 + (temp_f20 * temp_f22);
    } else {
        npc->pos.y = temp_f24 + (temp_f20 * temp_f22);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (basic_ai_try_detect_player(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->functionTemp[0] = 12;
            return;
        }
    }

    script->functionTemp[1]--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        posW = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (posW <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            script->functionTemp[0] = 2;
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
        script->functionTemp[0] = 0;
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(FlyingAI_00)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(FlyingAI_01)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(FlyingAI_02)(script, aiSettings, territoryPtr);
        case 3:
            N(FlyingAI_03)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(SentinelAI_12)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(SentinelAI_13)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(SentinelAI_14)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 15) {
                break;
            }
        case 15:
            N(SentinelAI_15)(script, aiSettings, territoryPtr);
            break;
        case 16:
            N(SentinelAI_16)(script, aiSettings, territoryPtr);
        case 17:
            N(SentinelAI_17)(script, aiSettings, territoryPtr);
            break;
        case 18:
            N(SentinelAI_18)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(SentinelAI_20)(script, aiSettings, territoryPtr);
            break;
        case 30:
            N(SentinelAI_30)(script, aiSettings, territoryPtr);
        case 31:
            N(SentinelAI_31)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->functionTemp[0] == 100) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

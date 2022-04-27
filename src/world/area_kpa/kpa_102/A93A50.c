#include "kpa_102.h"

#include "world/common/enemy/ProjectileAI.inc.c"

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c"

void N(FlyingMagikoopaAI_10)(Evt* script, NpcAISettings* arg1, EnemyTerritoryThing* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    npc->duration = 30;
    script->AI_TEMP_STATE = 11;
}

void N(FlyingMagikoopaAI_11)(Evt* script, NpcAISettings* arg1, EnemyTerritoryThing* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);    
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;
    s32 emoteTemp;
    
    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);
    
    if (N(UnkNpcAIFunc47)(script, arg1->chaseRadius, arg1->unk_28.f, arg2) == 1) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        npc->duration = 50;
        script->AI_TEMP_STATE = 20;
    } else {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 5;
            script->AI_TEMP_STATE = 15;
        }
    }
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_802425D8_A95D18);

void N(FlyingMagikoopaAI_16)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;
    
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);
    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    
    if (npc->turnAroundYawAdjustment == 0) {
        enemy->varTable[5] = npc->pos.y * 100.0;
        script->functionTemp[0] = 17;
    }
}

void N(FlyingMagikoopaAI_17)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 limitY = (f32)enemy->varTable[1] / 100.0;
    f32 basePosY = (f32)enemy->varTable[5] / 100.0;
    f32 startX = (f32)enemy->varTable[4] / 100.0;
    f32 startZ = (f32)enemy->varTable[6] / 100.0;
    f32 lerpX = update_lerp(EASING_SIN_OUT, startX, npc->moveToPos.x, npc->duration, enemy->varTable[3]);
    f32 lerpZ = update_lerp(EASING_SIN_OUT, startZ, npc->moveToPos.z, npc->duration, enemy->varTable[3]);

    npc->pos.x = lerpX;
    npc->pos.z = lerpZ;
    npc->pos.y = basePosY + sin_deg((s32)(npc->duration * (180.0 / (f32)enemy->varTable[3])) + 180) * 25.0;
    
    npc->duration++;
    if (npc->duration == (enemy->varTable[3] - 8)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    }
    if (limitY <= npc->pos.y) {
        npc->pos.y = limitY;
        enemy->varTable[0] = 0;
        script->functionTemp[0] = 10;
    } else if (npc->duration >= enemy->varTable[3]) {
        if (enemy->varTable[0] >= 180.0) {
            if (enemy->varTable[0] < 270.0) {
                enemy->varTable[0] = clamp_angle(540 - enemy->varTable[0]);
            }
        }
        script->functionTemp[0] = 10;
    }
}

void N(FlyingMagikoopaAI_20)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 40;
    script->functionTemp[0] = 21;
}

void N(FlyingMagikoopaAI_21)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration == 0) {
        npc->currentAnim.w = enemy->animList[0];
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 15;
        script->functionTemp[0] = 50;
    } else if ((N(UnkNpcAIFunc47)(script, aiSettings->chaseRadius, aiSettings->unk_28.f, territory) == 1) && (npc->turnAroundYawAdjustment == 0)) {
        ai_enemy_play_sound(npc, 0x20D4, 0);
        npc->currentAnim.w = enemy->animList[8];
        posX = npc->pos.x;
        posY = npc->pos.y + 29.0f;
        posZ = npc->pos.z + 1.0f;
        add_vec2D_polar(&posX, &posZ, 30.0f, 270.0f - npc->renderYaw);
        fx_gather_energy_pink(0, posX, posY, posZ, 0.1f, 13);
        npc->duration = 15;
        script->functionTemp[0] = 22;
    }
}

void N(FlyingMagikoopaAI_22)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[9];
        npc->duration = 7;
        script->functionTemp[0] = 0x17;
    }
}

void N(FlyingMagikoopaAI_23)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp_s1;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration <= 0) {
        temp_s1 = N(UnkNpcAIFunc47)(script, aiSettings->chaseRadius, aiSettings->unk_28.f, territory);
        if (temp_s1 != 1) {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
            npc->currentAnim.w = enemy->animList[0];
            npc->duration = 15;
            script->functionTemp[0] =  50;
        } else {
            ai_enemy_play_sound(npc, SOUND_SPELL_CAST2, 0);
            get_enemy(enemy->npcID + 1)->varTable[0] = temp_s1;
            npc->duration = 20;
            script->functionTemp[0] = 24;
        }
    }
}

void N(FlyingMagikoopaAI_24)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;

    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);
    
    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 3;
        script->AI_TEMP_STATE = 50;
    }
}

void N(FlyingMagikoopaAI_50)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;
    
    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = 10;
    }
}

ApiStatus N(FlyingMagikoopaAI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 120.0f;
    territory.unk_1C = 0;
    
    if (isInitialCall) {
        npc->flags &= ~0x200;
        npc->flags |= 0x8;
        npc->flags |= 0x200000;
        enemy->flags |= 0x200000;
        enemy->varTable[1] = npc->pos.y * 100.0;
        enemy->varTable[0] = 0;
        enemy->varTable[2] = 0;
        npc->duration = 0;
        script->AI_TEMP_STATE = 10;
    }

    npc->verticalRenderOffset = -5;

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }
    
    switch (script->AI_TEMP_STATE) {
        case 10:
            N(FlyingMagikoopaAI_10)(script, aiSettings, territoryPtr);
            // fallthrough
        case 11:
            N(FlyingMagikoopaAI_11)(script, aiSettings, territoryPtr);
            break;
        case 15:
            func_802425D8_A95D18(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 16) {
                break;
            }
        case 16:
            N(FlyingMagikoopaAI_16)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 17) {
                break;
            }
        case 17:
            N(FlyingMagikoopaAI_17)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(FlyingMagikoopaAI_20)(script, aiSettings, territoryPtr);
            break;
        case 21:
            N(FlyingMagikoopaAI_21)(script, aiSettings, territoryPtr);
            break;
        case 22:
            N(FlyingMagikoopaAI_22)(script, aiSettings, territoryPtr);
            break;
        case 23:
            N(FlyingMagikoopaAI_23)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 24) {
                break;
            }
        case 24:
            N(FlyingMagikoopaAI_24)(script, aiSettings, territoryPtr);
            break;
        case 50:
            N(FlyingMagikoopaAI_50)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

// FlyingMagikoopa onHit user functions:

#define NAMESPACE dup_kpa_102
#include "world/common/GetEncounterEnemyIsOwner.inc.c"
#define NAMESPACE kpa_102

ApiStatus func_8024353C_A96C7C(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (enemy->varTable[0] == 2) {
        npc->jumpVelocity = 0.0f;
        npc->moveSpeed = 0.0f;
    }
    return ApiStatus_DONE2;
}

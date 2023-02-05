#include "common.h"
#include "npc.h"
#include "sprite.h"

typedef struct MagikoopaTeleportAnim {
    f32 scaleX;
    f32 scaleY;
    u8 alpha;
} MagikoopaTeleportAnim;

#define ENEMY_FLAG_COMBINATION (ENEMY_FLAG_10000000 | ENEMY_FLAG_8000000 | \
    ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_100000)

extern MagikoopaTeleportAnim N(MagikoopaAI_TeleportAnim)[];

#include "world/common/enemy/ai/MagikoopaSpellAI.inc.c"

void N(MagikoopaAI_00)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_2;
        npc->duration = 0;
        script->AI_TEMP_STATE = 1;
    }
}

void N(MagikoopaAI_01)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    npc->scale.x = N(MagikoopaAI_TeleportAnim)[npc->duration].scaleX;
    npc->scale.y = N(MagikoopaAI_TeleportAnim)[npc->duration].scaleY;
    npc->alpha = N(MagikoopaAI_TeleportAnim)[npc->duration].alpha;
    
    npc->duration++;
    if (npc->duration == 4) {
        disable_npc_shadow(npc);
        enemy->flags |= ENEMY_FLAG_COMBINATION;
    }
    
    if (N(MagikoopaAI_TeleportAnim)[npc->duration].alpha == 0) {
        npc->alpha = 0xFF;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        npc->flags |= NPC_FLAG_2;
        script->AI_TEMP_STATE = 5;
    }
}

void N(MagikoopaAI_05)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 angle = (rand_int(100) % 2) * 180.0f;

    npc->duration = 15;
    npc->moveSpeed = 0.8f;
    npc->yaw = angle + 90.0f;
    script->AI_TEMP_STATE = 6;
}

void N(MagikoopaAI_06)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = 10;
    }
}

void N(MagikoopaAI_10)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 dist = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    f32 posX, posY, posZ;

    enemy->varTable[0] = 1;
    npc->currentAnim = enemy->animList[8];
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->flags &= ~NPC_FLAG_2;
    npc->scale.x = 0.1f;
    npc->scale.y = 0.1f;
    npc->scale.z = 0.1f;
    if (!(npc->flags & NPC_FLAG_8)) {
        posX = npc->pos.x;
        dist = 200.0f;
        posZ = npc->pos.z;
        posY = npc->pos.y + 100.0;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &dist) != 0) {
            npc->pos.y = posY;
        }
    }
    npc->duration = 0;
    script->AI_TEMP_STATE = 0xB;
}

void N(MagikoopaAI_11)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 scale;
    s16 alpha;
    
    if (enemy->varTable[0] == 0) {
        alpha = (npc->duration * 15) + 130;
    } else {
        alpha = (npc->duration * 15) + 30;
    }
    if (alpha > 0xFF) {
        alpha = 0xFF;
    }
    npc->alpha = alpha;
    
    npc->scale.x = ((f32)npc->duration * 0.1) + 0.4;
    if (npc->scale.x > 1.0) {
       npc->scale.x = 1.0f;
    }
    npc->scale.y = npc->scale.x;
    npc->scale.z = npc->scale.x;
    
    npc->duration++;
    if (npc->duration == 5) {
        enable_npc_shadow(npc);
        enemy->flags &= ~ENEMY_FLAG_COMBINATION;
    }
    if (enemy->varTable[0] == 0) {
        if (npc->duration >= 20) {
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
            npc->alpha = 0xFF;
            npc->scale.x = 1.0f;
            npc->scale.y = 1.0f;
            npc->scale.z = 1.0f;
            script->AI_TEMP_STATE = 20;
        }
    } else if (npc->duration >= 10) {
        npc->alpha = 0xFF;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        script->AI_TEMP_STATE = 20;
    }
}

void N(MagikoopaAI_20)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 40;
    script->AI_TEMP_STATE = 21;
}

void N(MagikoopaAI_21)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration == 0) {
        npc->currentAnim = enemy->animList[0];
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 0xF;
        script->AI_TEMP_STATE = 0;
        return;
    }
    if (N(MagikoopaAI_CanShootSpell)(script, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, territory) == 1) {
        ai_enemy_play_sound(npc, SOUND_SPELL_CAST1, 0);
        npc->currentAnim = enemy->animList[8];
        posX = npc->pos.x;
        posY = npc->pos.y + 32.0f;
        posZ = npc->pos.z + 1.0f;
        add_vec2D_polar(&posX, &posZ, 17.0f, 270.0f - npc->renderYaw);
        fx_gather_energy_pink(0, posX, posY, posZ, 0.1f, 0xD);
        npc->duration = 0xF;
        script->AI_TEMP_STATE = 0x16;
    }
}

void N(MagikoopaAI_22)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* temp_s0 = script->owner1.enemy;
    Npc* temp_v0 = get_npc_unsafe(temp_s0->npcID);
    
    temp_v0->duration--;
    if (temp_v0->duration <= 0) {
        temp_v0->currentAnim = temp_s0->animList[9];
        temp_v0->duration = 9;
        script->AI_TEMP_STATE = 0x17;
    }
}

void N(MagikoopaAI_23)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 projectileEnemy;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration <= 0) {
        projectileEnemy = N(MagikoopaAI_CanShootSpell)(script, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, territory);
        if (projectileEnemy != 1) {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &emoteTemp);
            npc->currentAnim = enemy->animList[0];
            npc->duration = 15;
            script->AI_TEMP_STATE = 0;
        } else {
            ai_enemy_play_sound(npc, SOUND_SPELL_CAST2, 0);
            get_enemy(enemy->npcID + 1)->varTable[0] = projectileEnemy;
            npc->duration = 0x14;
            script->AI_TEMP_STATE = 0x18;
        }
    }
}

void N(MagikoopaAI_24)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[0];
        npc->duration = 3;
        script->AI_TEMP_STATE = 0;
    }
}

ApiStatus N(MagikoopaAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    Bytecode* args = script->ptrReadPos;
    MobileAISettings* aiSettings = (MobileAISettings*) evt_get_variable(script, *args++);
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 hitDepth;
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;
    
    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_4)) {
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->flags |= NPC_FLAG_200000;
        enemy->flags |= ENEMY_FLAG_200000;
        npc->duration = 0;
        if (enemy->aiFlags & ENEMY_AI_FLAG_4) {
            enemy->aiFlags &= ~ENEMY_AI_FLAG_4;
            npc->alpha = 0xFF;
            npc->duration = 20;
            npc->scale.x = 1.0f;
            npc->scale.y = 1.0f;
            npc->scale.z = 1.0f;
        }
        script->AI_TEMP_STATE = 0;
    }
    
    switch (script->AI_TEMP_STATE) {
    case 0:
        N(MagikoopaAI_00)(script, aiSettings, territoryPtr);
        if (script->AI_TEMP_STATE != 1) {
            break;
        }
        // fallthrough
    case 1:
        N(MagikoopaAI_01)(script, aiSettings, territoryPtr);
        break;
    case 5:
        N(MagikoopaAI_05)(script, aiSettings, territoryPtr);
        // fallthrough
    case 6:
        N(MagikoopaAI_06)(script, aiSettings, territoryPtr);
        break;
    case 10:
        N(MagikoopaAI_10)(script, aiSettings, territoryPtr);
        // fallthrough
    case 11:
        N(MagikoopaAI_11)(script, aiSettings, territoryPtr);
        break;
    case 20:
        N(MagikoopaAI_20)(script, aiSettings, territoryPtr);
        break;
    case 21:
        N(MagikoopaAI_21)(script, aiSettings, territoryPtr);
        break;
    case 22:
        N(MagikoopaAI_22)(script, aiSettings, territoryPtr);
        break;
    case 23:
        N(MagikoopaAI_23)(script, aiSettings, territoryPtr);
        break;
    case 24:
        N(MagikoopaAI_24)(script, aiSettings, territoryPtr);
        break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(MagikoopaAI_OnPlayerWon)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->alpha = 255;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus N(MagikoopaAI_OnPlayerFled)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->alpha = 255;
    npc->currentAnim = enemy->animList[2];
    npc->duration = 0;
    script->functionTemp[0] = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(MagikoopaAI_OnHitInit)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;

    evt_set_variable(script, LVar0, gCurrentEncounter.currentEnemy == enemy);
    return ApiStatus_DONE2;
}

ApiStatus N(MagikoopaAI_OnHit)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (enemy->varTable[0] == 2) {
        npc->jumpVelocity = 0.0f;
        npc->moveSpeed = 0.0f;
    }
    return ApiStatus_DONE2;
}

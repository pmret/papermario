#include "world/common/enemy/state/MagikoopaAI_00.inc.c"

typedef struct MagikoopaTeleportAnim {
    f32 scaleX;
    f32 scaleY;
    u8 alpha;
} MagikoopaTeleportAnim;

extern MagikoopaTeleportAnim N(MagikoopaAI_TeleportAnim)[];

void N(MagikoopaAI_01)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    npc->scale.x = N(MagikoopaAI_TeleportAnim)[npc->duration].scaleX;
    npc->scale.y = N(MagikoopaAI_TeleportAnim)[npc->duration].scaleY;
    npc->alpha = N(MagikoopaAI_TeleportAnim)[npc->duration].alpha;
    
    npc->duration++;
    if (npc->duration == 4) {
        disable_npc_shadow(npc);
        enemy->flags |= 0x1F100000;
    }
    
    if (N(MagikoopaAI_TeleportAnim)[npc->duration].alpha == 0) {
        npc->alpha = 0xFF;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        npc->flags |= 2;
        script->functionTemp[0] = 5;
    }
}
#include "world/common/enemy/state/MagikoopaAI_05.inc.c"

void N(MagikoopaAI_06)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = 10;
    }
}

void N(MagikoopaAI_10)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 dist = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    f32 posX, posY, posZ;

    enemy->varTable[0] = 1;
    npc->currentAnim.w = enemy->animList[8];
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->flags &= ~2;
    npc->scale.x = 0.1f;
    npc->scale.y = 0.1f;
    npc->scale.z = 0.1f;
    if ((npc->flags & 8) == 0) {
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


void N(MagikoopaAI_11)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 scale;
    s16 alpha;
    
    if (enemy->varTable[0] == 0) {
        alpha = (npc->duration * 15) + 130;
    } else {
        alpha = (npc->duration * 15) + 30;
    }
    if (alpha >= 0x100) {
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
        enemy->flags &= 0xE0EFFFFF;
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

void N(MagikoopaAI_20)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 40;
    script->AI_TEMP_STATE = 21;
}

void N(MagikoopaAI_21)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration == 0) {
        npc->currentAnim.w = enemy->animList[0];
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 0xF;
        script->AI_TEMP_STATE = 0;
        return;
    }
    if (N(UnkNpcAIFunc47)(script, aiSettings->chaseRadius, aiSettings->unk_28.f, territory) == 1) {
        ai_enemy_play_sound(npc, 0x20D4, 0);
        npc->currentAnim.w = enemy->animList[8];
        posX = npc->pos.x;
        posY = npc->pos.y + 32.0f;
        posZ = npc->pos.z + 1.0f;
        add_vec2D_polar(&posX, &posZ, 17.0f, 270.0f - npc->renderYaw);
        fx_gather_energy_pink(0, posX, posY, posZ, 0.1f, 0xD);
        npc->duration = 0xF;
        script->AI_TEMP_STATE = 0x16;
    }
}

void N(MagikoopaAI_22)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* temp_s0 = script->owner1.enemy;
    Npc* temp_v0 = get_npc_unsafe(temp_s0->npcID);
    
    temp_v0->duration--;
    if (temp_v0->duration <= 0) {
        temp_v0->currentAnim.w = temp_s0->animList[9];
        temp_v0->duration = 9;
        script->AI_TEMP_STATE = 0x17;
    }
}

void N(MagikoopaAI_23)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 projectileEnemy;
    s32 emoteTemp;
    
    npc->duration--;
    if (npc->duration <= 0) {
        projectileEnemy = N(UnkNpcAIFunc47)(script, aiSettings->chaseRadius, aiSettings->unk_28.f, territory);
        if (projectileEnemy != 1) {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &emoteTemp);
            npc->currentAnim.w = enemy->animList[0];
            npc->duration = 0xF;
            script->AI_TEMP_STATE = 0;
        } else {
            ai_enemy_play_sound(npc, 0x20D5, 0);
            get_enemy(enemy->npcID + 1)->varTable[0] = projectileEnemy;
            npc->duration = 0x14;
            script->AI_TEMP_STATE = 0x18;
        }
    }
}

void N(MagikoopaAI_24)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 3;
        script->AI_TEMP_STATE = 0;
    }
}

ApiStatus N(MagikoopaAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args++);
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 hitDepth;
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 100.0f;
    territory.unk_1C = 0;
    
    if (isInitialCall || (enemy->aiFlags & 4)) {
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        npc->flags |= 0x200000;
        enemy->flags |= 0x200000;
        npc->duration = 0;
        if ((enemy->aiFlags & 4) != 0) {
            enemy->aiFlags &= ~4;
            npc->alpha = 0xFF;
            npc->duration = 0x14;
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

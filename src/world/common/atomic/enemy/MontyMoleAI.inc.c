#include "common.h"
#include "npc.h"
#include "sprite/npc/monty_mole.h"

s32 N(MontyMoleAI_TerritoryCheck)(Evt*, EnemyTerritoryThing*, f32, f32);
AIStateHandler N(MontyMoleAI_Init);
AIStateHandler N(MontyMoleAI_Loiter);
AIStateHandler N(MontyMoleAI_Surface);
AIStateHandler N(MontyMoleAI_ThrowRock);
AIStateHandler N(80241A4C_9110FC);
AIStateHandler N(80241B74_911224);
AIStateHandler N(80241C78_911328);
AIStateHandler N(MontyMoleAI_Dig);

enum AiStateMontyMole {
    AI_STATE_MOLE_INIT          = 0,
    AI_STATE_MOLE_LOITER        = 1,
    AI_STATE_MOLE_SURFACE       = 12,
    AI_STATE_MOLE_THROW_ROCK    = 13,
    AI_STATE_MOLE_DIG           = 21,
};

s32 N(MontyMoleAI_TerritoryCheck)(Evt* script, EnemyTerritoryThing* territory, f32 radius, f32 arg3) {
    Camera* cam;
    Enemy* enemy;
    Npc* npc;
    f32 angle;
    s32 retVal;

    enemy = script->owner1.enemy;
    npc = get_npc_unsafe(enemy->npcID);
    cam = &gCameras[gCurrentCamID];
    retVal = func_800490B4(territory, enemy, radius * 1.1, arg3, 0) != 0;
    angle = 270.0f;
    if (clamp_angle(get_clamped_angle_diff(cam->currentYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    }
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z))) > 60.0) {
        retVal = 0;
    }
    if (get_xz_dist_to_player(npc->pos.x, npc->pos.z) < gPlayerStatusPtr->colliderDiameter + npc->collisionRadius) {
        retVal = 0;
    }
    if (fabsf(npc->pos.y - gPlayerStatusPtr->position.y) >= 40.0f) {
        retVal = 0;
    }
    if (gPartnerActionStatus.actionState.b[3] == 9) {
        retVal = 0;
    }
    return retVal;
}

void N(MontyMoleAI_Init)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration = (aiSettings->moveTime / 2) + rand_int((aiSettings->moveTime / 2) + 1);
    npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->flags |= 0x1F100000;
    npc->flags |= 2;
    script->functionTemp[1] = 0;
    script->functionTemp[0] = AI_STATE_MOLE_LOITER;
}

void N(MontyMoleAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Npc dummyNpc;
    f32 hitDepth;
    
    if (is_point_within_region(enemy->territory->wander.wanderShape, 
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }
    dummyNpc.pos.x = npc->pos.x;
    dummyNpc.pos.y = npc->pos.y + 1.0f;
    dummyNpc.pos.z = npc->pos.z;
    npc_move_heading(&dummyNpc, npc->moveSpeed + npc->collisionRadius, npc->yaw);
    hitDepth = 1000.0f;
    if (npc_raycast_down_sides(0, &dummyNpc.pos.x, &dummyNpc.pos.y, &dummyNpc.pos.z, &hitDepth) && (hitDepth < 5.0f)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    if (npc->flags & 0x4000) {
        script->functionTemp[0] = 0;
    }
    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->unk_14;
            if (N(MontyMoleAI_TerritoryCheck)(script, territory, aiSettings->alertRadius, aiSettings->unk_10.f)) {
                npc->duration = 0;
                script->functionTemp[0] = AI_STATE_MOLE_SURFACE;
                return;
            }
        }
        script->functionTemp[1]--;
    }
    if (!(npc->flags & 0x1008)) {
        npc->homePos.x = npc->pos.x;
        npc->homePos.z = npc->pos.z;
    }
    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = 0;
    }
}

void N(MontyMoleAI_Surface)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    npc->flags &= -3;
    ai_enemy_play_sound(npc, SOUND_MOLE_SURFACE, 0);
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_10; // emerge from ground
    npc->duration = 10;
    script->functionTemp[0] = AI_STATE_MOLE_THROW_ROCK;
}

void N(MontyMoleAI_ThrowRock)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration == 2) {
        enemy->flags &= 0xE0EFFFFF;
    }
    if (npc->duration <= 0) {
        npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_18; // get and throw rock
        npc->duration = 10;
        script->functionTemp[0] = 0xE;
    }
}

void N(80241A4C_9110FC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc;
    s32 emoteOut;
    
    npc = get_npc_unsafe(script->owner1.enemy->npcID);
    npc->duration--;
    if ((npc->duration) <= 0) {
        if (!N(MontyMoleAI_TerritoryCheck)(script, territory, aiSettings->alertRadius * 1.1, aiSettings->unk_10.f)) {
            fx_emote(2, npc, 0.0f, (f32) npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteOut);
            npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_1;
            npc->duration = 30;
            script->functionTemp[0] =  0x14;
        } else {
            npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_1B; // throw rock
            npc->duration = 15;
            script->functionTemp[0] =  0xF;
        }
    }
}

void N(80241B74_911224)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* moleEnemy;
    Enemy* rockEnemy;
    Npc* moleNpc;

    moleEnemy = script->owner1.enemy;
    moleNpc = get_npc_unsafe(moleEnemy->npcID);
    moleNpc->duration--;
    if (moleNpc->duration == 13) {
        rockEnemy = get_enemy(moleEnemy->npcID + 1);
        rockEnemy->varTable[4] = moleEnemy->npcID;
        rockEnemy->varTable[0] = 1;
    }
    if (moleNpc->duration < 8) {
        if (dist2D(moleNpc->pos.x, moleNpc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > 100.0) {
            moleNpc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_15; // clap
        }
    }
    if (moleNpc->duration <= 0) {
        if (moleNpc->currentAnim.w != NPC_ANIM_monty_mole_Palette_00_Anim_15) {
            moleNpc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_1;
        }
        moleNpc->duration = 15;
        script->functionTemp[0] = 0x14;
    }
}

void N(80241C78_911328)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    npc->duration--;
    if (npc->duration <= 0) {
        ai_enemy_play_sound(npc, SOUND_MOLE_DIG, 0);
        npc->duration = 11;
        npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_11; // retreat into ground
        script->functionTemp[0] = AI_STATE_MOLE_DIG;
    }
}

void N(MontyMoleAI_Dig)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration == 3) {
        enemy->flags |= 0x1F100000;
    }
    if (npc->duration <= 0) {
        npc->flags |= 2;
        script->functionTemp[0] = AI_STATE_MOLE_INIT;
    }
}

ApiStatus N(MontyMoleAI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args  = script->ptrReadPos;
    Enemy* enemy  = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    
    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall != 0) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= -0x801;
        enemy->unk_B0 |= 0x18;
    }
    
    if ((enemy->unk_B0 & 4) != 0) {
        if (enemy->unk_B4 == 0) {
            enemy->unk_B0 &= ~4;
        } else {
            return ApiStatus_BLOCK;
        }
    }
    
    switch (script->functionTemp[0]) {
    case AI_STATE_MOLE_INIT:
        N(MontyMoleAI_Init)(script, aiSettings, territoryPtr);
        // fallthrough
    case AI_STATE_MOLE_LOITER:
        N(MontyMoleAI_Loiter)(script, aiSettings, territoryPtr);
        return ApiStatus_BLOCK;

    case AI_STATE_MOLE_SURFACE:
        N(MontyMoleAI_Surface)(script, aiSettings, territoryPtr);
        // fallthrough
    case AI_STATE_MOLE_THROW_ROCK:
        N(MontyMoleAI_ThrowRock)(script, aiSettings, territoryPtr);
        if (script->functionTemp[0] != 14) {
            return ApiStatus_BLOCK;
        }
    case 14:
        N(80241A4C_9110FC)(script, aiSettings, territoryPtr);
        if (script->functionTemp[0] != 15) {
            return ApiStatus_BLOCK;
        }
    case 15:
        N(80241B74_911224)(script, aiSettings, territoryPtr);
        if (script->functionTemp[0] != 16) {
            return ApiStatus_BLOCK;
        }
    case 20:
        N(80241C78_911328)(script, aiSettings, territoryPtr);
        return ApiStatus_BLOCK;

    case AI_STATE_MOLE_DIG:
        N(MontyMoleAI_Dig)(script, aiSettings, territoryPtr);
        return ApiStatus_BLOCK;
    }
    return ApiStatus_BLOCK;
}

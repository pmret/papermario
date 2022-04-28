#include "common.h"
#include "npc.h"
#include "sprite/npc/monty_mole.h"

// prerequisites
#include "world/common/enemy/ProjectileHitbox.inc.c"

// ensure state handlers conform to expected signature
static AIStateHandler N(MontyMoleAI_Init);
static AIStateHandler N(MontyMoleAI_Wander);
static AIStateHandler N(MontyMoleAI_PreSurface);
static AIStateHandler N(MontyMoleAI_Surface);
static AIStateHandler N(MontyMoleAI_DrawRock);
static AIStateHandler N(MontyMoleAI_ThrowRock);
static AIStateHandler N(MontyMoleAI_PreBurrow);
static AIStateHandler N(MontyMoleAI_Burrow);

enum AiStateMontyMole {
    AI_STATE_MOLE_INIT          = 0,    // choose random heading and duration for next state
    AI_STATE_MOLE_WANDER        = 1,    // wander around 'underground'
    AI_STATE_MOLE_PRE_SURFACE   = 12,   // delay before emerging from underground
    AI_STATE_MOLE_SURFACE       = 13,   // emerge from underground
    AI_STATE_MOLE_DRAW_ROCK     = 14,   // pull out a rock, can either attack or cancel
    AI_STATE_MOLE_THROW_ROCK    = 15,   // throw the rock
    AI_STATE_MOLE_UNUSED        = 16,
    AI_STATE_MOLE_PRE_BURROW    = 20,   // delay before burrowing back underground
    AI_STATE_MOLE_BURROW        = 21,   // burrow underground
};

#define MONTY_MOLE_UNK_NPC_FLAGS 0x1F100000

static s32 N(MontyMoleAI_CanAttack)(Evt* script, EnemyTerritoryThing* territory, f32 radius, f32 arg3) {
    Camera* cam;
    Enemy* enemy;
    Npc* npc;
    f32 angle;
    s32 retVal;

    enemy = script->owner1.enemy;
    npc = get_npc_unsafe(enemy->npcID);
    cam = &gCameras[gCurrentCamID];
    retVal = basic_ai_try_detect_player(territory, enemy, radius * 1.1, arg3, 0) != 0;
    // check npc facing angle for sight of player
    angle = 270.0f;
    if (clamp_angle(get_clamped_angle_diff(cam->currentYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    }
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z))) > 60.0) {
        retVal = FALSE;
    }
    // check for overlap with player
    if (get_xz_dist_to_player(npc->pos.x, npc->pos.z) < gPlayerStatusPtr->colliderDiameter + npc->collisionRadius) {
        retVal = FALSE;
    }
    // check player elevation difference
    if (fabsf(npc->pos.y - gPlayerStatusPtr->position.y) >= 40.0f) {
        retVal = FALSE;
    }
    // check for bow hiding
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        retVal = FALSE;
    }
    return retVal;
}

static void N(MontyMoleAI_Init)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration = (aiSettings->moveTime / 2) + rand_int((aiSettings->moveTime / 2) + 1);
    npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->flags |= MONTY_MOLE_UNK_NPC_FLAGS;
    npc->flags |= NPC_FLAG_2;
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_MOLE_WANDER;
}

static void N(MontyMoleAI_Wander)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
    if (npc->flags & NPC_FLAG_4000) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (N(MontyMoleAI_CanAttack)(script, territory, aiSettings->alertRadius, aiSettings->unk_10.f)) {
                npc->duration = 0;
                script->AI_TEMP_STATE = AI_STATE_MOLE_PRE_SURFACE;
                return;
            }
        }
        script->functionTemp[1]--;
    }
    if (!(npc->flags & (NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_1000))) {
        npc->homePos.x = npc->pos.x;
        npc->homePos.z = npc->pos.z;
    }
    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
}

static void N(MontyMoleAI_PreSurface)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->flags &= -(NPC_FLAG_PASSIVE | NPC_FLAG_2);
    ai_enemy_play_sound(npc, SOUND_MOLE_SURFACE, 0);
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_10; // emerge from ground
    npc->duration = 10;
    script->AI_TEMP_STATE = AI_STATE_MOLE_SURFACE;
}

static void N(MontyMoleAI_Surface)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration == 2) {
        enemy->flags &= ~MONTY_MOLE_UNK_NPC_FLAGS;
    }
    if (npc->duration <= 0) {
        npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_18; // get and throw rock
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_MOLE_DRAW_ROCK;
    }
}

static void N(MontyMoleAI_DrawRock)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteOut;
    
    npc->duration--;
    if ((npc->duration) <= 0) {
        if (!N(MontyMoleAI_CanAttack)(script, territory, aiSettings->alertRadius * 1.1, aiSettings->unk_10.f)) {
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteOut);
            npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_1; // cancel attack
            npc->duration = 30;
            script->AI_TEMP_STATE =  AI_STATE_MOLE_PRE_BURROW;
        } else {
            npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_1B; // throw rock
            npc->duration = 15;
            script->AI_TEMP_STATE =  AI_STATE_MOLE_THROW_ROCK;
        }
    }
}

static void N(MontyMoleAI_ThrowRock)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
        script->AI_TEMP_STATE = AI_STATE_MOLE_PRE_BURROW;
    }
}

static void N(MontyMoleAI_PreBurrow)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration <= 0) {
        ai_enemy_play_sound(npc, SOUND_MOLE_DIG, 0);
        npc->duration = 11;
        npc->currentAnim.w = NPC_ANIM_monty_mole_Palette_00_Anim_11; // retreat into ground
        script->AI_TEMP_STATE = AI_STATE_MOLE_BURROW;
    }
}

static void N(MontyMoleAI_Burrow)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->duration--;
    if (npc->duration == 3) {
        enemy->flags |= MONTY_MOLE_UNK_NPC_FLAGS;
    }
    if (npc->duration <= 0) {
        npc->flags |= NPC_FLAG_2;
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
}

ApiStatus N(MontyMoleAI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing tempTerritory;
    EnemyTerritoryThing* territory = &tempTerritory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    
    territory->skipPlayerDetectChance = 0;
    territory->shape = enemy->territory->wander.detectShape;
    territory->pointX = enemy->territory->wander.detect.x;
    territory->pointZ = enemy->territory->wander.detect.z;
    territory->sizeX = enemy->territory->wander.detectSizeX;
    territory->sizeZ = enemy->territory->wander.detectSizeZ;
    territory->halfHeight = 65.0f;
    territory->unk_1C = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
        npc->duration = 0;
        npc->flags &= -(NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING);
        enemy->aiFlags |= (ENEMY_AI_FLAGS_8 | ENEMY_AI_FLAGS_10);
    }
    
    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->aiPaused == 0) {
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else {
            return ApiStatus_BLOCK;
        }
    }
    
    switch (script->AI_TEMP_STATE) {
        case AI_STATE_MOLE_INIT:
            N(MontyMoleAI_Init)(script, aiSettings, territory);
            // fallthrough
        case AI_STATE_MOLE_WANDER:
            N(MontyMoleAI_Wander)(script, aiSettings, territory);
            return ApiStatus_BLOCK;
        case AI_STATE_MOLE_PRE_SURFACE:
            N(MontyMoleAI_PreSurface)(script, aiSettings, territory);
            // fallthrough
        case AI_STATE_MOLE_SURFACE:
            N(MontyMoleAI_Surface)(script, aiSettings, territory);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_DRAW_ROCK) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_DRAW_ROCK:
            N(MontyMoleAI_DrawRock)(script, aiSettings, territory);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_THROW_ROCK) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_THROW_ROCK:
            N(MontyMoleAI_ThrowRock)(script, aiSettings, territory);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_UNUSED) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_PRE_BURROW:
            N(MontyMoleAI_PreBurrow)(script, aiSettings, territory);
            return ApiStatus_BLOCK;
        case AI_STATE_MOLE_BURROW:
            N(MontyMoleAI_Burrow)(script, aiSettings, territory);
            return ApiStatus_BLOCK;
    }
    return ApiStatus_BLOCK;
}

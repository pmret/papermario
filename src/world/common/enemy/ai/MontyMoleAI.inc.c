#include "common.h"
#include "npc.h"
#include "sprite/npc/MontyMole.h"

// prerequisites
#include "world/common/enemy/ai/ProjectileHitbox.inc.c"

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

static s32 N(MontyMoleAI_CanAttack)(Evt* script, EnemyDetectVolume* territory, f32 radius, f32 arg3) {
    Camera* cam;
    Enemy* enemy;
    Npc* npc;
    f32 angle;
    s32 retVal;

    enemy = script->owner1.enemy;
    npc = get_npc_unsafe(enemy->npcID);
    cam = &gCameras[gCurrentCamID];
    retVal = basic_ai_check_player_dist(territory, enemy, radius * 1.1, arg3, 0) != 0;
    // check npc facing angle for sight of player
    angle = 270.0f;
    if (clamp_angle(get_clamped_angle_diff(cam->curYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    }
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z))) > 60.0) {
        retVal = FALSE;
    }
    // check for overlap with player
    if (get_xz_dist_to_player(npc->pos.x, npc->pos.z) < gPlayerStatusPtr->colliderDiameter + npc->collisionDiameter) {
        retVal = FALSE;
    }
    // check player elevation difference
    if (fabsf(npc->pos.y - gPlayerStatusPtr->pos.y) >= 40.0f) {
        retVal = FALSE;
    }
    // check for bow hiding
    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        retVal = FALSE;
    }
    return retVal;
}

static void N(MontyMoleAI_Init)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
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
    npc->flags |= NPC_FLAG_INVISIBLE;
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_MOLE_WANDER;
}

static void N(MontyMoleAI_Wander)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Npc dummyNpc;
    f32 hitDepth;

    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSize.x, enemy->territory->wander.wanderSize.z)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
    }
    dummyNpc.pos.x = npc->pos.x;
    dummyNpc.pos.y = npc->pos.y + 1.0f;
    dummyNpc.pos.z = npc->pos.z;
    npc_move_heading(&dummyNpc, npc->moveSpeed + npc->collisionDiameter, npc->yaw);
    hitDepth = 1000.0f;
    if (npc_raycast_down_sides(0, &dummyNpc.pos.x, &dummyNpc.pos.y, &dummyNpc.pos.z, &hitDepth) && (hitDepth < 5.0f)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    if (npc->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (N(MontyMoleAI_CanAttack)(script, territory, aiSettings->alertRadius, aiSettings->alertOffsetDist)) {
                npc->duration = 0;
                script->AI_TEMP_STATE = AI_STATE_MOLE_PRE_SURFACE;
                return;
            }
        }
        script->functionTemp[1]--;
    }
    if (!(npc->flags & (NPC_FLAG_FLYING | NPC_FLAG_GROUNDED))) {
        npc->homePos.x = npc->pos.x;
        npc->homePos.z = npc->pos.z;
    }
    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
}

static void N(MontyMoleAI_PreSurface)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->flags &= ~NPC_FLAG_INVISIBLE;
    ai_enemy_play_sound(npc, SOUND_BURROW_SURFACE, 0);
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    npc->curAnim = ANIM_MontyMole_Anim10; // emerge from ground
    npc->duration = 10;
    script->AI_TEMP_STATE = AI_STATE_MOLE_SURFACE;
}

static void N(MontyMoleAI_Surface)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 2) {
        enemy->flags &= ~MONTY_MOLE_UNK_NPC_FLAGS;
    }
    if (npc->duration <= 0) {
        npc->curAnim = ANIM_MontyMole_Anim18; // get and throw rock
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_MOLE_DRAW_ROCK;
    }
}

static void N(MontyMoleAI_DrawRock)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteOut;

    npc->duration--;
    if ((npc->duration) <= 0) {
        if (!N(MontyMoleAI_CanAttack)(script, territory, aiSettings->alertRadius * 1.1, aiSettings->alertOffsetDist)) {
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteOut);
            npc->curAnim = ANIM_MontyMole_Anim01; // cancel attack
            npc->duration = 30;
            script->AI_TEMP_STATE =  AI_STATE_MOLE_PRE_BURROW;
        } else {
            npc->curAnim = ANIM_MontyMole_Anim1B; // throw rock
            npc->duration = 15;
            script->AI_TEMP_STATE =  AI_STATE_MOLE_THROW_ROCK;
        }
    }
}

static void N(MontyMoleAI_ThrowRock)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
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
        if (dist2D(moleNpc->pos.x, moleNpc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z) > 100.0) {
            moleNpc->curAnim = ANIM_MontyMole_Anim15; // clap
        }
    }
    if (moleNpc->duration <= 0) {
        if (moleNpc->curAnim != ANIM_MontyMole_Anim15) {
            moleNpc->curAnim = ANIM_MontyMole_Anim01;
        }
        moleNpc->duration = 15;
        script->AI_TEMP_STATE = AI_STATE_MOLE_PRE_BURROW;
    }
}

static void N(MontyMoleAI_PreBurrow)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        ai_enemy_play_sound(npc, SOUND_BURROW_DIG, 0);
        npc->duration = 11;
        npc->curAnim = ANIM_MontyMole_Anim11; // retreat into ground
        script->AI_TEMP_STATE = AI_STATE_MOLE_BURROW;
    }
}

static void N(MontyMoleAI_Burrow)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 3) {
        enemy->flags |= MONTY_MOLE_UNK_NPC_FLAGS;
    }
    if (npc->duration <= 0) {
        npc->flags |= NPC_FLAG_INVISIBLE;
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
    }
}

API_CALLABLE(N(MontyMoleAI_Main)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_MOLE_INIT;
        npc->duration = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
        enemy->aiFlags |= (ENEMY_AI_FLAG_8 | ENEMY_AI_FLAG_10);
    }

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime == 0) {
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_MOLE_INIT:
            N(MontyMoleAI_Init)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_MOLE_WANDER:
            N(MontyMoleAI_Wander)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case AI_STATE_MOLE_PRE_SURFACE:
            N(MontyMoleAI_PreSurface)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_MOLE_SURFACE:
            N(MontyMoleAI_Surface)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_DRAW_ROCK) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_DRAW_ROCK:
            N(MontyMoleAI_DrawRock)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_THROW_ROCK) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_THROW_ROCK:
            N(MontyMoleAI_ThrowRock)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_MOLE_UNUSED) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_MOLE_PRE_BURROW:
            N(MontyMoleAI_PreBurrow)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case AI_STATE_MOLE_BURROW:
            N(MontyMoleAI_Burrow)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }
    return ApiStatus_BLOCK;
}

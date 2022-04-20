#include "common.h"
#include "effects.h"
#include "sprite/npc/world_clubba.h"

// ensure state handlers conform to expected signature
/*
static AIStateHandler N(MontyMoleAI_Init);
static AIStateHandler N(MontyMoleAI_Wander);
static AIStateHandler N(MontyMoleAI_PreSurface);
static AIStateHandler N(MontyMoleAI_Surface);
static AIStateHandler N(MontyMoleAI_DrawRock);
static AIStateHandler N(MontyMoleAI_ThrowRock);
static AIStateHandler N(MontyMoleAI_PreBurrow);
static AIStateHandler N(MontyMoleAI_Burrow);
*/

// ai script
#define TEMP_STATE                  functionTemp[0]
#define TEMP_STATE_AFTER_SUSPEND    functionTemp[1]
// main clubba enemy
#define VAR_ATTACK_STATE    varTable[0]
#define VAR_PREPARE_TIME    varTable[1]
#define VAR_STRIKE_TIME     varTable[2]
#define VAR_MISS_TIME       varTable[3]
#define VAR_NEXT_STATE      varTable[7]
// hitbox enemy
#define VAR_HITNPC_YOFFSET  varTable[0]
#define VAR_HITNPC_DIST     varTable[1]
#define VAR_HITNPC_2        varTable[2]
#define VAR_HITNPC_3        varTable[3]
#define VAR_HITNPC_4        varTable[4]
#define VAR_HITNPC_SOUND    varTable[15]

//#include "world/common/enemy/MeleeHitbox_30.inc.c"

void N(MeleeHitbox_30)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_INIT;
    // if flipping, wait for it to finish
    if (npc->turnAroundYawAdjustment == 0) {
        enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_PREPARE;
        npc->duration = enemy->VAR_PREPARE_TIME;
        npc->currentAnim.w = enemy->animList[8];
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_31;
    }
}

//#include "world/common/enemy/MeleeHitbox_31.inc.c"

void N(MeleeHitbox_31)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_STRIKE;
        npc->duration = enemy->VAR_STRIKE_TIME;
        npc->currentAnim.w = enemy->animList[9];
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_32;
    }
}

//#include "world/common/enemy/MeleeHitbox_32.inc.c"

void N(MeleeHitbox_32)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_POST;
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = enemy->VAR_MISS_TIME;
        if (enemy->VAR_MISS_TIME >= 8) {
            fx_emote(EMOTE_FRUSTRATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, enemy->VAR_MISS_TIME - 1, &emoteTemp);
        }
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_33;
    }
}

//#include "world/common/enemy/MeleeHitbox_33.inc.c"

void N(MeleeHitbox_33)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_NONE;
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT_CHASE;
    }
}

//#include "world/common/enemy/MeleeHitbox_CanSeePlayer.inc.c"

s32 N(MeleeHitbox_CanSeePlayer)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    Enemy* hitboxEnemy = get_enemy(enemy->npcID + 1);
    f32 angle;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > hitboxEnemy->VAR_HITNPC_2) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    } else {
        angle = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                     gPlayerStatusPtr->position.z))) > hitboxEnemy->VAR_HITNPC_3) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y)) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actingPartner == PARTNER_SUSHIE) {
        ret = FALSE;
    }

    return ret;
}

//#include "world/common/enemy/MeleeHitbox_Control.inc.c"

ApiStatus N(MeleeHitbox_Control)(Evt* script, s32 isInitialCall) {
    Enemy* hitboxEnemy = script->owner1.enemy;
    Npc* hitboxNpc = get_npc_unsafe(hitboxEnemy->npcID);
    Enemy* baseEnemy;
    Npc* baseNpc;
    f32 posX, posZ;

    if (isInitialCall || (hitboxEnemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->functionTemp[0] = 0;
        hitboxNpc->duration = 0;
        hitboxNpc->flags |= (NPC_FLAG_2 | NPC_FLAG_100);
        hitboxEnemy->flags |= ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000;
        hitboxNpc->pos.x = 0.0f;
        hitboxNpc->pos.y = -1000.0f;
        hitboxNpc->pos.z = 0.0f;
        if (hitboxEnemy->aiFlags & ENEMY_AI_FLAGS_4) {
            hitboxEnemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            baseEnemy = get_enemy(hitboxEnemy->npcID - 1);
            baseNpc = get_npc_unsafe(baseEnemy->npcID);
            hitboxEnemy->unk_07 = 1;
            if (baseEnemy->VAR_ATTACK_STATE == CLUBBA_ATTACK_STATE_STRIKE) {
                if (hitboxEnemy->VAR_HITNPC_SOUND != 0) {
                    ai_enemy_play_sound(baseNpc, hitboxEnemy->VAR_HITNPC_SOUND, 0);
                }
                posX = baseNpc->pos.x;
                posZ = baseNpc->pos.z;
                add_vec2D_polar(&posX, &posZ, hitboxEnemy->VAR_HITNPC_DIST, 270.0f - baseNpc->renderYaw);

                hitboxNpc->pos.x = posX;
                hitboxEnemy->unk_10.x = hitboxNpc->pos.x;

                hitboxNpc->pos.y = baseNpc->pos.y + hitboxEnemy->VAR_HITNPC_YOFFSET;
                hitboxEnemy->unk_10.y = hitboxNpc->pos.y;

                hitboxNpc->pos.z = posZ;
                hitboxEnemy->unk_10.z = hitboxNpc->pos.z;

                hitboxNpc->yaw = atan2(hitboxNpc->pos.x, hitboxNpc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                hitboxEnemy->flags &= ~(ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000);
                hitboxNpc->duration = 0;
                script->functionTemp[0] = 1;
            }
            break;

        case 1:
            baseEnemy = get_enemy(hitboxEnemy->npcID - 1);
            get_npc_unsafe(baseEnemy->npcID);
            hitboxNpc->duration++;
            if (hitboxNpc->duration >= hitboxEnemy->VAR_HITNPC_4) {
                hitboxEnemy->unk_07 = 0;
            }
            if (baseEnemy->VAR_ATTACK_STATE == CLUBBA_ATTACK_STATE_POST) {
                hitboxEnemy->flags |= ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000;
                hitboxNpc->pos.x = 0.0f;
                hitboxNpc->pos.y = -1000.0f;
                hitboxNpc->pos.z = 0.0f;
                hitboxEnemy->unk_07 = 1;
                script->functionTemp[0] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/enemy/ClubbaNappingAI.inc.c"

//TODO ClubbaWanderAI_Main ?
ApiStatus N(func_80241170_C3ED60)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_99;
            script->TEMP_STATE_AFTER_SUSPEND = AI_STATE_NAPPING_CLUBBA_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->VAR_ATTACK_STATE = CLUBBA_ATTACK_STATE_NONE;
    }

    if (script->TEMP_STATE < AI_STATE_NAPPING_CLUBBA_30
            && enemy->VAR_ATTACK_STATE == CLUBBA_ATTACK_STATE_NONE
            && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_30;
    }

    switch (script->TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case AI_STATE_WANDER:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
        case AI_STATE_LOITER:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_JUMP_INIT:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case AI_STATE_JUMP:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
        case AI_STATE_CHASE:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(MeleeHitbox_30)(script);
        case 31:
            N(MeleeHitbox_31)(script);
            if (script->TEMP_STATE != 32) {
                break;
            }
        case 32:
            N(MeleeHitbox_32)(script);
            if (script->TEMP_STATE != 33) {
                break;
            }
        case 33:
            N(MeleeHitbox_33)(script);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}

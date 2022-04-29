// Unclear purpose. Used in:
// - kmr_02	Toad
// - kmr_07	GoombaBros
// - kmr_11	GoombaBros/King
// - sbk_30	(unused)
// - trd_01	Bombomb
// - nok_01	(unused)
// - omo_02	(unused)

typedef struct Unk4AISettings {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 playerSearchInterval;    // how often to search for player (frames)
    /* 0x0C */ f32 chaseSpeed;
    /* 0x10 */ s32 chaseTurnRate;           // how many degrees this NPC can turn per frame while chasing          
    /* 0x14 */ s32 chaseUpdateInterval;     // how often to re-run chase init and re-acquire player position (frames)
    /* 0x18 */ f32 chaseRadius;      
    /* 0x1C */ f32 chaseOffsetDist;         // offset along npc->yaw of the test point for alert volume overlap, creates directionality to enemy 'sight' 
    /* 0x20 */ s32 unk_20;
} Unk4AISettings; // size = 0x24

#include "common.h"
#include "npc.h"
#include "effects.h"

void N(Unk4AI_00)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->AI_TEMP_STATE = 1;

    if (enemy->flags & ENEMY_FLAGS_100000) {
        npc->yaw = enemy->varTable[0];
    }

    if (enemy->territory->wander.moveSpeedOverride <= 0) {
        npc->moveSpeed = aiSettings->chaseSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
}

void N(Unk4AI_01)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->playerSearchInterval >= 0 && (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0) != 0)) {
        s32 emoteTemp;

        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if (!(enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER)) {
            script->AI_TEMP_STATE = 12;
        } else {
            script->AI_TEMP_STATE = 10;
        }
    }
}

void N(Unk4AI_10)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->AI_TEMP_STATE = 11;
}

void N(Unk4AI_11)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;

    if (!(npc->pos.y > npc->moveToPos.y)) {
        npc->pos.y = npc->moveToPos.y;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~NPC_FLAG_JUMPING;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

void N(Unk4AI_12)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 tempAngle;
    f32 angleDiff;

    npc->duration = (aiSettings->chaseUpdateInterval / 2) + rand_int(aiSettings->chaseUpdateInterval / 2 + 1);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_CHASE];
    npc->moveSpeed = aiSettings->chaseSpeed;

    tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
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
    script->AI_TEMP_STATE = 13;
}

void N(Unk4AI_13)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_check_player_dist(arg2, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1) == 0) {
        s32 something;

        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &something);
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->duration = 25;
        script->AI_TEMP_STATE = 14;
    } else {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        func_8003D660(npc, 1);
        npc->duration--;
        if (npc->duration == 0) {
            script->AI_TEMP_STATE = 12;
        }
    }
}

void N(Unk4AI_14)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = 15;
    }
}

void N(Unk4AI_15)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->chaseSpeed * 0.3;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = 16;
}

void N(Unk4AI_16)(Evt* script, Unk4AISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0) != 0) {
                s32 emoteTemp;

                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, (f32) npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                if (enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                    script->AI_TEMP_STATE = 10;
                } else {
                    script->AI_TEMP_STATE = 12;
                }
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z) < npc->moveSpeed) {
        npc->pos.x = enemy->territory->wander.point.x;
        npc->pos.z = enemy->territory->wander.point.z;
        npc->yaw = enemy->territory->wander.wanderSizeX;
        script->AI_TEMP_STATE = 0;
    }

    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

ApiStatus N(Unk4AI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    Unk4AISettings* aiSettings = (Unk4AISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = 0;
        npc->duration = 0;
        enemy->varTable[0] = npc->yaw;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;

        if (!(enemy->territory->wander.isFlying)) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = 15;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->AI_TEMP_STATE = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            N(Unk4AI_00)(script, aiSettings, territoryPtr);
        case 1:
            N(Unk4AI_01)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(Unk4AI_10)(script, aiSettings, territoryPtr);
        case 11:
            N(Unk4AI_11)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(Unk4AI_12)(script, aiSettings, territoryPtr);
        case 13:
            N(Unk4AI_13)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(Unk4AI_14)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(Unk4AI_15)(script, aiSettings, territoryPtr);
        case 16:
            N(Unk4AI_16)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}

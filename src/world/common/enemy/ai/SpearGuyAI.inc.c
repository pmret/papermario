#include "common.h"
#include "npc.h"
#include "effects.h"
#include "sprite/npc/SpearGuy.h"

void N(SpearGuyAI_LoiterInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 0;
    set_npc_yaw(npc, 270.0f);
    enemy->varTable[0] = 0;
    script->AI_TEMP_STATE = AI_STATE_LOITER;
}

void N(SpearGuyAI_Loiter)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 d100;

    if (enemy->varTable[0] == 0) {
        if (rand_int(100) >= 50) {
            enemy->varTable[0] = 3;
        } else {
            enemy->varTable[0] = 1;
        }
        set_npc_yaw(npc, 270.0f);
    }

    switch (enemy->varTable[0]) {
        case 1:
            enemy->varTable[0] = 2;
            enemy->varTable[1] = 0;
            npc->curAnim = ANIM_SpearGuy_Anim0F;
        case 2:
            enemy->varTable[1]++;
            if (enemy->varTable[1] > 50) {
                enemy->varTable[0] = 5;
            }
            break;
        case 3:
            enemy->varTable[0] = 4;
            enemy->varTable[1] = 0;
            npc->curAnim = ANIM_SpearGuy_Anim10;
        case 4:
            enemy->varTable[1]++;
            if (enemy->varTable[1] == 25) {
                npc->yaw = 90.0f;
            }
            if (enemy->varTable[1] > 60) {
                enemy->varTable[0] = 5;
            }
            break;
        case 5:
            enemy->varTable[0] = 6;
            enemy->varTable[1] = 0;
            npc->curAnim = ANIM_SpearGuy_Anim03;
            fx_sweat(0, npc->pos.x, npc->pos.y, npc->pos.z, npc->collisionHeight, 0, 10);
        case 6:
            enemy->varTable[1]++;
            if (enemy->varTable[1] > 10) {
                d100 = rand_int(100);

                if (d100 < 90) {
                    enemy->varTable[0] = 7;
                } else if (d100 >= 95) {
                    enemy->varTable[0] = 3;
                } else {
                    enemy->varTable[0] = 1;
                }
            }
            break;
    }

    if (enemy->varTable[0] == 7) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
    }
}

// prerequisites
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

API_CALLABLE(N(SpearGuyAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_FLYING;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_FLYING;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->AI_TEMP_STATE_AFTER_SUSPEND = AI_STATE_WANDER_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->AI_TEMP_STATE < AI_STATE_MELEE_HITBOX_INIT) && (enemy->varTable[0] == 0) && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_INIT;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case AI_STATE_WANDER:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;

        case AI_STATE_LOITER_INIT:
            N(SpearGuyAI_LoiterInit)(script, npcAISettings, territoryPtr);
        case AI_STATE_LOITER:
            N(SpearGuyAI_Loiter)(script, npcAISettings, territoryPtr);
            break;

        case AI_STATE_ALERT_INIT:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case AI_STATE_ALERT:
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

        case AI_STATE_MELEE_HITBOX_INIT:
            N(MeleeHitbox_30)(script);
        case AI_STATE_MELEE_HITBOX_PRE:
            N(MeleeHitbox_31)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_ACTIVE) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_ACTIVE:
            N(MeleeHitbox_32)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_MISS) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_MISS:
            N(MeleeHitbox_33)(script);
            break;

        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}

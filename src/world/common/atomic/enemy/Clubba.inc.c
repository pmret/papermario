#include "common.h"
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

enum AiStateNappingClubba {
    AI_STATE_NAPPING_CLUBBA_INIT                = 0,
    AI_STATE_NAPPING_CLUBBA_SLEEP               = 1,
    AI_STATE_NAPPING_CLUBBA_WAKE_UP             = 2,
    AI_STATE_NAPPING_CLUBBA_3                   = 3,
    AI_STATE_NAPPING_CLUBBA_ACQUIRE             = 4,
    AI_STATE_NAPPING_CLUBBA_10                  = 10,
    AI_STATE_NAPPING_CLUBBA_11                  = 11,
    AI_STATE_NAPPING_CLUBBA_INIT_CHASE          = AI_STATE_CHASE_INIT,
    AI_STATE_NAPPING_CLUBBA_CHASE               = AI_STATE_CHASE,
    AI_STATE_NAPPING_CLUBBA_LOSE_PLAYER         = AI_STATE_LOSE_PLAYER,
    AI_STATE_NAPPING_CLUBBA_30                  = 30,
    AI_STATE_NAPPING_CLUBBA_31                  = 31,
    AI_STATE_NAPPING_CLUBBA_32                  = 32,
    AI_STATE_NAPPING_CLUBBA_33                  = 33,
    AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME    = 40,
    AI_STATE_NAPPING_CLUBBA_RETURN_HOME         = 41,
    AI_STATE_NAPPING_CLUBBA_50                  = 50,
    AI_STATE_NAPPING_CLUBBA_99                  = 99,
};

extern Npc* wPartnerNpc;

#define TEMP_STATE functionTemp[0]

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

void N(ClubbaNappingAI_Init)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->duration == 1) {
        npc->currentAnim.w = enemy->animList[12];
    } else if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_SLEEP;
    }
}

void N(ClubbaNappingAI_Sleep)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerData* playerData = get_player_data();
    s32 shouldWakeUp = FALSE;
    s32 emoteTemp;
    f32 posX, posZ;

    if (basic_ai_try_detect_player(territory, enemy, 80.0f, 0.0f, 0)) {
        if (   gPlayerStatusPtr->actionState == ACTION_STATE_RUN
            || gPlayerStatusPtr->actionState == ACTION_STATE_SPIN
            || gPlayerStatusPtr->actionState == ACTION_STATE_JUMP
            || gPlayerStatusPtr->actionState == ACTION_STATE_GROUND_POUND
            || gPlayerStatusPtr->actionState == ACTION_STATE_ULTRA_POUND
            || gPlayerStatusPtr->actionState == ACTION_STATE_STEP_DOWN_LAND
            || gPlayerStatusPtr->actionState == ACTION_STATE_LAND
            || gPlayerStatusPtr->actionState == ACTION_STATE_HAMMER
            || gPlayerStatusPtr->actionState == ACTION_STATE_13
            || gPlayerStatusPtr->actionState == ACTION_STATE_25) {
            shouldWakeUp = TRUE;
        }

        if (playerData->currentPartner == PARTNER_KOOPER) {
            if (gPartnerActionStatus.partnerActionState == playerData->currentPartner) {
                shouldWakeUp = TRUE;
            }
        }
    }

    if (((playerData->currentPartner == PARTNER_GOOMBARIO) && (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE)) ||
        ((playerData->currentPartner == PARTNER_BOMBETTE) && (gPartnerActionStatus.partnerActionState == PARTNER_ACTION_BOMBETTE_2))) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        add_vec2D_polar(&posX, &posZ, 0.0f, npc->yaw);
        if (dist2D(posX, posZ, wPartnerNpc->pos.x, wPartnerNpc->pos.z) <= 80.0f) {
            shouldWakeUp = TRUE;
        }
    }

    if (shouldWakeUp) {
        ai_enemy_play_sound(npc, 0xB000000E, 0);
        npc->currentAnim.w = enemy->animList[11];
        npc->duration = 10;
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_WAKE_UP;
    }

    npc->duration++;
    if (npc->duration == 27) {
        ai_enemy_play_sound(npc, 0xB000000C, 0);
    } else if (npc->duration == 57) {
        ai_enemy_play_sound(npc, 0xB000000D, 0);
    } else if (npc->duration == 59) {
        npc->currentAnim.w = enemy->animList[12];
    } else if (npc->duration == 60) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
    }
}

void N(ClubbaNappingAI_WakeUp)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME;
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_3;
    }
}

void N(func_802409C0_C3E5B0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim.w = enemy->animList[0];
    script->functionTemp[1] = (rand_int(1000) % 2) + 2; // chose random number 2-3
    script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_ACQUIRE;
}

void N(ClubbaNappingAI_AcquirePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 nextState;

    // try to catch sight of player
    if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT_CHASE;
        return;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        // try to turn around and check the other direction
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            return;
        }

        // didnt see player, continue to next state
        nextState = enemy->varTable[7];
        if (nextState == AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME) {
            npc->duration = 20;
            script->TEMP_STATE = nextState;
        } else if (nextState == AI_STATE_NAPPING_CLUBBA_50) {
            npc->duration = 25;
            script->TEMP_STATE = nextState;
        }
    }
}

void N(ClubbaNappingAI_InitReturnHome)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[1];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_RETURN_HOME;
    }
}

void N(func_80240C4C_C3E83C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 currentYaw;

    if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT_CHASE;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x,
                      enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 15;
        enemy->varTable[7] = AI_STATE_NAPPING_CLUBBA_50;
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_3;
    } else if (npc->turnAroundYawAdjustment == 0) {
        currentYaw = npc->yaw;
        ai_check_fwd_collisions(npc, 5.0f, &currentYaw, 0, 0, 0);
        npc->yaw = currentYaw;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(func_80240DC4_C3E9B4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 0;
            script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT;
        }
    }
}

ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall) {
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
    territory.halfHeight = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT;
        npc->duration = 30;
        npc->currentAnim.w = enemy->animList[10];
        npc->flags &= ~NPC_FLAG_JUMPING;
        enemy->varTable[0] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | NPC_FLAG_GRAVITY) & ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags = (npc->flags & ~NPC_FLAG_GRAVITY) | NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_99;
            script->functionTemp[1] = 40;
            npc->currentAnim.w = enemy->animList[0];
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    //TODO find a better way to write the state-check condition
    if (((u32)script->TEMP_STATE - 10 < 20) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_30;
    }

    switch (script->TEMP_STATE) {
        case AI_STATE_NAPPING_CLUBBA_INIT:
            N(ClubbaNappingAI_Init)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_SLEEP:
            N(ClubbaNappingAI_Sleep)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_WAKE_UP:
            N(ClubbaNappingAI_WakeUp)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_3:
            N(func_802409C0_C3E5B0)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_ACQUIRE:
            N(ClubbaNappingAI_AcquirePlayer)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_INIT_CHASE:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            if (script->TEMP_STATE != AI_STATE_NAPPING_CLUBBA_CHASE) {
                break;
            }
        case AI_STATE_NAPPING_CLUBBA_CHASE:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_LOSE_PLAYER:
            // LOSE PLAYER
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            npc->duration = 15;
            enemy->varTable[7] = AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME;
            script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_3;
            break;
        case AI_STATE_NAPPING_CLUBBA_30:
            N(UnkNpcAIFunc6)(script);
            if (script->TEMP_STATE != AI_STATE_NAPPING_CLUBBA_31) {
                break;
            }
        case AI_STATE_NAPPING_CLUBBA_31:
            N(UnkNpcAIFunc7)(script);
            if (script->TEMP_STATE != AI_STATE_NAPPING_CLUBBA_32) {
                break;
            }
        case AI_STATE_NAPPING_CLUBBA_32:
            // frustration, attack missed 
            N(UnkNpcAIFunc8)(script);
            break;
        case AI_STATE_NAPPING_CLUBBA_33:
            N(UnkNpcAIFunc5)(script);
            break;
        case AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME:
            // START RETURN HOME
            N(ClubbaNappingAI_InitReturnHome)(script, npcAISettings, territoryPtr);
            if (script->TEMP_STATE != AI_STATE_NAPPING_CLUBBA_RETURN_HOME) {
                break;
            }
        case AI_STATE_NAPPING_CLUBBA_RETURN_HOME:
            // RETURN HOME
            N(func_80240C4C_C3E83C)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_50:
            // WAIT TO NAP
            N(func_80240DC4_C3E9B4)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_99:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}

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
        script->TEMP_STATE = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->TEMP_STATE = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->TEMP_STATE < 30) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->TEMP_STATE = 30;
    }

    switch (script->TEMP_STATE) {
        case 0:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case 1:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case 2:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
        case 3:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case 10:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case 11:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case 12:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
        case 13:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case 14:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->TEMP_STATE != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->TEMP_STATE != 33) {
                break;
            }
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 99:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}

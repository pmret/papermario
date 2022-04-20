#include "common.h"

extern Npc* wPartnerNpc;

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
        enemy->VAR_NEXT_STATE = AI_STATE_NAPPING_CLUBBA_INIT_RETURN_HOME;
        script->TEMP_STATE = AI_STATE_NAPPING_CLUBBA_3;
    }
}

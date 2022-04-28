#include "common.h"
#include "npc.h"

void N(UnkFloAI_Chase)(Evt* script, NpcAISettings* npcAISettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    if (!basic_ai_try_detect_player(territory, enemy, npcAISettings->chaseRadius, npcAISettings->unk_28.f, 1)) {
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->duration = 25;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
    } else {
        if (npc->currentAnim.w != enemy->animList[ENEMY_ANIM_MELEE_PRE]) {
            if (npc->moveSpeed < 4.0) {
                func_8003D660(npc, 0);
            } else {
                func_8003D660(npc, 1);
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
        if (npc->duration > 0) {
            npc->duration--;
            return;
        }
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

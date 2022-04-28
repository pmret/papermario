#include "common.h"
#include "npc.h"
#include "effects.h"

void N(Unk4AI_13)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_try_detect_player(arg2, enemy, aiSettings->chaseSpeed, aiSettings->unk_1C.f, 1) == 0) {
        s32 something;

        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &something);
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->duration = 25;
        script->functionTemp[0] = 14;
    } else {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        func_8003D660(npc, 1);
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[0] = 12;
        }
    }
}

#include "common.h"
#include "npc.h"

// identical to basic_ai_loiter_init
void N(PatrolAI_LoiterInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->AI_TEMP_STATE = AI_STATE_LOITER;
}

#include "common.h"
#include "npc.h"

void N(FlyingAI_JumpInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus* playerStatus = gPlayerStatusPtr;

    npc->duration = 0;
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
    script->functionTemp[0] = AI_STATE_ALERT;
}

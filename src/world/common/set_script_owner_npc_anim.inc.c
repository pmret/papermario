#include "common.h"
#include "npc.h"

void N(set_script_owner_npc_anim)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
    npc->duration = enemy->varTable[2];
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    script->AI_TEMP_STATE = 13;
}

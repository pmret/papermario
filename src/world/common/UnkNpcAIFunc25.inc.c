#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc25)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2]++;
    if (script->functionTemp[2] >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2] = 0;
    }
    npc->currentAnim.w = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0] = 1;
}

#include "common.h"
#include "npc.h"

void N(PatrolAI_PostLoiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2]++;
    if (script->functionTemp[2] >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2] = 0;
    }
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->AI_TEMP_STATE = AI_STATE_PATROL;
}

#include "common.h"
#include "npc.h"
#include "effects.h"

void N(PiranhaPlantAI_00)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    } else {
        enemy->varTable[0] = 0;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 1;
    }
}

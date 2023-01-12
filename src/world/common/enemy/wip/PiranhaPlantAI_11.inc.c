#include "common.h"

void N(PiranhaPlantAI_11)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (enemy->varTable[11] >= npc->duration) {
        enemy->flags &= ~(ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000);
    }
    if (npc->duration == 0) {
        npc->currentAnim = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 12;
    }
}

#include "common.h"
#include "npc.h"
#include "effects.h"

void N(PiranhaPlantAI_12)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    npc->duration++;
    if (npc->duration == enemy->varTable[13]) {
        npc->currentAnim = enemy->animList[11];
    }
    if (npc->duration == enemy->varTable[14]) {
        enemy->varTable[0] = 3;
    }
    if (npc->duration >= enemy->varTable[12]) {
        enemy->varTable[0] = 4;
        npc->duration = 8;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        fx_emote(EMOTE_FRUSTRATION, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        script->functionTemp[0] = 13;
    }
}

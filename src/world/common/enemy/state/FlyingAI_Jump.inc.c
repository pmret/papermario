#include "common.h"
#include "npc.h"

extern f32 N(sixFloats)[];

void N(FlyingAI_Jump)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(sixFloats)[npc->duration++];
    if (npc->duration >= 5) {
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}


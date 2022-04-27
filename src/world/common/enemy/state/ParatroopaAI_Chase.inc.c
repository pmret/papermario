#include "common.h"
#include "npc.h"

void N(ParatroopaAI_Chase)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->jumpVelocity += npc->jumpScale;
    npc->pos.y += npc->jumpVelocity;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    npc->duration--;

    if (npc->duration <= 0) {
        enemy->unk_07 = 0;
        npc->jumpScale = 0.3f;
        npc->jumpVelocity = 0.0f;
        npc->moveSpeed = 3.0f;
        npc->currentAnim.w = enemy->animList[10];
        script->AI_TEMP_STATE = 14;
    }
}

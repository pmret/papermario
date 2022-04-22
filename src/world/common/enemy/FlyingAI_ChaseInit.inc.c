#include "common.h"
#include "npc.h"

void N(FlyingAI_ChaseInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 jumpVelocity = (f32)enemy->varTable[5] / 100.0;
    f32 jumpScale = (f32)enemy->varTable[6] / 100.0;

    npc->currentAnim.w = enemy->animList[8];
    npc->jumpVelocity = jumpVelocity;
    npc->jumpScale = jumpScale;
    npc->moveSpeed = aiSettings->chaseSpeed;
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

    enemy->varTable[2] = 0;

    if (enemy->npcSettings->unk_2A & AI_ACTION_02) {
        npc->duration = 3;
        script->AI_TEMP_STATE = AI_STATE_CHASE;
    } else {
        npc->duration = 1;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
    }
}

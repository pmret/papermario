#include "common.h"
#include "npc.h"

void N(ParatroopaAI_ChaseInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 yawTemp;

    npc->currentAnim.w = enemy->animList[9];
    npc->jumpVelocity = -5.0f;
    npc->jumpScale = 0.15f;
    npc->collisionHeight = enemy->varTable[8] / 2;

    dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->moveSpeed = 7.0f;
    enemy->unk_10.x = npc->pos.x;
    enemy->unk_10.y = npc->pos.y;
    enemy->unk_10.z = npc->pos.z;
    enemy->unk_07 = 1;

    ai_enemy_play_sound(npc, SOUND_UNUSED_2C1, 0);
    yawTemp = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->duration = 12;
    npc->yaw = yawTemp;
    script->AI_TEMP_STATE = 13;
}

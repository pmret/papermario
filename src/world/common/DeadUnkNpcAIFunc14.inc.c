#include "common.h"
#include "map.h"

void N(DeadUnkNpcAIFunc14)(ScriptInstance* script, NpcAISettings* aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = func_8003E4BC(enemy->npcID);
    f32 vt5 = enemy->varTable[5];
    f32 jumpVelocity = vt5 / 100.0;
    f32 vt6 = enemy->varTable[6];
    f32 jumpScale = vt6 / 100.0;

    npc->currentAnim = enemy->animList[8];
    npc->jumpVelocity = jumpVelocity;
    npc->jumpScale = jumpScale;
    npc->moveSpeed = aiSettings->chaseSpeed;
    npc->yaw = dead_atan2(npc->pos.x, npc->pos.z, D_800FFC90->position.x, D_800FFC90->position.z);

    enemy->varTable[2] = 0;

    if (enemy->npcSettings->unk_2A & 2) {
        npc->duration = 3;
        script->functionTemp[0].s = 13;
    } else {
        npc->duration = 1;
        script->functionTemp[0].s = 14;
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
    }
}

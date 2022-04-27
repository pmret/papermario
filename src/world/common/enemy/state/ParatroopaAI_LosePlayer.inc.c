#include "common.h"
#include "npc.h"

void N(ParatroopaAI_LosePlayer)(Evt *script, NpcAISettings *arg1, EnemyTerritoryThing *arg2)
{
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 Braw = enemy->varTable[3];
    f32 posX, posY, posZ, hitDepth;
    f32 A;
    f32 B;

    npc->jumpVelocity += npc->jumpScale;
    npc->pos.y += npc->jumpVelocity;
    B = Braw / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    hitDepth = 1000.0f;
    if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
        A = posY + B;
    } else {
        A = B;
    }
    if (!(npc->pos.y < A)) {
        npc->duration = 10;
        npc->currentAnim.w = enemy->animList[11];
        npc->collisionHeight = enemy->varTable[8];
        script->AI_TEMP_STATE = 0xF;
    }
}

#include "common.h"
#include "npc.h"

void N(FlyingAI_Init)(Npc* npc, Enemy* enemy, Evt* script, NpcAISettings* aiSettings) {
    f32 posX, posY, posZ, depth;

    script->functionTemp[0] = 0;
    npc->duration = 0;

    npc->flags &= ~NPC_FLAG_GRAVITY;
    npc->flags |= NPC_FLAG_JUMPING;
    if (enemy->territory->wander.isFlying) {
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
    } else {
        npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    depth = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &depth);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = (depth * 100.0) + 0.5;
    enemy->varTable[7] = (posY * 100.0) + 0.5;
    script->functionTemp[1] = aiSettings->playerSearchInterval;
    enemy->aiFlags |= ENEMY_AI_FLAGS_10;
}

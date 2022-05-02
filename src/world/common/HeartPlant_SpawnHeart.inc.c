#include "common.h"

ApiStatus N(HeartPlant_SpawnHeart)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    if ((enemy->varTable[0] < 5) && (rand_int(1000) > 300)) {
        make_item_entity_nodelay(ITEM_HEART, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z + 5.0, 3, 0);
        enemy->varTable[0] += 1;
    }
    return ApiStatus_DONE2;
}

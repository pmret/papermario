#include "trd_01.h"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/enemy/UnkAI_4.inc.c"

ApiStatus func_80241630_99DFC0(Evt* script, s32 isInitialCall) {
    Enemy* owner1 = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    owner1->territory->wander.point.x = npc->pos.x;
    owner1->territory->wander.point.y = npc->pos.y;
    owner1->territory->wander.point.z = npc->pos.z;
    owner1->territory->wander.detect.x = npc->pos.x;
    owner1->territory->wander.detect.y = npc->pos.y;
    owner1->territory->wander.detect.z = npc->pos.z;
    return ApiStatus_DONE2;
}

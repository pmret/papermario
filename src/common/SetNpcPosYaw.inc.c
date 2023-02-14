#include "common.h"

API_CALLABLE(N(SetNpcPosYaw)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    npc->pos.x = x;
    npc->pos.y = y;
    npc->pos.z = z;
    npc->yaw = yaw;
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.y = npc->pos.y;
    npc->colliderPos.z = npc->pos.z;
    npc->flags |= NPC_FLAG_DIRTY_SHADOW;
    return ApiStatus_DONE2;
}

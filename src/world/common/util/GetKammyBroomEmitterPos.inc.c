#include "common.h"
#include "npc.h"

#ifndef KAMMY_NPC
#error  KAMMY_NPC must be defined
#define KAMMY_NPC 0
#endif

API_CALLABLE(N(GetKammyBroomEmitterPos)) {
    Npc* npc = get_npc_unsafe(KAMMY_NPC);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 40.0f);
    script->varTable[1] = npc->pos.y + 8.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 40.0f);
    return ApiStatus_DONE2;
}

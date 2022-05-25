#include "common.h"
#include "npc.h"

#ifndef UNK_NPC_POS_FUNC_NUM
#error  UNK_NPC_POS_FUNC_NUM must be defined
#define UNK_NPC_POS_FUNC_NUM 0
#endif

ApiStatus N(UnkNpcPosFunc)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(UNK_NPC_POS_FUNC_NUM);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 40.0f);
    script->varTable[1] = npc->pos.y + 8.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 40.0f);
    return ApiStatus_DONE2;
}

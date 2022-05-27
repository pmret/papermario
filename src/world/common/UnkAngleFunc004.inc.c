#include "common.h"
#include "npc.h"

ApiStatus N(UnkAngleFunc004)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    switch (script->functionTemp[1]) {
        case 0:
            npc->duration = rand_int(180) + 30;
            npc->pos.z = -300.0f;
            npc->pos.y = rand_int(50) + 80.0f;
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            if (rand_int(100) < 50) {
                npc->pos.x = 270.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -270.0f;
                npc->yaw = 90.0f;
            }
            script->functionTemp[1] = 1;
            break;
        case 1:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 2;
            }
            break;
        case 2:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -280.0f || npc->pos.x > 280.0f) {
                script->functionTemp[1] = 0;
            }
            break;
    }
    return ApiStatus_DONE2;
}

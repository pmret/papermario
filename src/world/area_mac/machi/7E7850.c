#include "machi.h"

ApiStatus func_802404B0_7E7850(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0x37);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->moveToPos.x = npc->pos.x + 500.0f;
            npc->moveToPos.y = npc->pos.y + 120.0f;
            npc->moveToPos.z = npc->pos.z - 500.0f;
            npc->duration = 20;
            npc->moveToPos.x = (npc->moveToPos.x - npc->pos.x) / npc->duration;
            npc->moveToPos.y = (npc->moveToPos.y - npc->pos.y) / npc->duration;
            npc->moveToPos.z = (npc->moveToPos.z - npc->pos.z) / npc->duration;
            npc->duration = 100;
            npc->moveToPos.x /= 10.0f;
            npc->moveToPos.y /= 10.0f;
            npc->moveToPos.z /= 10.0f;
            enable_npc_blur(npc);
            script->functionTemp[0] = 1;
            break;
        case 1:
            npc->pos.x += npc->moveToPos.x;
            npc->pos.y += npc->moveToPos.y;
            npc->pos.z += npc->moveToPos.z;
            npc->moveToPos.x = npc->moveToPos.x * 1.05;
            npc->moveToPos.y = npc->moveToPos.y * 1.05;
            npc->moveToPos.z = npc->moveToPos.z * 1.05;
            npc->duration--;
            if (npc->duration == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

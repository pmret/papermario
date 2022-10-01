#include "common.h"
#include "npc.h"

ApiStatus N(UnkAngleFunc001)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    Npc* npc = N(resolve_npc)(script, npcID);
    f32 y;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    N(unkAngle1) += 4;
    if (N(unkAngle1) >= 360) {
        N(unkAngle1) -= 360;
    }

    y = npc->pos.y;
    if (npc->currentAnim == 0xB60000 ||
        npc->currentAnim == 0xB60004 ||
        npc->currentAnim == 0xB60008 ||
        npc->currentAnim == 0xB6000C)
    {
        y += 2.0f * sin_deg(N(unkAngle1));
    }

    evt_set_float_variable(script, outX, npc->pos.x);
    evt_set_float_variable(script, outY, y);
    evt_set_float_variable(script, outZ, npc->pos.z);
    return ApiStatus_DONE2;
}

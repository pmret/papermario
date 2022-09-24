#include "kpa_63.h"

static char* N(exit_str_0) = "kpa_62";
static char* N(exit_str_1) = "kpa_60";

ApiStatus func_80240000_A735B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner;
    f32 x, y, z;
    f32 yBase;
    f32 angle;
    f32 var_f20;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        yBase = evt_get_variable(script, *args++);
        angle = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                var_f20 = 0.0f;
                break;
            case 1:
                var_f20 = 5.0f;
                break;
        }
    }

    x = (sin_deg(angle) * var_f20) + -120.0f;
    y = yBase - 11.0f;
    z = (cos_deg(angle) * var_f20) + 225.0f;

    switch (script->functionTemp[0]) {
        case 0:
            gPlayerStatus.position.x = x;
            gPlayerStatus.position.y = y;
            gPlayerStatus.position.z = z;
            break;
        case 1:
            partner = get_npc_safe(NPC_PARTNER);
            if (partner != NULL) {
                partner->pos.x = x;
                partner->pos.y = y;
                partner->pos.z = z;
                partner->colliderPos.x = partner->pos.x;
                partner->colliderPos.y = partner->pos.y;
                partner->colliderPos.z = partner->pos.z;
                partner->flags |= NPC_FLAG_DIRTY_SHADOW;
            }
            break;
        default:
            return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

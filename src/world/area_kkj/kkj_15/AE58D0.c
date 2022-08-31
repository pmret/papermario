#include "kkj_15.h"

ApiStatus func_80240340_AE58D0(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(-4);
    f32 angle;
    f32 mag;
    f32 var;

    var = (script->varTable[2] + 230000000);
    var /= 1024.0f;

    mag = dist2D(50.0f, -200.0f, script->varTable[7], script->varTable[8]);
    angle = clamp_angle(atan2(50.0f, -200.0f, script->varTable[7], script->varTable[8]) - var);
    gPlayerStatus.position.x = 50.0f + mag * sin_deg(angle);
    gPlayerStatus.position.z = -200.0f - mag * cos_deg(angle);

    mag = dist2D(50.0f, -200.0f, script->varTable[9], script->varTable[10]);
    angle = clamp_angle(atan2(50.0f, -200.0f, script->varTable[9], script->varTable[10]) - var);
    npc->pos.x = 50.0f + mag * sin_deg(angle);
    npc->pos.z = -200.0f - mag * cos_deg(angle);

    return ApiStatus_DONE2;
}

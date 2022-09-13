#include "common.h"

//TODO begin with a (guarded) include for GetItem functions:
// #include "world/common/atomic/ItemChoice_PartA.inc.c"

// extern s32 N(LetterDelivery_SavedNpcAnim);

ApiStatus N(LetterDelivery_Init)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2] = evt_get_variable(script, *args++);
    script->varTable[3] = evt_get_variable(script, *args++);
    script->varTable[4] = evt_get_variable(script, *args++);
    script->varTable[5] = evt_get_variable(script, *args++);
    script->varTable[6] = evt_get_variable(script, *args++);
    script->varTable[7] = evt_get_variable(script, *args++);
    script->varTable[8] = evt_get_variable(script, *args++);
    script->varTable[9] = evt_get_variable(script, *args++);
    script->varTable[10] = evt_get_variable(script, *args++);
    script->varTable[11] = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_CalcLetterPos)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    f32 a = evt_get_variable(script, a0);
    s32 a1 = *args++;
    f32 b = evt_get_variable(script, a1);
    s32 a2 = *args++;
    f32 c = evt_get_variable(script, a2);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);

    add_vec2D_polar(&a, &c, 15.0f, partner->yaw);
    add_vec2D_polar(&a, &c, 10.0f, currentCamYaw);

    evt_set_variable(script, a0, a);
    evt_set_variable(script, a1, b);
    evt_set_variable(script, a2, c);

    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_SaveNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    N(LetterDelivery_SavedNpcAnim) = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_RestoreNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    npc->currentAnim = N(LetterDelivery_SavedNpcAnim);
    return ApiStatus_DONE2;
}

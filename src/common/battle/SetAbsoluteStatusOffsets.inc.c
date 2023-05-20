#include "battle/battle.h"

API_CALLABLE(N(SetAbsoluteStatusOffsets)) {
    Bytecode* args = script->ptrReadPos;
    s32 iconX = evt_get_variable(script, *args++);
    s32 iconY = evt_get_variable(script, *args++);
    s32 textX = evt_get_variable(script, *args++);
    s32 textY = evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);

    actor->statusIconOffset.x = (s8)(iconX - actor->actorBlueprint->statusIconOffset.x);
    actor->statusIconOffset.y = (s8)(iconY - actor->actorBlueprint->statusIconOffset.y);
    actor->statusTextOffset.x = (s8)(textX - actor->actorBlueprint->statusTextOffset.x);
    actor->statusTextOffset.y = (s8)(textY - actor->actorBlueprint->statusTextOffset.y);

    return ApiStatus_DONE2;
}

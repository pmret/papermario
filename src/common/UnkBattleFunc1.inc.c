#include "battle/battle.h"

API_CALLABLE(N(UnkBattleFunc1)) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);

    actor->unk_194 = (s8)(var0 - actor->actorBlueprint->statusIconOffset.x);
    actor->unk_195 = (s8)(var1 - actor->actorBlueprint->statusIconOffset.y);
    actor->unk_196 = (s8)(var2 - actor->actorBlueprint->statusMessageOffset.x);
    actor->unk_197 = (s8)(var3 - actor->actorBlueprint->statusMessageOffset.y);

    return ApiStatus_DONE2;
}

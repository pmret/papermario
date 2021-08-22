#include "battle/battle.h"

ApiStatus N(UnkBattleFunc1)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);

    actor->unk_194 = (s8)(var0 - actor->staticActorData->statusIconOffset.x);
    actor->unk_195 = (s8)(var1 - actor->staticActorData->statusIconOffset.y);
    actor->unk_196 = (s8)(var2 - actor->staticActorData->statusMessageOffset.x);
    actor->unk_197 = (s8)(var3 - actor->staticActorData->statusMessageOffset.y);

    return ApiStatus_DONE2;
}

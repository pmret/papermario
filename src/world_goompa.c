#include "common.h"

void func_802BD100_324A10(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 20;
}

ApiStatus func_802BD114(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EECC4(ownerID);
    }
    return func_800EECE8(ownerID) != 0;
}


INCLUDE_ASM(s32, "world_goompa", func_802BD14C);

INCLUDE_ASM(s32, "world_goompa", func_802BD4E0);

ApiStatus func_802BD524(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_802BD52C(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EE994(ownerID);
    }
    return func_800EE9B8(ownerID) != 0;
}

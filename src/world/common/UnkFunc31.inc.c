#include "common.h"
#include "map.h"

void N(UnkFunc28)(ScriptInstance *script, s32 isInitialCall);

ApiStatus N(UnkFunc31)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->owner2.npcID);

    npc->onRender = N(UnkFunc28);
    npc->blurBuf = heap_malloc(8);
    *((s32*)npc->blurBuf) = 0;

    return ApiStatus_DONE1;
}

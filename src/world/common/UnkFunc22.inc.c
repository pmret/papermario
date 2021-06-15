#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc22)(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(-4);

    func_80070BB0(9, npc->pos.x, npc->pos.y + 12.5f, npc->pos.z, 1.0f, 0x1E);

    return ApiStatus_DONE2;
}

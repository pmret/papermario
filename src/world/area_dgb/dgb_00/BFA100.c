#include "dgb_00.h"

ApiStatus func_80240060_BFA100(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(get_enemy(6)->npcID);

    func_801499EC(0x32E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

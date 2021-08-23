#include "tst_04.h"

ApiStatus func_80240660_B1BBD0(Evt* script, s32 isInitialCall) {
    disable_npc_shadow(get_npc_unsafe(script->owner1.enemy->npcID));
    return ApiStatus_DONE2;
}

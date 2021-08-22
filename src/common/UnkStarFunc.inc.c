#include "common.h"

ApiStatus N(UnkStarFunc)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;

    set_animation(0x100, 0, D_8029C890[playerData->currentPartner][get_variable(script, *args++)]);

    return ApiStatus_DONE2;
}

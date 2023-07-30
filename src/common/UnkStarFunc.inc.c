#include "common.h"

API_CALLABLE(N(UnkStarFunc)) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;

    set_animation(ACTOR_PARTNER, 0, D_8029C890[playerData->curPartner][evt_get_variable(script, *args++)]);

    return ApiStatus_DONE2;
}

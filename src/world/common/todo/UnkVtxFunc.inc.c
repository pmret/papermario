#include "common.h"
#include "npc.h"

void N(SomeVtxFunc)(void) {
    script->varTable[0] = gPlayerData.coins;
    return ApiStatus_DONE2;
}

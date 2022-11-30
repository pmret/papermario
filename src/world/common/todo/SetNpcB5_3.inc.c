#include "common.h"
#include "npc.h"

API_CALLABLE(N(SetNpcB5_3)) {
    script->owner1.enemy->unk_B5 = 3;
    return ApiStatus_DONE2;
}

#include "common.h"
#include "npc.h"

API_CALLABLE(N(SetInstigatorValue_3)) {
    script->owner1.enemy->instigatorValue = 3;
    return ApiStatus_DONE2;
}

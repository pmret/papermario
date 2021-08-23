#include "common.h"
#include "map.h"

ApiStatus N(SetNpcB5_3)(Evt* script, s32 isInitialCall) {
    script->owner1.enemy->unk_B5 = 3;
    return ApiStatus_DONE2;
}

#include "tik_18.h"

#include "world/common/UnkPosFunc2.inc.c"

ApiStatus func_80240680_895D60(Evt* script, s32 isInitialCall) {
    Enemy* enemy = get_enemy_safe(1);

    if (enemy != 0) {
        enemy->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

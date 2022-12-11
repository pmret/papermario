#include "obk_08.h"

#define KNOCK_DOWN_MAP_VAR MapVar(10)
#include "world/common/complete/KnockDownPlayer.inc.c"

API_CALLABLE(N(func_80240808_BD4078)) {
    if (gPlayerData.curHP <= 1) {
        return ApiStatus_DONE2;
    }
    gPlayerData.curHP--;
    return ApiStatus_DONE2;
}

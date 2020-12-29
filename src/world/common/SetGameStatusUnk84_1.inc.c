#include "common.h"
#include "map.h"

ApiStatus M(SetGameStatusUnk84_1)(ScriptInstance* script, s32 isInitialCall) {
    GAME_STATUS->unk_84 = 1;
    return ApiStatus_BLOCK;
}

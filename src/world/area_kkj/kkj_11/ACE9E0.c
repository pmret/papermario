#include "kkj_11.h"

#define NAMESPACE dup_kkj_11
#include "../common/Searchlights.inc.c"
#define NAMESPACE kkj_11

#include "world/common/todo/GetPeachDisguise.inc.c"

ApiStatus func_80240F44_ACF084(Evt* script, s32 isInitialCall) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= PEACH_STATUS_FLAG_8;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_kkj_11
#include "../common/ApproachPlayer100Units.inc.c"
#define NAMESPACE kkj_11

const char* kkj_11_str2 = "kkj_14";

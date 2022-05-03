#include "kkj_11.h"

#define NAMESPACE dup_kkj_11
#include "world/common/atomic/UnkPhysicsFuncs.inc.c"
#define NAMESPACE kkj_11

#include "world/common/GetPeachDisguise.inc.c"

ApiStatus func_80240F44_ACF084(void) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= 8;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_kkj_11
#include "world/common/UnkGooberFunc.inc.c"
#define NAMESPACE kkj_11

const char* kkj_11_str2 = "kkj_14";

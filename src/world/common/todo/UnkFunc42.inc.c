#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc42)) {
    script->varTable[10] = atan2(script->varTable[0], script->varTable[2], script->varTable[3], script->varTable[5]);
    return ApiStatus_DONE2;
}

#include "dead.h"
#include "common.h"

ApiStatus func_80240530_EF7FB0(Evt* script, s32 isInitialCall) {
    script->varTable[10] = atan2(script->varTable[0], script->varTable[2], script->varTable[3], script->varTable[5]);
    return ApiStatus_DONE2;
}

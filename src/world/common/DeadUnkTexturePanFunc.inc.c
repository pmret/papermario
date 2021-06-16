#include "common.h"
#include "map.h"

ApiStatus N(DeadUnkTexturePanFunc)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[9] += script->varTable[1];
    if (script->varTable[9] < 0) {
        script->varTable[9] += 0x20000;
    } else if (script->varTable[9] > 0x20000) {
        script->varTable[9] -= 0x20000;
    }

    script->varTable[10] += script->varTable[2];
    if (script->varTable[10] < 0) {
        script->varTable[10] += 0x20000;
    } else if (script->varTable[10] > 0x20000) {
        script->varTable[10] -= 0x20000;
    }

    script->varTable[11] += script->varTable[3];
    if (script->varTable[11] < 0) {
        script->varTable[11] += 0x20000;
    } else if (script->varTable[11] > 0x20000) {
        script->varTable[11] -= 0x20000;
    }

    script->varTable[12] += script->varTable[4];
    if (script->varTable[12] < 0) {
        script->varTable[12] += 0x20000;
    } else if (script->varTable[12] > 0x20000) {
        script->varTable[12] -= 0x20000;
    }

    func_80126064(script->varTable[0], script->varTable[9]);
    func_8012607C(script->varTable[0], script->varTable[10]);
    func_80126094(script->varTable[0], script->varTable[11]);
    func_801260AC(script->varTable[0], script->varTable[12]);
    return ApiStatus_BLOCK;
}

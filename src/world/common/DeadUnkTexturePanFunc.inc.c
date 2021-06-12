#include "common.h"
#include "map.h"

ApiStatus N(DeadUnkTexturePanFunc)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[9].s += script->varTable[1].s;
    if (script->varTable[9].s < 0) {
        script->varTable[9].s += 0x20000;
    } else if (script->varTable[9].s > 0x20000) {
        script->varTable[9].s -= 0x20000;
    }

    script->varTable[10].s += script->varTable[2].s;
    if (script->varTable[10].s < 0) {
        script->varTable[10].s += 0x20000;
    } else if (script->varTable[10].s > 0x20000) {
        script->varTable[10].s -= 0x20000;
    }

    script->varTable[11].s += script->varTable[3].s;
    if (script->varTable[11].s < 0) {
        script->varTable[11].s += 0x20000;
    } else if (script->varTable[11].s > 0x20000) {
        script->varTable[11].s -= 0x20000;
    }

    script->varTable[12].s += script->varTable[4].s;
    if (script->varTable[12].s < 0) {
        script->varTable[12].s += 0x20000;
    } else if (script->varTable[12].s > 0x20000) {
        script->varTable[12].s -= 0x20000;
    }

    func_80126064(script->varTable[0].s, script->varTable[9].s);
    func_8012607C(script->varTable[0].s, script->varTable[10].s);
    func_80126094(script->varTable[0].s, script->varTable[11].s);
    func_801260AC(script->varTable[0].s, script->varTable[12].s);
    return ApiStatus_BLOCK;
}

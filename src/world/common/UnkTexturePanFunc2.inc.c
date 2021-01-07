#include "common.h"
#include "map.h"

ApiStatus N(UnkTexturePanFunc2)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 0;
        script->functionTemp[2].s = 0;
        script->functionTemp[3].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        script->varTable[9] += script->varTable[1];
        if (script->varTable[9] < 0) {
            script->varTable[9] += 0x20000;
        } else if (script->varTable[9] > 0x20000) {
            script->varTable[9] -= 0x20000;
        }
    }

    if (script->functionTemp[1].s == 0) {
        script->varTable[10] += script->varTable[2];
        if (script->varTable[10] < 0) {
            script->varTable[10] += 0x20000;
        } else if (script->varTable[10] > 0x20000) {
            script->varTable[10] -= 0x20000;
        }
    }

    if (script->functionTemp[2].s == 0) {
        script->varTable[11] += script->varTable[3];
        if (script->varTable[11] < 0) {
            script->varTable[11] += 0x20000;
        } else if (script->varTable[11] > 0x20000) {
            script->varTable[11] -= 0x20000;
        }
    }

    if (script->functionTemp[3].s == 0) {
        script->varTable[12] += script->varTable[4];
        if (script->varTable[12] < 0) {
            script->varTable[12] += 0x20000;
        } else if (script->varTable[12] > 0x20000) {
            script->varTable[12] -= 0x20000;
        }
    }

    set_main_pan_u(script->varTable[0], script->varTable[9]);
    set_main_pan_v(script->varTable[0], script->varTable[10]);
    set_aux_pan_u(script->varTable[0], script->varTable[11]);
    set_aux_pan_v(script->varTable[0], script->varTable[12]);

    script->functionTemp[0].s++;
    script->functionTemp[1].s++;
    script->functionTemp[2].s++;
    script->functionTemp[3].s++;

    if (script->functionTemp[0].s >= script->varTable[5]) {
        script->functionTemp[0].s = 0;
    }
    if (script->functionTemp[1].s >= script->varTable[6]) {
        script->functionTemp[1].s = 0;
    }
    if (script->functionTemp[2].s >= script->varTable[7]) {
        script->functionTemp[2].s = 0;
    }
    if (script->functionTemp[3].s >= script->varTable[8]) {
        script->functionTemp[3].s = 0;
    }
    return ApiStatus_BLOCK;
}

#include "common.h"
#include "map.h"

s32 N(UnkFunc23)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 ret = 0;

    if (isInitialCall) {
        script->varTable[0] = get_variable(script, *args++);
        script->varTable[1] = get_variable(script, *args++);
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 0;
        set_transition_stencil_color(0, 0xD0, 0xD0, 0xD0);
    }

    switch (script->functionTemp[0].s) {
        case 0:
            if (script->functionTemp[1].s == 0xFF) {
                script->functionTemp[0].s = 1;
                script->functionTemp[2].s = 0;
            }
            script->functionTemp[1].s += script->varTable[0];
            if (script->functionTemp[1].s >= 0x100) {
                script->functionTemp[1].s = 0xFF;
            }
            break;

        case 1:
            script->functionTemp[2].s++;
            if (script->functionTemp[2].s >= 2) {
                script->functionTemp[0].s = 2;
            }
            break;

        case 2:
            if (script->functionTemp[1].s == 0) {
                ret = 1;
            }
            script->functionTemp[1].s -= script->varTable[1];
            if (script->functionTemp[1].s < 0) {
                script->functionTemp[1].s = 0;
            }
            break;
    }

    set_transition_stencil_zoom_0(1, script->functionTemp[1].s);

    return ret;
}

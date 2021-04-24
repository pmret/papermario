#include "common.h"
#include "map.h"

ApiStatus N(UnkMusicFunc)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    X32* something;
    s32 cond = 0;
    f32 dist;

    if (isInitialCall) {
        script->functionTemp[0].s = get_variable(script, *args);
        script->functionTemp[1].s = 0;
        script->functionTemp[2].s = ((s32*)(script->functionTemp[0].s))[5];
    }

    something = (X32*) script->functionTemp[0].s;

    if (get_variable(script, script->functionTemp[2].s)) {
        if (script->functionTemp[1].s != 2) {
            script->functionTemp[1].s = 2;
            cond = TRUE;
        }
    } else {
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, something[0].f, something[1].f);

        switch (script->functionTemp[1].s) {
            case 0:
                if (dist < something[2].f) {
                    script->functionTemp[1].s = 1;
                    cond = TRUE;
                }
                break;
            case 1:
                if (dist > something[3].f) {
                    script->functionTemp[1].s = 0;
                    cond = TRUE;
                }
                break;
            case 2:
                script->functionTemp[1].s = 1;
                cond = TRUE;
                break;
        }
    }

    if (cond) {
        func_8014AA54(0, something[4].s, script->functionTemp[1].s);
    }

    return ApiStatus_BLOCK;
}

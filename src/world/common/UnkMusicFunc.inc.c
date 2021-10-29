#include "common.h"
#include "npc.h"

ApiStatus N(UnkMusicFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    X32* something;
    s32 cond = 0;
    f32 dist;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args);
        script->functionTemp[1] = 0;
        script->functionTemp[2] = ((s32*)(script->functionTemp[0]))[5];
    }

    something = (X32*) script->functionTemp[0];

    if (evt_get_variable(script, script->functionTemp[2])) {
        if (script->functionTemp[1] != 2) {
            script->functionTemp[1] = 2;
            cond = TRUE;
        }
    } else {
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, something[0].f, something[1].f);

        switch (script->functionTemp[1]) {
            case 0:
                if (dist < something[2].f) {
                    script->functionTemp[1] = 1;
                    cond = TRUE;
                }
                break;
            case 1:
                if (dist > something[3].f) {
                    script->functionTemp[1] = 0;
                    cond = TRUE;
                }
                break;
            case 2:
                script->functionTemp[1] = 1;
                cond = TRUE;
                break;
        }
    }

    if (cond) {
        func_8014AA54(0, something[4].s, script->functionTemp[1]);
    }

    return ApiStatus_BLOCK;
}

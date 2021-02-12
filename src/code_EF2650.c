#include "common.h"

extern s16 D_80169B16;

ApiStatus func_80240040_EF2650(ScriptInstance* script, s32 isInitialCall) {
    func_802D5468(script,*script->ptrReadPos, D_80169B16);
    return 2;
}

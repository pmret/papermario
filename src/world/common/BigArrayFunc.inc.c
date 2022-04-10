#include "common.h"
#include "npc.h"

ApiStatus N(BigArrayFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(bigArray)[i] = ptr[i];
        }
        N(bigArray)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(bigArray)[i] = i + 16;
            N(bigArray)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

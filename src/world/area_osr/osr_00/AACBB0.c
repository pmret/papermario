#include "osr_00.h"

#include "world/common/atomic/UnkFunc27.inc.c"

s32 func_80240678_AACEA8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = *args++;
    s32 primG = *args++;
    s32 primB = *args++;
    s32 envR = *args++;
    s32 envG = *args++;
    s32 envB = *args++;
    set_model_env_color_parameters(primR & 0xFF, primG & 0xFF, primB & 0xFF, envR & 0xFF, envG & 0xFF, envB & 0xFF);
    return 2;
}

INCLUDE_ASM(s32, "world/area_osr/osr_00/AACBB0", func_802406E0_AACF10);

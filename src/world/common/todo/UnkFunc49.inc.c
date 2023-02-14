#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc49)) {
    script->varTable[5] = (cos_deg(-(f32) script->varTable[3] - 35.0) * 3.0) - 2.3;
    script->varTable[6] = sin_deg(-(f32) script->varTable[3] - 35.0) * 5.0;

    return ApiStatus_DONE2;
}

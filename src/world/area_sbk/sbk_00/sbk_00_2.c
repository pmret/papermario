#include "common.h"

//INCLUDE_ASM(s32, "world/area_sbk/sbk_00", func_80240040_929270);
ApiStatus func_80240040_929270(ScriptInstance* script, s32 isInitialCall) {
    script->ownerActorID->unk_B5 = 3;
    return ApiStatus_DONE2;
}

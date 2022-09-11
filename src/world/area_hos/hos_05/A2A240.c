#include "hos_05.h"

static char* N(exit_str_0) = "hos_04";
static char* N(exit_str_1) = "";

#include "world/common/atomic/UnkFunc27.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus N(AwaitScriptComplete)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 waitingScriptID = evt_get_variable(script, *args++);

    if (!does_script_exist(waitingScriptID)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2A240", func_80240634_A2A874);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2A240", func_80240690_A2A8D0);

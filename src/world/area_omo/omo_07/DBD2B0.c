#include "omo_07.h"

static char* N(exit_str_0) = "omo_06";
static char* N(exit_str_1) = "";

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/ShyGuyPatrolAI.inc.c"

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

ApiStatus func_80242EA8_DC0158(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1;
    s32 t0;
    s32 t1;

    temp_s1 = AreaFlag(7);
    do {
        t0 = evt_get_variable(script, *(args++));
    } while (0); // TODO required to match
    t0 += temp_s1;
    t1 = evt_get_variable(script, *args++);

    evt_set_variable(script, t0, t1);
    return ApiStatus_DONE2;
}

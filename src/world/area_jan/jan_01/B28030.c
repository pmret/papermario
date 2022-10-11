#include "jan_01.h"

static char* N(exit_str_0) = "jan_00";
static char* N(exit_str_1) = "jan_02";

#include "world/common/atomic/TexturePan.inc.c"

void fx_sun_undeclared(s32, s32, s32, s32, s32, s32);

// will not match with correct function definition
ApiStatus func_8024030C_B2833C(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ai/HoppingAI.inc.c"

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

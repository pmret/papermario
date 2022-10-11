#include "omo_05.h"

static char* N(exit_str_0) = "omo_17";
static char* N(exit_str_1) = "";

#include "world/common/enemy/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/GrooveGuyAI.inc.c"

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242178_DB4438);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802421CC_DB448C);

extern s32 D_80245650[];

ApiStatus func_80242204_DB44C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80245650[i] = ptr[i];
        }
        D_80245650[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80245650[i] = i + 128;
            D_80245650[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802422A0_DB4560);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242328_DB45E8);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802423C8_DB4688);

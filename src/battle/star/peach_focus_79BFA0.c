#include "common.h"

#define NAMESPACE battle_star_peach_focus

#include "common/UnkStarFuncs.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/peach_focus_79BFA0", func_802A1494_79C434);

#include "common/SetNpcCollision32.inc.c"

ApiStatus func_802A1518_79C4B8(ScriptInstance* script, s32 isInitialCall) {
    ((s32*)script->varTable[0])[1]++; // TODO replace with actual struct when we know what this is
    return ApiStatus_DONE2;
}

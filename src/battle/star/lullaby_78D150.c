#include "common.h"

#define NAMESPACE battle_star_lullaby

#include "common/UnkStarFuncs.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/lullaby_78D150", func_802A1494_78D5E4);

#include "common/SetNpcCollision32.inc.c"

void func_800706D0(s32, f32, f32, f32);

//INCLUDE_ASM(s32, "battle/star/lullaby_78D150", func_802A1518_78D668);
ApiStatus func_802A1518_78D668(ScriptInstance* script, s32 isInitialCall) {
    s32 ret = ApiStatus_DONE2;
    s32 temp;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s != 0) {
        if (script->functionTemp[0].s != 1) {
            return 0;
        }

    } else {
        script->functionTemp[2].s = -80;
        script->functionTemp[1].s = 0;
        script->functionTemp[0].s = 1;
    }


    temp = script->functionTemp[2].s;
    func_800706D0(0, (f32)temp, (f32)((s32)((sin_rad((script->functionTemp[1].s * 6.28318f) / 360.0f) * 30.0f) + 30.0f)), 50.0f);

    script->functionTemp[2].s += 14;
    script->functionTemp[1].s += 20;

    if (script->functionTemp[1].s >= 360) {
        return ret;
    }

    return ApiStatus_BLOCK;
}

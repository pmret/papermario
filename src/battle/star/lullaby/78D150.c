#include "common.h"

#define NAMESPACE battle_star_lullaby

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_78D668(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
            s32 temp;
            s32 temp2;

        case 0:
            script->functionTemp[2] = -80;
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
        case 1:
            temp = script->functionTemp[2];
            temp2 = (sin_rad((script->functionTemp[1] * TAU) / 360.0f) * 30.0f) + 30.0f;
            playFX_26(0, temp, temp2, 50.0f);

            script->functionTemp[2] += 14;
            script->functionTemp[1] += 20;

            if (script->functionTemp[1] >= 360) {
                return ApiStatus_DONE2;
            }
    }
    return ApiStatus_BLOCK;
}

#include "obk_07.h"

INCLUDE_ASM(s32, "world/area_obk/obk_07/BCEEB0", func_802402C0_BCEEB0);

#include "world/common/todo/UnkAngleFunc004.inc.c"

extern s16 D_8024292C_BD151C[];

ApiStatus func_80240454_BCF044(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1 = script->varTable[1];
    s32 temp;

    if (var1 == 0) {
        script->functionTemp[2] = D_8024292C_BD151C[rand_int(3)];
        var1 = rand_int(50) + 30;
    }
    var1--;

    temp = script->functionTemp[2];
    if (var0 < temp) {
        var0 += 10;
        if (temp < var0) {
            var0 = temp;
        }
    }
    if (temp < var0) {
        var0 -= 10;
        if (var0 < temp) {
            var0 = temp;
        }
    }

    script->varTable[0] = var0;
    script->varTable[1] = var1;
    return ApiStatus_DONE2;
}

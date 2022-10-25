#include "obk_02.h"

static char* N(exit_str_0) = "obk_01";
static char* N(exit_str_1) = "obk_03";
static char* N(exit_str_2) = "obk_06";
static char* N(exit_str_3) = "";

ApiStatus func_80240000_BC2A90(Evt* script, s32 isInitialCall) {
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkAngleFunc004.inc.c"

extern s16 D_80240CBC_BC374C[];

ApiStatus func_80240194_BC2C24(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1 = script->varTable[1];
    s32 temp;

    if (var1 == 0) {
        script->functionTemp[2] = D_80240CBC_BC374C[rand_int(3)];
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

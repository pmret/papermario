#include "dead.h"
#include "common.h"

#define NAMESPACE EED1E0

extern s32 D_80094900[];
extern s8 D_80117852;
extern s32 D_800A15A8;
extern s8 D_80117160[];

ApiStatus func_802400E0_EED1E0(Evt* script, s32 isInitialCall) {
    D_800A15A8 |= 0x40;
    return ApiStatus_DONE2;
}

ApiStatus func_802400FC_EED1FC(Evt* script, s32 isInitialCall) {
    D_800A15A8 &= ~0x40;
    return ApiStatus_DONE2;
}

ApiStatus func_8024011C_EED21C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EED1E0", func_80240148_EED248);

INCLUDE_ASM(s32, "EED1E0", func_802401B4_EED2B4);

INCLUDE_ASM(s32, "EED1E0", func_80240200_EED300);

INCLUDE_ASM(s32, "EED1E0", func_802402AC_EED3AC);

ApiStatus func_802404FC_EED5FC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    func_800F2D5C(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_80240528_EED628(Evt* script, s32 isInitialCall) {
    func_80130C74(D_80094900[D_80117852 * 4], 0);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EED1E0", func_80240560_EED660);

ApiStatus func_802405F0_EED6F0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = evt_get_variable(script, *args++);

    *temp_v0 |= 0x10;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EED1E0", func_80240624_EED724);

INCLUDE_ASM(s32, "EED1E0", func_80240688_EED788);

INCLUDE_ASM(s32, "EED1E0", func_802406E0_EED7E0);

INCLUDE_ASM(s32, "EED1E0", func_80240C18_EEDD18);

#include "world/common/DeadUnkPartnerPosFuncs.inc.c"

ApiStatus func_80240DE8_EEDEE8(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if (D_80117160[0] != 0 && D_80117160[3] == 3) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240E18_EEDF18(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;

    do {} while (0);

    if (gPlayerActionState == ACTION_STATE_GROUND_POUND || gPlayerActionState == ACTION_STATE_ULTRA_POUND) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

#include "kkj_14.h"

extern s32 D_80241D38_ADCBD8;
extern u8 D_80241D3B_ADCBDB;

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024035C_ADB1FC(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~0x1;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}

ApiStatus func_80240384_ADB224(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= 0x4;
    return ApiStatus_DONE2;
}

#include "world/common/GetPeachDisguise.inc.c"

ApiStatus func_802403CC_ADB26C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241D38_ADCBD8 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_802403F8_ADB298(void) {
    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, PRIMITIVE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241D3B_ADCBDB);
}

ApiStatus func_80240480_ADB320(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_8024049C_ADB33C(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~0x10;
    return ApiStatus_DONE2;
}

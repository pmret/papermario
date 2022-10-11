#include "hos_01.h"
#include "effects.h"

extern u32 D_80241C2C_A124AC;
extern u32 D_80241C30_A124B0;

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_80240AAC_A1132C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 190.0f;
    effect->data.unk_75->unk_7C = 220.0f;
    effect->data.unk_75->unk_68 = 0.7f;
    return ApiStatus_DONE2;
}

ApiStatus func_80240B10_A11390(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 170.0f;
    effect->data.unk_75->unk_7C = 170.0f;
    effect->data.unk_75->unk_68 = 2.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80240B64_A113E4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_38 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_80240BB8_A11438(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241C2C_A124AC);
}

ApiStatus func_80240C08_A11488(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241C2C_A124AC = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_80240C34_A114B4(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241C30_A124B0);
}

ApiStatus func_80240C84_A11504(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241C30_A124B0 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "world/common/SwitchToPartner.inc.c"

ApiStatus func_80240CDC_A1155C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = evt_get_variable(script, *args++);
    s32 a1 = evt_get_variable(script, *args++);
    s32 a2 = evt_get_variable(script, *args++);
    s32 a3 = evt_get_variable(script, *args++);
    s32 a4 = evt_get_variable(script, *args++);

    fx_sparkles(a0, a1, a2, a3, a4);
    return ApiStatus_DONE2;
}

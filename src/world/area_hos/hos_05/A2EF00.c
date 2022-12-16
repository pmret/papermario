#include "hos_05.h"
#include "model.h"

extern s32 D_8024DCCC_A37F0C;
extern s32 D_8024DCD0_A37F10;
extern s16 D_802D9D72; // something wrong with this / the next
extern u8 D_802D9D73;

#define NAMESPACE dup_hos_05
#include "world/common/atomic/UnkFunc27.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

#define NAMESPACE hos_05

ApiStatus func_802452C4_A2F504(Evt* script, s32 isInitialCall) {
    Bytecode* args;
    static char N(bss_padding)[0x200]; // TODO remove / relocate this
    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;
    static s32 newPrimR, newPrimG, newPrimB;
    static s32 newEnvR, newEnvG, newEnvB;
    static s32 duration, time;

    args = script->ptrReadPos;
    if (isInitialCall) {
        get_model_env_color_parameters(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        newPrimR = evt_get_variable(script, *args++);
        newPrimG = evt_get_variable(script, *args++);
        newPrimB = evt_get_variable(script, *args++);
        newEnvR = evt_get_variable(script, *args++);
        newEnvG = evt_get_variable(script, *args++);
        newEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        time = 0;
    }

    if (duration > 0) {
        time++;
        set_model_env_color_parameters(
            (oldPrimR + ((newPrimR - oldPrimR) * time) / duration),
            (oldPrimG + ((newPrimG - oldPrimG) * time) / duration),
            (oldPrimB + ((newPrimB - oldPrimB) * time) / duration),
            (oldEnvR  + ( (newEnvR - oldEnvR)  * time) / duration),
            (oldEnvG  + ( (newEnvG - oldEnvG)  * time) / duration),
            (oldEnvB  + ( (newEnvB - oldEnvB)  * time) / duration));
        if (time >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

void func_8024564C_A2F88C(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_802D9D73);
}

ApiStatus func_8024569C_A2F8DC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802D9D72 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_802456C8_A2F908(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_8024DCCC_A37F0C);
}

ApiStatus func_80245718_A2F958(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_8024DCCC_A37F0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_80245744_A2F984(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_8024DCD0_A37F10);
}

ApiStatus func_80245794_A2F9D4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_8024DCD0_A37F10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802457C0_A2FA00(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        script->functionTemp[0] = 40;
    }
    script->functionTemp[0]--;
    if (camera->currentController != NULL) {
        camera->currentController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    } else if (camera->prevController != NULL) {
        camera->prevController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

const char* N(exit_str_0) = "hos_20";
const char* N(exit_str_1) = "hos_04";

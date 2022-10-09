#include "hos_04.h"
#include "nu/nusys.h"

extern f32 D_80241B54_A28A24;
extern f32 D_80241B74_A28A44;
extern f32 D_80241B7C_A28A4C;
extern s32 D_80241B80_A28A50;
extern s32 D_80241B84_A28A54;
extern s32 D_80241B88_A28A58;
extern f32 D_80243370;
extern f32 D_80243374;

ApiStatus N(SetCamXXVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240654_A27524(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->creditsViewportMode < 5U) {
        gGameStatusPtr->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

ApiStatus func_8024068C_A2755C(Evt* script, s32 isInitialCall) {
    return ApiStatus_BLOCK;
}

void func_80240694_A27564(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4) {
    f32 temp_f2 = arg1 - arg2;

    if (arg1 - arg0 > 0.0f) {
        if (temp_f2 < 0.0f) {
            *arg4 = arg1;
        } else if (arg3 < temp_f2) {
            *arg4 += arg3;
        } else {
            *arg4 += temp_f2;
        }
    } else if (temp_f2 > 0.0f) {
        *arg4 = arg1;
    } else if (temp_f2 < -arg3) {
        *arg4 -= arg3;
    } else {
        *arg4 += temp_f2;
    }
}

void func_80240734_A27604(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32* arg5) {
    f32 var_f12_2;

    if (arg3 > arg4) {
        arg3 = arg4;
    }

    switch (arg0) {
        case 1:
            var_f12_2 = sin_deg((arg3 / arg4) * 90.0f);
            break;
        case 2:
            if (arg3 < 30.0f) {
                var_f12_2 = 0.0f;
            } else {
                var_f12_2 = sin_deg((((arg3 - 30.0f) / (arg4 - 30.0f)) * 90.0f) + -90.0f) + 1.0f;
            }
            break;
        case 3:
            var_f12_2 = (sin_deg(((arg3 / arg4) * 180.0f) - 90.0f) + 1.0f) * 0.5;
            break;
        case 4:
            var_f12_2 = sin_deg(((arg3 / arg4) * 90.0f) - 90.0f) + 1.0f;
            break;
        case 5:
            var_f12_2 = (2.0 * (sin_deg(((arg3 / arg4) * 60.0f) - 60.0f) + 0.8660254f)) / 1.7320507764816284;
            break;
        default:
            var_f12_2 = arg3 / arg4;
            break;
    }
    *arg5 = arg1 + ((arg2 - arg1) * var_f12_2);
}

ApiStatus func_802408F8_A277C8(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == D_80241B80_A28A50) {
        return ApiStatus_BLOCK;
    }

    D_80241B80_A28A50 = nuGfxCfb_ptr;
    func_80240694_A27564(700.0f, 300.0f, D_80241B7C_A28A4C, 1.2f, &D_80241B7C_A28A4C);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_80241B7C_A28A4C;
    return ApiStatus_BLOCK;
}

ApiStatus func_802409B0_A27880(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        D_80243370 = D_80241B54_A28A24;
    }
    func_80240734_A27604(1, D_80241B54_A28A24, 700.0f, D_80241B84_A28A54, 70.0f, &D_80243370);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_80243370;
    D_80241B84_A28A54++;
    if (D_80241B84_A28A54 < 70) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80240A84_A27954(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        D_80243374 = D_80241B74_A28A44;
    }
    func_80240734_A27604(5, D_80241B74_A28A44, -80.0f, D_80241B88_A28A58, 200.0f, &D_80243374);
    camera->panActive = TRUE;
    camera->controlSettings.viewPitch = D_80243374;
    D_80241B88_A28A58++;
    if (D_80241B88_A28A58 == 200) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

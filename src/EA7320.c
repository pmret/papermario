#include "dead.h"
#include "common.h"

#define NAMESPACE EA7320

extern s16 D_80169B12;

ApiStatus func_80240350_EA7320(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[0];

    camera->flags |= 0x1000;
    return ApiStatus_DONE2;
}

ApiStatus func_8024036C_EA733C(Evt* script, s32 isInitialCall) {
    gCameras->flags &= 0xEFFF;
    return ApiStatus_DONE2;
}

ApiStatus func_80240388_EA7358(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, D_80169B12);
    return ApiStatus_DONE2;
}

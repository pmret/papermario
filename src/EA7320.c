#include "dead.h"
#include "common.h"

#define NAMESPACE EA7320

ApiStatus func_80240350_EA7320(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[0];

    camera->flags |= 0x1000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA7320", func_8024036C_EA733C);

INCLUDE_ASM(s32, "EA7320", func_80240388_EA7358);

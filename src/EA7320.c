#include "common.h"

#define NAMESPACE EA7320

ApiStatus func_80240350_EA7320(ScriptInstance* script, s32 isInitialCall) {
    Camera* camera = &dead_gCameras[0];

    camera->flags |= 0x1000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA7320", func_8024036C_EA733C);

INCLUDE_ASM(s32, "EA7320", func_80240388_EA7358);

#include "hos_04.h"

ApiStatus N(SetCamXXVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_80240654_A27524);

ApiStatus func_8024068C_A2755C(Evt* script, s32 isInitialCall) {
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_80240694_A27564);

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_80240734_A27604);

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_802408F8_A277C8);

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_802409B0_A27880);

INCLUDE_ASM(s32, "world/area_hos/hos_04/A274B0", func_80240A84_A27954);

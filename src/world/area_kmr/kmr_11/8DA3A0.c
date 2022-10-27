#include "kmr_11.h"
#include "effects.h"

ApiStatus func_802402A0_8DA3A0(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f24 = evt_get_float_variable(script, *args++);
    f32 temp_f22 = evt_get_float_variable(script, *args++);
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    s32 t4 = evt_get_variable(script, *args++);

    fx_lens_flare(0, temp_f24, temp_f22, temp_f20, t4);
    return ApiStatus_DONE2;
}
ApiStatus func_80240344_8DA444(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ai/StationaryAI.inc.c"

#define UNK_NPC_POS_FUNC_NUM 4
#include "world/common/todo/UnkNpcPosFunc.inc.c"

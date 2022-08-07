#include "isk_11.h"
#include "effects.h"

static char* N(exit_str_0) = "isk_08";
static char* N(exit_str_1) = "isk_12";
static char* N(exit_str_2) = "isk_19";
static char* N(exit_str_3) = "";

ApiStatus func_80240000_98AA10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    
    fx_lens_flare(0, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

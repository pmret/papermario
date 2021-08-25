#include "common.h"
#include "map.h"

void set_model_fog_color_parameters(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7, u8 var8, s32 var9, s32 var10);
void set_model_env_color_parameters(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7);

ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args++);
    s32 var6 = get_variable(script, *args++);
    s32 var7 = get_variable(script, *args++);
    s32 var8 = get_variable(script, *args++);
    s32 var9 = get_variable(script, *args++);
    s32 var10 = get_variable(script, *args++);

    switch (var1) {
        case 1:
            set_background_color_blend(var2, var3, var4, var5);
            break;
        case 2:
            set_model_fog_color_parameters(var2, var3, var4, var5, var6, var7, var8, var9, var10);
            break;
        case 3:
            set_model_env_color_parameters(var2, var3, var4, var5, var6, var7);
            break;
    }

    return ApiStatus_DONE2;
}

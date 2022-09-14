#include "common.h"
#include "npc.h"
#include "model.h"

ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 testS2 = evt_get_variable(script, *args++);
    s32 testS0 = evt_get_variable(script, *args++);
    s32 testS1 = evt_get_variable(script, *args++);
    s32* temp_s0_3 = (s32*) testS0;
    s32 temp_s1 = testS1;
    s32 temp_s2 = testS2;

    if (temp_s0_3 == PTR_LIST_END) {
        mdl_set_all_fog_mode(temp_s1);
        return ApiStatus_DONE2;
    }

    switch (temp_s2) {
        case 0:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(*temp_s0_3)), -1, temp_s1);
                temp_s0_3++;
            };
            break;

        case 1:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                func_8011B950(*temp_s0_3, -1, temp_s1, 0);
                temp_s0_3++;
            };
            break;

        case 2:
            *D_801512F0 = temp_s1;
            break;

    }
    return ApiStatus_DONE2;
}

void set_model_fog_color_parameters(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7, u8 var8, s32 var9, s32 var10);
void set_model_env_color_parameters(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7);

ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args++);
    s32 var6 = evt_get_variable(script, *args++);
    s32 var7 = evt_get_variable(script, *args++);
    s32 var8 = evt_get_variable(script, *args++);
    s32 var9 = evt_get_variable(script, *args++);
    s32 var10 = evt_get_variable(script, *args++);

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

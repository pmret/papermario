#include "common.h"
#include "npc.h"
#include "model.h"

API_CALLABLE(N(UnkFunc27)) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    s32 testS0 = evt_get_variable(script, *args++);
    s32 fogType = evt_get_variable(script, *args++);
    s32* modelIDList = (s32*) testS0;
    s32 listIndex;
    Model* mdl;

    if (modelIDList == PTR_LIST_END) {
        mdl_set_all_fog_mode(fogType);
        return ApiStatus_DONE2;
    }

    switch (mode) {
        case 0:
            while (TRUE) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                listIndex = get_model_list_index_from_tree_index(*modelIDList);
                mdl = get_model_from_list_index(listIndex);
                set_mdl_custom_gfx_set(mdl, -1, fogType);
                modelIDList++;
            };
            break;

        case 1:
            while (TRUE) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                func_8011B950(*modelIDList, -1, fogType, 0);
                modelIDList++;
            };
            break;

        case 2:
            *gBackgroundFogModePtr = fogType;
            break;

    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UnkFunc26)) {
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

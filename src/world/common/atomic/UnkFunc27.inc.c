#include "common.h"
#include "npc.h"
#include "model.h"

enum {
    FUNC27_MODE_0   = 0,
    FUNC27_MODE_1   = 1,
    FUNC27_MODE_2   = 2,
};

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
        case FUNC27_MODE_0:
            while (TRUE) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                listIndex = get_model_list_index_from_tree_index(*modelIDList);
                mdl = get_model_from_list_index(listIndex);
                set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, fogType);
                modelIDList++;
            };
            break;

        case FUNC27_MODE_1:
            while (TRUE) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                func_8011B950(*modelIDList, CUSTOM_GFX_NONE, fogType, FALSE);
                modelIDList++;
            };
            break;

        case FUNC27_MODE_2:
            *gBackgroundFogModePtr = fogType;
            break;

    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UnkFunc26)) {
    Bytecode* args = script->ptrReadPos;
    s32 fogMode = evt_get_variable(script, *args++);
    s32 arg0 = evt_get_variable(script, *args++);
    s32 arg1 = evt_get_variable(script, *args++);
    s32 arg2 = evt_get_variable(script, *args++);
    s32 arg3 = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);
    s32 arg7 = evt_get_variable(script, *args++);
    s32 arg8 = evt_get_variable(script, *args++);

    switch (fogMode) {
        case FOG_MODE_1:
            set_background_color_blend(arg0, arg1, arg2, arg3);
            break;
        case FOG_MODE_2:
            mdl_set_fog2_color_parameters(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            break;
        case FOG_MODE_3:
            mdl_set_fog3_color_parameters(arg0, arg1, arg2, arg3, arg4, arg5);
            break;
    }

    return ApiStatus_DONE2;
}

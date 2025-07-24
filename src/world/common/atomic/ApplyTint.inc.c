#include "common.h"
#include "npc.h"
#include "model.h"

enum {
    APPLY_TINT_MODELS   = 0,
    APPLY_TINT_GROUPS   = 1,
    APPLY_TINT_BG       = 2,
};

API_CALLABLE(N(SetModelTintMode)) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    s32 testS0 = evt_get_variable(script, *args++);
    s32 tintType = evt_get_variable(script, *args++);
    s32* modelIDList = (s32*) testS0;
    s32 listIndex;
    Model* mdl;

    if (modelIDList == PTR_LIST_END) {
        mdl_set_all_tint_type(tintType);
        return ApiStatus_DONE2;
    }

    switch (mode) {
        case APPLY_TINT_MODELS:
            while (true) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                listIndex = get_model_list_index_from_tree_index(*modelIDList);
                mdl = get_model_from_list_index(listIndex);
                set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, tintType);
                modelIDList++;
            };
            break;

        case APPLY_TINT_GROUPS:
            while (true) {
                if (*modelIDList == 0xFFFF) {
                    break;
                }
                mdl_group_set_custom_gfx(*modelIDList, CUSTOM_GFX_NONE, tintType, false);
                modelIDList++;
            };
            break;

        case APPLY_TINT_BG:
            *gBackgroundTintModePtr = tintType;
            break;

    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetModelTintParams)) {
    Bytecode* args = script->ptrReadPos;
    s32 tintType = evt_get_variable(script, *args++);
    s32 arg0 = evt_get_variable(script, *args++);
    s32 arg1 = evt_get_variable(script, *args++);
    s32 arg2 = evt_get_variable(script, *args++);
    s32 arg3 = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);
    s32 arg7 = evt_get_variable(script, *args++);
    s32 arg8 = evt_get_variable(script, *args++);

    switch (tintType) {
        case ENV_TINT_SHROUD:
            mdl_set_shroud_tint_params(arg0, arg1, arg2, arg3);
            break;
        case ENV_TINT_DEPTH:
            mdl_set_depth_tint_params(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            break;
        case ENV_TINT_REMAP:
            mdl_set_remap_tint_params(arg0, arg1, arg2, arg3, arg4, arg5);
            break;
    }

    return ApiStatus_DONE2;
}

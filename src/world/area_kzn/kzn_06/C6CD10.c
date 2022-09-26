#include "kzn_06.h"
#include "model.h"

#include "world/common/atomic/LavaBlockage.inc.c"

ApiStatus N(AdjustFog)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ModelIDList* modelIDs;
    ModelIDList* iterList;
    s32 colR, colG, colB;
    s32 duration;
    s32 mode;
    s32 i;
    
    modelIDs = (ModelIDList*) evt_get_variable(script, *args++);
    colR = evt_get_variable(script, *args++);
    colG = evt_get_variable(script, *args++);
    colB = evt_get_variable(script, *args++);
    duration = evt_get_variable(script, *args++);
    mode = evt_get_variable(script, *args++);
    iterList = modelIDs; 
    
    if (isInitialCall) {
        for (i = 0; i < iterList->count; i++) {
            s32 treeIndex = get_model_list_index_from_tree_index(iterList->list[i]);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, -1, 3);
            if (mode) {
                mdl->flags &= ~MODEL_FLAGS_ENABLED;
            }
        }
        script->functionTemp[0] = duration;
    }
    
    if (mode) {
        set_background_color_blend(colR, colG, colB, 
            (script->functionTemp[0] * 255) / duration);
    } else {
        set_background_color_blend(colR, colG, colB, 
            255 - ((script->functionTemp[0] * 255) / duration));
    }
    
    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        for (i = 0; i < iterList->count; i++) {
            s32 treeIndex = get_model_list_index_from_tree_index(iterList->list[i]);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, -1, 0);
            if (!mode) {
                mdl->flags |= MODEL_FLAGS_ENABLED;
            }
        }
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80240A44_C6D364(Evt* script, s32 isInitialCall) {
    snd_ambient_80055618(0, 1);
    return ApiStatus_DONE2;
}

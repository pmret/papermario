#include "common.h"
#include "model.h"

void set_model_fog_color_parameters(u8, u8, u8, u8, u8, u8, u8, s32, s32);

extern f32 N(LavaBlockageTime);

s32 N(LavaBlockageFunc1)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    ModelIDList* modelIDs = (ModelIDList*) evt_get_variable(script, *args++);
    f32 deltaX;
    f32 scale;
    s32 fogStart;
    f32 baseAlpha; 
    f32 slowOsc, fastOsc;
    f64 primA;
    s32 i;
    
    if (isInitialCall) {
        if (modelIDs != NULL) {
            u16* idList = modelIDs->list;
            for (i = 0; i < modelIDs->count; i++, idList++) {
                s32 treeIndex = get_model_list_index_from_tree_index(*idList);
                Model* mdl = get_model_from_list_index(treeIndex);
                set_mdl_custom_gfx_set(mdl, -1, 2);
            }
        } else {
            Model** models = (Model**) gCurrentModels;
            for (i = 0; i < MAX_MODELS; i++, models++) {
                if (*models != NULL) {
                    set_mdl_custom_gfx_set(*models, -1, 2);
                }
            }
        }
    }
    
    N(LavaBlockageTime) += 1.0f;
    if (N(LavaBlockageTime) > 360.0f) {
        N(LavaBlockageTime) -= 360.0f;
    }

    switch (mode) {
        case 1:
            if (evt_get_float_variable(NULL, MapVar(0)) <= 0.0f) {
                return ApiStatus_DONE2;
            }
            deltaX = -75.0f - playerStatus->position.x;
            if (deltaX < 0.0f) {
                deltaX = -deltaX;
            }
            baseAlpha = 512.0f - deltaX;
            if (baseAlpha < 0.0f) {
                baseAlpha = 0.0f;
            }
            fogStart = 970;
            baseAlpha *= 0.2 * evt_get_float_variable(NULL, MapVar(0));
            break;
        case 2:
            baseAlpha = 100.0f;
            fogStart = 995 - evt_get_variable(NULL, MapVar(0));
            break;   
        case 10:
            return 0;
        default:
            baseAlpha = 100.0f;
            fogStart = 970;
            break;
    }

    slowOsc = sin_deg(N(LavaBlockageTime) * 3.0f);
    fastOsc = sin_deg(N(LavaBlockageTime) * 8.0f);
    primA = baseAlpha + baseAlpha * (slowOsc * 0.5 + fastOsc * 0.5);

    set_model_fog_color_parameters(60, 50, 30, primA, 20, 20, 20, fogStart, 1000);
    return ApiStatus_BLOCK;
}

ApiStatus N(LavaBlockageFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ModelIDList* modelIDs = (ModelIDList*) evt_get_variable(script, *args++);
    s32 i;
        
    if (modelIDs != NULL) {
        u16* idList = modelIDs->list;
        for (i = 0; i < modelIDs->count; i++, idList++) {
            s32 treeIndex = get_model_list_index_from_tree_index(*idList);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, -1, 0);
        }
    } else {
        Model** models = (Model**) gCurrentModels;
        for (i = 0; i < MAX_MODELS; i++, models++) {
            if (*models != NULL) {
                set_mdl_custom_gfx_set(*models, -1, 0);
            }
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(LavaBlockageFunc3)(Evt* script, s32 isInitialCall) {
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

#include "kzn_07.h"
#include "model.h"

void set_model_fog_color_parameters(u8, u8, u8, u8, u8, u8, u8, s32, s32);

extern f32 D_802423E0_C70710;

//TODO LavaBlockageFunc1
s32 func_80240000_C6E330(Evt* script, s32 isInitialCall) {
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
    
    D_802423E0_C70710 += 1.0f;
    if (D_802423E0_C70710 > 360.0f) {
        D_802423E0_C70710 -= 360.0f;
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

    slowOsc = sin_deg(D_802423E0_C70710 * 3.0f);
    fastOsc = sin_deg(D_802423E0_C70710 * 8.0f);
    primA = baseAlpha + baseAlpha * (slowOsc * 0.5 + fastOsc * 0.5);

    set_model_fog_color_parameters(60, 50, 30, primA, 20, 20, 20, fogStart, 1000);
    return ApiStatus_BLOCK;
}

ApiStatus func_80240348_C6E678(Evt* script, s32 isInitialCall) {
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

#include "world/common/atomic/TexturePan.inc.c"

static char* kzn_06 = "kzn_06";

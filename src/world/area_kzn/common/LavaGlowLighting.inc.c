#include "common.h"
#include "model.h"

// REQUIRES:
// MapVar:  MV_GlowIntensity

enum {
    LAVA_GLOW_MODE_0     = 0,
    LAVA_GLOW_MODE_1     = 1,
    LAVA_GLOW_MODE_2     = 2,
    LAVA_GLOW_MODE_END   = 10
};

f32 N(LavaGlowLightTime) = 0.0f;

API_CALLABLE(N(ApplyLavaGlowLighting)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 glowMode = evt_get_variable(script, *args++);
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
            // apply effect to models in the list
            u16* idList = modelIDs->list;
            for (i = 0; i < modelIDs->count; i++, idList++) {
                s32 treeIndex = get_model_list_index_from_tree_index(*idList);
                Model* mdl = get_model_from_list_index(treeIndex);
                set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, ENV_TINT_DEPTH);
            }
        } else {
            // list is NULL -> apply effect to ALL models
            Model** models = (Model**) gCurrentModels;
            for (i = 0; i < MAX_MODELS; i++, models++) {
                if (*models != NULL) {
                    set_mdl_custom_gfx_set(*models, CUSTOM_GFX_NONE, ENV_TINT_DEPTH);
                }
            }
        }
    }

    N(LavaGlowLightTime) += 1.0f;
    if (N(LavaGlowLightTime) > 360.0f) {
        N(LavaGlowLightTime) -= 360.0f;
    }

    switch (glowMode) {
        case LAVA_GLOW_MODE_1:
            if (evt_get_float_variable(NULL, MV_GlowIntensity) <= 0.0f) {
                return ApiStatus_DONE2;
            }
            deltaX = -75.0f - playerStatus->pos.x;
            if (deltaX < 0.0f) {
                deltaX = -deltaX;
            }
            baseAlpha = 512.0f - deltaX;
            if (baseAlpha < 0.0f) {
                baseAlpha = 0.0f;
            }
            baseAlpha *= 0.2 * evt_get_float_variable(NULL, MV_GlowIntensity);
            fogStart = 970;
            break;
        case LAVA_GLOW_MODE_2:
            baseAlpha = 100.0f;
            fogStart = 995 - evt_get_variable(NULL, MV_GlowIntensity);
            break;
        case LAVA_GLOW_MODE_END:
            return ApiStatus_BLOCK;
        default:
            baseAlpha = 100.0f;
            fogStart = 970;
            break;
    }

    slowOsc = sin_deg(N(LavaGlowLightTime) * 3.0f);
    fastOsc = sin_deg(N(LavaGlowLightTime) * 8.0f);
    primA = baseAlpha + baseAlpha * (slowOsc * 0.5 + fastOsc * 0.5);

    mdl_set_depth_tint_params(60, 50, 30, primA, 20, 20, 20, fogStart, 1000);
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ClearLavaGlowLighting)) {
    Bytecode* args = script->ptrReadPos;
    ModelIDList* modelIDs = (ModelIDList*) evt_get_variable(script, *args++);
    s32 i;

    if (modelIDs != NULL) {
        // clear effect from models in the list
        u16* idList = modelIDs->list;
        for (i = 0; i < modelIDs->count; i++, idList++) {
            s32 treeIndex = get_model_list_index_from_tree_index(*idList);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, ENV_TINT_NONE);
        }
    } else {
        // list is NULL -> clear effect from ALL models
        Model** models = (Model**) gCurrentModels;
        for (i = 0; i < MAX_MODELS; i++, models++) {
            if (*models != NULL) {
                set_mdl_custom_gfx_set(*models, CUSTOM_GFX_NONE, ENV_TINT_NONE);
            }
        }
    }
    return ApiStatus_DONE2;
}

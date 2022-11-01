#include "omo_11.h"
#include "model.h"

static char* N(exit_str_0) = "omo_12";
static char* N(exit_str_1) = "omo_10";

typedef struct UnkOmo9 {
    /* 0x00 */ s32 shadowIndexes[8];
} UnkOmo11; // size = 0x20

extern s32 D_80241740_DDDF70[8];

ApiStatus func_80240000_DDC830(Evt* script, s32 isInitialCall) {
    f32 x, y, z;
    f32 rotX, rotZ;
    f32 scale;
    Shadow* shadow;
    UnkOmo11* unkStruct;
    Model* model;
    u32 i;

    if (isInitialCall) {

        script->functionTempPtr[0] = unkStruct = heap_malloc(sizeof(*unkStruct));
        for (i = 0; i < ARRAY_COUNT(D_80241740_DDDF70); i++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241740_DDDF70[i]));
            unkStruct->shadowIndexes[i] =
                create_shadow_type(0, model->center.x, model->center.y - 100.0f, model->center.z);
        }
    }

    unkStruct = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(D_80241740_DDDF70); i++) {
        shadow = get_shadow_by_index(unkStruct->shadowIndexes[i]);
        model = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241740_DDDF70[i]));
        x = model->center.x;
        y = model->center.y;
        z = model->center.z;
        scale = 1000.0f;
        entity_raycast_down(&x, &y, &z, &rotX, &rotZ, &scale);
        set_standard_shadow_scale(shadow, scale);
        shadow->rotation.y = 0.0f;
        shadow->position.x = x;
        shadow->position.y = y;
        shadow->position.z = z;
        shadow->rotation.x = rotX;
        shadow->rotation.z = rotZ;
        shadow->scale.x *= 3.0f;
        shadow->scale.z *= 3.0f;
    }
    return ApiStatus_BLOCK;
}


INCLUDE_ASM(s32, "world/area_omo/omo_11/DDC830", func_802401A0_DDC9D0);

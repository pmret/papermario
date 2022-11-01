#include "omo_09.h"
#include "model.h"

typedef struct UnkOmo9 {
    /* 0x00 */ s32 shadowIndexes[4];
} UnkOmo9; // size = 0x10

extern s32 D_802451AC_DD1E7C[];
extern s32 D_8024636C_DD303C[4];

ApiStatus func_802402D0_DCCFA0(Evt* script, s32 isInitialCall) {
    s32 sp10[3];
    Bytecode* args = script->ptrReadPos;
    s32 v1 = evt_get_variable(script, *args++);
    s32 v2 = evt_get_variable(script, *args++);
    s32 v3 = evt_get_variable(script, *args++);
    s32 iNum, jNum;
    s32 i, j;

    if (v1 != -1) {
        sp10[0] = D_802451AC_DD1E7C[(v1 % 360) / 45];
    } else {
        sp10[0] = 0;
    }
    if (v2 != -1) {
        sp10[1] = D_802451AC_DD1E7C[((v2 % 360) / 45) + 8];
    } else {
        sp10[1] = 0;
    }
    if (v3 != -1) {
        sp10[2] = D_802451AC_DD1E7C[((v3 % 360) / 45) + 16];
    } else {
        sp10[2] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(sp10) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(sp10); j++) {
            iNum = sp10[i];
            jNum = sp10[j];
            if (jNum < iNum) {
                sp10[i] = jNum;
                sp10[j] = iNum;
            }
        }
    }
    if (sp10[1] == sp10[0]) {
        if (sp10[1] == sp10[2]) {
            script->varTable[10] = 3;
        } else {
            script->varTable[10] = 2;
        }
    } else if (sp10[1] == sp10[2]) {
        script->varTable[10] = 2;
    } else {
        script->varTable[10] = 0;
    }
    script->varTable[11] = sp10[1];
    return ApiStatus_DONE2;
}

ApiStatus func_80240534_DCD204(Evt* script, s32 isInitialCall) {
    f32 x, y, z;
    f32 rotX, rotZ;
    f32 scale;
    Shadow* shadow;
    UnkOmo9* unkStruct;
    Model* model;
    u32 i;

    if (isInitialCall) {

        script->functionTempPtr[0] = unkStruct = heap_malloc(sizeof(*unkStruct));
        for (i = 0; i < ARRAY_COUNT(D_8024636C_DD303C); i++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(D_8024636C_DD303C[i]));
            unkStruct->shadowIndexes[i] = create_shadow_type(1, model->center.x, model->center.y - 100.0f, model->center.z);
        }
    }

    unkStruct = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(D_8024636C_DD303C); i++) {
        shadow = get_shadow_by_index(unkStruct->shadowIndexes[i]);
        model = get_model_from_list_index(get_model_list_index_from_tree_index(D_8024636C_DD303C[i]));
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
        shadow->scale.x *= 1.3f;
        shadow->scale.z *= 1.3f;
    }
    return ApiStatus_BLOCK;
}

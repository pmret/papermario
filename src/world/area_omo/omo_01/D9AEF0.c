#include "omo_01.h"
#include "model.h"

extern s32 D_802412A0_D9C190[];

ApiStatus func_80240000_D9AEF0(Evt* script, s32 isInitialCall) {
    Matrix4f sp18, sp58;
    RockingHorse* it;
    Model* model;
    f32 temp_f20;
    f32 temp_f24;
    u32 i;

    if (isInitialCall) {
        it = heap_malloc(sizeof(*it) * 2);
        script->functionTempPtr[0] = it;

        for (i = 0; i < 2; i++, it++) {
            s32 treeIndex = D_802412A0_D9C190[i];

            it->modelID = treeIndex;
            model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
            it->posX = model->center.x;
            it->posZ = model->center.z;
            it->rockPhaseAngularVel = 3.5f;
            it->rockPhase = 0;
            it->lastRockAngle = 0;
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < 2; i++, it++) {
        it->rockPhase += it->rockPhaseAngularVel;
        it->rockPhase = clamp_angle(it->rockPhase);
        temp_f20 = sin_deg(it->rockPhase) * 20.0f;
        temp_f24 = SQ(temp_f20) / 90.0f;
        if (i == 0) {
            if ((it->lastRockAngle >= 0.0f && temp_f20 < 0.0f) || (it->lastRockAngle < 0.0f && temp_f20 >= 0.0f)) {
                sfx_play_sound_at_position(SOUND_CREAKY_ROCKING_CHAIR, 0, -185.0f, 0.0f, 160.0f);
            }
            it->lastRockAngle = temp_f20;
        }
        model = get_model_from_list_index(get_model_list_index_from_tree_index(it->modelID));
        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp18, -it->posX, 0.0f, -it->posZ);
        guRotateF(sp58, temp_f20, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp18, sp58, model->transformMatrix);
        guTranslateF(sp18, it->posX, temp_f24, it->posZ);
        guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    }
    return ApiStatus_BLOCK;
}

#include "omo_02.h"
#include "model.h"

extern s32 D_802434F8_DA09C8[];

ApiStatus func_80240040_D9D510(Evt* script, s32 isInitialCall) {
    Matrix4f sp18, sp58;
    UnkOmo* it;
    Model* model;
    f32 temp_f20;
    f32 temp_f24;
    u32 i;

    if (isInitialCall) {
        it = heap_malloc(sizeof(*it) * 2);
        script->functionTempPtr[0] = it;

        for (i = 0; i < 2; i++, it++) {
            s32 treeIndex = D_802434F8_DA09C8[i];

            it->treeIndex = treeIndex;
            model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
            it->unk_00 = model->center.x;
            it->unk_04 = model->center.z;
            it->unk_0C = 3.5f;
            it->unk_10 = 0;
            it->unk_08 = 0;
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < 2; i++, it++) {
        it->unk_10 += it->unk_0C;
        it->unk_10 = clamp_angle(it->unk_10);
        temp_f20 = sin_rad((it->unk_10 * 3.14f) / 180.0f) * 20.0f;
        temp_f24 = SQ(temp_f20) / 90.0f;
        if (i == 0) {
            if ((it->unk_08 >= 0.0f && temp_f20 < 0.0f) || (it->unk_08 < 0.0f && temp_f20 >= 0.0f)) {
                sfx_play_sound_at_position(SOUND_CREAKY_ROCKING_CHAIR, 0, -706.0f, 0.0f, 102.0f);
            }
            it->unk_08 = temp_f20;
        }
        model = get_model_from_list_index(get_model_list_index_from_tree_index(it->treeIndex));
        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp18, -it->unk_00, 0.0f, -it->unk_04);
        guRotateF(sp58, temp_f20, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp18, sp58, model->transformMatrix);
        guTranslateF(sp18, it->unk_00, temp_f24, it->unk_04);
        guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    }
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_omo/omo_02/D9D510", func_802402C0_D9D790);

INCLUDE_ASM(s32, "world/area_omo/omo_02/D9D510", func_8024043C_D9D90C);

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/StationaryAI.inc.c"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/SetInstigatorValue_3.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

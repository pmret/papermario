#include "sam_07.h"
#include "model.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_08";

extern s32 D_802424C0_D2E1F0[55]; // TODO remove hard-coded size when data is migrated

typedef struct UnkSam07 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f rotVel;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ Matrix4f transformMatrix;
} UnkSam07; // size = 0x80

NOP_FIX
ApiStatus func_80240000_D2BD30(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp18, sp58, sp98, spD8;
    UnkSam07* it;
    Model* model;
    u32 i;
    s32 j, k;

    if (isInitialCall) {

        script->functionTempPtr[0] = heap_malloc(sizeof(*it) * ARRAY_COUNT(D_802424C0_D2E1F0));
        script->functionTemp[1] = 0;

        it = script->functionTempPtr[0];
        for (i = 0; i < ARRAY_COUNT(D_802424C0_D2E1F0); i++, it++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(D_802424C0_D2E1F0[i]));
            it->unk_00 = 0;
            it->unk_04.x = model->center.x;
            it->unk_04.y = model->center.y;
            it->unk_04.z = model->center.z;
            it->rot.x = 0.0f;

            it->rot.y = 0.0f;
            it->rot.z = 0.0f;
            it->unk_10.x = it->unk_04.x;
            it->unk_10.y = it->unk_04.y;
            it->unk_10.z = it->unk_04.z;
            it->rotVel.x = rand_int(20) - 10;
            it->rotVel.y = rand_int(20) - 10;
            it->rotVel.z = rand_int(20) - 10;
            it->unk_34 = rand_int(5) + 5.0f;
            it->unk_38 = rand_int(3) + 1.0f;
            it->unk_3C = rand_int(360);

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = model->transformMatrix[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(D_802424C0_D2E1F0); i++, it++) {
        model = get_model_from_list_index(get_model_list_index_from_tree_index(D_802424C0_D2E1F0[i]));
        if (it->unk_00 == 0) {
            add_vec2D_polar(&it->unk_04.x, &it->unk_04.z, it->unk_38, it->unk_3C);
            it->unk_34 -= 1.0f;
            it->unk_04.y += it->unk_34;
            if (it->unk_34 < 0.0f) {
                if (it->unk_04.y < playerStatus->position.y - 150.0f) {
                    script->functionTemp[1]++;
                    it->unk_00 = 101;
                }
            }
        }

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                model->transformMatrix[j][k] = it->transformMatrix[j][k];
            }
        }

        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp18, it->unk_04.x - it->unk_10.x, it->unk_04.y - it->unk_10.y, it->unk_04.z - it->unk_10.z);
        it->rot.x += it->rotVel.x;
        it->rot.y += it->rotVel.y;
        it->rot.z += it->rotVel.z;
        it->rot.x = clamp_angle(it->rot.x);
        it->rot.y = clamp_angle(it->rot.y);
        it->rot.z = clamp_angle(it->rot.z);
        guRotateF(sp58, it->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(sp98, it->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(spD8, it->rot.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(spD8, sp58, sp58);
        guMtxCatF(sp58, sp98, sp98);
        guMtxCatF(sp98, sp18, sp18);
        guMtxCatF(sp18, model->transformMatrix, model->transformMatrix);
    }

    if ((u32) script->functionTemp[1] >= ARRAY_COUNT(D_802424C0_D2E1F0)) {
        heap_free(script->functionTempPtr[0]);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
NOP_UNFIX

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

ApiStatus func_802405B0_D2C2E0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 floor = evt_get_variable(script, *args++);
    s32 floor2 = evt_get_variable(script, *args++);

    if (gCollisionStatus.currentFloor == floor || gCollisionStatus.currentFloor == floor2) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
            playerStatus->actionState == ACTION_STATE_TORNADO_POUND)
        {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

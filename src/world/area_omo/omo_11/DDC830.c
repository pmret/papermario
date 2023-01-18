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

typedef struct UnkOmo11 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Matrix4f transformMatrix;
} UnkOmo11_2; // size = 0x58

extern s32 D_80241760_DDDF90[6]; // TODO remove hard-coded size once data is migrated
extern s32 D_80241778_DDDFA8[6]; // TODO remove hard-coded size once data is migrated

NOP_FIX
ApiStatus func_802401A0_DDC9D0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp20, sp60, spA0, spE0;
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Model* model1 = get_model_from_list_index(get_model_list_index_from_tree_index(0x4A));
    Model* model2 = get_model_from_list_index(get_model_list_index_from_tree_index(0x3F));
    f32 ox, oy, oz;
    Model* loopModel;
    f32 x, y, z;
    UnkOmo11_2* it;
    u32 cond;
    u32 i;
    s32 j, k;

    if (isInitialCall) {
        sfx_play_sound_at_position(SOUND_80000016, 0, 315.0f, 125.0f, -100.0f);
        script->functionTempPtr[0] = it = heap_malloc(sizeof(*it) * ARRAY_COUNT(D_80241760_DDDF90));
        script->functionTemp[1] = 0;

        for (i = 0; i < ARRAY_COUNT(D_80241760_DDDF90); it++, i += 2) {
            loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241760_DDDF90[i]));
            it->unk_00.x = x = loopModel->center.x - model1->center.x;
            it->unk_00.y = y = loopModel->center.y - model1->center.y;
            it->unk_00.z = z = loopModel->center.z - model1->center.z;

            ox = x;
            oy = y;
            oz = z;

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = loopModel->transformMatrix[j][k];
                }
            }

            loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241760_DDDF90[i + 1]));

            it = it + 1;
            it->unk_00.x = ox;
            it->unk_00.y = oy;
            it->unk_00.z = oz;

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = loopModel->transformMatrix[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < 6; i++, it++) {
        loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241760_DDDF90[i]));

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                loopModel->transformMatrix[j][k] = it->transformMatrix[j][k];
            }
        }

        loopModel->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp20, it->unk_00.x, it->unk_00.y, it->unk_00.z);
        guRotateF(spA0, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
        guTranslateF(sp60, -it->unk_00.x, -it->unk_00.y, -it->unk_00.z);
        guRotateF(spE0, -script->functionTemp[1], 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp20, spA0, spA0);
        guMtxCatF(spA0, sp60, sp60);
        guMtxCatF(spE0, sp60, sp60);
        guMtxCatF(loopModel->transformMatrix, sp60, loopModel->transformMatrix);
        update_collider_transform(D_80241778_DDDFA8[i]);
        guMtxXFMF(loopModel->transformMatrix, 0.0f, 0.0f, 0.0f, &ox, &oy, &oz);
        if (gCollisionStatus.currentFloor == D_80241778_DDDFA8[i] ||
            gCollisionStatus.lastTouchedFloor == D_80241778_DDDFA8[i])
        {
            playerStatus->pushVelocity.x = ox - it->unk_0C.x;
            playerStatus->pushVelocity.y = oy - it->unk_0C.y;
            playerStatus->pushVelocity.z = oz - it->unk_0C.z;
        }
        if (partner->currentFloor == D_80241778_DDDFA8[i]) {
            partner->pos.x += ox - it->unk_0C.x;
            partner->pos.y += oy - it->unk_0C.y;
            partner->pos.z += oz - it->unk_0C.z;
        }
        it->unk_0C.x = ox;
        it->unk_0C.y = oy;
        it->unk_0C.z = oz;
    }

    guRotateF(model1->transformMatrix, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
    model1->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
    update_collider_transform(0x32);

    guRotateF(model2->transformMatrix, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
    model2->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
    update_collider_transform(0x27);

    cond = FALSE;
    for (i = 0; i < ARRAY_COUNT(D_80241778_DDDFA8); i++) {
        if (gCollisionStatus.currentFloor == D_80241778_DDDFA8[i]) {
            if (playerStatus->flags & PS_FLAG_NO_STATIC_COLLISION) {
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            }
            if (playerStatus->actionState == ACTION_COMMAND_AIR_RAID ||
                playerStatus->actionState == ACTION_COMMAND_POWER_SHOCK)
            {
                cond = TRUE;
            }
        }
    }
    if (!cond) {
        script->functionTemp[1]--;
    }

    return ApiStatus_BLOCK;
}

#include "omo_11.h"
#include "model.h"

s32 N(PlatformFloorModels)[] = {
    MODEL_1_1,
    MODEL_1_2,
    MODEL_1_3,
    MODEL_2_1,
    MODEL_2_2,
    MODEL_2_3,
    MODEL_2_4,
    MODEL_2_5,
};

s32 N(RotatingPlatformModels)[] = {
    MODEL_1_1,
    MODEL_f1_1,
    MODEL_1_2,
    MODEL_f1_2,
    MODEL_1_3,
    MODEL_f1_3,
};

s32 N(RotatingPlatformColliders)[] = {
    COLLIDER_1_1,
    COLLIDER_f1_1,
    COLLIDER_1_2,
    COLLIDER_f1_2,
    COLLIDER_1_3,
    COLLIDER_f1_3,
};

s32 N(BasicPlatform1)[] = {
    MODEL_2_1,
    COLLIDER_2_1,
    MODEL_f2_1,
    COLLIDER_f2_1,
};

s32 N(BasicPlatform2)[] = {
    MODEL_2_2,
    COLLIDER_2_2,
    MODEL_f2_2,
    COLLIDER_f2_2,
};

s32 N(BasicPlatform3)[] = {
    MODEL_2_3,
    COLLIDER_2_3,
    MODEL_f2_3,
    COLLIDER_f2_3,
};

s32 N(BasicPlatform4)[] = {
    MODEL_2_4,
    COLLIDER_2_4,
    MODEL_f2_4,
    COLLIDER_f2_4,
};

s32 N(BasicPlatform5)[] = {
    MODEL_2_5,
    COLLIDER_2_5,
    MODEL_f2_5,
    COLLIDER_f2_5,
};

API_CALLABLE(N(UpdatePlatformShadows)) {
    s32 (*shadowIDs)[8];
    Model* model;
    Shadow* shadow;
    f32 x, y, z;
    f32 rotX, rotZ;
    f32 scale;
    u32 i;

    if (isInitialCall) {
        script->functionTempPtr[0] = shadowIDs = heap_malloc(sizeof(*shadowIDs));
        for (i = 0; i < ARRAY_COUNT(N(PlatformFloorModels)); i++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(N(PlatformFloorModels)[i]));
            (*shadowIDs)[i] = create_shadow_type(0, model->center.x, model->center.y - 100.0f, model->center.z);
        }
    }

    shadowIDs = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(PlatformFloorModels)); i++) {
        shadow = get_shadow_by_index((*shadowIDs)[i]);
        model = get_model_from_list_index(get_model_list_index_from_tree_index(N(PlatformFloorModels)[i]));
        x = model->center.x;
        y = model->center.y;
        z = model->center.z;
        scale = 1000.0f;
        entity_raycast_down(&x, &y, &z, &rotX, &rotZ, &scale);
        set_standard_shadow_scale(shadow, scale);
        shadow->rot.y = 0.0f;
        shadow->pos.x = x;
        shadow->pos.y = y;
        shadow->pos.z = z;
        shadow->rot.x = rotX;
        shadow->rot.z = rotZ;
        shadow->scale.x *= 3.0f;
        shadow->scale.z *= 3.0f;
    }
    return ApiStatus_BLOCK;
}

typedef struct RotatingPlatform {
    /* 0x00 */ Vec3f relativePos;
    /* 0x0C */ Vec3f lastRelativePos;
    /* 0x18 */ Matrix4f transformMatrix;
} RotatingPlatform; // size = 0x58

API_CALLABLE(N(UpdateRotatingPlatforms)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp20, sp60, spA0, spE0;
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Model* axisModel = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_fl));
    Model* ringModel = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_1_0));
    f32 ox, oy, oz;
    Model* loopModel;
    f32 x, y, z;
    RotatingPlatform* it;
    u32 isPounding;
    u32 i;
    s32 j, k;

    if (isInitialCall) {
        sfx_play_sound_at_position(SOUND_LOOP_OMO_ROTATING_WHEEL, SOUND_SPACE_DEFAULT, 315.0f, 125.0f, -100.0f);
        script->functionTempPtr[0] = it = heap_malloc(sizeof(*it) * ARRAY_COUNT(N(RotatingPlatformModels)));
        script->functionTemp[1] = 0;

        for (i = 0; i < ARRAY_COUNT(N(RotatingPlatformModels)); it++, i += 2) {
            loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(N(RotatingPlatformModels)[i]));

            it->relativePos.x = x = loopModel->center.x - axisModel->center.x;
            it->relativePos.y = y = loopModel->center.y - axisModel->center.y;
            it->relativePos.z = z = loopModel->center.z - axisModel->center.z;

            ox = x;
            oy = y;
            oz = z;

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = loopModel->userTransformMtx[j][k];
                }
            }

            it++;
            loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(N(RotatingPlatformModels)[i + 1]));

            it->relativePos.x = ox;
            it->relativePos.y = oy;
            it->relativePos.z = oz;

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = loopModel->userTransformMtx[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(RotatingPlatformModels)); i++, it++) {
        loopModel = get_model_from_list_index(get_model_list_index_from_tree_index(N(RotatingPlatformModels)[i]));

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                loopModel->userTransformMtx[j][k] = it->transformMatrix[j][k];
            }
        }

        loopModel->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
        guTranslateF(sp20, it->relativePos.x, it->relativePos.y, it->relativePos.z);
        guRotateF(spA0, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
        guTranslateF(sp60, -it->relativePos.x, -it->relativePos.y, -it->relativePos.z);
        guRotateF(spE0, -script->functionTemp[1], 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp20, spA0, spA0);
        guMtxCatF(spA0, sp60, sp60);
        guMtxCatF(spE0, sp60, sp60);
        guMtxCatF(loopModel->userTransformMtx, sp60, loopModel->userTransformMtx);
        update_collider_transform(N(RotatingPlatformColliders)[i]);
        guMtxXFMF(loopModel->userTransformMtx, 0.0f, 0.0f, 0.0f, &ox, &oy, &oz);
        if (gCollisionStatus.curFloor == N(RotatingPlatformColliders)[i] ||
            gCollisionStatus.lastTouchedFloor == N(RotatingPlatformColliders)[i])
        {
            playerStatus->pushVel.x = ox - it->lastRelativePos.x;
            playerStatus->pushVel.y = oy - it->lastRelativePos.y;
            playerStatus->pushVel.z = oz - it->lastRelativePos.z;
        }
        if (partner->curFloor == N(RotatingPlatformColliders)[i]) {
            partner->pos.x += ox - it->lastRelativePos.x;
            partner->pos.y += oy - it->lastRelativePos.y;
            partner->pos.z += oz - it->lastRelativePos.z;
        }
        it->lastRelativePos.x = ox;
        it->lastRelativePos.y = oy;
        it->lastRelativePos.z = oz;
    }

    guRotateF(axisModel->userTransformMtx, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
    axisModel->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
    update_collider_transform(COLLIDER_fl);

    guRotateF(ringModel->userTransformMtx, script->functionTemp[1], 0.0f, 0.0f, 1.0f);
    ringModel->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
    update_collider_transform(COLLIDER_1_0);

    isPounding = FALSE;
    for (i = 0; i < ARRAY_COUNT(N(RotatingPlatformColliders)); i++) {
        if (gCollisionStatus.curFloor == N(RotatingPlatformColliders)[i]) {
            if (playerStatus->flags & PS_FLAG_NO_STATIC_COLLISION) {
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            }
            if (playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
                playerStatus->actionState == ACTION_STATE_TORNADO_POUND)
            {
                isPounding = TRUE;
            }
        }
    }
    if (!isPounding) {
        script->functionTemp[1]--;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_UpdateBasicPlatform_Silent) = {
    EVT_CALL(RandInt, 20, LVarA)
    EVT_WAIT(LVarA)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar6, LVar7, LVar8, LVar9)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -82, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar6, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar8, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar7)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, -82, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar6, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar8, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar7)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_WAIT(20)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateBasicPlatform_Audible) = {
    EVT_CALL(RandInt, 20, LVarA)
    EVT_WAIT(LVarA)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar6, LVar7, LVar8, LVar9)
    EVT_LABEL(0)
        EVT_CALL(PlaySound, SOUND_OMO_PLATFORM_ASCEND)
        EVT_CALL(MakeLerp, 0, 70, 51, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar6, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar8, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar7)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_OMO_PLATFORM_DESCEND)
        EVT_CALL(MakeLerp, 70, 0, 51, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar6, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar8, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar7)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_WAIT(20)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(ParentColliderToModel, COLLIDER_1_0, MODEL_1_0)
    EVT_CALL(ParentColliderToModel, COLLIDER_fl, MODEL_fl)
    EVT_CALL(ParentColliderToModel, COLLIDER_1_1, MODEL_1_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_f1_1, MODEL_f1_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_1_2, MODEL_1_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_f1_2, MODEL_f1_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_1_3, MODEL_1_3)
    EVT_CALL(ParentColliderToModel, COLLIDER_f1_3, MODEL_f1_3)
    EVT_THREAD
        EVT_CALL(N(UpdateRotatingPlatforms))
    EVT_END_THREAD
    EVT_CALL(ParentColliderToModel, COLLIDER_2_1, MODEL_2_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_f2_1, MODEL_f2_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_2_2, MODEL_2_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_f2_2, MODEL_f2_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_2_3, MODEL_2_3)
    EVT_CALL(ParentColliderToModel, COLLIDER_f2_3, MODEL_f2_3)
    EVT_CALL(ParentColliderToModel, COLLIDER_2_4, MODEL_2_4)
    EVT_CALL(ParentColliderToModel, COLLIDER_f2_4, MODEL_f2_4)
    EVT_CALL(ParentColliderToModel, COLLIDER_2_5, MODEL_2_5)
    EVT_CALL(ParentColliderToModel, COLLIDER_f2_5, MODEL_f2_5)
    EVT_SET(LVar0, EVT_PTR(N(BasicPlatform1)))
    EVT_EXEC(N(EVS_UpdateBasicPlatform_Silent))
    EVT_SET(LVar0, EVT_PTR(N(BasicPlatform2)))
    EVT_EXEC(N(EVS_UpdateBasicPlatform_Silent))
    EVT_SET(LVar0, EVT_PTR(N(BasicPlatform3)))
    EVT_EXEC(N(EVS_UpdateBasicPlatform_Silent))
    EVT_SET(LVar0, EVT_PTR(N(BasicPlatform4)))
    EVT_EXEC(N(EVS_UpdateBasicPlatform_Audible))
    EVT_SET(LVar0, EVT_PTR(N(BasicPlatform5)))
    EVT_EXEC(N(EVS_UpdateBasicPlatform_Silent))
    EVT_THREAD
        EVT_CALL(N(UpdatePlatformShadows))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
